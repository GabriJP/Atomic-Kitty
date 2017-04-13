#include "Scope.h"

Scope::Scope(){
	this->parent = NULL;
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

Scope::~Scope(){
	//for(auto& node : symbolTable) delete node.second;
	for(SymbolTable::iterator i = symbolTable.begin(); i != symbolTable.end(); i++) delete i->second;
};
