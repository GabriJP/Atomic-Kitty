#include "Scope.h"

const char *Scope::VAR_PREFIX = "dato_";
const char *Scope::FUNC_PREFIX = "func_";

Scope::Scope(MemManager *memManager, Scope *scope, std::string nombre) : parent(scope), memManager(memManager) {
    Scope(memManager, scope);
    std::vector<ParameterNode *> *args = ((FunctionNode *) scope->getSymbol(
            std::string("func_") + nombre))->getParameters();
    for (auto parameter : *args) {
        defineSymbol("dato_" + parameter->getName(), new VariableNode(parameter->getType()));
    }
}

Scope::Scope(MemManager *memManager, Scope *scope) : parent(scope), memManager(memManager) {
    memManager->entraBloque();
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
    for (auto dato : symbolTable){
        memManager->libera(dato.second->getType()->getId());
        delete dato.second->getType();
        delete dato.second;
    }
    memManager->saleBloque();
}

string ParameterNode::getName() {
    return name;
}

string FunctionNode::toString() {
    return "funcion";
}

VariableNode::VariableNode(Type *type) : type(type) {}

Category VariableNode::getCategory() {
    return VARIABLE;
}

string VariableNode::toString() {
    return type->toString();
}

Type *VariableNode::getType() {
    return type;
}

Category ParameterNode::getCategory() {
    return PARAMETER;
}

ParameterNode::ParameterNode(Type *t, const std::string &name) : VariableNode(t), name(std::move(name)) {}

FunctionNode::FunctionNode(int label, Type *returned, std::vector<ParameterNode *> *v) : label(label),
                                                                                         returned(returned),
                                                                                         parameters(v) {}

FunctionNode::FunctionNode(Type *returned) : returned(returned), parameters(new std::vector<ParameterNode *>) {}

Category FunctionNode::getCategory() {
    return FUNCTION;
}

vector<ParameterNode *> *FunctionNode::getParameters() {
    return parameters;
}

Type *FunctionNode::getType() {
    return returned;
}

int FunctionNode::getLabel() {
    return label;
}
