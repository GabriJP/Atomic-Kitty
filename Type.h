#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

template <typename T>
  std::string numberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }


struct TupleType;

struct Type{
	virtual std::string toString() = 0;
	virtual bool isTuple() = 0;
	virtual TupleType* add(Type* other) = 0;
	virtual bool equals(Type* type) {
		return false;
	}
};

struct TupleType : public Type{
	std::vector<Type*> types;
	std::string toString() {
		std::string str = "(";
		//for(auto& type : types) 
		for(std::vector<Type*>::iterator type = types.begin(); type != types.end(); type++)
			str += (*type)->toString() + ",";
		return str+')';
	};
	TupleType* add(Type* other) {
		types.push_back(other);
		return this;
	}
	bool isTuple() {
		return true;
	};
	bool equals(Type* type) {
		if(!type->isTuple()) return false;
		TupleType* other = (TupleType*)type;
		if(other->types.size() != types.size()) return false;
		for(int i = 0; i < types.size(); i++)
			if(!types[i]->equals(other->types[i])) return false;
		return true;
	}
	Type* getSubType(int pos) {
		return types[types.size() - pos - 1];
	}
	~TupleType(){
		//for(auto& type : types) 
		/*for(std::vector<Type*>::iterator type = types.begin(); type != types.end(); type++)
			delete *type;*/
	}
};

struct PrimitiveType : public Type{
	unsigned id;
	PrimitiveType(unsigned id) : id(id) {}
	std::string toString() {
		return numberToString(id);
	};
	TupleType* add(Type* other) {
		TupleType* tuple = new TupleType;
		tuple->types.push_back(this);
		tuple->types.push_back(other);
		return tuple;
	}
	bool equals(Type* type) {
		if(type->isTuple()) return false;
		return ((PrimitiveType*)type)->id == id;
	}
	bool isTuple() {
		return false;
	};
};


