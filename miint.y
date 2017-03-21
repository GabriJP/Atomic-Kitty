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
%left '-' '+'
%left '*' '/'

%%

lista					: error FIN_DE_LINEA {printf(" en expresión\n");} lista
              				|
					| bloque FIN_DE_LINEA lista
					;

exp_l					: exp
					| exp ',' exp_l
					;

tupla 					: '(' exp_l ')'
					;

func					: IDENTIFICADOR tupla
					| IDENTIFICADOR '(' ')'
					;

exp					: exp '-' exp
					| exp '+' exp
					| exp '/' exp
					| exp '*' exp
					| exp AND exp
					| exp OR exp
					| is
					| func
					| in
					| VALOR_INT
					| VALOR_FLOAT
					| VALOR_DOUBLE
					| VALOR_LONG
					| VALOR_BOOL
					| VALOR_CHAR
					| VALOR_STRING
					| IDENTIFICADOR
					;

tipo					: tupla
					| INT
					| FLOAT
					| LONG
					| DOUBLE
					| BOOL
					| STRING
					| CHAR
					;


ret_tipo				: tipo
					| VOID
					;


init					: tipo IDENTIFICADOR '=' exp
					;

asign					: IDENTIFICADOR '=' exp
					;

decl					: tipo IDENTIFICADOR
					;

rango					: exp RANGE exp
					| exp RANGE exp ',' exp
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
					| bloque
					;

inst_l					: inst
					| inst FIN_DE_LINEA inst_l
					;

bloque					: ABREBLOQUE CIERRABLOQUE
					| ABREBLOQUE inst_l CIERRABLOQUE
					;

cases					: exp WHEN_CASE exp
					| exp WHEN_CASE exp FIN_DE_LINEA cases

when					: WHEN exp ':' FIN_DE_LINEA ABREBLOQUE cases CIERRABLOQUE

for					: FOR exp ':' FIN_DE_LINEA bloque
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
