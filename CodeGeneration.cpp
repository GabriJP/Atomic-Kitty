#include "CodeGeneration.h"

MemManager memStack;

enum yytokentype;

Scope *scope;
std::ofstream gc("program.q");
int ec = 1;
std::stack<int> returnLabels;

void opera(int left, int right, const char* op){ //TODO detect type
    if (/*isNumberType(memStack.getType(left)) &&*/ memStack.typeOf(left) == memStack.typeOf(right)) {
        RegCode r1 = memStack.load(left);
        RegCode r2 = memStack.load(right);
        gc << '\t' << r1 << " = " << r1 << " " << op << " " << r2 <<
              "; #Operation with id " << left << " and id " << right << "\n";

        gc.flush();
        memStack.remove(right);
    } else {
        logError(std::string("Tipos diferentes: '") +
                         memStack.getType(left)->toString() + "' y '" + memStack.getType(right)->toString() + "'");
    }
}

bool isNumberType(Type *tipo) {
    switch (tipo->getType()) {
        case INT:
        case LONG:
        case FLOAT:
        case DOUBLE:
            return true;
        default:
            return false;
    }
}


int ne() {
    return ec++;
}

void logError(std::string str) {
    yyerror((char *) str.c_str());
}

int createFunction(char *nombre, Type *returnType, vector<ParameterNode *> *v) {
    if (scope->existsFunction(nombre)) {
        logError("Se intenta crear función '" + std::string(nombre) + "', pero ya existe.");
        return -1;
    } else {

        memStack.createFunction();

        int functionEndLabel = ne();
        int label = ne();
        scope->defineFunction(nombre, new FunctionNode(label, returnType, v));

        gc << "\tGT( " << functionEndLabel << " ); #Skip function in global code\n";

        gc << "\nL " << label << ":\t\t\t\t\t\t#Function: " << nombre << '\n';
        scope = new Scope(scope, nombre);

        scope->defineFunction(nombre, new FunctionNode(label, returnType, v));



        for(auto& param : *v) {
            int id = memStack.addToStackWithoutChangingR7(param->getType());
            ((ParameterNode*)scope->getVariable(param->getName()))->setId(id);
        }

        PrimitiveType p(INT);
        memStack.addToStackWithoutChangingR7(&p); //Save r6
        memStack.addToStackWithoutChangingR7(&p); //Save return label

        gc << "\tR6 = R6 - " << memStack.currentStackSize() - returnType->size() << "; #Fix R6\n";

        gc.flush();

        return functionEndLabel;
    }
}

int primitiveExp(yytokentype tipo) {
    return memStack.addToRegister(new PrimitiveType(tipo));
}

bool ofType(yytokentype expected, Type *type) {
    return type->getType() == expected;
}

template<typename Car1, typename Car2>
bool ofType(Car1 car1, Car2 car2) {
    return car1 == car2;
}

template<typename Car1, typename Car2, typename... Cdr>
bool ofType(Car1 car1, Car2 car2, Cdr ... cdr) {
    return car1 == car2 && equal(car1, cdr...);
}

int callFunction(char* nombreFun, int id){
    FunctionNode *nodo = scope->getFunction(nombreFun);
    int labelFin = ne();

    Type * t = new PrimitiveType(INT);
    int r6id = memStack.addToStack(t); //Save r6
    memStack.asign(r6id, RegCode::R6);
    int labelReturnId = memStack.addToStack(t); //Save return label
    memStack.asign(labelReturnId, std::to_string(labelFin));

    gc << "\tR6 = R7 + " << t->size()*2 + memStack.getType(id)->size() <<  "; #Update R6 \n";
    delete t;

    gc << "\tGT(" << nodo->getLabel() << ");\n";

    gc << "L " << labelFin << ": #Return Label\n";

    gc.flush();

    return 0; //Return returned id
}

void yyerror(char *str) {
    extern int yylineno;
    printf("Parse  Error near line %d \n %s\n", fines, str);
    memStack.print();
    gc.flush();
    exit(-1);
}

int addNewVar(Type *type, char *name) {
    int id = memStack.addToStack(type, name);
    scope->defineVariable(name, new VariableNode(type, id));
    return id;
}

void initQ() {

    gc << "#include \"Q.h\" \n"
          "#define C R7    // cima de la pila \n"
          "#define B R6    // base del marco actual \n\n";

    gc.flush();

}


int primitiveExp(yytokentype tipo, char c) {
    int id = primitiveExp(tipo);
    RegCode reg = memStack.load(id);
    gc << "\t" << reg << " = " << std::string(1,c) << "; \n";
    return id;
}
