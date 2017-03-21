/* scanner for a toy Pascal-like language */

%option noyywrap

%{
/* need this for the call to atof() below */
#include <math.h>
#include "miint.tab.h"


#define YY_USER_ACTION                                   \
{                                                        \
  if (tabulado<numtabs){                                 \
      printf("CIERRABLOQUE %d %d\n", tabulado, numtabs); \
      numtabs--;                                         \
    yyless(0);                                           \
    return CIERRABLOQUE;                                 \
  } else if (tabulado>numtabs){                          \
      printf("ABREBLOQUE %d %d\n", tabulado, numtabs);   \
      numtabs++;                                         \
    yyless(0);                                           \
    return ABREBLOQUE;                                   \
  }                                                      \
}                                                        \

int tabulado = 0;
int numtabs = 0;

%}

FINLINEA                                                 [ \t]*\n
DIGIT                                                    [0-9]
LETTER                                                   [a-zA-Z]
WORD                                                     {LETTER}|{DIGIT}
IDENTIFIER                                               {LETTER}{WORD}*
ENTERO                                                   {DIGIT}+
FLOTANTE                                                 {ENTERO}("."{DIGIT}+)?
TABULADOR                                                \t|(" "{4})
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


%%


\n{WORD}                                                 {
                                                             tabulado = 0;
                                                             yyless(1);
                                                             return FIN_DE_LINEA;
                                                         }

\n                                                       {
                                                             return FIN_DE_LINEA;
                                                         }

^{TABULADOR}+/{WORD}                                     {
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
                                                             printf("String: %s\n", yytext);
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

in							 {
							     return IN;
							 }

"not is" 						 {
							     return NOTIS;
							 }

".."                                                     {
                                                             return RANGE;
                                                         }

"return"                                                 {
                                                             return RETURN;
                                                         }

{IDENTIFIER}                                             {
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
