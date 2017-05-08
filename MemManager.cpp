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

map<int, char *> regNames = {
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

int contenidoRegistros[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

MemManager::MemManager() = default;

MemManager::~MemManager() = default;

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

RegCode MemManager::creaVariableSimpleCarga(yytokentype tipo) {
    int id = creaVariableSimple(tipo);
    return load(id);
}

int MemManager::creaFuncion() {
    fprintf(stderr, "Por implementar creaFuncion\n");
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

RegCode MemManager::getRegister(RegCode (*nextReg)(MemManager *), map<int, RegCode> *registros, map<int, int> *memoria,
                                map<int, yytokentype> *values) {
    RegCode registro = nextReg(this);
    if (contenidoRegistros[registro] != -1) {
        int valorId = registros->at(registro);
        int direccion = memoria->at(valorId);
        yytokentype tipo = values->at(valorId);
        gc("\t%c(%d)=R%d;\n", letra.at(tipo), direccion, registro);
        registros->erase(registros->find(registro));
    }
    return registro;
}

RegCode MemManager::getIntRegister() {
    return getRegister(nextIntRegister, &intR, &memoria, &values);
}

RegCode MemManager::getFloatRegister() {
    return getRegister(nextFloatRegister, &floatR, &memoria, &values);
}

RegCode MemManager::nextIntRegister(MemManager *memoria) {
    int registro = memoria->intCounter;
    memoria->intCounter = (memoria->intCounter + 1) % 7;
    return (RegCode) registro;
}

RegCode MemManager::nextFloatRegister(MemManager *memoria) {
    int registro = memoria->floatCounter;
    memoria->floatCounter = (memoria->floatCounter + 1) % 4;
    return (RegCode) (registro + 8);
}

void MemManager::print() {
    fprintf(stderr, "Valores:\n");
    for (auto pair : values) {
        fprintf(stderr, "(%d, %d)\n", pair.first, pair.second);
    }
}

void MemManager::libera(int id) {
    yytokentype tipo = values.at(id);
    map<int, RegCode> mapa = tipo == FLOAT || tipo == DOUBLE ? floatR : intR;
    if (mapa.find(id) != mapa.end()) {
        contenidoRegistros[mapa.at(id)] = -1;
        mapa.erase(id);
    }
    memoria.erase(id);
    values.erase(id);
}

void MemManager::actualizaValor(int id, RegCode registro) {
    int direccion = memoria.at(id);
    yytokentype tipo = values.at(id);
    gc("\t%c(%d)=%s;\n", letra.at(tipo), direccion, regNames.at(registro));
}

void MemManager::entraBloque() {
    functionPointers.push(stack);
}

void MemManager::saleBloque() {
    stack = functionPointers.top();
    functionPointers.pop();
}