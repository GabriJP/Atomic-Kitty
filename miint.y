%{
#include <stdio.h>
#include <stdlib.h>
extern  void  yyerror(char *);
extern FILE *yyin;
int yydebug=1;
%}

%union { float real; int entero; char op; }
%token <real> VALOR_FLOAT
%token <entero> VALOR_INT
%token <entero> OP
%token FIN_DE_LINEA
%type <real> expf
%type <entero> expi
%left '-' '+'
%left '*' '/'

%%




lista	: exp {printf("%d\n", $1 );} FIN_DE_LINEA lista
	|	
	| error FIN_DE_LINEA {printf(" en expresión\n")} lista
	;
int a=2*(4);
int a  = 1
a = 3

list	: exp
	| exp ',' list
	;

A : A x | y ;  y1 x x x   y2 x x x  y1 y2 
 
A : x A | y ;  x x x y   y

exp , exp , exp   exp


fun	: ID ABREPA list CIERRAPAR
	| ID ABREPA CIERRAPAR
	;

exp	: exp '-' exp	
	| exp '+' exp	
	| exp '/' exp	
	| exp '*' exp
	| fun
	| VALOR_INT
	| VALOR_FLOAT
	;


init	: PRIM ID IGUAL exp
	;

asign	: ID IGUAL exp
	;

decl	: PRIM ID
	;

inst	: exp
	|init


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
