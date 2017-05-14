#include "MemManager.h"

const std::map<yytokentype, char> MemManager::letterMap = {
        {INT,    'I'},
        {LONG,   'J'},
        {FLOAT,  'F'},
        {DOUBLE, 'D'},
        {CHAR,   'U'},
        {TUPLE,  'I'},
        {BOOL,   'U'},
};

int MemManager::getId() {
    return id++;
}

int MemManager::addToStack(Type *type, int id, std::string name) {

    gc << "\tR7 = R7 - " << type->size() << "; #Add to stack\n";

    return addToStackWithoutChangingR7(type, id, name);
}

int MemManager::addToStackWithoutChangingR7(Type *type, int id, std::string name) {
    stack().push_back({id, type->clone(), name});
    stackSize += type->size();

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

void MemManager::remove(int id) {
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
    PrimitiveType p(INT);
    auto f = [this, &p](auto& reg) {
        if(reg.id !=  NOT_USED) {
            int id = addToStack(reg.type, reg.id);
            asign(id, load(reg.id));
        }else
            addToStack(&p, reg.id);
    };
    for(auto& reg : registers32Bits) f(reg);
    for(auto& reg : registers64Bits) f(reg);

}

void MemManager::loadRegisters() {

    auto f = [this](StackElement& reg, RegCode regCode) {
        StackElement& loadedReg = stack().back();
        gc << "\t" << regCode << " = " <<  getInstruction(loadedReg) << "; #Loading register" << regCode << "\n";
        gc << "\tR7 = R7 + " << loadedReg.type->size() << ";\n";
        stack().pop_back();
    };

    for(int i = 0; i < registers32Bits.size(); i++) f(registers32Bits[i], RegCode(i));
    for(int i = 0; i < registers64Bits.size(); i++) f(registers64Bits[i], RegCode(i + (int)RegCode::RR0));


}

//Join two loops
//TODO
RegCode MemManager::load(int id, int &newId) {
    newId = id;
    for(int i = 0; i < registers32Bits.size(); i++)
        if(registers32Bits[i].id == id)
            return (RegCode) i;

    for(int i = 0; i < registers64Bits.size(); i++)
        if(registers32Bits[i].id == id)
            return (RegCode) (i + (int)RegCode::RR0);

    auto& element = get(id);

    newId = getId();

    RegCode reg;

    if(element.type->isTuple()) return RegCode::INVALID;
    else if(element.type->size() <= 4) reg = addToRegister(registers32Bits, element.type, newId);
    else if(element.type->size() == 8) reg = addToRegister(registers64Bits, element.type, newId);
    else return RegCode::INVALID;

    gc << '\t' << reg << " = " << getInstruction(element) << "; #Load " << id << " " << element.name << " from stack\n";

    return reg;

}

void MemManager::print() {
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
            std::cout << "\t" << (RegCode) (i + (int)RegCode::RR0) << ":" << registers32Bits[i].id << " -> " << registers32Bits[i].type->toString() << "\n";
        else
            std::cout << "\t" << (RegCode) (i + (int)RegCode::RR0) << ": Not used\n";

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

    return (RegCode)reg;

}


template<typename T>
bool MemManager::haveFreeRegister(T &registers, int &id) {
    for(int i = 0; i < registers.size(); i++) {
        if(registers[i].id == NOT_USED) {
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
        if(minId > registers[i].id) {
            minId = registers[i].id;
            regNumber = i;
        }

    return regNumber; //TODO, how to get the lastRegister???
}

std::deque<MemManager::StackElement> &MemManager::stack() {
    if(inFunction) return localStack;
    else return globalStack;
}

std::ostream &operator<<(std::ostream &os, RegCode const &reg) {
    std::map<RegCode, char *> regNames = {
            {RegCode::R0,  "R0"},
            {RegCode::R1,  "R1"},
            {RegCode::R2,  "R2"},
            {RegCode::R3,  "R3"},
            {RegCode::R4,  "R4"},
            {RegCode::R5,  "R5"},
            {RegCode::R6,  "R6"},
            {RegCode::R7,  "R7"},
            {RegCode::RR0, "RR0"},
            {RegCode::RR1, "RR1"},
            {RegCode::RR2, "RR2"},
            {RegCode::RR3, "RR3"},
    };
    os << regNames[reg];
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

void MemManager::asign(int varId, int expId) {
    int expLoadedId;
    StackElement& var = get(varId);
    RegCode expRegister = load(expId, expLoadedId);
    StackElement exp = get(expLoadedId);

    if(!exp.type->equals(var.type)) {
        std::cout << "Types don't match in assign";
        exit(-1);
    }

    gc << '\t' << getInstruction(var) << " = " << expRegister << " # Asign value" <<'\n';

    remove(expLoadedId);
    if(expId != expLoadedId) remove(expId);

}

void MemManager::asign(int varId, RegCode expRegister) {

    StackElement& var = get(varId);
    gc << '\t' << getInstruction(var) << " = " << expRegister << " # Asign value" <<'\n';

}


void MemManager::asign(int varId, std::string value) {
    StackElement& var = get(varId);
    gc << '\t' << getInstruction(var) << " = " << value << " # Asign" <<'\n';
}


std::string MemManager::getInstruction(MemManager::StackElement &var) {
    std::string out(1,letter(var.type));
    bool inGlobal;
    std::size_t offset = offsetOf(var.id, inGlobal);

    if(inGlobal) {

        stringstream ss;
        ss << std::hex << stackStart - offset;
        string str = ss.str();

        return out + "( 0x" + str + " )";
    }else
        return out + "( R6 - "+ std::to_string(offset) + " )";

}

MemManager::MemManager() {
    registers32Bits.fill(StackElement{NOT_USED, nullptr});
    registers64Bits.fill(StackElement{NOT_USED, nullptr});
}

size_t MemManager::currentStackSize() {
    size_t size = 0;
    for(auto& elem : stack()) size += elem.type->size();

    return size;
}

void MemManager::createFunction() {
    inFunction = true;
}

