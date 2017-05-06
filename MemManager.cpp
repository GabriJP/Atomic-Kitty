#include "MemManager.h"

map<yytokentype, char> letra = {
        {INT,    'I'},
        {LONG,   'J'},
        {FLOAT,  'F'},
        {DOUBLE, 'D'},
        {CHAR,   'U'},
        {TUPLE,  'I'},
        {BOOL,   'U'},
};

map<yytokentype, int> sizes = {
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

template<typename K, typename V>
V getMapValue(map<K, V> mapa, K key) {
    try {
        return mapa.at(key);
    } catch (out_of_range) {
        return INVALID;
    }
}

int MemManager::getId() {
    return idCounter++;
}

int MemManager::creaVariableSimple(yytokentype tipo) {
    if (tipo == VOID) return getId();
    if (getMapValue(sizes, tipo) == INVALID && tipo != STRING) {
        fprintf(stderr, "Tipo no reconocido: %d\n", tipo);
        exit(-1);
    }

    int size = tipo == STRING ? yylval.i : sizes.at(tipo);
    int id = getId();
    stack -= size;
    memoria.insert(pair<int, int>(id, stack));
    values.insert(pair<int, yytokentype>(id, tipo));
    return id;
}

int MemManager::creaVariableSimpleCarga(yytokentype tipo) {
    int id = creaVariableSimple(tipo);
    return load(id);
}

int MemManager::creaFuncion() {
    return getId();
}

RegCode MemManager::myLoad(int id, map<int, RegCode> mapa, int direccion, yytokentype tipo) {
    RegCode reg = getMapValue(mapa, id);
    if (reg == INVALID) {
        reg = tipo == FLOAT || tipo == DOUBLE ? getFloatRegister() : getIntRegister();
        gc("\t%s=%c(%d);\n", regNames.at(reg), letra.at(tipo), direccion);
    }
    return reg;
}

RegCode MemManager::load(int id) {
    int direccion = memoria.at(id);
    yytokentype tipo = values.at(id);
    if (tipo == FLOAT || tipo == DOUBLE) {
        return myLoad(id, floatR, direccion, tipo);
    } else {
        return myLoad(id, intR, direccion, tipo);
    }
}

RegCode MemManager::getIntRegister() {
    int registro = intCounter;
    intCounter = (intCounter + 1) % 7;
    int valorId = intR.at(registro);
    int direccion = memoria.at(valorId);
    yytokentype tipo = values.at(valorId);
    gc("\t%c(%d)=R%d;\n", letra.at(tipo), direccion, registro);
    intR.erase(intR.find(registro));
    return static_cast<RegCode>(registro);
}

RegCode MemManager::getFloatRegister() {
    int registro = floatCounter;
    floatCounter = (floatCounter + 1) % 4;
    int valorId = floatR.at(registro);
    int direccion = memoria.at(valorId);
    yytokentype tipo = values.at(valorId);
    gc("\t%c(%d)=RR%d;", letra.at(tipo), direccion, registro);
    floatR.erase(floatR.find(registro));
    return static_cast<RegCode>(registro + 8);
}

void MemManager::print() {
    fprintf(stderr, "Valores:\n");
    for (auto pair : values) {
        fprintf(stderr, "(%d, %d)\n", pair.first, pair.second);
    }
}

void MemManager::libera(int id) {

}

void MemManager::actualizaValor(int id, RegCode registro) {
    int direccion = memoria.at(id);
    yytokentype tipo = values.at(id);
    gc("\t%c(%d)=%s;\n", letra.at(tipo), direccion, regNames.at(registro));
}
