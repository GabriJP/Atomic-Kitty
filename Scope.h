#include <map>
#include <vector>
#include <string>
#include "Type.h"

enum Category{VARIABLE, FUNCTION, PARAMETER};

class Node{
public:
	std::string value;

	Node(){};
	Category virtual getCategory() = 0;
};

class VariableNode : public Node{
	std::string value;
	Type type;
public:
	Category getCategory() {
		return VARIABLE;
	};
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
