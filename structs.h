#pragma once

#include "Scope.h"

class Type;

typedef struct _ValoresRango {
	Type* type;
	int inicio;
	int fin;
	int paso;
} ValoresRango;

