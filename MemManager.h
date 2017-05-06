#pragma once

#include "miint.tab.h"
#include "Scope.h"

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

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"

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

map<int, char *> regNames = {
        {R0,  "R0"},
        {R1,  "R1"},
        {R2,  "R2"},
        {R3,  "R3"},
        {R4,  "R4"},
        {R5,  "R5"},
        {R6,  "R6"},
        {R7,  "R7"},
        {RR0, "RR0"},
        {RR1, "RR1"},
        {RR2, "RR2"},
        {RR3, "RR3"},
};

class MemManager {
private:
    int idCounter = 0;

    int intCounter = 0;

    int floatCounter = 0;

    int stack = 0x12000;

    map<int, RegCode> intR;

    map<int, RegCode> floatR;

    map<int, int> memoria;

    map<int, yytokentype> values;

    int getId();

    RegCode getIntRegister();

    RegCode getFloatRegister();

    RegCode myLoad(int id, map<int, RegCode> mapa, int direccion, yytokentype tipo);

public:
    MemManager();

    ~MemManager();

    int creaFuncion();

    int creaVariableSimple(yytokentype tipo);

    int creaVariableSimpleCarga(yytokentype tipo);

    RegCode load(int id);

    void print();

    void libera(int id);

    void actualizaValor(int id, RegCode registro);
};

#pragma clang diagnostic pop

