/* bison -d miint.y && flex milex.l && gcc -o micomp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
%{
#include <stdio.h>
#include <stdlib.h>
extern  void  yyerror(char *);
extern FILE *yyin;
int yydebug=1;
%}

%union { float f; double d; int i; long l; char c; char* str; }
%token <f> VALOR_FLOAT
%token <d> VALOR_DOUBLE
%token <i> VALOR_INT VALOR_BOOL
%token <l> VALOR_LONG
%token <c> VALOR_CHAR
%token <str> VALOR_STRING IDENTIFICADOR
%token FIN_DE_LINEA INT LONG FLOAT DOUBLE BOOL STRING VOID CHAR WHEN WHEN_CASE IF ELIF ELSE WHILE FOR NOTIS IS OR RANGE RETURN ABREBLOQUE CIERRABLOQUE
%left '-' '+'
%left '*' '/'

%%

lista					: error FIN_DE_LINEA {printf(" en expresión\n");} lista
              |
							;

exp_l					: exp
							| exp ',' exp_l
							;

tupla 				: '(' exp_l ')'
							;

func					: IDENTIFICADOR tupla
							| IDENTIFICADOR '(' ')'
							;

exp						: exp '-' exp
							| exp '+' exp
							| exp '/' exp
							| exp '*' exp
							| func
							| VALOR_INT
							| VALOR_FLOAT
							;



tipo					: tupla
							| INT
							| FLOAT
							| LONG
							| DOUBLE
							| BOOL
							| STRING
							;

ret_tipo			: tipo
							| VOID
							;


init					: tipo IDENTIFICADOR '=' exp
							;

asign					: IDENTIFICADOR '=' exp
							;

decl					: tipo IDENTIFICADOR
							;

inst					: exp
							| init
							| asign
							| decl
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
