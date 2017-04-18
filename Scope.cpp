#include "Scope.h"

Scope::Scope(){
	this->parent = NULL;
}

Scope::Scope(Scope *scope, std::string nombre) {
	this->parent = scope;
	std::vector<ParameterNode*> *args = ((FunctionNode*) scope->getSymbol(std::string("func_") + nombre))->getParameters();
	for(std::vector<ParameterNode*>::iterator i = args->begin(); i != args->end(); i++) {
		defineSymbol("dato_" + (*i)->name, new VariableNode((*i)->getType()));
	}
}

Scope::Scope(Scope *scope) {
	this->parent = scope;
}

Scope* Scope::getParent(){
	return this->parent;
}

bool Scope::haveSymbol(std::string symbol){
	return symbolTable.find(symbol) != symbolTable.end();
}

bool Scope::existsSymbol(std::string symbol){
	return symbolTable.find(symbol) != symbolTable.end() || (this->parent != NULL && parent->existsSymbol(symbol));
}

void Scope::defineSymbol(std::string name, Node *node){
	std::cout << name << " " << node->toString() << "\n";
	symbolTable.insert(std::make_pair(name, node));
}

Node* Scope::getSymbol(std::string symbol) {
	SymbolTable::iterator it = symbolTable.find(symbol);
	if(it != symbolTable.end()) return it->second;  
	else if(parent) return parent->getSymbol(symbol);
	else return NULL;
}

bool Scope::isEmpty(){
	return symbolTable.empty();
}

Scope::~Scope(){
	//for(auto& node : symbolTable) delete node.second;
	for(SymbolTable::iterator i = symbolTable.begin(); i != symbolTable.end(); i++) delete i->second;
}
