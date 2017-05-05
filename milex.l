/* scanner for a toy Pascal-like language */



%{
/* need this for the call to atof() below */
#include <math.h>
#include <cstdlib>
#include "Scope.h"
#include "structs.h"
#include "miint.tab.h"

/*#define VALOR_INT 257
#define VALOR_FLOAT 258
#define ABREBLOQUE 259
#define CIERRABLOQUE 260
#define INT 261
#define FLOAT 262
#define LONG 263
#define DOUBLE 264
#define CHAR 265
#define BOOL 266
#define VOID 267
#define STRING 278
#define FIN_DE_LINEA 279
#define IF 280
#define WHILE 281
#define FOR 282
#define WHEN 283
#define ELSE 284
#define ELIF 285
#define NOTIS 286
#define IS 287
#define IN 288
#define OR 289
#define RANGE 290
#define RETURN 291
#define VALOR_CHAR 292
#define VALOR_STRING 293
#define VALOR_BOOL 294
#define WHEN_CASE 295
#define IDENTIFICADOR 296
#define ACCESO 297
*/
#define YY_USER_ACTION                                   \
{                                                        \
  if (tabulado<numtabs){                                 \
      numtabs--;                                         \
    yyless(0);                                           \
    return CIERRABLOQUE;                                 \
  } else if (tabulado>numtabs){                          \
      numtabs++;                                         \
    yyless(0);                                           \
    return ABREBLOQUE;                                   \
  }                                                      \
}                                                        \

int tabulado = 0;
int numtabs = 0;
int fines = 0;
%}
%option noyywrap
FINLINEA                                                 [ \t]*\n
DIGIT                                                    [0-9]
LETTER                                                   [a-zA-Z]
WORD                                                     {LETTER}|{DIGIT}
IDENTIFIER                                               {LETTER}{WORD}*
ENTERO                                                   {DIGIT}+
FLOTANTE                                                 {ENTERO}("."{DIGIT}+)?
TABULADOR                                                \t|"    "
ABREPAR                                                  "("
CIERRAPAR                                                ")"
OPERADOR                                                 [=/+*-]
MAYORIGUAL                                               >=
MENORIGUAL                                               <=
ISNOT                                                    is not
IS                                                       is
MENORQUE                                                 <
MAYORQUE                                                 >
ESPACIO                                                  [ \t]+
COMENTARIO                                               #[^\n]*
ACCESO                                                   \[{ENTERO}\]
EOF                                                      <<EOF>>
PRIMITIVE                                                int|long|float|double|char|string|bool
SPACE_PRIMITIVE                                          {ESPACIO}*PRIMITIVE{ESPACIO}*
TUPLA                                                    "("({SPACE_PRIMITIVE},)*{SPACE_PRIMITIVE}")"
VISIBLE                                                  \n|{WORD}|\s{1,3}|{ABREPAR}


%%


\n[^\t\n ]|\n" "[^ \n]|\n"  "[^ \n]|\n"   "[^ \n]         {
                                                             tabulado = 0;
                                                             yyless(yyleng - 1);
                                                             fines++;
                                                         }

\n                                                       {
                                                             fines++;
                                                             return FIN_DE_LINEA;
                                                         }

^{TABULADOR}+             	                         {
                                                             int i;
                                                             int tabsEncontrados = 0;
                                                             for (i = 0; yytext[i] != '\0'; i++){
                                                                 if (yytext[i] == ' '){
                                                                     i += 3;
                                                                 }
                                                                 tabsEncontrados++;
                                                             }
                                                             tabulado = tabsEncontrados;
                                                         }

{ESPACIO}|{COMENTARIO}                                   {}


"\"".*"\""                                               {
                                                             yylval.i = yyleng;
                                                             return VALOR_STRING;
                                                         }

"\'"(.|\\.)"\'"                                          {
                                                             printf("Carácter: %s\n", yytext);
                                                             return VALOR_CHAR;
                                                         }


int                                                      {
                                                             return INT;
                                                         }

float                                                    {
                                                             return FLOAT;
                                                         }

long                                                     {
                                                             return LONG;
                                                         }

double                                                   {
                                                             return DOUBLE;
                                                         }

char                                                     {
                                                             return CHAR;
                                                         }

bool                                                     {
                                                             return BOOL;
                                                         }

void                                                     {
                                                             return VOID;
                                                         }

string                                                   {
                                                             return STRING;
                                                         }

{ENTERO}                                                 {
                                                             return VALOR_INT;
                                                         }

{FLOTANTE}                                               {
                                                             return VALOR_FLOAT;
                                                         }

"\->"                                                    {
                                                             return WHEN_CASE;
                                                         }

{OPERADOR}                                               {
                                                             return yytext[0];
                                                         }

"true"|"false"                                           {
                                                             return VALOR_BOOL;
                                                         }

{ACCESO}						 {
							     yylval.i = std::atoi(yytext+1);
							     printf("%i<------------------------------------------------------------------ \n", yylval.i);
							     return ACCESO;
							 }

if                                                       {
                                                             return IF;
                                                         }

while                                                    {
                                                             return WHILE;
                                                         }

for                                                      {
                                                             return FOR;
                                                         }

when                                                     {
                                                             return WHEN;
                                                         }

else                                                     {
                                                             return ELSE;
                                                         }

elif                                                     {
                                                             return ELIF;
                                                         }

"not is"                                                 {
                                                             return NOTIS;
                                                         }

is                                                       {
                                                             return IS;
                                                         }

or                                                       {
                                                             return OR;
                                                         }

and                                                       {
                                                             return AND;
                                                         }

in							 {
							     return IN;
							 }

{MENORQUE}						 {
							     return MENORQUE;
							 }

{MAYORQUE}						 {
							     return MAYORQUE;
							 }

{MENORIGUAL}						 {
							     return MENORIGUAL;
							 }

{MAYORIGUAL}						 {
							     return MAYORIGUAL;
							 }

".."                                                     {
                                                             return RANGE;
                                                         }

"return"                                                 {
                                                             return RETURN;
                                                         }

{IDENTIFIER}                                             {
                                                             yylval.str = strdup(yytext);
                                                             return IDENTIFICADOR;
                                                         }

":"|","|{ABREPAR}|{CIERRAPAR}                            {
                                                             return yytext[0];
                                                         }

\r                                                       { }


<<EOF>>                                                  {
                                                             tabulado = 0;
                                                             if(tabulado<numtabs){
                                                                 numtabs--;
                                                                 return CIERRABLOQUE;
                                                             } else {
                                                                 return 0;
                                                             }
                                                         }



.                                                        {
                                                             printf( "Unrecognized character: %s\n", yytext );
                                                         }

%%

/*int main(int argc, char** argv){
	int s;
	if(argc>1) yyin=fopen(argv[1],"r");
	do printf("%i ",s=yylex());
	while(s != 0);
  return 0;
}*/
