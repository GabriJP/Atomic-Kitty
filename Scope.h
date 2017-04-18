#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Type.h"

enum Category{VARIABLE, FUNCTION, PARAMETER};

class Node{
public:

	Node(){};
	Category virtual getCategory() = 0;
	virtual std::string toString() { return ""; };
	virtual Type* getType() { return NULL; };
};

class VariableNode : public Node{
	Type* type;
public:
	VariableNode(Type* t) : type(t) {}
	virtual Category getCategory() {
		return VARIABLE;
	};
	virtual std::string toString() {return type->toString();};
	Type* getType() { return type; };
};

class ParameterNode : public VariableNode{
public:
	std::string name;
	Category getCategory() {
		return PARAMETER;
	};
	ParameterNode(Type* t, std::string name) : VariableNode(t), name(name) {}
};

class FunctionNode : public Node{
	std::vector<ParameterNode*> *parameters;
	Type* returned;

public:
	FunctionNode(std::vector<ParameterNode*> *v) :  parameters(v) {}

	Category getCategory() {
		return FUNCTION;
	};
	std::vector<ParameterNode*>* getParameters() {
		return parameters;
	}
};



typedef std::map<std::string, Node*> SymbolTable; 

class Scope{

	SymbolTable symbolTable;
	Scope *parent;

public:
	Scope(Scope *scope, std::string name);
	Scope(Scope *scope);
	Scope();

	Scope* getParent();
	bool haveSymbol(std::string symbol);
    	bool existsSymbol(std::string symbol);
	Node* getSymbol(std::string symbol);
	void defineSymbol(std::string symbol, Node *node);
	bool isEmpty();

	~Scope();
};
