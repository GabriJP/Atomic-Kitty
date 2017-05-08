/* bison -dt miint.y && flex milex.l && gcc -o micomp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
//Sin yydebug
    /* bison -dt miint.y && flex milex.l && sed -i '/^int yydebug \= 1\;/d' miint.tab.c  && g++ -Wno-write-strings -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fact.aki */
//Con yydebug
/* bison -dt miint.y && flex milex.l && sed -i '/^int yydebug;/d' miint.tab.c  && g++ -Wno-write-strings -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
%{
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include "MemManager.h"
#include "structs.h"


//Variable globales
MemManager* memoria;
Scope *scope;
FILE* qFile;
int ec = 1;
std::stack<int> returnLabels;

extern FILE *yyin;
extern int fines;

#if YYBISON
union YYSTYPE;
int yylex();
#endif



//Funciones
void logError(std::string str);
void creaFuncion(char *nombre, Type *returnType, vector<ParameterNode *> *v);
bool isNumberType(Type *tipo);
int ne();
PrimitiveType* creaPrimitivo(yytokentype tipo);
extern  void  yyerror(char *str);
void opera(Type* izq, Type* der, const char *op);

%}

%code requires {
  #include "structs.h"
  #include "Scope.h"
  #include "MemManager.h"
  void gc(const char* code, ...);
  class ParameterNode;
}

%union { float f; double d; int i; long l; char c; char* str; Type* type; std::vector<ParameterNode*> *args_v; ValoresRango* valoresRango; }
%token <f> VALOR_FLOAT
%token <d> VALOR_DOUBLE
%token <i> VALOR_INT VALOR_BOOL ACCESO
%token <l> VALOR_LONG
%token <c> VALOR_CHAR
%token <str> VALOR_STRING IDENTIFICADOR
%token FIN_DE_LINEA INT LONG FLOAT DOUBLE BOOL STRING VOID CHAR WHEN WHEN_CASE IF ELIF ELSE WHILE FOR NOTIS IS OR AND RANGE RETURN ABREBLOQUE CIERRABLOQUE IN NOTIN MAYORIGUAL MENORIGUAL MAYORQUE MENORQUE TUPLE

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

lista				: error FIN_DE_LINEA {printf(" en expresión\n");} lista
					| FIN_DE_LINEA lista
              		|
					| func lista
					| inst_l FIN_DE_LINEA lista
					| inst_l
					;

exp_l				: exp { $$ = $1; }
					| exp ',' exp_l { $$ = $3->add($1); }
					;

tupla 				: '(' exp_l ')' { $$ = $2; };
					;

tupla_decl			: '(' tipo_l ')' { $$ = $2; }
                    ;

func_call			: IDENTIFICADOR tupla { $$ = $1; returnLabels.push(ne()); gc("\tGT(%d);\nL %d:\n", scope->getFunction($1)->getLabel(), returnLabels.top()); }
					| IDENTIFICADOR '(' ')' { $$ = $1; }
					;

exp					: exp '-' exp { opera($1, $3, "-"); $$ = $1; }
					| exp '+' exp { opera($1, $3, "+"); $$ = $1; }
					| exp '/' exp { opera($1, $3, "/"); $$ = $1; }
					| exp '*' exp { opera($1, $3, "*"); $$ = $1; }
					| exp AND exp {
					                    if ($1->getType() == BOOL && $3->getType() == BOOL) {
					                        $$ = $1;
					                        int r1 = memoria->load($1->getId());
					                        int r2 = memoria->load($1->getId());
					                        char* r1Name = regNames[r1];
                                            char* r2Name = regNames[r2];
                                            gc("\t%s=%s %s %s;\n", r1Name, r1Name, "&&", r2Name);
					                    } else {
					                        yyerror("Expresiones no booleanas");
					                    }
					              }
					| exp OR exp {
					                    if ($1->getType() == BOOL && $3->getType() == BOOL) {
                                            $$ = $1;
                                            int r1 = memoria->load($1->getId());
                                            int r2 = memoria->load($1->getId());
                                            char* r1Name = regNames[r1];
                                            char* r2Name = regNames[r2];
                                            gc("\t%s=%s %s %s;\n", r1Name, r1Name, "||", r2Name);
                                        } else {
                                            yyerror("Expresiones no booleanas");
                                        }
					             }
					| comp { $$ = $1; }
					| func_call { $$ = scope->getFunction($1)->getType(); returnLabels.push(ne()); gc("\tGT(%d);\nL %d:\n", scope->getFunction($1)->getLabel(), returnLabels.top()); }
					| VALOR_INT { $$ = creaPrimitivo(INT); }
					| VALOR_FLOAT { $$ = creaPrimitivo(FLOAT); }
					| VALOR_DOUBLE  { $$ = creaPrimitivo(DOUBLE); }
					| VALOR_LONG { $$ = creaPrimitivo(LONG); }
					| VALOR_BOOL { $$ = creaPrimitivo(BOOL); }
					| VALOR_CHAR { $$ = creaPrimitivo(CHAR); }
					| VALOR_STRING { $$ = creaPrimitivo(STRING); }
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

tipo				: tupla_decl { $$ = $1; }
					| INT { $$ = creaPrimitivo(INT); }
					| FLOAT { $$ = creaPrimitivo(FLOAT); }
					| LONG { $$ = creaPrimitivo(LONG); }
					| DOUBLE { $$ = creaPrimitivo(DOUBLE); }
					| BOOL { $$ = creaPrimitivo(BOOL); }
					| STRING { $$ = creaPrimitivo(STRING); }
					| CHAR { $$ = creaPrimitivo(CHAR); }
					;

tipo_l				: tipo { $$ = $1; }
					| tipo ',' tipo_l { $$ = $3->add($1); }
					;

args				: tipo IDENTIFICADOR { std::vector<ParameterNode*> *vector = new std::vector<ParameterNode*>(); vector->push_back(new ParameterNode($1, $2)); $$ = vector; }
					| tipo IDENTIFICADOR ',' args { $4->push_back(new ParameterNode($1, $2)); $$ = $4; }
					;

init				: tipo IDENTIFICADOR '=' exp {
                                                            if (scope->haveVariable($2)) {
                                                                logError("Se intenta crear '" + std::string($2) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineVariable($2, new VariableNode($1));
                                                                int id = memoria->creaVariableSimple($1->getType());
                                                                memoria->actualizaValor(id, memoria->load($4->getId()));
                                                            }
						}
					;

asign				: IDENTIFICADOR '=' exp {
                                                            if (!scope->existsVariable($1)) {
                                                                logError("Se intenta usar '" + std::string($1) + "', pero no existe."); 
                                                            } else {
                                                                memoria->actualizaValor(scope->getVariable($1)->getType()->getId(), memoria->load($3->getId()));
                                                            }
							}
					;

decl				: tipo IDENTIFICADOR {
                                                            if (scope->haveVariable($2)) {
                                                                logError("Se intenta crear '" + std::string($2) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineVariable($2, new VariableNode($1));
                                                                memoria->creaVariableSimple($1->getType());
                                                            }
						}
					;


comp				: exp MENORQUE exp { opera($1, $3, "<"); $$ = creaPrimitivo(BOOL); }
					| exp MAYORQUE exp { opera($1, $3, ">"); $$ = creaPrimitivo(BOOL); }
					| exp MENORIGUAL exp { opera($1, $3, "<="); $$ = creaPrimitivo(BOOL); }
					| exp MAYORIGUAL exp { opera($1, $3, ">="); $$ = creaPrimitivo(BOOL); }
					| exp IS exp { opera($1, $3, "=="); $$ = creaPrimitivo(BOOL); }
					| exp NOTIS exp { opera($1, $3, "!="); $$ = creaPrimitivo(BOOL); }
					;

inst				: exp FIN_DE_LINEA
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

inst_l				: inst
					| inst inst_l
					;

bloque          	: ABREBLOQUE
            				  { if (!scope->isEmpty()) scope = new Scope(memoria, scope); memoria->entraBloque(); }
            				  dentroBloque
            				  CIERRABLOQUE
            				  {
            				    memoria->saleBloque();
            					Scope* oldScope = scope;
            					scope = scope->getParent();
            					delete oldScope; 
            				  }
          				;

dentroBloque      	: inst_l
            		;

func				: tipo IDENTIFICADOR '(' ')'  {
                                                            creaFuncion($2, $1, NULL);
						} ':' FIN_DE_LINEA bloque
					| tipo IDENTIFICADOR '(' args ')'  {
                                                            creaFuncion($2, $1, $4);
					        } ':' FIN_DE_LINEA bloque
					| VOID IDENTIFICADOR '(' ')' {
                                                            creaFuncion($2, creaPrimitivo(VOID), NULL);
					        } ':' FIN_DE_LINEA bloque
					| VOID IDENTIFICADOR '(' args ')' {
                                                            creaFuncion($2, creaPrimitivo(VOID), $4);
					        } ':' FIN_DE_LINEA bloque
					;

cases				: exp WHEN_CASE exp
					| exp WHEN_CASE exp FIN_DE_LINEA cases
					;	

when				: WHEN exp ':' FIN_DE_LINEA ABREBLOQUE cases CIERRABLOQUE
					| WHEN rango ':' FIN_DE_LINEA ABREBLOQUE cases CIERRABLOQUE
					;

for					: FOR IDENTIFICADOR IN rango ne[vuelta] ne[salida] ':' FIN_DE_LINEA {/*crear variable identificador si no existe, asignarle el valor de inicio menos paso, label vuelta, identificador+=paso, comprobar que sea menor que fin y hacer bloque o ir a salida*/} bloque { gc("\tGT(%d);\nL %d:\n", $vuelta, $salida); }
					;





if					: IF exp ':' FIN_DE_LINEA ne[salida] if_evalua_expresion bloque {gc("L %d:\n", $salida);}
					| IF exp ':' FIN_DE_LINEA ne[elif] if_evalua_expresion bloque ne[salida] { $<i>$=$<i>elif; } elif_l {gc("L %d:\n", $salida);}
					;

/*ELIF. $0=fin elif -> donde se va si no se cumple la condición / $-1=salida if -> donde se va al acabar un bloque */

elif_l				: ELIF exp ':' FIN_DE_LINEA ne[fin] elif_control bloque {gc("L %d:\n", $fin);}
					| ELIF exp ':' FIN_DE_LINEA ne[siguiente_elif] elif_control bloque elif_copia_salida elif_copia_siguiente elif_l
					| ELSE ':' FIN_DE_LINEA { gc("\tGT(%d);\nL %d:\n", $<i>-1, $<i>0);} bloque
					;


/*Genera una etiqueta nueva*/
ne					: { $<i>$ = ne(); }
					;

/* Ir a salida, Si (!cond) ir a siguiente elif/else/salida */
elif_control		: { gc("\tGT  (%d);\nL %d:\n\tIF(!R%d) GT(%d);\n", $<i>-6, $<i>-5, $<i>-3, $<i>0); }
					;

/*Evalua expresión en $-3 y si no se cumple salta a $0*/
if_evalua_expresion	: { gc("\tIF(!%s) GT(%d);\n", regNames.at(memoria->load(($<type>-3)->getId())), $<i>0); }
					;

/*Copia el valor de $-8, que corresponde con la salida del elif*/
elif_copia_salida	: { $$ = $<i>-8; /*($-1 del anterior)*/ }
					;

/*Copia del valor de $-3, util en el elif que lleva otro elif despues*/
elif_copia_siguiente: { $$ = $<i>-3; }
					;

/*FIN ELIF*/


while				: WHILE ne[salida] ne[vuelta] { gc("L %d:\n", $vuelta); } exp ':' { gc("\tIF(!R %d) GT( %d);\n", $exp, $salida); } FIN_DE_LINEA bloque { gc("\tGT(%d);\nL %d:\n", $vuelta, $salida); }
					;

rango				: exp[inicio] RANGE exp[fin] { ValoresRango valoresRango = {$inicio, $fin, creaPrimitivo(INT)}; $$=&valoresRango; }
					| exp[inicio] RANGE exp[fin] ',' exp[paso] { ValoresRango valoresRango = {$inicio, $fin, $paso}; $$=&valoresRango; }
					;
%%

bool isNumberType(Type *tipo) {
    switch (tipo->getType()) {
        case INT:
        case LONG:
        case FLOAT:
        case DOUBLE:
            return true;
        default:
            return false;
    }
}

void gc(const char *code, ...) {
    va_list args;
    va_start (args, code);
    vfprintf(qFile, code, args);
    va_end (args);
}

int ne() {
    return ec++;
}

int main(int argc, char **argv) {
    memoria = new MemManager();
    scope = new Scope(memoria);
//Funciones del sistema
    scope->defineFunction("print", new FunctionNode(creaPrimitivo(VOID)));
    scope->defineFunction("getchar", new FunctionNode(creaPrimitivo(CHAR)));
    if (argc > 1) yyin = fopen(argv[1], "r");
    qFile = fopen("../program.q", "w+");
    yyparse();
    gc("\tR0=0;\t//Código de salida\n\tGT(-2);\t//Fin de programa");
}

void logError(std::string str) {
    yyerror((char *) str.c_str());
}

void yyerror(char *str) {
    extern int yylineno;
    printf("Parse  Error near line %d \n %s\n", fines, str);
    memoria->print();
    exit(-1);
}

void creaFuncion(char *nombre, Type *returnType, vector<ParameterNode *> *v) {
    if (scope->existsFunction(nombre)) {
        logError("Se intenta crear función '" + std::string(nombre) + "', pero ya existe.");
    } else {
        int label = ne();
        gc("L %d:\n", label);
        scope->defineFunction(nombre, new FunctionNode(label, returnType, v));
        scope = new Scope(memoria, scope, std::string(nombre));
    }
}

PrimitiveType *creaPrimitivo(yytokentype tipo) {
    return new PrimitiveType(memoria->creaVariableSimple(tipo), tipo);
}

void opera(Type* izq, Type* der, const char* op){
    if (isNumberType(izq) && izq->getType() == der->getType()) {
        RegCode r1 = memoria->load(izq->getId());
        RegCode r2 = memoria->load(der->getId());
        char* r1Name = regNames[r1];
        char* r2Name = regNames[r2];
        gc("\t%s=%s%s%s;\n", r1Name, r1Name, op, r2Name);
    } else {
        yyerror((char*) ((std::string("Tipos diferentes: '") + izq->toString() + "' y '" + der->toString() + "'").c_str()));
    }
}

bool ofType(yytokentype expected, Type *type) {
    return type->getType() == expected;
}

template<typename Car1, typename Car2>
bool ofType(Car1 car1, Car2 car2) {
    return car1 == car2;
}

template<typename Car1, typename Car2, typename... Cdr>
bool ofType(Car1 car1, Car2 car2, Cdr ... cdr) {
    return car1 == car2 && equal(car1, cdr...);
}