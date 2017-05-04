/* bison -dt miint.y && flex milex.l && gcc -o micomp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
//Sin yydebug
    /* bison -dt miint.y && flex milex.l && sed -i '/^int yydebug \= 1\;/d' miint.tab.c  && g++ -Wno-write-strings -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fact.aki */
//Con yydebug
/* bison -dt miint.y && flex milex.l && sed -i '/^int yydebug;/d' miint.tab.c  && g++ -Wno-write-strings -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
%{
#include <stdio.h>
#include <stdlib.h>
#include "Scope.h"
#include <stdarg.h>
#include "structs.h"
#include "MemManager.h"


//Variable globales
Scope *scope;
FILE* qFile;
int ec = 1;

extern FILE *yyin;
int yydebug = 1;
extern int fines;

#if YYBISON
union YYSTYPE;
int yylex();
#endif



//Funciones
void logError(std::string str);
void creaFuncion(char* nombre, Type* returnType, std::vector<ParameterNode*> *v = new std::vector<ParameterNode*>());
bool isNumberType(Type* tipo);
void gc(const char* code, ...)	;
int ne();
extern  void  yyerror(char *);

MemManager memoria;

%}

%union { float f; double d; int i; long l; char c; char* str; Type* type; std::vector<ParameterNode*> *args_v; ValoresRango* valoresRango; }
%token <f> VALOR_FLOAT
%token <d> VALOR_DOUBLE
%token <i> VALOR_INT VALOR_BOOL ACCESO
%token <l> VALOR_LONG
%token <c> VALOR_CHAR
%token <str> VALOR_STRING IDENTIFICADOR
%token FIN_DE_LINEA INT LONG FLOAT DOUBLE BOOL STRING VOID CHAR WHEN WHEN_CASE IF ELIF ELSE WHILE FOR NOTIS IS OR AND RANGE RETURN ABREBLOQUE CIERRABLOQUE IN NOTIN MAYORIGUAL MENORIGUAL MAYORQUE MENORQUE

%type  <type>  tipo tupla_decl tipo_l exp exp_l tupla comp
%type  <str> func_call
%type  <args_v> args
%type  <i> ne elif_copia_salida elif_copia_siguiente
%type  <valoresRango> rango

%right '='
%left ','
%left IN
%left AND OR RANGE
%left IS NOTIS
%left MAYORIGUAL MENORIGUAL MAYORQUE MENORQUE
%left '-' '+'
%left '*' '/'

%%

lista					: error FIN_DE_LINEA {printf(" en expresión\n");} lista
					| FIN_DE_LINEA lista
              				|
					| func lista
					| inst_l FIN_DE_LINEA lista
					| inst_l
					;

exp_l					: exp { $$ = $1; }
					| exp ',' exp_l { $$ = $3->add($1); }
					;

tupla 					: '(' exp_l ')' { $$ = $2; };
					;

tupla_decl				: '(' tipo_l ')' { $$ = $2; };

func_call				: IDENTIFICADOR tupla { printf("%s----------------------------------------------------\n", $1); $$ = $1; }
					| IDENTIFICADOR '(' ')' { $$ = $1; }
					;

exp					: exp '-' exp { if ($1->equals($3)) { $$ = $1; } else { yyerror((char*) ((std::string("Tipos diferentes: '") + $1->toString() + "' y '" + $3->toString() + "'").c_str())); } }
					| exp '+' exp { if ($1->equals($3)) { $$ = $1; } else { yyerror("Tipos diferentes"); } }
					| exp '/' exp { if ($1->equals($3)) { $$ = $1; } else { yyerror("Tipos diferentes"); } }
					| exp '*' exp { if ($1->equals($3)) { $$ = $1; } else { yyerror("Tipos diferentes"); } }
					| exp AND exp { PrimitiveType* booleano = new PrimitiveType(BOOL);  if ($1->equals(booleano) && $3->equals(booleano)) { $$ = $1; } else { yyerror("Expresiones no booleanas"); } delete booleano; }
					| exp OR exp { PrimitiveType* booleano = new PrimitiveType(BOOL); if ($1->equals(booleano) && $3->equals(booleano)) { $$ = $1; } else { yyerror("Expresiones no booleanas"); } delete booleano; }
					| comp { $$ = new PrimitiveType(BOOL); }
					| func_call { $$ = scope->getFunction($1)->getType(); }
					| VALOR_INT { $$ = new PrimitiveType(INT); }
					| VALOR_FLOAT { $$ = new PrimitiveType(FLOAT); }
					| VALOR_DOUBLE  { $$ = new PrimitiveType(DOUBLE); }
					| VALOR_LONG { $$ = new PrimitiveType(LONG); }
					| VALOR_BOOL { $$ = new PrimitiveType(BOOL); }
					| VALOR_CHAR { $$ = new PrimitiveType(CHAR); }
					| VALOR_STRING { $$ = new PrimitiveType(STRING); }
					| IDENTIFICADOR { $$ = scope->getVariable($1)->getType(); }
					| tupla { $$ = $1; }
					| IDENTIFICADOR ACCESO { 
						Type* type = scope->getVariable($1)->getType();
						if(type->isTuple())
							$$ = ((TupleType*)type)->getSubType($2); 
						else
							yyerror("Acceso a una tupla");
					
					} 
					;

tipo					: tupla_decl { $$ = $1; }
					| INT { $$ = new PrimitiveType(INT); }
					| FLOAT { $$ = new PrimitiveType(FLOAT); }
					| LONG { $$ = new PrimitiveType(LONG); }
					| DOUBLE { $$ = new PrimitiveType(DOUBLE); }
					| BOOL { $$ = new PrimitiveType(BOOL); }
					| STRING { $$ = new PrimitiveType(STRING); }
					| CHAR { $$ = new PrimitiveType(CHAR); }
					;

tipo_l					: tipo { $$ = $1; }
					| tipo ',' tipo_l { $$ = $3->add($1); }
					;

args					: tipo IDENTIFICADOR { std::vector<ParameterNode*> *vector = new std::vector<ParameterNode*>(); vector->push_back(new ParameterNode($1, $2)); $$ = vector; }
					| tipo IDENTIFICADOR ',' args { $4->push_back(new ParameterNode($1, $2)); $$ = $4; }
					;

init					: tipo IDENTIFICADOR '=' exp {
                                                            if (scope->haveVariable($2)) {
                                                                logError("Se intenta crear '" + std::string($2) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineVariable($2, new VariableNode($1));
                                                            }
						}
					;

asign					: IDENTIFICADOR '=' exp {
                                                            if (!scope->existsVariable($1)) {
                                                                logError("Se intenta usar '" + std::string($1) + "', pero no existe."); 
                                                            }
							}
					;

decl				: tipo IDENTIFICADOR {
                                                            if (scope->haveVariable($2)) {
                                                                logError("Se intenta crear '" + std::string($2) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineVariable($2, new VariableNode($1));
                                                            }
						}
					;


comp				: exp MENORQUE exp { if (isNumberType($1) && $1->equals($3)) $$ = new PrimitiveType(BOOL); else logError("Expresiones no numericas"); }
					| exp MAYORQUE exp { if (isNumberType($1) && $1->equals($3)) $$ = new PrimitiveType(BOOL); else logError("Expresiones no numericas"); }
					| exp MENORIGUAL exp { if (isNumberType($1) && $1->equals($3)) $$ = new PrimitiveType(BOOL); else logError("Expresiones no numericas"); }
					| exp MAYORIGUAL exp { if (isNumberType($1) && $1->equals($3)) $$ = new PrimitiveType(BOOL); else logError("Expresiones no numericas"); }
					| exp IS exp { if (isNumberType($1) && $1->equals($3)) $$ = new PrimitiveType(BOOL); else logError("Expresiones no booleanas"); }
					| exp NOTIS exp { if (isNumberType($1) && $1->equals($3)) $$ = new PrimitiveType(BOOL); else logError("Expresiones no booleanas"); }
					;

inst					: exp FIN_DE_LINEA
					| init FIN_DE_LINEA
					| asign FIN_DE_LINEA
					| decl FIN_DE_LINEA
					| when
					| for
					| while
					| if
					| bloque
					| RETURN exp FIN_DE_LINEA
					;

inst_l					: inst
					| inst inst_l
					;

bloque          			: ABREBLOQUE 
            				  { if (!scope->isEmpty()) scope = new Scope(scope); } 
            				  dentroBloque
            				  CIERRABLOQUE
            				  { 
            					Scope* oldScope = scope;
            					scope = scope->getParent();
            					delete oldScope; 
            				  }
          				;

dentroBloque      			: inst_l 
            				;

func					: tipo IDENTIFICADOR '(' ')'  {
                                                            creaFuncion($2, $1, NULL);
						} ':' FIN_DE_LINEA bloque
					| tipo IDENTIFICADOR '(' args ')'  {
                                                            creaFuncion($2, $1, $4);
					        } ':' FIN_DE_LINEA bloque
					| VOID IDENTIFICADOR '(' ')' {
                                                            creaFuncion($2, new PrimitiveType(VOID), NULL);
					        } ':' FIN_DE_LINEA bloque
					| VOID IDENTIFICADOR '(' args ')' {
                                                            creaFuncion($2, new PrimitiveType(VOID), $4);
					        } ':' FIN_DE_LINEA bloque
					;

cases					: exp WHEN_CASE exp
					| exp WHEN_CASE exp FIN_DE_LINEA cases
					;	

when					: WHEN exp ':' FIN_DE_LINEA ABREBLOQUE cases CIERRABLOQUE
					| WHEN rango ':' FIN_DE_LINEA ABREBLOQUE cases CIERRABLOQUE
					;

for					: FOR IDENTIFICADOR IN rango ne[vuelta] ne[salida] ':' FIN_DE_LINEA {/*crear variable identificador si no existe, asignarle el valor de inicio menos paso, label vuelta, identificador+=paso, comprobar que sea menor que fin y hacer bloque o ir a salida*/} bloque { gc("\tGT(%d);\nL %d:\n", $vuelta, $salida); }
					;





if					: IF exp ':' FIN_DE_LINEA ne[salida] if_evalua_expresion bloque {gc("L %d:\n", $salida);}
					| IF exp ':' FIN_DE_LINEA ne[elif] if_evalua_expresion bloque ne[salida] { $<i>$=$<i>elif; } elif_l {gc("L %d:\n", $salida);}
					;

/*ELIF. $0=fin elif -> donde se va si no se cumple la condición / $-1=salida if -> donde se va al acabar un bloque */

elif_l					: ELIF exp ':' FIN_DE_LINEA ne[fin] elif_control bloque {gc("L %d:\n", $fin);}
					| ELIF exp ':' FIN_DE_LINEA ne[siguiente_elif] elif_control bloque elif_copia_salida elif_copia_siguiente elif_l
					| ELSE ':' FIN_DE_LINEA { gc("\tGT(%d);\nL %d:\n", $<i>-1, $<i>0);} bloque
					;


/*Genera una etiqueta nueva*/
ne					: { $<i>$ = ne(); }
					;

/* Ir a salida, Si (!cond) ir a siguiente elif/else/salida */
elif_control			: { gc("\tGT  (%d);\nL %d:\n\tIF(!R%d) GT(%d);\n", $<i>-6, $<i>-5, $<i>-3, $<i>0); }
					;

/*Evalua expresión en $-3 y si no se cumple salta a $0*/
if_evalua_expresion			: { gc("\tIF(!R%d) GT(%d);\n", $<i>-3, $<i>0); /*si no $-4 ir a $0*/ }
					;

/*Copia el valor de $-8, que corresponde con la salida del elif*/
elif_copia_salida			: { $$ = $<i>-8; /*($-1 del anterior)*/ }
					;

/*Copia del valor de $-3, util en el elif que lleva otro elif despues*/
elif_copia_siguiente			: { $$ = $<i>-3; }
					;

/*FIN ELIF*/


while					: WHILE ne[salida] ne[vuelta] { gc("L %d:\n", $vuelta); } exp ':' { gc("\tIF(!R %d) GT( %d);\n", $exp, $salida); } FIN_DE_LINEA bloque { gc("\tGT(%d);\nL %d:\n", $vuelta, $salida); }
					;

rango					: exp[inicio] RANGE exp[fin] { ValoresRango valoresRango = {$inicio, $fin, new PrimitiveType(INT)}; $$=&valoresRango; }
					| exp[inicio] RANGE exp[fin] ',' exp[paso] { ValoresRango valoresRango = {$inicio, $fin, $paso}; $$=&valoresRango; }
					;
%%

PrimitiveType nums[] = {PrimitiveType(INT), PrimitiveType(LONG), PrimitiveType(FLOAT), PrimitiveType(DOUBLE)};
std::vector<PrimitiveType> numeros (nums, nums + sizeof(PrimitiveType) / sizeof(Type));

bool isNumberType(Type* tipo){
	for(std::vector<PrimitiveType>::iterator i = numeros.begin(); i != numeros.end(); i++) {
		if ((*i).equals(tipo)) {
			return true;
		}
	}
	return false;
}

void gc(const char* code, ...) {
	va_list args;
	va_start (args, code);
	vfprintf (qFile, code, args);
	va_end (args);
}

int ne(){
	return ec++;
}

int main(int argc, char** argv) {
	scope = new Scope();
//Funciones del sistema
	scope->defineFunction("print", new FunctionNode(new PrimitiveType(VOID)));
	scope->defineFunction("getchar", new FunctionNode(new PrimitiveType(CHAR)));
	if (argc>1) yyin=fopen(argv[1],"r");
	qFile=fopen("program.q", "w+");
	yyparse();
}

void  logError(std::string str) {
    yyerror((char*)str.c_str());
}

void  yyerror(char* str) {
    extern int yylineno;
    printf("Parse  Error near line %d \n %s\n",fines,str );
    exit(-1);
}

void creaFuncion(char* nombre, Type* returnType, std::vector<ParameterNode*> *v){
    if (scope->existsFunction(nombre)) {
        logError("Se intenta crear función '" + std::string(nombre) + "', pero ya existe."); 
    } else {
        scope->defineFunction(nombre, new FunctionNode(returnType, v));
	    scope = new Scope(scope, std::string(nombre));
    }
}
