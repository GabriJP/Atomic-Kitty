#pragma once

#include <map>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include "Type.h"

class MemManager;
class Type;

enum Category {
    VARIABLE, FUNCTION, PARAMETER
};

using namespace std;

class Node {
public:

    virtual Category getCategory() = 0;

    virtual std::string toString() = 0;

    virtual Type *getType() = 0;
};

class VariableNode : public Node {
protected:
    Type *type;
    int id;
public:
    explicit VariableNode(Type* type, int id);

    Category getCategory();

    std::string toString() override;

    Type *getType() override;

    int getId();
};

class ParameterNode : public VariableNode {
private:
    std::string name;
public:

    Category getCategory() override;

    ParameterNode(Type *t, const std::string &name, int id = 0);

    std::string getName();

    void setId(int id);
};

class FunctionNode : public Node {
    std::vector<ParameterNode *> *parameters;
    Type *returned;
    int label;
    //int returnId;

public:
    FunctionNode(int label, Type *returned, std::vector<ParameterNode *> *v);

    explicit FunctionNode(Type *returned);

    Category getCategory() override;

    std::vector<ParameterNode *> *getParameters();

    std::size_t paramterSize();

    Type *getType();

    int getLabel();

    string toString() override;
};


typedef std::map<std::string, Node *> SymbolTable;

class Scope {

    SymbolTable symbolTable;
    Scope *parent;
    const static char *VAR_PREFIX;
    const static char *FUNC_PREFIX;

public:
    explicit Scope(Scope *scope, std::string name);

    explicit Scope(Scope *scope = nullptr);

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
