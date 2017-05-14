#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <fstream>
#include <stack>
#include "Type.h"
#include "Scope.h"
#include "structs.h"

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


//Variable globales
extern MemManager memStack;

extern Scope *scope;
extern std::ofstream gc;
extern int ec;
extern std::stack<int> returnLabels;
extern int fines;

void initQ();
void opera(int left, int right, const char *op);
void logError(std::string str);
int createFunction(char *nombre, Type *returnType, vector<ParameterNode *> *v);
bool isNumberType(Type *tipo);
int ne();
int callFunction(char* nombreFun, int tupleId);
int primitiveExp(yytokentype tipo);

template <typename T>
int primitiveExp(yytokentype tipo, T n) {
    int id = primitiveExp(tipo);
    RegCode reg = memStack.load(id);
    gc << "\t" << reg << " = " << std::to_string(n) << "; \n";
    return id;
}
;

int primitiveExp(yytokentype tipo, char c);

void yyerror(char *str);

int addNewVar(Type* type, char* name);