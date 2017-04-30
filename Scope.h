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
	FunctionNode(Type* returned) :  returned(returned), parameters(new std::vector<ParameterNode*>) {}
	FunctionNode(Type* returned, std::vector<ParameterNode*> *v) :  returned(returned), parameters(v) {}

	Category getCategory() {
		return FUNCTION;
	};
	std::vector<ParameterNode*>* getParameters() {
		return parameters;
	}
	Type* getType() { return returned; };
};



typedef std::map<std::string, Node*> SymbolTable; 

class Scope{

	SymbolTable symbolTable;
	Scope *parent;
	const static char* VAR_PREFIX;
	const static char* FUNC_PREFIX;

public:
	Scope(Scope *scope, std::string name);
	Scope(Scope *scope);
	Scope();

	Scope* getParent();

	bool haveSymbol(std::string symbol);
	bool haveVariable(std::string symbol);

	bool existsFunction(std::string function);
	bool existsVariable(std::string function);
    	bool existsSymbol(std::string symbol);

	Node* getSymbol(std::string symbol);
	VariableNode* getVariable(std::string symbol);
	FunctionNode* getFunction(std::string symbol);

	void defineSymbol(std::string symbol, Node *node);
	void defineFunction(std::string symbol, FunctionNode *node);
	void defineVariable(std::string symbol, VariableNode *node);
	bool isEmpty();

	~Scope();
};
