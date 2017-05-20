#include "MemManager.h"

const std::map<yytokentype, char> MemManager::letterMap = {
        {INT,    'I'},
        {LONG,   'J'},
        {FLOAT,  'F'},
        {DOUBLE, 'D'},
        {CHAR,   'U'},
        {TUPLE,  'I'}, //TODO: Implement
        {STRING,  'I'},
        {BOOL,   'U'},
};

int MemManager::getId() {
    return id++;
}

int MemManager::addToStack(Type *type, int id, std::string name) {

    gc << "\tR7 = R7 - " << type->size() << "; # Add to stack\n";

    return addToStackWithoutChangingR7(type, id, name);
}

int MemManager::addToStackWithoutChangingR7(Type *type, int id, std::string name) {
    stack().push_back({id, type->clone(), name});
    stackSize += type->size();

    gc.flush();

    return id;
}


int MemManager::addToRegister(Type *type, int id) {

    if(type->size() <= 4)
        addToRegister(registers32Bits, type, id);
    else if(type->size() == 8)
        addToRegister(registers64Bits, type, id);
    else
        addToStack(type, id);

    return id;
}


RegCode MemManager::getFreeRegister(Type *type) {
    if(type->size() <= 4)
        return addToRegister(registers32Bits, type, getId());
    else if(type->size() == 8)
        return addToRegister(registers64Bits, type, getId());

    return RegCode::INVALID;
}


void MemManager::release(int id) {
    for(auto& reg : registers32Bits) {
        if(reg.id == id) {
            reg.id = NOT_USED;
            reg.type = nullptr;
            return;
        }
    }
    for(auto& reg : registers64Bits) {
        if(reg.id == id) {
            reg.id = NOT_USED;
            reg.type = nullptr;
            return;
        }
    }
}

//TODO Improve
void MemManager::saveRegisters() {

    savedRegisters.fill(false);

    PrimitiveType p(INT);
    auto save = [this, &p](auto& reg, RegCode i) {
        if(reg.id !=  NOT_USED) {
            int id = addToStack(reg.type, reg.id, MemManager::regNames[RegCode(i)] + std::string(" saved"));
            assign(id, i);
            savedRegisters[i] = true;
        }
    };

    StackElement e{getId(), &p};
    for(int i = 0; i < registers32Bits.size(); i++) save(registers32Bits[i], RegCode(i));
    for(int i = 0; i < registers64Bits.size(); i++) save(registers64Bits[i], RegCode(i + (int)RR0));
    //save(e, R7);
    save(e, R6);

    gc.flush();

}

void MemManager::loadRegisters() {

    auto loadReg = [this](int i) {
        if(savedRegisters[i]){
            StackElement& loadedReg = stack().back();
            gc << "\t" << RegCode(i) << " = " <<  getInstruction(loadedReg) << "; # Loading register " << RegCode(i) << "\n";
            //gc << "\tR7 = R7 + " << loadedReg.type->size() << ";\n";
            if(i >= R0 && i < R6) {
                registers32Bits[i] = loadedReg;
            }else if(i >= RR0) {
                registers32Bits[i-RR0] = loadedReg;
            }
            //stack().pop_back();
        }
    };

    gc << "\tR6 = I(R6 + 8); # Loading register R6\n";
    //loadReg(R7);
    for(int i = RR3; i > R7; i--) loadReg(i);
    for(int i = R5; i >= R0; i--) loadReg(i);

    gc.flush();

}

RegCode MemManager::load(int id, int &newId) {
    newId = id;
    auto& element = get(id);

    if(element.type->isTuple()) return RegCode::INVALID;

    RegCode reg = getFromRegisters(id);
    if(reg != RegCode::INVALID) return reg;

    newId = getId();

    if(element.type->size() <= 4) reg = addToRegister(registers32Bits, element.type, newId);
    else if(element.type->size() == 8) reg = addToRegister(registers64Bits, element.type, newId);
    else return RegCode::INVALID;

    gc << '\t' << reg << " = " << getInstruction(element) << "; # Load id:" << id << " " << element.name << " from stack\n";
    gc.flush();

    return reg;

}

RegCode MemManager::load(int id, int pos, int &newId) {
    auto& element = get(id);

    if(!element.type->isTuple()) {
        throw new bad_alloc();
        return RegCode::INVALID;
    }

    TupleType* tuple = (TupleType*)element.type;
    bool isInGlobal;
    std::size_t offset = offsetOf(id, isInGlobal) + tuple->offsetOf(pos);
    Type* subType = tuple->getSubType(pos);

    if(tuple->getSubType(pos)->isTuple()) {
        newId = addToStack(subType, "sub-element "+std::to_string(pos)+" of tuple "+element.name);

        bool SubElemIsInGlobal;
        std::size_t SubElemOffset = offsetOf(id, isInGlobal);
        assign(offset, isInGlobal, SubElemOffset, SubElemIsInGlobal, subType);

        gc.flush();
        return RegCode::INVALID;
    }else{
        newId = addToRegister(subType);
        RegCode reg = getFromRegisters(newId);
        gc << '\t' << reg << " = " << getInstruction(offset, isInGlobal, subType) <<
            "; # Load id:" << newId << " sub-element "+std::to_string(pos)+" of tuple "+element.name + "\n";
        gc.flush();

        return reg;
    }


}

void MemManager::print() {

    gc.flush();

    std::cout << "STACK INFO-------------------\n";

    if(inFunction)std::cout << "Parsing function code\n";
    else std::cout << "Parsing global code\n";

    std::cout << "REG INFO:\n";
    for(int i = 0; i < registers32Bits.size(); i++)
        if(registers32Bits[i].id != NOT_USED)
            std::cout << "\t" << (RegCode)i << ":" << registers32Bits[i].id << " -> " << registers32Bits[i].type->toString() << "\n";
        else
            std::cout << "\t" << (RegCode)i << ": Not used\n";

    for(int i = 0; i < registers64Bits.size(); i++)
        if(registers64Bits[i].id != NOT_USED)
            std::cout << "\t" << (RegCode) (i + (int)RR0) << ":" << registers32Bits[i].id << " -> " << registers32Bits[i].type->toString() << "\n";
        else
            std::cout << "\t" << (RegCode) (i + (int)RR0) << ": Not used\n";

    std::cout << "LOCAL STACK:\n";
    for(auto&item : localStack) std::cout << "\t" << item.id << " " << item.name << ":" << item.type->toString() << "\n";

    std::cout << "GLOBAL STACK:\n";
    for(auto&item : globalStack) std::cout << "\t" << item.id << " " << item.name << ":" << item.type->toString() << "\n";

    std::cout << "STACK INFO END---------------\n";
}


template<typename T>
RegCode MemManager::addToRegister(T &registers, Type* type, int id) {
    int reg;

    if(haveFreeRegister(registers, reg)){
        registers[reg] = StackElement{id, type->clone()};
    }else{
        reg = lastRegister(registers);
        addToStack(registers[reg].type, registers[reg].id);
        registers[reg] = {id, type->clone()};
    }

    gc.flush();

    registers[reg].blockDepth = currentDepth;
    return (RegCode)reg;

}


template<typename T>
bool MemManager::haveFreeRegister(T &registers, int &id) {
    for(int i = 0; i < registers.size(); i++) {
        if(registers[i].id == NOT_USED && !registers[i].blocked) {
            id = i;
            return true;
        }
    }
    return false;
}

template<typename T>
int MemManager::lastRegister(T &registers) {
    int minId = std::numeric_limits<int>::max();
    int regNumber = 0;
    for(int i = 0; i < registers.size(); i++)
        if(minId > registers[i].id && !registers[i].blocked) {
            minId = registers[i].id;
            regNumber = i;
        }

    return regNumber;
}

std::deque<MemManager::StackElement> &MemManager::stack() {
    if(inFunction) return localStack;
    else return globalStack;
}

std::map<RegCode, char *> MemManager::regNames = {
        {R0,  "R0"},
        {R1,  "R1"},
        {R2,  "R2"},
        {R3,  "R3"},
        {R4,  "R4"},
        {R5,  "R5"},
        {R6,  "R6"},
        {R7,  "R7"},
        {RR0, "RR0"},
        {RR1, "RR1"},
        {RR2, "RR2"},
        {RR3, "RR3"},
};

std::ostream &operator<<(std::ostream &os, RegCode const &reg) {

    os << MemManager::regNames[reg];
    return os;
}

MemManager::StackElement &MemManager::get(int id) {

    for(auto& elem : registers32Bits) if(id==elem.id) return elem;
    for(auto& elem : registers64Bits) if(id==elem.id) return elem;

    for(auto& elem : localStack) if(id==elem.id) return elem;
    for(auto& elem : globalStack) if(id==elem.id) return elem;

    throw new std::bad_alloc();

}

yytokentype MemManager::typeOf(int id) {
    return getType(id)->getType();
}

Type *MemManager::getType(int id) {
    return get(id).type;
}

std::size_t MemManager::offsetOf(int id, bool &offsetFromGlobal) {
    if(inFunction) {
        std::size_t offset = 0;
        for(auto& item : localStack) {
            if(item.id == id) {
                offsetFromGlobal = false;
                return offset;
            }
            offset += item.type->size();
        }
    }

    offsetFromGlobal = true;
    std::size_t offset = 0;
    for(auto& item : globalStack) {
        if(item.id == id) return offset;
        offset += item.type->size();
    }

    throw new bad_alloc();

    return 0;

}

char MemManager::letter(Type *type) {
    return letterMap.find(type->getType())->second;
}

void MemManager::assign(int varId, int expId) {
    if(getType(expId)->isTuple()) return assignTuple(varId, expId);

    int expLoadedId;
    StackElement& var = get(varId);

    RegCode expRegister = load(expId, expLoadedId);
    StackElement exp = get(expLoadedId);

    if(!exp.type->equals(var.type)) {
        std::cout << "Types don't match in assign";
        exit(-1);
    }

    gc << '\t' << getInstruction(var) << " = " << expRegister
       << "; # Asign value id:" << varId << " " << var.name << " = id:"
       << expId << " " << exp.name <<'\n';

    release(expLoadedId);
    if(expId != expLoadedId) release(expId);

    gc.flush();

}

void MemManager::assign(int varId, RegCode expRegister) {

    StackElement& var = get(varId);
    gc << '\t' << getInstruction(var) << " = " << expRegister << "; # Asign value id:" << varId << " " << var.name <<'\n';
    gc.flush();

}


void MemManager::assign(int varId, std::string value) {
    StackElement& var = get(varId);
    gc << '\t' << getInstruction(var) << " = " << value << "; # Asign id:" << varId << " " << var.name <<'\n';
    gc.flush();
}


std::string MemManager::getInstruction(MemManager::StackElement &var) {
    std::string out(1,letter(var.type));
    bool inGlobal;
    std::size_t offset = offsetOf(var.id, inGlobal);

    return getInstruction(offset, inGlobal, var.type);
}

std::string MemManager::getInstruction(std::size_t offset, bool inGlobal, Type *type) {
    std::string out(1,letter(type));

    if(inGlobal) {

        stringstream ss;
        ss << std::hex << stackStart - offset - type->size();
        string str = ss.str();

        return out + "(0x" + str + ")";
    }else
        return out + "(R6 - "+ std::to_string(offset) + ")";
}


MemManager::MemManager() {
    releaseAllRegisters();
}

size_t MemManager::currentStackSize() {
    size_t size = 0;
    for(auto& elem : stack()) size += elem.type->size();

    return size;
}

void MemManager::createFunction() {
    inFunction = true;
}

void MemManager::releaseAllRegisters() {
    registers32Bits.fill(StackElement{NOT_USED, nullptr});
    registers64Bits.fill(StackElement{NOT_USED, nullptr});
}

void MemManager::endFuntion() {
    inFunction = false;
    releaseAllRegisters();
    localStack.clear();
}

void MemManager::pop() {
    stack().pop_back();
}

RegCode MemManager::getFromRegisters(int id) {
    for(int i = 0; i < registers32Bits.size(); i++)
        if(registers32Bits[i].id == id)
            return (RegCode) i;

    for(int i = 0; i < registers64Bits.size(); i++)
        if(registers64Bits[i].id == id)
            return (RegCode) (i + (int)RR0);

    return RegCode::INVALID;
}

bool MemManager::isInRegister(int id) {
    return getFromRegisters(id) != RegCode::INVALID;
}

void MemManager::assignTuple(int varId, int expId) {

    StackElement& var = get(varId);
    StackElement& exp = get(expId);

    if(!exp.type->equals(var.type)) {
        std::cout << "Types don't match in assign";
        exit(-1);
    }

    TupleType* types = (TupleType*)exp.type;
    int typeLength = types->length();

    bool varInGlobal = false;
    std::size_t varOffset = offsetOf(var.id, varInGlobal);

    bool expInGlobal = false;
    std::size_t expOffset = offsetOf(exp.id, expInGlobal);

    assign(varOffset, varInGlobal, expOffset, expInGlobal, exp.type);

}

void MemManager::assign(std::size_t varOffset, bool  varInGlobal, std::size_t expOffset, bool  expInGlobal, Type* type) {

    if(type->isTuple()) {
        TupleType* types = (TupleType*)type;
        int typeLength = types->length();

        for(int i = 0; i < typeLength; i++) {
        //for(int i = typeLength-1; i >= 0; i--) {
            Type* subType = types->getSubType(i);
            std::size_t offset = types->offsetOf(i);
            assign((int)varOffset + (int)offset, varInGlobal, (int)expOffset + (int)offset, expInGlobal, subType);

        }
    }else{
        RegCode reg = getFreeRegister(type);
        gc << "\t" << reg << " = " << letter(type) <<
           offsetToString(expOffset, expInGlobal) <<
           "; # Loading " << type->getType() << "\n";

        gc << "\t" << letter(type) << offsetToString(varOffset, varInGlobal) <<
           " = " << reg << "; # Saving it \n";

    }


}



std::string MemManager::offsetToString(int offset, bool inGlobal) {
    if(inGlobal) {

        stringstream ss;
        ss << std::hex << stackStart - offset - 4;
        string str = ss.str();

        return "(0x" + str + ")";
    }else if(offset >= 0)
        return "(R6 - "+ std::to_string(offset) + ")";
    else
        return "(R6 + "+ std::to_string(offset*-1) + ")";
}

void MemManager::saveReturn(int i) {
    RegCode reg = getFromRegisters(i);
    if(reg != RegCode::INVALID) {
        gc << "\t" << letter(getType(i)) << "( R6 + 4 ) = " << reg << "; # Saving return id:" << i << "\n";
    }else {
        bool nop;
        assign(-4, false, offsetOf(i, nop), false, getType(i));
    }
}

void MemManager::enterBlock() {
    PrimitiveType p(VOID);
    stack().push_back(StackElement{-2, new PrimitiveType(VOID), "Enter Block"});
    currentDepth++;
}

void MemManager::exitBlock() {
    while(stack().back().id != -2) {
        stack().pop_back();
    }
    stack().pop_back();

    for(auto& reg : registers32Bits) if(reg.blockDepth == currentDepth) {
            reg.blockDepth = -1;
            reg.name = "";
            reg.type = nullptr;
            reg.id = -1;
        }

    for(auto& reg : registers64Bits) if(reg.blockDepth == currentDepth) {
            reg.blockDepth = -1;
            reg.name = "";
            reg.type = nullptr;
            reg.id = -1;
        }

    currentDepth--;
}

void MemManager::block(RegCode reg) {
    get(reg).blocked = true;
}

void MemManager::unBlock(RegCode reg) {
    get(reg).blocked = false;
}

MemManager::StackElement &MemManager::get(RegCode reg) {
    if(reg >= R0 && reg < R6) {
        return registers32Bits[reg];
    }else if(reg >= RR0 && reg <= RR3)
        return registers64Bits[int(reg) - RR0];
}



