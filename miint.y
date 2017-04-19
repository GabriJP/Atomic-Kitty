/* bison -dt miint.y && flex milex.l && gcc -o micomp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
//Sin yydebug
/* bison -dt miint.y && flex milex.l && g++ -Wno-write-strings -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
//Con yydebug
/* bison -dt miint.y && flex milex.l && sed -i '/^int yydebug;/d' miint.tab.c  && g++ -Wno-write-strings -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
%{
#include <stdio.h>
#include <stdlib.h>
#include "Scope.h"
Scope *scope;
extern  void  yyerror(char *);
extern FILE *yyin;
int yydebug = 1;
#if YYBISON
union YYSTYPE;
int yylex();
#endif
extern int fines;
void  logError(std::string str);
void creaFuncion(char* nombre, std::vector<ParameterNode*> *v = new std::vector<ParameterNode*>());
%}

%union { float f; double d; int i; long l; char c; char* str; Type* type; std::vector<ParameterNode*> *args_v;}
%token <f> VALOR_FLOAT
%token <d> VALOR_DOUBLE
%token <i> VALOR_INT VALOR_BOOL ACCESO
%token <l> VALOR_LONG
%token <c> VALOR_CHAR
%token <str> VALOR_STRING IDENTIFICADOR
%token FIN_DE_LINEA INT LONG FLOAT DOUBLE BOOL STRING VOID CHAR WHEN WHEN_CASE IF ELIF ELSE WHILE FOR NOTIS IS OR AND RANGE RETURN ABREBLOQUE CIERRABLOQUE IN NOTIN

%type  <type>  tipo tupla_decl tipo_l exp exp_l tupla
%type  <str> func_call
%type  <args_v> args

%right '='
%left ','
%left IN
%left AND OR RANGE
%left IS NOTIS	
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
					| exp AND exp { if ($1->equals(&PrimitiveType(BOOL)) && $3->equals(&PrimitiveType(BOOL))) { $$ = $1; } else { yyerror("Expresiones no booleanas"); } }
					| exp OR exp { if ($1->equals(&PrimitiveType(BOOL)) && $3->equals(&PrimitiveType(BOOL))) { $$ = $1; } else { yyerror("Expresiones no booleanas"); } }
					| is { $$ = new PrimitiveType(BOOL); }
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

decl					: tipo IDENTIFICADOR {
                                                            if (scope->haveVariable($2)) {
                                                                logError("Se intenta crear '" + std::string($2) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineVariable($2, new VariableNode($1));
                                                            }
						}
					;

in					: IDENTIFICADOR IN rango  {
                                                            if (!scope->existsVariable($1)) {
                                                                logError("Se intenta usar '" + std::string($1) + "', pero no existe."); 
                                                            }
						}
					| IDENTIFICADOR NOTIN rango {
                                                            if (!scope->existsVariable($1)) {
                                                                logError("Se intenta usar '" + std::string($1) + "', pero no existe."); 
                                                            }
						}
					;

is					: exp IS exp
					| exp NOTIS exp
					;

inst					: exp
					| init
					| asign
					| decl
					| when
					| for
					| while
					| if
					| bloque
					| RETURN exp
					;

inst_l					: inst FIN_DE_LINEA
					| inst FIN_DE_LINEA inst_l
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
            				| inst
            				;

func					: tipo IDENTIFICADOR '(' ')'  {
                                                            creaFuncion($2, NULL);
						} ':' FIN_DE_LINEA bloque
					| tipo IDENTIFICADOR '(' args ')'  {
                                                            creaFuncion($2, $4);
					        } ':' FIN_DE_LINEA bloque
					| VOID IDENTIFICADOR '(' ')' {
                                                            creaFuncion($2, NULL);
					        } ':' FIN_DE_LINEA bloque
					| VOID IDENTIFICADOR '(' args ')' {
                                                            creaFuncion($2, $4);
					        } ':' FIN_DE_LINEA bloque
					;

cases					: exp WHEN_CASE exp
					| exp WHEN_CASE exp FIN_DE_LINEA cases
					;	

when					: WHEN exp ':' FIN_DE_LINEA ABREBLOQUE cases CIERRABLOQUE
					| WHEN rango ':' FIN_DE_LINEA ABREBLOQUE cases CIERRABLOQUE
					;

for					: FOR in ':' FIN_DE_LINEA bloque
					;

if					: IF exp ':' FIN_DE_LINEA bloque
					| IF exp ':' FIN_DE_LINEA bloque else
					| IF exp ':' FIN_DE_LINEA bloque elif_l
					| IF exp ':' FIN_DE_LINEA bloque elif_l else
					;

elif_l					: ELIF exp ':' FIN_DE_LINEA bloque
					| ELIF exp ':' FIN_DE_LINEA bloque elif_l
					;

else					: ELSE ':' FIN_DE_LINEA bloque
					;

while					: WHILE exp ':' FIN_DE_LINEA bloque
					;

rango					: exp RANGE exp
					| exp RANGE exp ',' exp
					;
%%

int main(int argc, char** argv) {
	scope = new Scope();
//Funciones del sistema
	scope->defineFunction("print", new FunctionNode);
	scope->defineFunction("getchar", new FunctionNode);
	if (argc>1) yyin=fopen(argv[1],"r");
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

void creaFuncion(char* nombre, std::vector<ParameterNode*> *v){
    if (scope->existsFunction(nombre)) {
        logError("Se intenta crear función '" + std::string(nombre) + "', pero ya existe."); 
    } else {
        scope->defineFunction(nombre, new FunctionNode(v));
	scope = new Scope(scope, std::string(nombre));
    }
}
