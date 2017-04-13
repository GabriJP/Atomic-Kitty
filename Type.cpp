#include "Type.h"

TupleType* addTo(Type* t1, Type* t2) {
	if(t2->isTuple()) {
		((TupleType*)t2)->types.push_back(t1);
		return (TupleType*)t2;
	}else{
		TupleType* tuple = new TupleType;
		tuple->types.push_back(t1);
		tuple->types.push_back(t2);
		return tuple;
	}
}