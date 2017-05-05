#pragma once

#include "Scope.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"

class MemManager {
private:
    int idCounter = 0;

    int intCounter = 0;

    int floatCounter = 0;

    map<int, int> intR;

    map<int, int> floatR;

    map<int, int> memoria;

    map<int, Type *> values;

    int getId();

    int getIntRegister();

    int getFloatRegister();

public:
    MemManager();

    ~MemManager();

    int creaFuncion();

    int creaVariableSimple();

    int load(int id);
};

#pragma clang diagnostic pop

