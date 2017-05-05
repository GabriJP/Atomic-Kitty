/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 6 "miint.y" /* yacc.c:339  */

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include "MemManager.h"
#include "structs.h"


//Variable globales
MemManager* memoria;
Scope *scope;
FILE* qFile;
int ec = 1;

extern FILE *yyin;
extern int fines;

#if YYBISON
union YYSTYPE;
int yylex();
#endif



//Funciones
void logError(std::string str);
void creaFuncion(char* nombre, Type* returnType, std::vector<ParameterNode*> *v = new std::vector<ParameterNode*>());
bool isNumberType(Type* tipo);
void gc(const char* code, ...)	;
int ne();
PrimitiveType* creaPrimitivo(int tipo);
extern  void  yyerror(char *);


#line 101 "miint.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "miint.tab.h".  */
#ifndef YY_YY_MIINT_TAB_H_INCLUDED
# define YY_YY_MIINT_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VALOR_FLOAT = 258,
    VALOR_DOUBLE = 259,
    VALOR_INT = 260,
    VALOR_BOOL = 261,
    ACCESO = 262,
    VALOR_LONG = 263,
    VALOR_CHAR = 264,
    VALOR_STRING = 265,
    IDENTIFICADOR = 266,
    FIN_DE_LINEA = 267,
    INT = 268,
    LONG = 269,
    FLOAT = 270,
    DOUBLE = 271,
    BOOL = 272,
    STRING = 273,
    VOID = 274,
    CHAR = 275,
    WHEN = 276,
    WHEN_CASE = 277,
    IF = 278,
    ELIF = 279,
    ELSE = 280,
    WHILE = 281,
    FOR = 282,
    NOTIS = 283,
    IS = 284,
    OR = 285,
    AND = 286,
    RANGE = 287,
    RETURN = 288,
    ABREBLOQUE = 289,
    CIERRABLOQUE = 290,
    IN = 291,
    NOTIN = 292,
    MAYORIGUAL = 293,
    MENORIGUAL = 294,
    MAYORQUE = 295,
    MENORQUE = 296,
    TUPLE = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "miint.y" /* yacc.c:355  */
 float f; double d; int i; long l; char c; char* str; Type* type; std::vector<ParameterNode*> *args_v; ValoresRango* valoresRango; 

#line 187 "miint.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MIINT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "miint.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   570

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,    50,    47,    46,    44,    45,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,     2,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    67,    68,    69,    70,    71,    72,    75,
      76,    79,    82,    84,    85,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   115,   116,   117,   118,   119,   120,   121,
     122,   125,   126,   129,   130,   133,   142,   149,   159,   160,
     161,   162,   163,   164,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   179,   180,   184,   183,   194,   197,
     197,   200,   200,   203,   203,   206,   206,   211,   212,   215,
     216,   219,   219,   226,   227,   227,   232,   233,   234,   234,
     239,   243,   247,   251,   255,   261,   261,   261,   264,   265
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VALOR_FLOAT", "VALOR_DOUBLE",
  "VALOR_INT", "VALOR_BOOL", "ACCESO", "VALOR_LONG", "VALOR_CHAR",
  "VALOR_STRING", "IDENTIFICADOR", "FIN_DE_LINEA", "INT", "LONG", "FLOAT",
  "DOUBLE", "BOOL", "STRING", "VOID", "CHAR", "WHEN", "WHEN_CASE", "IF",
  "ELIF", "ELSE", "WHILE", "FOR", "NOTIS", "IS", "OR", "AND", "RANGE",
  "RETURN", "ABREBLOQUE", "CIERRABLOQUE", "IN", "NOTIN", "MAYORIGUAL",
  "MENORIGUAL", "MAYORQUE", "MENORQUE", "TUPLE", "'='", "','", "'-'",
  "'+'", "'*'", "'/'", "'('", "')'", "':'", "$accept", "lista", "$@1",
  "exp_l", "tupla", "tupla_decl", "func_call", "exp", "tipo", "tipo_l",
  "args", "init", "asign", "decl", "comp", "inst", "inst_l", "bloque",
  "$@2", "dentroBloque", "func", "$@3", "$@4", "$@5", "$@6", "cases",
  "when", "for", "$@7", "if", "@8", "elif_l", "$@9", "ne", "elif_control",
  "if_evalua_expresion", "elif_copia_salida", "elif_copia_siguiente",
  "while", "$@10", "$@11", "rango", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    61,    44,    45,    43,    42,    47,    40,
      41,    58
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -94

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     165,    32,  -136,  -136,  -136,  -136,  -136,  -136,  -136,    36,
     165,  -136,  -136,  -136,  -136,  -136,  -136,    18,  -136,    59,
      59,  -136,    35,    59,  -136,   239,    75,  -136,  -136,  -136,
     246,    48,    68,    71,    74,  -136,   202,    76,  -136,   165,
    -136,  -136,  -136,  -136,  -136,  -136,    59,    11,  -136,  -136,
      38,    23,    59,   349,    39,   373,  -136,    53,   270,   202,
      41,   445,    50,    45,  -136,  -136,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,   -31,  -136,
    -136,  -136,    93,  -136,   165,  -136,   165,   508,  -136,    85,
      59,    94,    95,    99,  -136,    59,  -136,  -136,    77,  -136,
      59,   327,  -136,   155,   155,   522,   522,   -22,   -22,   -22,
     -22,   -37,   -37,  -136,  -136,    59,   247,    73,  -136,  -136,
     327,  -136,   103,    67,   466,    84,    86,  -136,    59,   487,
    -136,  -136,  -136,  -136,   508,  -136,    69,    78,    81,  -136,
      59,    59,    59,  -136,   397,  -136,    80,  -136,   116,   327,
      88,   508,   324,    97,   101,   106,  -136,    91,   125,    92,
     106,  -136,   133,    59,  -136,  -136,    10,   134,   135,   106,
     136,  -136,   106,   291,  -136,   106,  -136,  -136,   106,  -136,
      59,    15,  -136,   106,  -136,  -136,    59,    98,  -136,  -136,
     421,   139,   140,  -136,  -136,   106,  -136,  -136,   106,    17,
    -136,    15,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    24,    25,    23,    27,    26,    28,    29,    30,
       0,    34,    36,    35,    37,    38,    39,     0,    40,     0,
       0,    90,     0,     0,    66,     0,     0,    31,    33,    22,
       0,     0,     0,     0,     0,    21,    64,     8,    62,     0,
      58,    59,    61,    60,     2,    32,     0,     0,    13,     4,
       0,    30,     0,     0,     0,     0,    90,     0,     0,     0,
       0,     9,    41,     0,     1,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    55,
      56,    57,     0,    65,     0,     6,     0,    46,    14,     0,
       0,     0,     0,     0,    95,     0,    63,    68,     0,    11,
       0,     0,    12,    53,    52,    20,    19,    51,    50,    49,
      48,    15,    16,    18,    17,     0,     0,    47,     7,     3,
       0,    73,     0,     0,    98,     0,     0,    90,     0,     0,
      90,    67,    10,    42,    45,    69,     0,     0,    43,    75,
       0,     0,     0,    92,     0,    90,     0,    71,     0,     0,
       0,    99,     0,     0,     0,     0,    96,     0,     0,     0,
       0,    44,     0,     0,    79,    80,    83,     0,     0,     0,
       0,    74,     0,    77,    84,     0,    81,    70,     0,    76,
       0,     0,    97,     0,    72,    78,     0,     0,    85,    82,
       0,     0,     0,    88,    90,     0,    91,    89,     0,    86,
      94,     0,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,    -2,  -136,    54,    22,  -136,  -136,   -19,   -23,    55,
    -111,  -136,  -136,  -136,  -136,  -136,   -27,   -45,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -135,  -136,  -136,  -136,  -136,
    -136,   -46,  -136,   -53,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,    62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    86,    60,    27,    28,    29,    30,    31,    63,
     123,    32,    33,    34,    35,    36,    37,    38,    59,    98,
      39,   146,   159,   137,   150,   153,    40,    41,   183,    42,
     181,   188,   195,    56,   198,   155,   200,   201,    43,   128,
     167,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    55,    62,    94,    58,   136,    61,   154,    49,    83,
      76,    77,   115,    82,     2,     3,     4,     5,   116,     6,
       7,     8,    51,    74,    75,    76,    77,    87,    61,    50,
      45,    48,    97,    61,   -90,   -90,    82,    85,   161,   186,
     187,   -93,   -93,    45,    44,   185,    57,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    78,
      52,    88,     2,     3,     4,     5,   122,     6,     7,     8,
      51,   124,    47,    48,   143,    64,   129,   145,    62,    46,
      79,    61,   118,    80,   119,    47,    81,    89,    84,    95,
      92,    99,   157,   122,   101,   102,   134,    62,    11,    12,
      13,    14,    15,    16,   117,    18,   125,   126,    52,   144,
     166,   127,   131,   174,   138,   171,   115,   139,   141,   147,
     142,   151,   152,   152,   177,   149,   122,   179,   160,   148,
     182,   158,   164,   184,   120,   121,   165,   169,   189,   162,
      24,   196,   168,   170,   173,   172,   175,   176,   178,   191,
     197,   193,   194,   199,   132,   202,   133,   130,     0,     0,
       0,   152,     0,     0,     0,    -5,     1,   190,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,     0,
       0,    21,    22,    70,    71,    72,    73,     0,    23,    24,
      74,    75,    76,    77,     0,     2,     3,     4,     5,     0,
       6,     7,     8,     9,    25,    11,    12,    13,    14,    15,
      16,     0,    18,    19,     0,    20,     0,     0,    21,    22,
       0,     0,     0,     0,     0,    23,    24,     0,     0,     0,
       0,     0,     2,     3,     4,     5,     0,     6,     7,     8,
      51,    25,    11,    12,    13,    14,    15,    16,    65,    18,
      11,    12,    13,    14,    15,    16,     0,    18,     0,     0,
       0,     0,     0,     0,    66,    67,    68,    69,     0,     0,
       0,     0,    96,     0,    70,    71,    72,    73,    25,     0,
       0,    74,    75,    76,    77,     0,   120,   135,    66,    67,
      68,    69,     0,   180,     0,     0,     0,     0,    70,    71,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
      71,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      11,    12,    13,    14,    15,    16,   163,    18,     0,     0,
       0,     0,    66,    67,    68,    69,     0,     0,     0,     0,
       0,     0,    70,    71,    72,    73,     0,     0,     0,    74,
      75,    76,    77,     0,     0,     0,   120,    66,    67,    68,
      69,    90,     0,     0,     0,     0,     0,    70,    71,    72,
      73,     0,     0,     0,    74,    75,    76,    77,     0,     0,
      91,    66,    67,    68,    69,     0,     0,     0,     0,     0,
       0,    70,    71,    72,    73,     0,     0,     0,    74,    75,
      76,    77,     0,     0,    93,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,    70,    71,    72,    73,     0,
       0,     0,    74,    75,    76,    77,     0,     0,   156,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    70,
      71,    72,    73,     0,     0,     0,    74,    75,    76,    77,
       0,     0,   192,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,    70,    71,    72,    73,     0,     0,   100,
      74,    75,    76,    77,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,    70,    71,    72,    73,     0,     0,
     140,    74,    75,    76,    77,    66,    67,    68,    69,    90,
       0,     0,     0,     0,     0,    70,    71,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    66,    67,    68,    69,
       0,     0,     0,     0,     0,     0,    70,    71,    72,    73,
      66,    67,     0,    74,    75,    76,    77,     0,     0,     0,
      70,    71,    72,    73,     0,     0,     0,    74,    75,    76,
      77
};

static const yytype_int16 yycheck[] =
{
      19,    20,    25,    56,    23,   116,    25,   142,    10,    36,
      47,    48,    43,    36,     3,     4,     5,     6,    49,     8,
       9,    10,    11,    45,    46,    47,    48,    46,    47,    11,
       7,     9,    59,    52,    24,    25,    59,    39,   149,    24,
      25,    24,    25,     7,    12,   180,    11,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    11,
      49,    50,     3,     4,     5,     6,    89,     8,     9,    10,
      11,    90,    49,    51,   127,     0,    95,   130,   101,    43,
      12,   100,    84,    12,    86,    49,    12,    49,    12,    36,
      51,    50,   145,   116,    44,    50,   115,   120,    13,    14,
      15,    16,    17,    18,    11,    20,    12,    12,    49,   128,
     155,    12,    35,   166,    11,   160,    43,    50,    34,    50,
      34,   140,   141,   142,   169,    44,   149,   172,    12,    51,
     175,    51,    35,   178,    49,    50,    35,    12,   183,    51,
      34,   194,    51,    51,   163,    12,    12,    12,    12,    51,
     195,    12,    12,   198,   100,   201,   101,    95,    -1,    -1,
      -1,   180,    -1,    -1,    -1,     0,     1,   186,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    23,    -1,
      -1,    26,    27,    38,    39,    40,    41,    -1,    33,    34,
      45,    46,    47,    48,    -1,     3,     4,     5,     6,    -1,
       8,     9,    10,    11,    49,    13,    14,    15,    16,    17,
      18,    -1,    20,    21,    -1,    23,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    49,    13,    14,    15,    16,    17,    18,    12,    20,
      13,    14,    15,    16,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    12,    -1,    38,    39,    40,    41,    49,    -1,
      -1,    45,    46,    47,    48,    -1,    49,    50,    28,    29,
      30,    31,    -1,    12,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    45,    46,    47,    48,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      13,    14,    15,    16,    17,    18,    22,    20,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    45,
      46,    47,    48,    -1,    -1,    -1,    49,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    45,    46,    47,    48,    -1,    -1,
      51,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    45,    46,
      47,    48,    -1,    -1,    51,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    46,    47,    48,    -1,    -1,    51,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      -1,    -1,    51,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    46,    47,    48,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      28,    29,    -1,    45,    46,    47,    48,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,    45,    46,    47,
      48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      23,    26,    27,    33,    34,    49,    53,    56,    57,    58,
      59,    60,    63,    64,    65,    66,    67,    68,    69,    72,
      78,    79,    81,    90,    12,     7,    43,    49,    56,    53,
      11,    11,    49,    59,    93,    59,    85,    11,    59,    70,
      55,    59,    60,    61,     0,    12,    28,    29,    30,    31,
      38,    39,    40,    41,    45,    46,    47,    48,    11,    12,
      12,    12,    60,    68,    12,    53,    54,    59,    50,    49,
      32,    51,    51,    51,    85,    36,    12,    68,    71,    50,
      44,    44,    50,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    43,    49,    11,    53,    53,
      49,    50,    60,    62,    59,    12,    12,    12,    91,    59,
      93,    35,    55,    61,    59,    50,    62,    75,    11,    50,
      44,    34,    34,    85,    59,    85,    73,    50,    51,    44,
      76,    59,    59,    77,    77,    87,    51,    85,    51,    74,
      12,    62,    51,    22,    35,    35,    69,    92,    51,    12,
      51,    69,    12,    59,    85,    12,    12,    69,    12,    69,
      12,    82,    69,    80,    69,    77,    24,    25,    83,    69,
      59,    51,    51,    12,    12,    84,    85,    69,    86,    69,
      88,    89,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    54,    53,    53,    53,    53,    53,    53,    55,
      55,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    61,    61,    62,    62,    63,    64,    65,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    70,    69,    71,    73,
      72,    74,    72,    75,    72,    76,    72,    77,    77,    78,
      78,    80,    79,    81,    82,    81,    83,    83,    84,    83,
      85,    86,    87,    88,    89,    91,    92,    90,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     2,     0,     2,     3,     1,     1,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     4,     4,     3,     2,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     3,     1,     2,     0,     4,     1,     0,
       8,     0,     9,     0,     8,     0,     9,     3,     5,     7,
       7,     0,    10,     7,     0,    10,     7,    10,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     9,     3,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 67 "miint.y" /* yacc.c:1646  */
    {printf(" en expresión\n");}
#line 1499 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 75 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1505 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 76 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type)->add((yyvsp[-2].type)); }
#line 1511 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 79 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 1517 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 82 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 1523 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 84 "miint.y" /* yacc.c:1646  */
    { printf("%s----------------------------------------------------\n", (yyvsp[-1].str)); (yyval.str) = (yyvsp[-1].str); }
#line 1529 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 85 "miint.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[-2].str); }
#line 1535 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "miint.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].type)->equals((yyvsp[0].type))) { (yyval.type) = (yyvsp[-2].type); } else { yyerror((char*) ((std::string("Tipos diferentes: '") + (yyvsp[-2].type)->toString() + "' y '" + (yyvsp[0].type)->toString() + "'").c_str())); } }
#line 1541 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 89 "miint.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].type)->equals((yyvsp[0].type))) { (yyval.type) = (yyvsp[-2].type); } else { yyerror("Tipos diferentes"); } }
#line 1547 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 90 "miint.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].type)->equals((yyvsp[0].type))) { (yyval.type) = (yyvsp[-2].type); } else { yyerror("Tipos diferentes"); } }
#line 1553 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 91 "miint.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].type)->equals((yyvsp[0].type))) { (yyval.type) = (yyvsp[-2].type); } else { yyerror("Tipos diferentes"); } }
#line 1559 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 92 "miint.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].type)->getType() == BOOL && (yyvsp[0].type)->getType() == BOOL) { (yyval.type) = (yyvsp[-2].type); } else { yyerror("Expresiones no booleanas"); } }
#line 1565 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 93 "miint.y" /* yacc.c:1646  */
    { if ((yyvsp[-2].type)->getType() == BOOL && (yyvsp[0].type)->getType() == BOOL) { (yyval.type) = (yyvsp[-2].type); } else { yyerror("Expresiones no booleanas"); } }
#line 1571 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 94 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(BOOL); }
#line 1577 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 95 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = scope->getFunction((yyvsp[0].str))->getType(); }
#line 1583 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 96 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(INT); }
#line 1589 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 97 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(FLOAT); }
#line 1595 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 98 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(DOUBLE); }
#line 1601 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 99 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(LONG); }
#line 1607 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 100 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(BOOL); }
#line 1613 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 101 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(CHAR); }
#line 1619 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 102 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(STRING); }
#line 1625 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 103 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = scope->getVariable((yyvsp[0].str))->getType(); }
#line 1631 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 104 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1637 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 105 "miint.y" /* yacc.c:1646  */
    { 
						Type* type = scope->getVariable((yyvsp[-1].str))->getType();
						if(type->isTuple())
							(yyval.type) = ((TupleType*)type)->getSubType((yyvsp[0].i)); 
						else
							yyerror("Acceso a una tupla");
					
					}
#line 1650 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 115 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1656 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 116 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(INT); }
#line 1662 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 117 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(FLOAT); }
#line 1668 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 118 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(LONG); }
#line 1674 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 119 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(DOUBLE); }
#line 1680 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 120 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(BOOL); }
#line 1686 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 121 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(STRING); }
#line 1692 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 122 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = creaPrimitivo(CHAR); }
#line 1698 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 125 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1704 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 126 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type)->add((yyvsp[-2].type)); }
#line 1710 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 129 "miint.y" /* yacc.c:1646  */
    { std::vector<ParameterNode*> *vector = new std::vector<ParameterNode*>(); vector->push_back(new ParameterNode((yyvsp[-1].type), (yyvsp[0].str))); (yyval.args_v) = vector; }
#line 1716 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 130 "miint.y" /* yacc.c:1646  */
    { (yyvsp[0].args_v)->push_back(new ParameterNode((yyvsp[-3].type), (yyvsp[-2].str))); (yyval.args_v) = (yyvsp[0].args_v); }
#line 1722 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 133 "miint.y" /* yacc.c:1646  */
    {
                                                            if (scope->haveVariable((yyvsp[-2].str))) {
                                                                logError("Se intenta crear '" + std::string((yyvsp[-2].str)) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineVariable((yyvsp[-2].str), new VariableNode((yyvsp[-3].type)));
                                                            }
						}
#line 1734 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 142 "miint.y" /* yacc.c:1646  */
    {
                                                            if (!scope->existsVariable((yyvsp[-2].str))) {
                                                                logError("Se intenta usar '" + std::string((yyvsp[-2].str)) + "', pero no existe."); 
                                                            }
							}
#line 1744 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 149 "miint.y" /* yacc.c:1646  */
    {
                                                            if (scope->haveVariable((yyvsp[0].str))) {
                                                                logError("Se intenta crear '" + std::string((yyvsp[0].str)) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineVariable((yyvsp[0].str), new VariableNode((yyvsp[-1].type)));
                                                            }
						}
#line 1756 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 159 "miint.y" /* yacc.c:1646  */
    { if (isNumberType((yyvsp[-2].type)) && (yyvsp[-2].type)->equals((yyvsp[0].type))) (yyval.type) = creaPrimitivo(BOOL); else logError("Expresiones no numericas"); }
#line 1762 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 160 "miint.y" /* yacc.c:1646  */
    { if (isNumberType((yyvsp[-2].type)) && (yyvsp[-2].type)->equals((yyvsp[0].type))) (yyval.type) = creaPrimitivo(BOOL); else logError("Expresiones no numericas"); }
#line 1768 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 161 "miint.y" /* yacc.c:1646  */
    { if (isNumberType((yyvsp[-2].type)) && (yyvsp[-2].type)->equals((yyvsp[0].type))) (yyval.type) = creaPrimitivo(BOOL); else logError("Expresiones no numericas"); }
#line 1774 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 162 "miint.y" /* yacc.c:1646  */
    { if (isNumberType((yyvsp[-2].type)) && (yyvsp[-2].type)->equals((yyvsp[0].type))) (yyval.type) = creaPrimitivo(BOOL); else logError("Expresiones no numericas"); }
#line 1780 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 163 "miint.y" /* yacc.c:1646  */
    { if (isNumberType((yyvsp[-2].type)) && (yyvsp[-2].type)->equals((yyvsp[0].type))) (yyval.type) = creaPrimitivo(BOOL); else logError("Expresiones no booleanas"); }
#line 1786 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 164 "miint.y" /* yacc.c:1646  */
    { if (isNumberType((yyvsp[-2].type)) && (yyvsp[-2].type)->equals((yyvsp[0].type))) (yyval.type) = creaPrimitivo(BOOL); else logError("Expresiones no booleanas"); }
#line 1792 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 184 "miint.y" /* yacc.c:1646  */
    { if (!scope->isEmpty()) scope = new Scope(scope); }
#line 1798 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 187 "miint.y" /* yacc.c:1646  */
    { 
            					Scope* oldScope = scope;
            					scope = scope->getParent();
            					delete oldScope; 
            				  }
#line 1808 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 197 "miint.y" /* yacc.c:1646  */
    {
                                                            creaFuncion((yyvsp[-2].str), (yyvsp[-3].type), NULL);
						}
#line 1816 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 200 "miint.y" /* yacc.c:1646  */
    {
                                                            creaFuncion((yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].args_v));
					        }
#line 1824 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 203 "miint.y" /* yacc.c:1646  */
    {
                                                            creaFuncion((yyvsp[-2].str), creaPrimitivo(VOID), NULL);
					        }
#line 1832 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 206 "miint.y" /* yacc.c:1646  */
    {
                                                            creaFuncion((yyvsp[-3].str), creaPrimitivo(VOID), (yyvsp[-1].args_v));
					        }
#line 1840 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 219 "miint.y" /* yacc.c:1646  */
    {/*crear variable identificador si no existe, asignarle el valor de inicio menos paso, label vuelta, identificador+=paso, comprobar que sea menor que fin y hacer bloque o ir a salida*/}
#line 1846 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 219 "miint.y" /* yacc.c:1646  */
    { gc("\tGT(%d);\nL %d:\n", (yyvsp[-5].i), (yyvsp[-4].i)); }
#line 1852 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 226 "miint.y" /* yacc.c:1646  */
    {gc("L %d:\n", (yyvsp[-2].i));}
#line 1858 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 227 "miint.y" /* yacc.c:1646  */
    { (yyval.i)=(yyvsp[-3].i); }
#line 1864 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 227 "miint.y" /* yacc.c:1646  */
    {gc("L %d:\n", (yyvsp[-2].i));}
#line 1870 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 232 "miint.y" /* yacc.c:1646  */
    {gc("L %d:\n", (yyvsp[-2].i));}
#line 1876 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 234 "miint.y" /* yacc.c:1646  */
    { gc("\tGT(%d);\nL %d:\n", (yyvsp[(-1) - (3)].i), (yyvsp[-3].i));}
#line 1882 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 239 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = ne(); }
#line 1888 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 243 "miint.y" /* yacc.c:1646  */
    { gc("\tGT  (%d);\nL %d:\n\tIF(!R%d) GT(%d);\n", (yyvsp[(-6) - (0)].i), (yyvsp[(-5) - (0)].i), (yyvsp[(-3) - (0)].i), (yyvsp[0].i)); }
#line 1894 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 247 "miint.y" /* yacc.c:1646  */
    { gc("\tIF(!R%d) GT(%d);\n", (yyvsp[(-3) - (0)].i), (yyvsp[0].i)); /*si no $-4 ir a $0*/ }
#line 1900 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 251 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[(-8) - (0)].i); /*($-1 del anterior)*/ }
#line 1906 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 255 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[(-3) - (0)].i); }
#line 1912 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 261 "miint.y" /* yacc.c:1646  */
    { gc("L %d:\n", (yyvsp[0].i)); }
#line 1918 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 261 "miint.y" /* yacc.c:1646  */
    { gc("\tIF(!R %d) GT( %d);\n", (yyvsp[-1].type), (yyvsp[-4].i)); }
#line 1924 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 261 "miint.y" /* yacc.c:1646  */
    { gc("\tGT(%d);\nL %d:\n", (yyvsp[-6].i), (yyvsp[-7].i)); }
#line 1930 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 264 "miint.y" /* yacc.c:1646  */
    { ValoresRango valoresRango = {(yyvsp[-2].type), (yyvsp[0].type), creaPrimitivo(INT)}; (yyval.valoresRango)=&valoresRango; }
#line 1936 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 265 "miint.y" /* yacc.c:1646  */
    { ValoresRango valoresRango = {(yyvsp[-4].type), (yyvsp[-2].type), (yyvsp[0].type)}; (yyval.valoresRango)=&valoresRango; }
#line 1942 "miint.tab.c" /* yacc.c:1646  */
    break;


#line 1946 "miint.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 267 "miint.y" /* yacc.c:1906  */


bool isNumberType(Type* tipo){
    if(!tipo->isTuple()){
        switch(((PrimitiveType*) tipo)->getType()){
            case INT:
            case LONG:
            case FLOAT:
            case DOUBLE:
                return true;
            default:
                return false;
        }
    }
}

void gc(const char* code, ...) {
	va_list args;
	va_start (args, code);
	vfprintf (qFile, code, args);
	va_end (args);
}

int ne(){
	return ec++;
}

int main(int argc, char** argv) {
    memoria = new MemManager();
	scope = new Scope();
//Funciones del sistema
	scope->defineFunction("print", new FunctionNode(creaPrimitivo(VOID)));
	scope->defineFunction("getchar", new FunctionNode(creaPrimitivo(CHAR)));
	if (argc>1) yyin=fopen(argv[1],"r");
	qFile=fopen("program.q", "w+");
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

void creaFuncion(char* nombre, Type* returnType, std::vector<ParameterNode*> *v){
    if (scope->existsFunction(nombre)) {
        logError("Se intenta crear función '" + std::string(nombre) + "', pero ya existe."); 
    } else {
        scope->defineFunction(nombre, new FunctionNode(returnType, v));
	    scope = new Scope(scope, std::string(nombre));
    }
}

PrimitiveType* creaPrimitivo(int tipo){
    return new PrimitiveType(memoria->creaVariableSimple(), tipo);
}
