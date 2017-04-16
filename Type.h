#pragma once

#include <vector>
#include <string>
#include <iostream>

struct TupleType;

struct Type{
	virtual std::string toString() = 0;
	virtual bool isTuple() = 0;
	virtual TupleType* add(Type* other) = 0;
};

struct TupleType : public Type{
	std::vector<Type*> types;
	std::string toString() override {
		std::string str = "(";
		for(auto& type : types) str += type->toString() + ",";
		return str+')';
	};
	TupleType* add(Type* other) {
		types.push_back(other);
		return this;
	}
	bool isTuple() {
		return true;
	};
	~TupleType(){
		for(auto& type : types) delete type;
	}
};

struct PrimitiveType : public Type{
	unsigned id;
	PrimitiveType(unsigned id) : id(id) {}
	std::string toString() override {
		return std::to_string(id);
	};
	TupleType* add(Type* other) {
		TupleType* tuple = new TupleType;
		tuple->types.push_back(this);
		tuple->types.push_back(other);
		return tuple;
	}
	bool isTuple() {
		return false;
	};
};


