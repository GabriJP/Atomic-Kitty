#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class TupleType;

class Type {
protected:
    int id;
public:
    explicit Type(int id);

    ~Type() = default;

    virtual int getId();

    virtual bool isTuple() = 0;

    virtual TupleType *add(Type *other) = 0;

    virtual string toString() = 0;

    virtual bool equals(Type *type) = 0;
};


class TupleType : public Type {
private:
    std::vector<Type *> types;
public:
    explicit TupleType(int id);

    bool isTuple() override;

    Type *getSubType(int pos);

    TupleType *add(Type *other) override;

    string toString() override;

    bool equals(Type *type) override;
};

class PrimitiveType : public Type {
public:
    explicit PrimitiveType(int id);

    bool isTuple() override;

    string toString() override;

    TupleType *add(Type *other) override;

    bool equals(Type *type) override;
};
