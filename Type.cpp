#include "Type.h"
//#include "miint.tab.h"

using namespace std;

/*
 *
 * TYPE
 *
 * */
Type::Type(yytokentype id) : id(id) {}

int Type::getId() {
    return id;
}

std::size_t Type::size() {
    float typeSize = realSize();
    return std::ceil( typeSize / 4.f ) * 4;
}


/*
 *
 * TUPLETYPE
 *
 * */
TupleType::TupleType(yytokentype id) : Type(id) {}

bool TupleType::isTuple() {
    return true;
}

std::string TupleType::toString() {
    std::string str = "(";
    for (auto &type : types)
        str += type->toString() + ',';

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

yytokentype TupleType::getType() {
    return TUPLE;
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

PrimitiveType::PrimitiveType(yytokentype type) : Type(type), type(type) {

    switch (id) {
        case INT:
            _size = 4;
            break;
        case LONG:
            _size = 8;
            break;
        case FLOAT:
            _size = 4;
            break;
        case DOUBLE:
            _size = 8;
            break;
        case CHAR:
            _size = 1;
            break;
        case BOOL:
            _size = 1;
            break;
        case STRING:
            _size = 1;
            break;
        case VOID:
            _size = 0;
            break;
        default:
            fprintf(stderr, "Tipo no reconocido: %d\n", type);
            //exit(-1);
    }
}


std::string PrimitiveType::toString() {
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

yytokentype PrimitiveType::getType() {
    return type;
}

std::size_t TupleType::realSize() {
    std::size_t size = 0;
    for(auto& type : types)
        size += type->size();

    return size;
}

std::size_t PrimitiveType::realSize() {
    return _size;
}

Type *TupleType::clone() {
    return new TupleType(*this);
}

int TupleType::length() {
    return types.size();
}

std::size_t TupleType::offsetOf(int pos) {
    std::size_t size = 0;
    //for(int i = 0; i < pos; i++)
    for(int i = types.size()-1; i > pos; i--)
        size += getSubType(i)->size();

    return size;
}

Type *PrimitiveType::clone() {
    return new PrimitiveType(*this);
}

std::ostream &operator<<(std::ostream &os, yytokentype const &yytoken) {

    os << [](yytokentype const &yytoken){
        switch(yytoken) {
            case yytokentype::VALOR_INT:
            case yytokentype::INT:
                return "INT";
            case yytokentype::VALOR_BOOL:
            case yytokentype::BOOL:
                return "BOOL";
            case yytokentype::VALOR_CHAR:
            case yytokentype::CHAR:
                return "CHAR";
            case yytokentype::VALOR_DOUBLE:
            case yytokentype::DOUBLE:
                return "DOUBLE";
            case yytokentype::VALOR_FLOAT:
            case yytokentype::FLOAT:
                return "FLOAT";
            case yytokentype::VALOR_LONG:
            case yytokentype::LONG:
                return "LONG";
            case yytokentype::VALOR_STRING:
            case yytokentype::STRING:
                return "STRING";
        }
        return "UNKNOWN";
    }(yytoken) << '(' << (int)yytoken << ')';
    return os;
}