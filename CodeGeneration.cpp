#include "CodeGeneration.h"

MemManager memStack;

enum yytokentype;

Scope *scope;
std::ofstream gc("program.q");
int ec = 1;

int opera(int left, int right, const char* op){
    if (memStack.getType(left)->equals(memStack.getType(right)) || (isNumberType(memStack.getType(left)) && isNumberType(memStack.getType(right))) ) {
        RegCode r1 = memStack.load(left);
        RegCode r2 = memStack.load(right);
        gc << '\t' << r1 << " = " << r1 << " " << op << " " << r2 <<
              "; # Operation with id " << left << " and id " << right << "\n";

        gc.flush();
        memStack.release(right);

        return memStack.get(r1).id;
    } else {
        logError(std::string("Tipos diferentes: '") +
                         memStack.getType(left)->toString() + "' y '" + memStack.getType(right)->toString() + "'");
        return -1;
    }
}

int ne() {
    return ec++;
}

void logError(std::string str) {
    yyerror((char *) str.c_str());
}

static void bp() {
    static int p = 0;

    //gc << "\tRR3 = " << p++ << ";\n";
    gc << "\tGT( -1 );\n";
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

        if(v) for(auto& param : *v) {
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


int callFunction(char* funcName, int paramId, int returnLabel){


    if(isASystemFunction(funcName)) {
        return callSystemFunction(funcName, paramId, returnLabel);
    }

    FunctionNode *nodo = scope->getFunction(funcName);
    if(!nodo) {
        logError("Function " + std::string(funcName) + " don't exist");
        return -1;
    }

    if(paramId != -1) {
        MemManager::StackElement& param = memStack.get(paramId);
        RegCode reg = memStack.getFromRegisters(paramId);
        if(reg != RegCode::INVALID) {
            int newId = memStack.addToStack(param.type, "Parameters");
            memStack.assign(newId, reg);
            memStack.release(paramId);
        }

        gc << "\tR6 = R7 + " << nodo->paramterSize() << "; # Update R6 \n";
    }else{
        PrimitiveType p(INT); //Little tweak
        gc << "\tR6 = R7; # Update R6 \n";

    }

    bp();

    gc << "\tGT( " << nodo->getLabel() << " ); # Call " << funcName << "\n";
    gc << "L " << returnLabel << ": # Return Label\n";

    bp();

    if(paramId != -1) memStack.pop();
    memStack.pop();

    memStack.loadRegisters();

    gc << "\tR7 = R6 - " << nodo->getType()->size()  + memStack.currentStackSize()  <<  "; # Update R7 \n";

    bp();

    gc.flush();

    

    if(nodo->getType()->getType() == VOID) return -1;
    return memStack.addToStackWithoutChangingR7(nodo->getType(), std::string("returned by ") + funcName);
}

int callSystemFunction(std::string name, int id, int returnLabel) {
    if(std::string(name) == "print") {
        memStack.block(R0);
        memStack.block(R1);
        memStack.block(R2);
        RegCode reg = memStack.load(id);
        gc << "\tR2 = " << reg << "; # Loading print argument\n";

        if(memStack.typeOf(id) == CHAR)
            gc << "\tR1 = 0x11FF8; # Address of print char format\n";
        else
            gc << "\tR1 = 0x11FFC; # Address of print int format\n";

        gc << "\tR0 = "<< returnLabel << "; # Return Address\n";
        gc << "\tGT(putf_); # Call print\n";
        gc << "L " << returnLabel << ": # Return Label\n";
        memStack.unBlock(R0);
        memStack.unBlock(R1);
        memStack.unBlock(R2);
        return -1;
    }else if(std::string(name) == "exit") {
        gc << "\tR0 = 0;\n";
        gc << "\tGT( -2 );\n";
    }
    return -1;
}

void yyerror(const char *str) {
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
          "\tR6 = 0x12000;\n";

    std::string printIntCode("%d");
    memStack.addToStackWithoutChangingR7(new PrimitiveType(STRING, 4));
    std::string printCharCode("%c");
    memStack.addToStackWithoutChangingR7(new PrimitiveType(STRING, 4));

    gc << "STAT(0)\n";
    gc << "\tSTR( 0x11FFC, \"" << printIntCode << "\");\n";
    gc << "\tSTR( 0x11FF8, \"" << printCharCode << "\");\n";
    gc << "CODE(0)\n";

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

    gc << "\t" << reg << " = '";
    if(c == '\n') gc  << "\\n'; \n";
    else if(c == '\t') gc  << "\\t'; \n";
    else gc << std::string(1,c) << "'; \n";

    return id;
}

int generateReturn(int expId) {


    PrimitiveType tInt(INT);
    RegCode reg = memStack.getFreeRegister(&tInt); //Register for label

    memStack.block(reg);

    gc << "\t" << reg << " = I( R6 ); # Load return label \n";

    memStack.saveReturn(expId);


    gc << "\tGT( " << reg << " ); # Return \n";

    memStack.unBlock(reg);

    return 0;
}

void functionEnd(int endLabel) {
    PrimitiveType tInt(INT);
    RegCode reg = memStack.getFreeRegister(&tInt);
    gc << "\t" << reg << " = I( R6 ); # Load return label \n";
    gc << "\tGT( " << reg << " ); # Return \n";

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
        memStack.assign((int) (memStack.offsetOf(expList, expListInGlobal) + memStack.getType(expList)->size()), expListInGlobal,
                        (int) memStack.offsetOf(exp, expInGlobal), expInGlobal, memStack.getType(exp));

    }

    memStack.get(expList).type = memStack.getType(expList)->add( memStack.getType(exp) );
    memStack.release(exp);

    return expList;
}

bool isASystemFunction(std::string name) {
    return name == "print" || name == "getchar" || name == "exit";
}

void forInst(std::string variable, ValoresRango range, int loopLabel, int exitLabel) {
    int varId;
    if(!scope->existsVariable(variable)) {
        varId = memStack.addToStack(range.type ,variable+" loop iterator");
        scope->defineVariable(variable, new VariableNode(range.type, varId));
    }else{
        varId = scope->getVariable(variable)->getId();
    }

    memStack.assign(varId, range.inicio);

    int jumpUpdate = ne();
    gc << "\tGT( " << jumpUpdate << " ); # dont update iterator the first time\n";

    gc << "L " << loopLabel << ": # for loop tag\n";
    RegCode stepReg = memStack.load(range.paso);
    RegCode varReg = memStack.load(varId);
    gc << '\t' << varReg << " = " << varReg << " + " << stepReg << "; # Update for range\n";
    memStack.release(stepReg);
    memStack.assign(varId, varReg);

    gc << "L " << jumpUpdate << ": # for condition label \n";

    RegCode cond = memStack.getFreeRegister(range.type);
    RegCode finalReg = memStack.load(range.fin);
    RegCode initReg = memStack.load(range.inicio);
    varReg = memStack.load(varId); //Reload just in case
    gc << '\t' << cond << " = " << varReg << " >= " << finalReg << "; # Check for end\n";
    gc << "\tIF( " << cond << " ) GT( " << exitLabel << " ); # Exit for range\n";

    gc << '\t' << cond << " = " << varReg << " < " << initReg << "; # Check for init\n";
    gc << "\tIF( " << cond << " ) GT( " << exitLabel << " ); # Exit for range\n";

    memStack.release(cond);
    memStack.release(finalReg);
    memStack.release(initReg);
    memStack.release(varReg);

}


