#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include "miint.tab.h"


class TupleType;

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
//#pragma ide diagnostic ignored "ClangTidyInspection"

class Type {
protected:
    yytokentype id;
public:
    Type(yytokentype id);

    ~Type() = default;

    virtual int getId();

    virtual bool isTuple() = 0;

    virtual TupleType *add(Type *other) = 0;

    virtual yytokentype getType() = 0;

    std::size_t size();
    virtual std::size_t realSize() = 0;

    virtual std::string toString() = 0;

    virtual bool equals(Type *type) = 0;

    virtual Type* clone() = 0;
};

#pragma clang diagnostic pop


class TupleType : public Type {
private:
    std::vector<Type *> types;
public:
    explicit TupleType(yytokentype id);

    bool isTuple() override;

    Type *getSubType(int pos);
    int length();
    std::size_t offsetOf(int pos);

    TupleType *add(Type *other) override;

    yytokentype getType() override;

    std::size_t realSize() override;

    std::string toString() override;

    bool equals(Type *type) override;


    Type* clone() override;

};


class PrimitiveType : public Type {
private:
    yytokentype type;
    size_t _size = 0;
public:
    PrimitiveType(yytokentype id);
    PrimitiveType(yytokentype id, std::size_t size);

    bool isTuple() override;

    TupleType *add(Type *other) override;

    yytokentype getType() override;

    std::size_t realSize() override;

    std::string toString() override;

    bool equals(Type *type) override;

    Type* clone() override;

};

std::ostream& operator<<(std::ostream& os, yytokentype const& yytoken);