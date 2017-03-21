/* bison -d miint.y && flex milex.l && gcc -o micomp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
%{
#include <stdio.h>
#include <stdlib.h>
extern  void  yyerror(char *);
extern FILE *yyin;
int yydebug=1;
#if YYBISON
union YYSTYPE;
int yylex();
#endif
%}

%union { float f; double d; int i; long l; char c; char* str; }
%token <f> VALOR_FLOAT
%token <d> VALOR_DOUBLE
%token <i> VALOR_INT VALOR_BOOL
%token <l> VALOR_LONG
%token <c> VALOR_CHAR
%token <str> VALOR_STRING IDENTIFICADOR
%token FIN_DE_LINEA INT LONG FLOAT DOUBLE BOOL STRING VOID CHAR WHEN WHEN_CASE IF ELIF ELSE WHILE FOR NOTIS IS OR AND RANGE RETURN ABREBLOQUE CIERRABLOQUE IN NOTIN

%right '='
%left ','
%left IN
%left AND OR RANGE
%left IS NOTIS	
%left '-' '+'
%left '*' '/'

%%

lista					: error FIN_DE_LINEA {printf(" en expresión\n");} lista
              				|
					| func FIN_DE_LINEA lista
					/*| inst_l FIN_DE_LINEA lista //Como corregimos esto? */
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

init					: tipo IDENTIFICADOR '=' exp
					;

asign					: IDENTIFICADOR '=' exp
					;

decl					: tipo IDENTIFICADOR
					;

in					: IDENTIFICADOR IN rango
					| IDENTIFICADOR NOTIN rango
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

inst_l					: inst
					| inst FIN_DE_LINEA inst_l
					;

bloque					: ABREBLOQUE CIERRABLOQUE
					| ABREBLOQUE inst_l CIERRABLOQUE
					;

func					: tipo IDENTIFICADOR '(' ')' ':' FIN_DE_LINEA bloque
					| tipo IDENTIFICADOR '(' args ')' ':' FIN_DE_LINEA bloque
					| VOID IDENTIFICADOR '(' ')' ':' FIN_DE_LINEA bloque
					| VOID IDENTIFICADOR '(' args ')' ':' FIN_DE_LINEA bloque
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

else					: ELSE exp ':' FIN_DE_LINEA bloque
					;

while					: WHILE exp ':' FIN_DE_LINEA bloque
					;

rango					: exp RANGE exp
					| exp RANGE exp ',' exp
					;
%%

int main(int argc, char** argv) {
	if (argc>1) yyin=fopen(argv[1],"r");
	yyparse();
}

void  yyerror(char* str) {
    extern int yylineno;
    printf("Parse  Error near line %d \n %s\n",yylineno,str );
    exit(-1);

}
