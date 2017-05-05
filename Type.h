#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class TupleType;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"

class Type {
protected:
    int id;
public:
    explicit Type(int id);

    ~Type() = default;

    virtual int getId();

    virtual bool isTuple() = 0;

    virtual TupleType *add(Type *other) = 0;

    virtual int getType() = 0;

    virtual string toString() = 0;

    virtual bool equals(Type *type) = 0;
};

#pragma clang diagnostic pop


class TupleType : public Type {
private:
    std::vector<Type *> types;
public:
    explicit TupleType(int id);

    bool isTuple() override;

    Type *getSubType(int pos);

    TupleType *add(Type *other) override;

    int getType() override;

    string toString() override;

    bool equals(Type *type) override;
};

class PrimitiveType : public Type {
private:
    int type;
public:
    explicit PrimitiveType(int id, int type);

    bool isTuple() override;

    TupleType *add(Type *other) override;

    int getType() override;

    string toString() override;

    bool equals(Type *type) override;

};
