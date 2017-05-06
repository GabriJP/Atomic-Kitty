#pragma once

#include <map>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include "Type.h"
#include "MemManager.h"

class MemManager;

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
    explicit VariableNode(Type *type);

    Category getCategory() override;

    std::string toString() override;

    Type *getType() override;
};

class ParameterNode : public VariableNode {
private:
    std::string name;
public:

    Category getCategory() override;

    ParameterNode(Type *t, const std::string &name);

    string getName();
};

class FunctionNode : public Node {
    std::vector<ParameterNode *> *parameters;
    Type *returned;
    int label;

public:
    FunctionNode(int label, Type *returned, std::vector<ParameterNode *> *v);

    explicit FunctionNode(Type *returned);

    Category getCategory() override;

    std::vector<ParameterNode *> *getParameters();

    Type *getType();

    string toString() override;
};


typedef std::map<std::string, Node *> SymbolTable;

class Scope {

    SymbolTable symbolTable;
    Scope *parent;
    MemManager *memManager;
    const static char *VAR_PREFIX;
    const static char *FUNC_PREFIX;

public:
    Scope(MemManager *memManager, Scope *scope, std::string name);

    Scope(MemManager *memManager, Scope *scope);

    explicit Scope(MemManager *memManager);

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
