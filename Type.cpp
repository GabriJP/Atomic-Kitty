#include "Type.h"

using namespace std;

/*
 *
 * TYPE
 *
 * */
Type::Type(int id) : id(id) {}

int Type::getId() {
    return id;
}


/*
 *
 * TUPLETYPE
 *
 * */
TupleType::TupleType(int id) : Type(id) {}

bool TupleType::isTuple() {
    return true;
}

string TupleType::toString() {
    std::string str = "(";
    //for(auto& type : types)
    for (auto &type : types)
        str += type->toString() + ",";
    return str + ')';
}

Type *TupleType::getSubType(int pos) {
    return types[types.size() - pos - 1];
}


TupleType *TupleType::add(Type *other) {
    types.push_back(other);
    return this;
}

bool TupleType::equals(Type *type) {
    if (!type->isTuple()) return false;
    auto *other = (TupleType *) type;
    if (other->types.size() != types.size()) return false;
    for (int i = 0; i < types.size(); i++)
        if (!types[i]->equals(other->types[i])) return false;
    return true;
}

/*
 *
 * PRIMITIVETYPE
 *
 * */
template<typename T>
std::string numberToString(T Number) {
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

PrimitiveType::PrimitiveType(int id) : Type(id) {}

string PrimitiveType::toString() {
    return numberToString(id);
}

TupleType *PrimitiveType::add(Type *other) {
    auto *tuple = new TupleType(id);
    tuple->add(this);
    tuple->add(other);
    return tuple;
}

bool PrimitiveType::equals(Type *type) {
    return !type->isTuple() && ((PrimitiveType *) type)->id == id;
}

bool PrimitiveType::isTuple() {
    return false;
}
