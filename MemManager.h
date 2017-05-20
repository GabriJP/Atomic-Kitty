#pragma once

#include <deque>
#include <array>
#include <map>
#include <limits>
#include <fstream>
#include <exception>
//#include "miint.tab.h"
#include "Type.h"
//#include "Scope.h"

#ifndef YYTOKENTYPE
# define YYTOKENTYPE
enum yytokentype
{
  VALOR_FLOAT = 258,
  VALOR_DOUBLE = 259,
  VALOR_INT = 260,
  VALOR_BOOL = 261,
  ACCESO = 262,
  VALOR_LONG = 263,
  VALOR_CHAR = 264,
  VALOR_STRING = 265,
  IDENTIFICADOR = 266,
  FIN_DE_LINEA = 267,
  INT = 268,
  LONG = 269,
  FLOAT = 270,
  DOUBLE = 271,
  BOOL = 272,
  STRING = 273,
  VOID = 274,
  CHAR = 275,
  WHEN = 276,
  WHEN_CASE = 277,
  IF = 278,
  ELIF = 279,
  ELSE = 280,
  WHILE = 281,
  FOR = 282,
  NOTIS = 283,
  IS = 284,
  OR = 285,
  AND = 286,
  RANGE = 287,
  RETURN = 288,
  ABREBLOQUE = 289,
  CIERRABLOQUE = 290,
  IN = 291,
  NOTIN = 292,
  MAYORIGUAL = 293,
  MENORIGUAL = 294,
  MAYORQUE = 295,
  MENORQUE = 296,
  TUPLE = 297
};
#endif

extern std::ofstream gc;

enum RegCode {
    R0 = 0,
    R1 = 1,
    R2 = 2,
    R3 = 3,
    R4 = 4,
    R5 = 5,
    R6 = 6,
    R7 = 7,
    RR0 = 8,
    RR1 = 9,
    RR2 = 10,
    RR3 = 11,
    INVALID = 12,
};

class MemManager {
public:


    MemManager();

    int addToStack(Type* type, int id, std::string name="");
    int addToRegister(Type* type, int id);
    RegCode getFreeRegister(Type* type);
    int addToStack(Type* type, std::string name="") {
        return addToStack(type, getId(), name);
    };

    int addToStackWithoutChangingR7(Type* type, int id, std::string name = "");
    int addToStackWithoutChangingR7(Type* type, std::string name = "") {
        return addToStackWithoutChangingR7(type, getId(), name);
    };

    int addToRegister(Type* type) {
        return addToRegister(type, getId());
    };
    void release(int id);
    void releaseAllRegisters();

    void saveRegisters();
    void loadRegisters();

    RegCode getFromRegisters(int id);
    bool isInRegister(int id);

    void createFunction();

    void print();

    void enterBlock();
    void exitBlock();

    RegCode load(int id, int pos, int& newId);
    RegCode load(int id, int &newId);
    RegCode load(int id) {
        int n;
        return load(id, n);
    };

    void block(RegCode reg);
    void unBlock(RegCode reg);

    int saveInStack(int id);

    struct StackElement{
        int id;
        Type *type;
        std::string name;
        int blockDepth = -1; //Only working in registers
        bool blocked = false; //Register can't be used

        StackElement() : id(-1), type(nullptr), name(""){}
        StackElement(int id, Type* type) : id(id), type(type), name(""){}
        StackElement(int id, Type* type, std::string name) : id(id), type(type), name(name){}

    };

    StackElement& get(int id);
    StackElement& get(RegCode reg);
    yytokentype typeOf(int id);
    Type* getType(int id);

    void assign(int varId, int expId);
    void assign(int varId, RegCode expRegister);
    void assign(int varId, std::string value);

    void pop();

    std::string getInstruction(StackElement &element);
    std::string getInstruction(std::size_t offset, bool inGlobal, Type* type);

    size_t currentStackSize();

    void endFuntion();

    static std::map<RegCode, char *> regNames;

    void saveReturn(int i);

    void assign(std::size_t varOffset, bool  varInGlobal, std::size_t expOffset, bool  expInGlobal, Type* type);
    std::size_t offsetOf(int id, bool &offsetFromGlobal);
    static char letter(Type* type);
    std::string offsetToString(int offset, bool inGlobal);

private:

    std::size_t stackSize = 0;
    const int stackStart = 0x12000;

    std::deque<StackElement> localStack;
    std::deque<StackElement> globalStack;
    bool inFunction = false;

    const int NOT_USED = -1;
    std::array<StackElement, 6> registers32Bits;
    std::array<StackElement, 4> registers64Bits;

    std::deque<StackElement>& stack();

    template<typename T>
    bool haveFreeRegister(T &registers, int &id);
    template<typename T>
    int lastRegister(T &registers);
    template<typename T>
    RegCode addToRegister(T &registers, Type* type, int id);

    int id = 0;
    int getId();

    int currentDepth = 0;

    const static std::map<yytokentype, char> letterMap;

    std::array<bool, RegCode::RR3> savedRegisters;

    void assignTuple(int id, int expId);

};

std::ostream& operator<<(std::ostream& os, RegCode const& reg);