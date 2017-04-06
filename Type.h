
class Type{

};

class PrimitiveType : public Type{
	unsigned id;
};

class TupleType : public Type{
	Type *types;
	std::size_t size;
};