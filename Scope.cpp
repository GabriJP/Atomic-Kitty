#include "Scope.h"

Scope::Scope() : parent(NULL) {}
Scope::Scope(Scope & scope) : parent(&scope) {}

bool Scope::haveSymbol(std::string symbol){
	return symbolTable.find(symbol) != symbolTable.end();
}

void Scope::defineSymbol(std::string type, Node *node){
	symbolTable.insert(std::make_pair(type, node));
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
