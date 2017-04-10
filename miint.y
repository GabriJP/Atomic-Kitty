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
%}

%union { float f; double d; int i; long l; char c; char* str; }
%token <f> VALOR_FLOAT
%token <d> VALOR_DOUBLE
%token <i> VALOR_INT VALOR_BOOL
%token <l> VALOR_LONG
%token <c> VALOR_CHAR
%token <str> VALOR_STRING IDENTIFICADOR
%token FIN_DE_LINEA INT LONG FLOAT DOUBLE BOOL STRING VOID CHAR WHEN WHEN_CASE IF ELIF ELSE WHILE FOR NOTIS IS OR AND RANGE RETURN ABREBLOQUE CIERRABLOQUE IN NOTIN ACCESO

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

tupla_decl				: '(' tipo_l ')';

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

tipo					: tupla_decl
					| INT
					| FLOAT
					| LONG
					| DOUBLE
					| BOOL
					| STRING
					| CHAR
					;

tipo_l					: tipo
					| tipo ',' tipo_l
					;

args					: tipo IDENTIFICADOR
					| tipo IDENTIFICADOR ',' tipo_l
					;

init					: tipo IDENTIFICADOR '=' exp {
							if (scope->haveSymbol(std::string("dato_") + std::string($2))) {
								logError(std::string("Se intenta crear '") + std::string($2) + std::string("', pero ya existe.")) ;
							} 
						}
					;

asign					: IDENTIFICADOR '=' exp {
							if (!scope->existsSymbol("dato_" + std::string($1))) {
								logError("Se intenta usar '" + std::string($1) + "', pero no existe."); } 
							}
					;

decl					: tipo IDENTIFICADOR { 
							if (scope->haveSymbol("dato_" + std::string($2))){
								logError("Se intenta crear '" + std::string($2) + "', pero ya existe."); } 
						}
					;

in					: IDENTIFICADOR IN rango  {
							if (!scope->existsSymbol("dato_" + std::string($1))){
							logError("Se intenta usar '" + std::string($1) + "', pero no existe."); } 
						}
					| IDENTIFICADOR NOTIN rango {
							if (!scope->existsSymbol("dato_" + std::string($1)))
								{logError("Se intenta usar '" + std::string($1) + "', pero no existe."); } 
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

bloque					: ABREBLOQUE CIERRABLOQUE
					| ABREBLOQUE 
					  { scope = new Scope(scope); } 
					  inst_l 
					  { 
						Scope* oldScope = scope;
						scope = scope->getParent();
						delete oldScope; 
					  }
					  CIERRABLOQUE
					| ABREBLOQUE 
					  { scope = new Scope(scope); } 
					  inst
					  { 
						Scope* oldScope = scope;
						scope = scope->getParent();
						delete oldScope; 
					  }
					  CIERRABLOQUE
					;

func					: tipo IDENTIFICADOR '(' ')' ':' FIN_DE_LINEA bloque {
							 if (scope->existsSymbol("func_" + std::string($2))){
								logError(std::string("Se intenta crear funcion '") + std::string($2) + std::string("', pero ya existe.")); } 
						}
					| tipo IDENTIFICADOR '(' args ')' ':' FIN_DE_LINEA bloque {
							 if (scope->existsSymbol("func_" + std::string($2))){
								logError(std::string("Se intenta crear funcion '") + std::string($2) + std::string("', pero ya existe.")); 
							} 
					}
					| VOID IDENTIFICADOR '(' ')' ':' FIN_DE_LINEA bloque  { 
							if (scope->existsSymbol("func_" + std::string($2))){
								logError(std::string("Se intenta crear funcion '") + std::string($2) + std::string("', pero ya existe.")); 
							} 
					}
					| VOID IDENTIFICADOR '(' args ')' ':' FIN_DE_LINEA bloque	{
						 if (scope->existsSymbol("func_" + std::string($2))) {
							logError(std::string("Se intenta crear funcion '") + std::string($2) + std::string("', pero ya existe.")); 
						} 
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
