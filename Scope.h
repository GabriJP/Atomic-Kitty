#pragma once

#include <map>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include "Type.h"

enum Category {
    VARIABLE, FUNCTION, PARAMETER
};

class Node {
public:

    virtual Category getCategory() = 0;

    virtual std::string toString() = 0;

    virtual Type *getType() = 0;
};

class VariableNode : public Node {
private:
    Type *type;
public:
    explicit VariableNode(Type *type) : type(type) {}

    Category getCategory() override {
        return VARIABLE;
    };

    std::string toString() override { return type->toString(); };

    Type *getType() { return type; };
};

class ParameterNode : public VariableNode {
private:
    std::string name;
public:

    Category getCategory() override {
        return PARAMETER;
    };

    ParameterNode(Type *t, const std::string &name) : VariableNode(t), name(std::move(name)) {}

    string getName();
};

class FunctionNode : public Node {
    std::vector<ParameterNode *> *parameters;
    Type *returned;

public:
    FunctionNode(Type *returned, std::vector<ParameterNode *> *v) : returned(returned), parameters(v) {}

    explicit FunctionNode(Type *returned) : returned(returned), parameters(new std::vector<ParameterNode *>) {}

    Category getCategory() override {
        return FUNCTION;
    };

    std::vector<ParameterNode *> *getParameters() {
        return parameters;
    }

    Type *getType() { return returned; };

    string toString() override ;
};


typedef std::map<std::string, Node *> SymbolTable;

class Scope {

    SymbolTable symbolTable;
    Scope *parent;
    const static char *VAR_PREFIX;
    const static char *FUNC_PREFIX;

public:
    Scope(Scope *scope, std::string name);

    explicit Scope(Scope *scope);

    Scope();

    Scope *getParent();

    bool haveSymbol(std::string symbol);

    bool haveVariable(std::string symbol);

    bool existsFunction(std::string function);

    bool existsVariable(std::string function);

    bool existsSymbol(std::string symbol);

    Node *getSymbol(std::string symbol);

    VariableNode *getVariable(std::string symbol);

    FunctionNode *getFunction(std::string symbol);

    void defineSymbol(std::string symbol, Node *node);

    void defineFunction(std::string symbol, FunctionNode *node);

    void defineVariable(std::string symbol, VariableNode *node);

    bool isEmpty();

    ~Scope();
};
