#include "CodeGeneration.h"

MemManager memStack;

enum yytokentype;

Scope *scope;
std::ofstream gc("../program.q");
int ec = 1;

void opera(int left, int right, const char* op){ //TODO detect type
    if (memStack.getType(left)->equals(memStack.getType(right))) {
        RegCode r1 = memStack.load(left);
        RegCode r2 = memStack.load(right);
        gc << '\t' << r1 << " = " << r1 << " " << op << " " << r2 <<
              "; # Operation with id " << left << " and id " << right << "\n";

        gc.flush();
        memStack.release(right);
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
int createFunction(char *name, Type *returnType, vector<ParameterNode *> *v) {

    if (isASystemFunction(name)){
        logError("'" + std::string(name) + "' it's a system function");
        return -1;
    }else if (scope->existsFunction(name)) {
        logError("Function '" + std::string(name) + "' already exists");
        return -1;
    } else {

        memStack.createFunction();

        int functionEndLabel = ne();
        int label = ne();
        scope->defineFunction(name, new FunctionNode(label, returnType, v));

        gc << "\tGT( " << functionEndLabel << " ); # Skip function in global code\n";

        gc << "\nL " << label << ":\t\t\t\t\t\t# Function: " << name << '\n';
        scope = new Scope(scope, name);

        for(auto& param : *v) {
            int id = memStack.addToStackWithoutChangingR7(param->getType(), "param: " + param->getName());
            ((ParameterNode*)scope->getVariable(param->getName()))->setId(id);
        }

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

/*
 * Registers
 * ReturnLabel
 * Params <- R6
 */

int callFunctionInit(char *name) {

    memStack.saveRegisters();

    int returnLabel = ne();

    PrimitiveType intType(INT);
    int labelReturnId = memStack.addToStack(&intType, "Return Label"); //Save return label
    memStack.assign(labelReturnId, std::to_string(returnLabel));

    return returnLabel;
}


int callFunction(char* funcName, int id, int returnLabel){


    FunctionNode *nodo = scope->getFunction(funcName);

    if(id != -1) {
        MemManager::StackElement& param = memStack.get(id);
        RegCode reg = memStack.getFromRegisters(id);
        if(reg != RegCode::INVALID) {
            int newId = memStack.addToStack(param.type, "Parameters");
            memStack.assign(newId, reg);
            memStack.release(id);
            id = newId;
        }

        gc << "\tR6 = R7 + " << nodo->paramterSize() - 4 << "; # Update R6 \n";
    }

    gc << "\tGT( " << nodo->getLabel() << " ); # Call " << funcName << "\n";


    gc << "L " << returnLabel << ": # Return Label\n";

    /**gc << "R0 = 0;\n" //For Testing
            "    R1 = 0;\n"
            "    R2 = 0;\n"
            "    R3 = 0;\n"
            "    R4 = 0;\n"
            "    R5 = 0;\n";*/


    memStack.pop();
    memStack.pop();

    memStack.loadRegisters();

    gc << "\tR7 = R6 - " << nodo->getType()->size() + PrimitiveType(INT).size() <<  "; # Update R7 = R6 - R6.size - returned.size \n";

    gc.flush();

    return memStack.addToStackWithoutChangingR7(nodo->getType(), std::string("returned by ") + funcName);
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
          "#define B R6    // base del marco actual \n\n"
          "BEGIN \n\n"
          "L 0:\n"
          "\tR6 = R7;\n";

    gc.flush();

}

void endQ() {

    gc << "\n\tGT( -1 ); # Breakpoint for debug\n";

    gc << "\n\n\tR0 = 0; # Exit code\n"
          "\tGT( -2 ); # Program end\n"
          "END"  ;

    gc.flush();

}


int primitiveExp(yytokentype tipo, char c) {
    int id = primitiveExp(tipo);
    RegCode reg = memStack.load(id);
    gc << "\t" << reg << " = " << std::string(1,c) << "; \n";
    return id;
}

int generateReturn(int expId) {
    PrimitiveType tInt(INT);
    RegCode reg = memStack.getFreeRegister(&tInt);

    memStack.block(reg);

    gc << "\t" << reg << " = I( R6 + 4 ); # Load return label \n";

    memStack.saveReturn(expId);
    gc << "\tGT( " << reg << " ); # Return \n";

    memStack.unBlock(reg);

    return 0;
}

int functionEnd(int endLabel) {
    gc << "L " << endLabel << ": # End of function\n\n";
    memStack.endFuntion();
}

int buildExpList(int exp, int expList) {
    RegCode regExpList = memStack.getFromRegisters(expList);
    if(regExpList != RegCode::INVALID) {
        int newExpList = memStack.addToStack(memStack.getType(expList), "tuple init");
        memStack.assign(newExpList, regExpList);
        memStack.release(expList);
        expList = newExpList;
    }

    bool expListInGlobal;
    std::size_t offset = memStack.offsetOf(expList, expListInGlobal);

    gc << "\tR7 = R7 - " << memStack.getType(exp)->size() << "; # Update size for tuple\n";

    RegCode reg = memStack.getFromRegisters(exp);
    if(reg != INVALID) {
        gc << "\t" << memStack.getInstruction(offset + memStack.getType(expList)->size(),
                                              expListInGlobal, memStack.getType(exp)) <<
                " = " << reg << "; # Saving " << memStack.getType(expList)->toString() << " tuple sub-element\n";
    }else{
        bool expInGlobal;
        memStack.assign(memStack.offsetOf(expList, expListInGlobal) + memStack.getType(expList)->size(), expListInGlobal,
                        memStack.offsetOf(exp, expInGlobal), expInGlobal, memStack.getType(exp));

    }

    memStack.get(expList).type = memStack.getType(expList)->add( memStack.getType(exp) );
    memStack.release(exp);

    return expList;
}

bool isASystemFunction(std::string name) {
    return name == "print" || name == "getchar";
}


