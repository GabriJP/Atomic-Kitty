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
	virtual std::string toString() {};
};

class VariableNode : public Node{
	Type* type;
public:
	VariableNode(Type* t) : type(t) {}
	Category getCategory() {
		return VARIABLE;
	};
	virtual std::string toString() {return type->toString();};
};

class ParameterNode : public VariableNode{
public:
	Category getCategory() {
		return PARAMETER;
	};
};

class FunctionNode : public Node{
	std::vector<ParameterNode> parameters;
public:
	Category getCategory() {
		return FUNCTION;
	};
};



typedef std::map<std::string, Node*> SymbolTable; 

class Scope{

	SymbolTable symbolTable;
	Scope *parent;

public:
	Scope(Scope *scope);
	Scope();

	Scope* getParent();
	bool haveSymbol(std::string symbol);
    bool existsSymbol(std::string symbol);
	Node* getSymbol(std::string symbol);
	void defineSymbol(std::string symbol, Node *node);

	~Scope();
};
