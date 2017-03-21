%{
#include <stdio.h>
extern FILE *yyin;
extern int numlin;
%}

%union { float real; int entero; }
%token <real> REAL
%token <entero> ENTERO
%type <real> exp
%left '-'
%left '*'

%%

lista : exp {printf("%f\n", $1 );} ';' lista
	|	
	| error ';' {printf(" en expresión\n")} lista
	;


exp	: exp '-' exp	{$$ = $1 - $3;}
	| exp '*' exp	{$$ = $1 * $3;}
	| REAL		{$$ = $1;}
	| ENTERO	{$$ = $1;}
	;

%%

int main(int argc, char** argv) {
	if (argc>1) yyin=fopen(argv[1],"r");
	yyparse();
}

void yyerror(char* mens)
{
	printf("Error en linea %i: %s ",numlin,mens);
}
