#include "MemManager.h"
#include "miint.tab.h"

MemManager::MemManager() {

}

MemManager::~MemManager() {

}

int MemManager::getId() {
    return idCounter++;
}

int MemManager::creaVariableSimple() {
    return getId();
}

int MemManager::creaFuncion() {
    return getId();
}

int getMapValue(map<int, int> mapa, int key) {
    try {
        return mapa.at(key);
    } catch (out_of_range) {
        return -1;
    }
}

int MemManager::load(int id) {
    Type *tipo = values.at(id);
    if (tipo->isTuple()) {
        TupleType *tupla = (TupleType *) tipo;
        int reg = getMapValue(intR, tupla->getId());
        if (reg == -1) {
            reg = getIntRegister();
            //TODO cargar objeto en reg
        }
        return reg;
    } else {
        PrimitiveType *primitivo = (PrimitiveType *) tipo;
        if (primitivo->getType() == FLOAT || primitivo->getType() == DOUBLE) {
            int reg = getMapValue(floatR, primitivo->getId());
            if (reg == -1) {
                reg = getFloatRegister();
                //TODO cargar objeto en reg
            }
            return reg;
        } else {
            int reg = getMapValue(intR, primitivo->getId());
            if (reg == -1) {
                reg = getIntRegister();
                //TODO cargar objeto en reg
            }
            return reg;
        }
    }
}

int MemManager::getIntRegister() {
    intR.erase(intR.find(intCounter));
    return intCounter++;
}

int MemManager::getFloatRegister() {
    floatR.erase(floatR.find(floatCounter));
    return floatCounter++;
}