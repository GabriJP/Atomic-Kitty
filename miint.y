/* bison -dt miint.y && flex milex.l && gcc -o micomp miint.tab.c lex.yy.c && ./micomp < fibo.aki */
//Sin yydebug
/* bison -dt miint.y && flex milex.l && sed -i '/^int yydebug \= 1\;/d' miint.tab.c  && g++ -Wno-write-strings -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fact.aki */
//Con yydebug
/* bison -dt miint.y && flex milex.l && sed -i '/^int yydebug;/d' miint.tab.c  && g++ -Wno-write-strings -o micomp Scope.cpp miint.tab.c lex.yy.c && ./micomp < fibo.aki */

/* bison -dt miint.y && flex milex.l && sed -i '/^int yydebug;/d' miint.tab.c  && g++ -Wno-write-strings -o micomp Scope.cpp Type.cpp MemManager.cpp CodeGeneration.cpp miint.tab.c lex.yy.c && ./micomp < fibo.aki */

%{


#include "Type.h"
#include "CodeGeneration.h"


extern FILE *yyin;

#define YYDEBUG 1
int yydebug = 1;

#if YYBISON
union YYSTYPE;
int yylex();
#endif

//Funciones
extern  void  yyerror(char *str);

%}


%code requires {
  #include "structs.h"
  #include "Scope.h"
  #include "MemManager.h"
  class ParameterNode;

}


%union { float f; double d; int i; long l; char c; char* str; Type* type; std::vector<ParameterNode*> *args_v; ValoresRango* valoresRango; }
%token <f> VALOR_FLOAT
%token <d> VALOR_DOUBLE
%token <i> VALOR_INT VALOR_BOOL ACCESO
%token <l> VALOR_LONG
%token <c> VALOR_CHAR
%token <str> VALOR_STRING IDENTIFICADOR
%token FIN_DE_LINEA INT LONG FLOAT DOUBLE BOOL STRING VOID CHAR WHEN WHEN_CASE IF ELIF ELSE WHILE FOR NOTIS IS OR AND RANGE RETURN ABREBLOQUE CIERRABLOQUE IN NOTIN MAYORIGUAL MENORIGUAL MAYORQUE MENORQUE TUPLE

%type  <type>  tipo tupla_decl tipo_l
%type  <str> func_call
%type  <args_v> args
%type  <i> ne elif_copia_salida elif_copia_siguiente
%type  <i> exp exp_l tupla comp
%type  <valoresRango> rango

%right '='
%left ','
%left IN
%left AND OR RANGE
%left IS NOTIS
%left MAYORIGUAL MENORIGUAL MAYORQUE MENORQUE
%left '-' '+'
%left '*' '/'

%%

lista				: error FIN_DE_LINEA {printf(" en expresión\n");} lista
					| FIN_DE_LINEA lista
					| func lista
					| inst_l FIN_DE_LINEA lista //TODO Solucionar
					| inst_l
              		|
					;

exp_l				: exp { $$ = $1; }
					| exp ',' exp_l { memStack.getType($3)->add( memStack.getType($1) ); $$ = $3; memStack.remove($1); }
					;

tupla 				: '(' exp_l ')' { $$ = $2; };
					;

tupla_decl			: '(' tipo_l ')' { $$ = $2; }
                    ;

func_call			: IDENTIFICADOR saveReg tupla { $<i>$ = callFunction($1, $3); memStack.loadRegisters(); }
					| IDENTIFICADOR saveReg '(' ')' { $<i>$ = callFunction($1, -1); memStack.loadRegisters(); }
					;

saveReg                 : { memStack.saveRegisters(); }

exp					: exp '-' exp { opera($1, $3, "-"); $$ = $1; }
					| exp '+' exp { opera($1, $3, "+"); $$ = $1; }
					| exp '/' exp { opera($1, $3, "/"); $$ = $1; }
					| exp '*' exp { opera($1, $3, "*"); $$ = $1; }
					| exp AND exp { opera($1, $3, "&&"); $$ = $1; }
					| exp OR exp  { opera($1, $3, "||"); $$ = $1; }
					| comp { $$ = $1; }
					| func_call { $$ = 0; //scope->getFunction($1)->getType(); //TODO Think about it
					    //returnLabels.push(ne());
					     //gc << "\tGT(" << scope->getFunction($1)->getLabel() << ");" //TODO Change!!
					     //"\t\t\t\t#Ir a función: " << $1 << "\nL " << returnLabels.top() << ":\t\t\t\t\t#Label para vuelta de funcion\n";
					     }
					| VALOR_INT { $$ = primitiveExp(INT, $1); } //TODO Añadir código tipo R0 = 2
					| VALOR_FLOAT { $$ = primitiveExp(FLOAT); }
					| VALOR_DOUBLE  { $$ = primitiveExp(DOUBLE); }
					| VALOR_LONG { $$ = primitiveExp(LONG); }
					| VALOR_BOOL { $$ = primitiveExp(BOOL); }
					| VALOR_CHAR { $$ = primitiveExp(CHAR); }
					| VALOR_STRING { $$ = primitiveExp(STRING); }
					| IDENTIFICADOR { memStack.load(scope->getVariable($1)->getId(), $$); }
					| tupla { $$ = $1; }
					| IDENTIFICADOR ACCESO {
					    VariableNode* var = scope->getVariable($1);

						if(var->getType()->isTuple()) ;
							//memStack.load(var->getId(), $$); //TODO Create new loadSub
						else
							yyerror("Acceso a una tupla");
					}
					;

tipo				: tupla_decl { $$ = $1; }
					| INT { $$ = new PrimitiveType(INT); }
					| FLOAT { $$ = new PrimitiveType(FLOAT); }
					| LONG { $$ = new PrimitiveType(LONG); }
					| DOUBLE { $$ = new PrimitiveType(DOUBLE); }
					| BOOL { $$ = new PrimitiveType(BOOL); }
					| STRING { $$ = new PrimitiveType(STRING); }
					| CHAR { $$ = new PrimitiveType(CHAR); }
					;

tipo_l				: tipo { $$ = $1; }
					| tipo ',' tipo_l { $$ = $3->add($1); }
					;

args				: tipo IDENTIFICADOR
                        { std::vector<ParameterNode*> *vector = new std::vector<ParameterNode*>();
                          vector->push_back(new ParameterNode($1, $2)); $$ = vector; } //TODO Change
					| tipo IDENTIFICADOR ',' args { $4->push_back(new ParameterNode($1, $2)); $$ = $4; }
					;

init				: tipo IDENTIFICADOR '=' exp {
                                                            if (scope->haveVariable($2)) {
                                                                logError("Se intenta crear '" + std::string($2) + "', pero ya existe.");
                                                            } else {
                                                                int id = addNewVar($1, $2);
                                                                memStack.asign(id, $4);
                                                            }
						}
					;

asign				: IDENTIFICADOR '=' exp {
                                                            if (!scope->existsVariable($1)) {
                                                                logError("Se intenta usar '" + std::string($1) + "', pero no existe.");
                                                            } else {
                                                                memStack.asign(scope->getVariable($1)->getId(), $3);
                                                            }
							}
					;

decl				: tipo IDENTIFICADOR FIN_DE_LINEA{
                                                            if (scope->haveVariable($2)) {
                                                                logError("Se intenta crear '" + std::string($2) + "', pero ya existe.");
                                                            } else {
                                                                addNewVar($1, $2);
                                                            }
						}
					;


comp				: exp MENORQUE exp { opera($1, $3, "<"); $$ = primitiveExp(BOOL); }
					| exp MAYORQUE exp { opera($1, $3, ">"); $$ = primitiveExp(BOOL); }
					| exp MENORIGUAL exp { opera($1, $3, "<="); $$ = primitiveExp(BOOL); }
					| exp MAYORIGUAL exp { opera($1, $3, ">="); $$ = primitiveExp(BOOL); }
					| exp IS exp { opera($1, $3, "=="); $$ = primitiveExp(BOOL); }
					| exp NOTIS exp { opera($1, $3, "!="); $$ = primitiveExp(BOOL); }
					;

inst				: exp FIN_DE_LINEA
					| init FIN_DE_LINEA
					| asign FIN_DE_LINEA
					| decl
					| when
					| for
					| while
					| if
					| bloque
					| RETURN exp FIN_DE_LINEA {gc << "#Aquí hay un RETURN\n";}
					;

inst_l				: inst
					| inst inst_l
					;

bloque          	: ABREBLOQUE
            				  { scope = new Scope(scope); }
            				  dentroBloque
            				  CIERRABLOQUE
            				  {
            					Scope* oldScope = scope;
            					scope = scope->getParent();
            					delete oldScope;
            				  }
          				;

dentroBloque      	: inst_l
            		;

func				: tipo IDENTIFICADOR '(' ')'  {
                             $<i>$ = createFunction($2, $1, NULL);
						} ':' FIN_DE_LINEA bloque funcFinal
					| tipo IDENTIFICADOR '(' args ')'  {
					std::cout << "FUUUUNC!";
                            $<i>$ = createFunction($2, $1, $4);
					        } ':' FIN_DE_LINEA bloque funcFinal
					| VOID IDENTIFICADOR '(' ')' {
                            $<i>$ = createFunction($2, new PrimitiveType(VOID), NULL);
					        } ':' FIN_DE_LINEA bloque funcFinal
					| VOID IDENTIFICADOR '(' args ')' {
                            $<i>$ = createFunction($2, new PrimitiveType(VOID), $4);
					        } ':' FIN_DE_LINEA bloque funcFinal
					;

funcFinal           : { gc << "L " << $<i>-3 << ": #End of function\n\n"; }

cases				: exp WHEN_CASE exp
					| exp WHEN_CASE exp FIN_DE_LINEA cases
					;

when				: WHEN exp ':' FIN_DE_LINEA ABREBLOQUE cases CIERRABLOQUE
					| WHEN rango ':' FIN_DE_LINEA ABREBLOQUE cases CIERRABLOQUE
					;

for					: FOR IDENTIFICADOR IN rango ne[vuelta] ne[salida] ':' FIN_DE_LINEA {
                        /*crear variable identificador si no existe, asignarle el valor de inicio menos paso, label vuelta,
                         identificador+=paso, comprobar que sea menor que fin y hacer bloque o ir a salida*/} bloque
                         { gc << "\tGT(" << $vuelta << ");\nL " << $salida << ":\n"; }
					;





if					: IF exp ':' FIN_DE_LINEA ne[salida] if_evalua_expresion bloque
                        {gc << "L " << $salida << ":\t\t\t#Label salida if\n";}
					| IF exp ':' FIN_DE_LINEA ne[elif] if_evalua_expresion bloque ne[salida]
					    { $<i>$=$<i>elif; } elif_l {gc << "L " << $salida << ":\t\t\t\t\t\t#Label salida if\n"; }
					;

/*ELIF. $0=fin elif -> donde se va si no se cumple la condición / $-1=salida if -> donde se va al acabar un bloque */

elif_l				: ELIF exp ':' FIN_DE_LINEA ne[fin] elif_control bloque
                        {gc << "L %d:\t\t#Se termina el bloque del if y se sale\n", $fin;}
					| ELIF exp ':' FIN_DE_LINEA ne[siguiente_elif] elif_control bloque
                        elif_copia_salida elif_copia_siguiente elif_l
					| ELSE ':' FIN_DE_LINEA
					    { gc << "\tGT(" << $<i>-1 << ");\t\t\t\t\t#Ir a salida\nL " << $<i>0 << ":\t\t\t\t\t\t#Label del else\n";} bloque
					;


/*Genera una etiqueta nueva*/
ne					: { $<i>$ = ne(); }
					;

/* Ir a salida, Si (!cond) ir a siguiente elif/else/salida */
elif_control		: { gc << "\tGT  (" << $<i>-6 << ");\t\t#Fin bloque y salida a fin del if\n"
                        "L " <<  $<i>-5 << ":\t\t\t#Label de este elif\n"
                        "\tIF(!" << memStack.load($<i>-3) << ") "
                        "GT(" << $<i>0 << ");\t#Si no se cumple la condición se va al siguiente elif\n"; }
					;

/*Evalua expresión en $-3 y si no se cumple salta a $0*/
if_evalua_expresion	: { gc << "\tIF(!" << memStack.load($<i>-3) << ") GT(" << $<i>0 << ");\t\t\t#Comprobación condición if\n";
                        memStack.remove($<i>-3);
                      }
					;

/*Copia el valor de $-8, que corresponde con la salida del elif*/
elif_copia_salida	: { $$ = $<i>-8; /*($-1 del anterior)*/ }
					;

/*Copia del valor de $-3, util en el elif que lleva otro elif despues*/
elif_copia_siguiente: { $$ = $<i>-3; }
					;

/*FIN ELIF*/


while				: WHILE ne[salida] ne[vuelta] { gc << "L " << $vuelta << ":\n"; } exp ':'
                    { gc << "\tIF(!R " << memStack.load($exp) << ") GT(" << $salida << ");\n"; } FIN_DE_LINEA
                    bloque { gc << "\tGT(" << $vuelta << ");\nL " << $salida << ":\n"; }
					;

rango				: exp[inicio] RANGE exp[fin] { ValoresRango valoresRango = {memStack.getType($inicio), memStack.getType($fin), new PrimitiveType(INT)}; $$=&valoresRango; }
					| exp[inicio] RANGE exp[fin] ',' exp[paso] { ValoresRango valoresRango = {memStack.getType($inicio), memStack.getType($fin), memStack.getType($paso)}; $$=&valoresRango; }
					;
%%

int main(int argc, char **argv) {

    scope = new Scope();

//Funciones del sistema
    scope->defineFunction("print", new FunctionNode(new PrimitiveType(VOID)));
    scope->defineFunction("getchar", new FunctionNode(new PrimitiveType(CHAR)));
    if(argc <= 1) return -1;

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        return -2;
    }
    initQ();

    std::cout << "Compiling " << argv[1] << "...\n";
    //try{
        yyparse();
    /**}catch(const std::exception& e) {
        std::cout << "Unexpected error" << e.what() << "\n";
        gc.flush();
        gc.close();
        fclose(yyin);
        exit(-3);
    }*/
    gc << "\tR0=0;\t\t\t\t\t#Código de salida\n\tGT(-2);\t\t\t\t\t#Fin de programa";
    gc.close();
    fclose(yyin);
}


