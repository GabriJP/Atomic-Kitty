#include "Scope.h"

const char *Scope::VAR_PREFIX = "dato_";
const char *Scope::FUNC_PREFIX = "func_";

Scope::Scope() {
    this->parent = NULL;
}

Scope::Scope(Scope *scope, std::string nombre) {
    this->parent = scope;
    std::vector<ParameterNode *> *args = ((FunctionNode *) scope->getSymbol(
            std::string("func_") + nombre))->getParameters();
    for (std::vector<ParameterNode *>::iterator i = args->begin(); i != args->end(); i++) {
        defineSymbol("dato_" + (*i)->getName(), new VariableNode((*i)->getType()));
    }
}

Scope::Scope(Scope *scope) {
    this->parent = scope;
}

Scope *Scope::getParent() {
    return this->parent;
}

bool Scope::haveSymbol(std::string symbol) {
    return symbolTable.find(symbol) != symbolTable.end();
}

bool Scope::haveVariable(std::string name) {
    return haveSymbol(VAR_PREFIX + name);
}

bool Scope::existsVariable(std::string name) {
    return existsSymbol(VAR_PREFIX + name);
}

bool Scope::existsFunction(std::string name) {
    return existsSymbol(FUNC_PREFIX + name);
}

bool Scope::existsSymbol(std::string symbol) {
    return symbolTable.find(symbol) != symbolTable.end() || (this->parent != NULL && parent->existsSymbol(symbol));
}

void Scope::defineSymbol(std::string name, Node *node) {
    std::cout << name << " " << node->toString() << "\n";
    symbolTable.insert(std::make_pair(name, node));
}

void Scope::defineFunction(std::string name, FunctionNode *node) {
    defineSymbol(FUNC_PREFIX + name, node);
}

void Scope::defineVariable(std::string name, VariableNode *node) {
    defineSymbol(VAR_PREFIX + name, node);
}

Node *Scope::getSymbol(std::string symbol) {
    SymbolTable::iterator it = symbolTable.find(symbol);
    if (it != symbolTable.end()) return it->second;
    else if (parent) return parent->getSymbol(symbol);
    else return NULL;
}

VariableNode *Scope::getVariable(std::string symbol) {
    return (VariableNode *) getSymbol(VAR_PREFIX + symbol);
}

FunctionNode *Scope::getFunction(std::string symbol) {
    return (FunctionNode *) getSymbol(FUNC_PREFIX + symbol);
}

bool Scope::isEmpty() {
    return symbolTable.empty();
}

Scope::~Scope() {
    //for(auto& node : symbolTable) delete node.second;
    //for(SymbolTable::iterator i = symbolTable.begin(); i != symbolTable.end(); i++) delete i->second;
}

string ParameterNode::getName() {
    return name;
}

string FunctionNode::toString() {
    return "funcion";
}
