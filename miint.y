/* bison -dt miint.y && flex milex.l && gcc -o micomp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
//Sin yydebug
/* bison -dt miint.y && flex milex.l && g++ -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
//Con yydebug
/* bison -dt miint.y && flex milex.l && sed -i '/^int yydebug;/d' miint.tab.c  && g++ -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
%{
#include <stdio.h>
#include <stdlib.h>
#include "Scope.h"
Scope *scope;
extern  void  yyerror(char *);
extern FILE *yyin;
//int yydebug = 1;
#if YYBISON
union YYSTYPE;
int yylex();
#endif
extern int fines;
void  logError(std::string str);
void creaFuncion(char* nombre);
%}

%union { float f; double d; int i; long l; char c; char* str; void* type; }
%token <f> VALOR_FLOAT
%token <d> VALOR_DOUBLE
%token <i> VALOR_INT VALOR_BOOL
%token <l> VALOR_LONG
%token <c> VALOR_CHAR
%token <str> VALOR_STRING IDENTIFICADOR
%token FIN_DE_LINEA INT LONG FLOAT DOUBLE BOOL STRING VOID CHAR WHEN WHEN_CASE IF ELIF ELSE WHILE FOR NOTIS IS OR AND RANGE RETURN ABREBLOQUE CIERRABLOQUE IN NOTIN ACCESO

%type  <type>  tipo tupla_decl tipo_l

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

exp_l					: exp
					| exp ',' exp_l
					;

tupla 					: '(' exp_l ')'
					;

tupla_decl				: '(' tipo_l ')' { $$ = $2; };

func_call				: IDENTIFICADOR tupla
					| IDENTIFICADOR '(' ')'
					;

exp					: exp '-' exp
					| exp '+' exp
					| exp '/' exp
					| exp '*' exp
					| exp AND exp
					| exp OR exp
					| is
					| func_call
					| VALOR_INT
					| VALOR_FLOAT
					| VALOR_DOUBLE
					| VALOR_LONG
					| VALOR_BOOL
					| VALOR_CHAR
					| VALOR_STRING
					| IDENTIFICADOR
					| tupla
					| IDENTIFICADOR ACCESO
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
					| tipo ',' tipo_l { $$ = addTo((Type*)$1, (Type*)$3); }
					;

args					: tipo IDENTIFICADOR
					| tipo IDENTIFICADOR ',' tipo_l
					;

init					: tipo IDENTIFICADOR '=' exp {
                                                            if (scope->haveSymbol("dato_" + std::string($2))) {
                                                                logError("Se intenta crear '" + std::string($2) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineSymbol("dato_" + std::string($2), new VariableNode((Type*)$1));
                                                            }
						}
					;

asign					: IDENTIFICADOR '=' exp {
                                                            if (!scope->existsSymbol("dato_" + std::string($1))) {
                                                                logError("Se intenta usar '" + std::string($1) + "', pero no existe."); 
                                                            }
							}
					;

decl					: tipo IDENTIFICADOR {
                                                            if (scope->haveSymbol("dato_" + std::string($2))) {
                                                                logError("Se intenta crear '" + std::string($2) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineSymbol("dato_" + std::string($2), new VariableNode((Type*)$1));
                                                            }
						}
					;

in					: IDENTIFICADOR IN rango  {
                                                            if (!scope->existsSymbol("dato_" + std::string($1))) {
                                                                logError("Se intenta usar '" + std::string($1) + "', pero no existe."); 
                                                            }
						}
					| IDENTIFICADOR NOTIN rango {
                                                            if (!scope->existsSymbol("dato_" + std::string($1))) {
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
            				  { scope = new Scope(scope); } 
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

func					: tipo IDENTIFICADOR '(' ')' ':' FIN_DE_LINEA bloque {
                                                            creaFuncion($2);
						}
					| tipo IDENTIFICADOR '(' args ')' ':' FIN_DE_LINEA bloque {
                                                            creaFuncion($2);
					        }
					| VOID IDENTIFICADOR '(' ')' ':' FIN_DE_LINEA bloque {
                                                            creaFuncion($2);
					        }
					| VOID IDENTIFICADOR '(' args ')' ':' FIN_DE_LINEA bloque {
                                                            creaFuncion($2);
					        }
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

void creaFuncion(char* nombre){
    if (scope->existsSymbol("func_" + std::string(nombre))) {
        logError("Se intenta crear función '" + std::string(nombre) + "', pero ya existe."); 
    } else {
        scope->defineSymbol("func_" + std::string(nombre), NULL);
    }
}
