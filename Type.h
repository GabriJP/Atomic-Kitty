#pragma once

#include <vector>
#include <string>
#include <iostream>


struct Type{
	virtual std::string toString() = 0;
	virtual bool isTuple() = 0;
};

struct PrimitiveType : public Type{
	unsigned id;
	PrimitiveType(unsigned id) : id(id) {}
	std::string toString() override {
		return std::to_string(id);
	};
	bool isTuple() {
		return false;
	};
};

struct TupleType : public Type{
	std::vector<Type*> types;
	std::string toString() override {
		std::string str = "(";
		for(auto& type : types) str += type->toString() + ",";
		return str+')';
	};
	bool isTuple() {
		return true;
	};
};

TupleType* addTo(Type* t1, Type* t2);