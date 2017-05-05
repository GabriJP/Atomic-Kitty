#include "MemManager.h"
#include "miint.tab.h"

map<int, char> letra = {
        {INT,    'I'},
        {LONG,   'J'},
        {FLOAT,  'F'},
        {DOUBLE, 'D'},
        {CHAR,   'U'},
        {TUPLE,  'I'},
        {BOOL,   'U'},
};

map<int, int> sizes = {
        {INT,    4},
        {LONG,   8},
        {FLOAT,  4},
        {DOUBLE, 8},
        {CHAR,   1},
        {TUPLE,  4},
        {BOOL,   1},
};

MemManager::MemManager() {

}

MemManager::~MemManager() {

}

int getMapValue(map<int, int> mapa, int key) {
    try {
        return mapa.at(key);
    } catch (out_of_range) {
        return -1;
    }
}

int MemManager::getId() {
    return idCounter++;
}

int MemManager::creaVariableSimple(int tipo) {
    if (tipo == VOID) return getId();
    if (getMapValue(sizes, tipo) == -1 && tipo != STRING) {
        fprintf(stderr, "Tipo no reconocido: %d\n", tipo);
        exit(-1);
    }

    int size = tipo == STRING? yylval.i : sizes.at(tipo);
    int id = getId();
    stack -= size;
    memoria.insert(pair<int, int>(id, stack));
    values.insert(pair<int, int>(id, tipo));
    return id;
}

int MemManager::creaFuncion() {
    return getId();
}

int MemManager::load(int id) {
    int direccion = memoria.at(id);
    int tipo = values.at(id);
    if (tipo == TUPLE) {
        TupleType *tupla = (TupleType *) tipo;
        int reg = getMapValue(intR, tupla->getId());
        if (reg == -1) {
            reg = getIntRegister();
            gc("\tR%d=%c(%d);\n", reg, letra.at(TUPLE), direccion);
        }
        return reg;
    } else {
        if (tipo == FLOAT || tipo == DOUBLE) {
            int reg = getMapValue(floatR, id);
            if (reg == -1) {
                reg = getFloatRegister();
                gc("\tRR%d=%c(%d);\n", reg, letra.at(tipo), direccion);
            }
            return reg;
        } else {
            int reg = getMapValue(intR, id);
            if (reg == -1) {
                reg = getIntRegister();
                gc("\tR%d=%c(%d);\n", reg, letra.at(tipo), direccion);
            }
            return reg;
        }
    }
}

int MemManager::getIntRegister() {
    int registro = intCounter;
    intCounter = (intCounter + 1) % 7;
    int valorId = intR.at(registro);
    int direccion = memoria.at(valorId);
    int tipo = values.at(valorId);
    gc("\t%c(%d)=R%d;\n", letra.at(tipo), direccion, registro);
    intR.erase(intR.find(registro));
    return registro;
}

int MemManager::getFloatRegister() {
    int registro = floatCounter;
    floatCounter = (floatCounter + 1) % 4;
    int valorId = floatR.at(registro);
    int direccion = memoria.at(valorId);
    int tipo = values.at(valorId);
    gc("\t%c(%d)=RR%d;", letra.at(tipo), direccion, registro);
    floatR.erase(floatR.find(registro));
    return registro;
}

void MemManager::print() {
    fprintf(stderr, "Valores:\n");
    for (auto pair : values) {
        fprintf(stderr, "(%d, %d)\n", pair.first, pair.second);
    }
}
