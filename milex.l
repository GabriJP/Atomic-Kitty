/* scanner for a toy Pascal-like language */

%option noyywrap

%{
/* need this for the call to atof() below */
#include <math.h>

#define VALOR_INT 257
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
#define WHEN_CASE 294

#define YY_USER_ACTION																	\
{																											\
  if (tabulado<numtabs){																				\
  	printf("CIERRABLOQUE %d %d\n", tabulado, numtabs);															\
  	numtabs--;																					\
    yyless(0);																			\
    return CIERRABLOQUE;																	\
  } else if (tabulado>numtabs){																\
  	printf("ABREBLOQUE %d %d\n", tabulado, numtabs);															\
  	numtabs++;																					\
	yyless(0);																			\
    return ABREBLOQUE;																\
  }																											\
}																												\

int tabulado = 0;
int numtabs = 0;

%}

FINLINEA															[ \t]*\n
DIGIT      														[0-9]
LETTER     														[a-zA-Z]
WORD															{LETTER}|{DIGIT}
IDENTIFIER 														{LETTER}{WORD}*
ENTERO 	   														[+-]?{DIGIT}+
FLOTANTE															[+-]?{ENTERO}("."{DIGIT}+)?
TABULADOR															\t|(" "{4})
ABREPAR																"("
CIERRAPAR															")"
OPERADOR															["=""+""\-""*""/"]
MAYORIGUAL														>=
MENORIGUAL														<=
ISNOT																	is not
IS																		is
MENORQUE															<
MAYORQUE															>
ESPACIO																[ \t]+
COMENTARIO														#[^\n]*
ACCESO																\[{ENTERO}\]
EOF																		<<EOF>>
PRIMITIVE															int|long|float|double|char|string|bool
SPACE_PRIMITIVE												{ESPACIO}*PRIMITIVE{ESPACIO}*
TUPLA																	"("({SPACE_PRIMITIVE},)*{SPACE_PRIMITIVE}")"


%%


\n{WORD}												{
  																			tabulado = 0;
  																			yyless(1);
																			}

\n																		{
  																			printf( "FINLINEA\n");
																				return FIN_DE_LINEA;
																			}

^{TABULADOR}+/{WORD}									{
  																			int i;
																			int tabsEncontrados = 0;
																				for (i = 0; yytext[i] != '\0'; i++){
																					if (yytext[i] == ' '){
																						i += 3;
																					}
																					tabsEncontrados++;
																				}
  																			tabulado = tabsEncontrados;
  																			printf("ANALIZO TABS %d %d\n", tabsEncontrados, tabulado);
																			//printf( "I found: %s\n", yytext );
																			//yyless(1);
																			}

{ESPACIO}|{COMENTARIO}								{}


"\"".*"\""											{
															printf("String: %s\n", yytext);
															return VALOR_STRING;
														}

"\'"(.|\\.)"\'"											{
															printf("Carácter: %s\n", yytext);
															return VALOR_CHAR;
														}


{ACCESO}															{
  																			printf("Un acceso por indice: %s\n", yytext);
																			}


int																		{
  																			printf( "Primitive int\n");
																				return INT;
																			}

float																	{
  																			printf( "Primitive float\n");
																				return FLOAT;
																			}

long																	{
  																			printf( "Primitive long\n");
																				return LONG;
																			}

double																{
                                        printf( "Primitive double\n");
																				return DOUBLE;
																			}

char																	{
                                        printf( "Primitive char\n");
																				return CHAR;
																			}

bool																	{
                                        printf( "Primitive bool\n");
																				return BOOL;
																			}

void																	{
                                        printf( "Primitive void\n");
																				return VOID;
																			}

string																{
                                        printf( "Primitive string\n");
																				return STRING;
																			}

{TUPLA}																{
																				printf("Tupla: %s", yytext);
																			}

{ENTERO}															{
																				printf("Entero: %d\n", atoi( yytext ));
																				return VALOR_INT;
																			}

{FLOTANTE}														{
																				printf( "A float: %g\n", atof( yytext ) );
																				return VALOR_FLOAT;
																			}

"\->"															{
																				printf( "An operator: %s\n", yytext );
																				return WHEN_CASE;
																			}

{OPERADOR}														{
																				printf( "An operator: %s\n", yytext );
																				return yytext[0];
																			}

"true"|"false"                        {
											            		  printf( "A bool: %s\n", yytext );
                                        return VALOR_BOOL;
                                      }

if                                    {
											            		  printf( "A keyword: %s\n", yytext );
                                        return IF;
                                      }

while                                 {
                                        printf( "A keyword: %s\n", yytext );
                                        return WHILE;
                                      }

for                                   {
                                        printf( "A keyword: %s\n", yytext );
                                        return FOR;  
                                      }

when                                  {
                                        printf( "A keyword: %s\n", yytext );
                                        return WHEN;  
                                      }

else                                  {
                                        printf( "A keyword: %s\n", yytext );
                                        return ELSE;  
                                      }									  

elif                                  {
                                        printf( "A keyword: %s\n", yytext );
                                        return ELIF;  
                                      }	
									  
"not is"                              {
                                        printf( "A keyword: %s\n", yytext );
                                        return NOTIS;  
                                      }	
									  
is                                    {
                                        printf( "A keyword: %s\n", yytext );
                                        return IS;  
                                      }										  
									  
or                                    {
                                        printf( "A keyword: %s\n", yytext );
                                        return OR;  
                                      }	

"..."                                 {
                                        printf( "A keyword: %s\n", yytext );
                                        return RANGE;  
                                      }	

"return"                              {
                                        printf( "A keyword: %s\n", yytext );
                                        return RETURN;  
                                      }	
									  
{IDENTIFIER} 						  {
										printf( "An identifier: %s\n", yytext );
																			}

":"|","|{ABREPAR}|{CIERRAPAR}		  {
  										printf("A token: %s\n", yytext);
										return yytext[0];
									  }


\r										{ }


 
<<EOF>> 								{
													 tabulado = 0;
													 if(tabulado<numtabs){
														 printf("CIERRABLOQUE EOF %d %d\n", tabulado, numtabs);	
														 numtabs--;
														 return CIERRABLOQUE;
													 } else {
														 printf("EOF\n");	
														 return 0;
													 }
										}



.           							{
													 printf( "Unrecognized character: %s\n", yytext );
										}

%%

int main(int argc, char** argv){
	int s;
	if(argc>1) yyin=fopen(argv[1],"r");
	do printf("%i ",s=yylex());
	while(s != 0);
  return 0;
}
