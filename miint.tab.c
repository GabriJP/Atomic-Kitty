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
#line 9 "miint.y" /* yacc.c:339  */



#include "Type.h"
#include "CodeGeneration.h"


extern FILE *yyin;

#define YYDEBUG 1

#if YYBISON
union YYSTYPE;
int yylex();
#endif

//Funciones
extern  void  yyerror(char *str);


#line 88 "miint.tab.c" /* yacc.c:339  */

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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 32 "miint.y" /* yacc.c:355  */

  #include "structs.h"
  #include "Scope.h"
  #include "MemManager.h"
  class ParameterNode;


#line 126 "miint.tab.c" /* yacc.c:355  */

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
 float f; double d; int i; long l; char c; char* str; Type* type; std::vector<ParameterNode*> *args_v; ValoresRango valoresRango; 

#line 184 "miint.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MIINT_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "miint.tab.c" /* yacc.c:358  */

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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   622

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

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
       0,    70,    70,    70,    71,    72,    73,    74,    75,    78,
      79,    82,    85,    88,    89,    92,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   119,   120,   121,   122,   123,   124,
     125,   126,   129,   130,   133,   136,   139,   149,   158,   168,
     169,   170,   171,   172,   173,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   188,   189,   193,   192,   207,
     210,   210,   213,   213,   216,   216,   219,   219,   224,   226,
     227,   227,   230,   244,   247,   247,   250,   250,   259,   262,
     261,   268,   270,   273,   272,   278,   282,   287,   295,   301,
     305,   311,   312,   311,   316,   321
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
  "exp_l", "tupla", "tupla_decl", "func_call", "func_call_init", "exp",
  "tipo", "tipo_l", "args", "init", "assign", "decl", "comp", "inst",
  "inst_l", "bloque", "$@2", "dentroBloque", "func", "@3", "@4", "@5",
  "@6", "funcFinal", "cases", "@7", "case_cond", "case_jump", "when", "@8",
  "for", "$@9", "if", "@10", "elif_l", "$@11", "ne", "elif_control",
  "elif_eval", "if_evalua_expresion", "elif_copia_salida",
  "elif_copia_siguiente", "while", "$@12", "$@13", "rango", YY_NULLPTR
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

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -100

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     170,     4,  -159,  -159,  -159,  -159,  -159,  -159,  -159,   -32,
     170,  -159,  -159,  -159,  -159,  -159,  -159,     8,  -159,   156,
     156,  -159,    10,   156,  -159,   244,    23,  -159,  -159,  -159,
     341,    17,  -159,  -159,  -159,  -159,   207,    18,  -159,   170,
      26,  -159,  -159,  -159,  -159,   156,   -14,  -159,    -8,    -5,
     156,   237,   266,  -159,    27,   366,   207,    16,   391,    29,
      33,  -159,  -159,  -159,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,    -7,    73,  -159,   170,
    -159,  -159,   170,   416,   106,  -159,   557,    74,    75,  -159,
     156,  -159,  -159,    50,  -159,   156,   573,  -159,   161,   161,
      93,    93,    13,    13,    13,    13,    20,    20,    81,    81,
    -159,   156,   565,    -3,  -159,  -159,  -159,  -159,   573,  -159,
      80,    43,    60,  -159,   156,   441,  -159,  -159,  -159,  -159,
     471,  -159,    47,    44,    55,  -159,  -159,  -159,   291,   156,
    -159,  -159,    51,  -159,    86,   573,    52,   156,    67,  -159,
     496,    53,    94,    56,    67,  -159,   101,   521,    83,    45,
     107,   156,   112,    67,   113,  -159,    67,   104,  -159,  -159,
      67,   521,  -159,  -159,    67,  -159,  -159,   156,    54,  -159,
      67,  -159,  -159,  -159,   521,  -159,    76,  -159,  -159,  -159,
     117,   156,   118,  -159,   316,  -159,   156,   123,    67,  -159,
    -159,  -159,  -159,    67,    57,  -159,    54,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    25,    26,    24,    28,    27,    29,    30,    31,
       0,    35,    37,    36,    38,    39,    40,     0,    41,     0,
       0,    95,     0,     0,    67,     0,     0,    32,    34,    23,
       0,     0,    56,    57,    58,    22,    65,     7,    63,     0,
       0,    60,    62,    61,     2,     0,     0,     4,     0,    31,
       0,     0,     0,    95,     0,     0,     0,     0,     9,    42,
       0,     1,    33,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,     0,
       5,    59,     0,     0,     0,    13,     0,     0,     0,   101,
       0,    64,    69,     0,    11,     0,     0,    12,    54,    53,
      21,    20,    52,    51,    50,    49,    16,    17,    19,    18,
      48,     0,     0,     0,     6,     3,    47,    14,     0,    74,
       0,     0,     0,    95,     0,     0,    95,    68,    10,    43,
       0,    70,     0,     0,    44,    76,    84,    98,     0,     0,
      95,    46,     0,    72,     0,     0,     0,     0,     0,   102,
     104,     0,     0,     0,     0,    45,     0,    82,     0,    88,
       0,     0,     0,     0,     0,    78,     0,     0,    85,    89,
       0,   105,    86,    78,     0,    75,    78,     0,     0,   103,
       0,    71,    78,    77,    83,    96,     0,    90,    87,    73,
      79,     0,     0,    80,     0,    93,     0,     0,     0,    81,
      95,    94,    97,     0,    91,   100,     0,    92
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,    -2,  -159,    41,    91,  -159,  -159,  -159,   -19,   -22,
      48,  -102,  -159,  -159,  -159,  -159,  -159,   -24,  -141,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -158,   -53,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,   -61,  -159,   -51,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    82,    57,    27,    28,    29,    46,    30,    31,
      60,   121,    32,    33,    34,    35,    36,    37,    38,    56,
      93,    39,   142,   153,   133,   146,   175,   158,   196,   167,
     190,    40,   147,    41,   180,    42,   178,   187,   198,    53,
     191,   203,   148,   205,   206,    43,   124,   160,   126
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    52,    89,    59,    55,   110,    58,   159,    47,   110,
     132,    45,    78,   165,    77,   181,    44,   -15,   183,    48,
      62,    54,   173,    61,   189,   176,    83,    62,    76,   179,
      79,    58,    92,   182,    77,    84,   111,    80,    81,   188,
     111,    86,   112,   155,   -15,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   201,    72,    73,
      74,    75,   204,    90,   120,    58,    94,    74,    75,   -95,
     -95,   125,   137,    96,    59,   140,    58,   114,   185,   186,
     115,   -99,   -99,    97,   113,   127,   122,   123,    62,   151,
     120,   134,   130,   135,   136,   144,    59,   143,   154,   145,
      62,    24,   152,   156,   162,   138,   163,   164,   169,     2,
       3,     4,     5,   166,     6,     7,     8,    49,   168,   170,
     150,    64,    65,   120,   172,   174,   177,   192,   157,   193,
     195,    68,    69,    70,    71,   200,   128,    85,    72,    73,
      74,    75,   171,   199,   129,   207,     0,     0,     0,   202,
       0,     0,     0,     0,     0,    50,   117,     0,   184,     2,
       3,     4,     5,     0,     6,     7,     8,    49,    62,     0,
      -8,     1,   194,     2,     3,     4,     5,   157,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,     0,     0,    21,    22,     0,    68,
      69,    70,    71,    23,    24,    50,    72,    73,    74,    75,
       2,     3,     4,     5,     0,     6,     7,     8,     9,    25,
      11,    12,    13,    14,    15,    16,     0,    18,    19,     0,
      20,     0,     0,    21,    22,     0,     0,     0,     0,     0,
      23,    24,     0,     0,    62,     0,     0,     2,     3,     4,
       5,     0,     6,     7,     8,    49,    25,    11,    12,    13,
      14,    15,    16,     0,    18,    64,    65,    66,    67,     0,
       0,     0,     0,    62,     0,    68,    69,    70,    71,     0,
       0,     0,    72,    73,    74,    75,     0,     0,    87,     0,
       0,     0,     0,    25,    64,    65,    66,    67,    62,     0,
       0,     0,     0,     0,    68,    69,    70,    71,     0,     0,
       0,    72,    73,    74,    75,     0,     0,    88,     0,    64,
      65,    66,    67,    62,     0,     0,     0,     0,     0,    68,
      69,    70,    71,     0,     0,     0,    72,    73,    74,    75,
       0,     0,   149,     0,    64,    65,    66,    67,    62,     0,
       0,     0,     0,    63,    68,    69,    70,    71,     0,     0,
       0,    72,    73,    74,    75,     0,     0,   197,     0,    64,
      65,    66,    67,    62,     0,     0,     0,     0,    91,    68,
      69,    70,    71,     0,     0,     0,    72,    73,    74,    75,
       0,     0,     0,     0,    64,    65,    66,    67,    62,     0,
       0,     0,     0,     0,    68,    69,    70,    71,     0,     0,
       0,    72,    73,    74,    75,     0,     0,     0,     0,    64,
      65,    66,    67,    62,     0,     0,     0,     0,   116,    68,
      69,    70,    71,     0,     0,    95,    72,    73,    74,    75,
       0,     0,     0,     0,    64,    65,    66,    67,    62,     0,
       0,     0,     0,     0,    68,    69,    70,    71,     0,     0,
       0,    72,    73,    74,    75,     0,     0,     0,     0,    64,
      65,    66,    67,   139,     0,     0,     0,     0,    62,    68,
      69,    70,    71,   141,     0,     0,    72,    73,    74,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,    67,    62,     0,     0,     0,     0,     0,    68,
      69,    70,    71,     0,     0,     0,    72,    73,    74,    75,
       0,     0,     0,     0,    64,    65,    66,    67,    62,     0,
       0,     0,     0,     0,    68,    69,    70,    71,     0,     0,
     161,    72,    73,    74,    75,     0,     0,     0,     0,    64,
      65,    66,    67,     0,     0,     0,     0,     0,     0,    68,
      69,    70,    71,     0,     0,     0,    72,    73,    74,    75,
      11,    12,    13,    14,    15,    16,     0,    18,    11,    12,
      13,    14,    15,    16,     0,    18,    11,    12,    13,    14,
      15,    16,     0,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   119,     0,     0,
       0,     0,     0,     0,   118,   131,     0,     0,     0,     0,
       0,     0,   118
};

static const yytype_int16 yycheck[] =
{
      19,    20,    53,    25,    23,    12,    25,   148,    10,    12,
     112,    43,    36,   154,    36,   173,    12,    49,   176,    11,
       7,    11,   163,     0,   182,   166,    45,     7,    11,   170,
      12,    50,    56,   174,    56,    49,    43,    39,    12,   180,
      43,    49,    49,   145,    49,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   198,    45,    46,
      47,    48,   203,    36,    86,    84,    50,    47,    48,    24,
      25,    90,   123,    44,    96,   126,    95,    79,    24,    25,
      82,    24,    25,    50,    11,    35,    12,    12,     7,   140,
     112,    11,   111,    50,    34,    51,   118,    50,    12,    44,
       7,    34,    51,    51,    51,   124,    12,    51,   159,     3,
       4,     5,     6,    12,     8,     9,    10,    11,    35,    12,
     139,    28,    29,   145,    12,    12,    22,    51,   147,    12,
      12,    38,    39,    40,    41,    12,    95,    46,    45,    46,
      47,    48,   161,   196,    96,   206,    -1,    -1,    -1,   200,
      -1,    -1,    -1,    -1,    -1,    49,    50,    -1,   177,     3,
       4,     5,     6,    -1,     8,     9,    10,    11,     7,    -1,
       0,     1,   191,     3,     4,     5,     6,   196,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    26,    27,    -1,    38,
      39,    40,    41,    33,    34,    49,    45,    46,    47,    48,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    49,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    -1,
      23,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,     7,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    10,    11,    49,    13,    14,    15,
      16,    17,    18,    -1,    20,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,     7,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,    45,    46,    47,    48,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    49,    28,    29,    30,    31,     7,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    45,    46,    47,    48,    -1,    -1,    51,    -1,    28,
      29,    30,    31,     7,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      -1,    -1,    51,    -1,    28,    29,    30,    31,     7,    -1,
      -1,    -1,    -1,    12,    38,    39,    40,    41,    -1,    -1,
      -1,    45,    46,    47,    48,    -1,    -1,    51,    -1,    28,
      29,    30,    31,     7,    -1,    -1,    -1,    -1,    12,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,     7,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,     7,    -1,    -1,    -1,    -1,    12,    38,
      39,    40,    41,    -1,    -1,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,     7,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,     7,    38,
      39,    40,    41,    12,    -1,    -1,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,     7,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,     7,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      13,    14,    15,    16,    17,    18,    -1,    20,    13,    14,
      15,    16,    17,    18,    -1,    20,    13,    14,    15,    16,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      23,    26,    27,    33,    34,    49,    53,    56,    57,    58,
      60,    61,    64,    65,    66,    67,    68,    69,    70,    73,
      83,    85,    87,    97,    12,    43,    59,    53,    11,    11,
      49,    60,    60,    91,    11,    60,    71,    55,    60,    61,
      62,     0,     7,    12,    28,    29,    30,    31,    38,    39,
      40,    41,    45,    46,    47,    48,    11,    61,    69,    12,
      53,    12,    54,    60,    49,    56,    49,    51,    51,    91,
      36,    12,    69,    72,    50,    44,    44,    50,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      12,    43,    49,    11,    53,    53,    12,    50,    49,    50,
      61,    63,    12,    12,    98,    60,   100,    35,    55,    62,
      60,    50,    63,    76,    11,    50,    34,    91,    60,    32,
      91,    12,    74,    50,    51,    44,    77,    84,    94,    51,
      60,    91,    51,    75,    12,    63,    51,    60,    79,    70,
      99,    44,    51,    12,    51,    70,    12,    81,    35,    91,
      12,    60,    12,    70,    12,    78,    70,    22,    88,    70,
      86,    78,    70,    78,    60,    24,    25,    89,    70,    78,
      82,    92,    51,    12,    60,    12,    80,    51,    90,    79,
      12,    70,    91,    93,    70,    95,    96,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    54,    53,    53,    53,    53,    53,    53,    55,
      55,    56,    57,    58,    58,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    65,    66,    67,
      67,    67,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    69,    71,    70,    72,
      74,    73,    75,    73,    76,    73,    77,    73,    78,    79,
      80,    79,    81,    82,    84,    83,    86,    85,    87,    88,
      87,    89,    89,    90,    89,    91,    92,    93,    94,    95,
      96,    98,    99,    97,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     2,     2,     3,     1,     0,     1,
       3,     3,     3,     3,     4,     0,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     4,     5,     4,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     2,
       1,     1,     1,     1,     3,     1,     2,     0,     4,     1,
       0,     9,     0,    10,     0,     9,     0,    10,     0,     5,
       0,     8,     0,     0,     0,     8,     0,    10,     7,     0,
      10,     8,    11,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     3,     5
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
#line 70 "miint.y" /* yacc.c:1646  */
    {printf(" en expresión\n");}
#line 1510 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 78 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 1516 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 79 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = buildExpList((yyvsp[-2].i), (yyvsp[0].i)); }
#line 1522 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-1].i); }
#line 1528 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 1534 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 88 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = callFunction((yyvsp[-2].str), (yyvsp[0].i), (yyvsp[-1].i)); }
#line 1540 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 89 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = callFunction((yyvsp[-3].str), -1, (yyvsp[-2].i)); }
#line 1546 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 92 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = callFunctionInit((yyvsp[0].str)); }
#line 1552 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 94 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "-"); (yyval.i) = (yyvsp[-2].i); }
#line 1558 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 95 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "+"); (yyval.i) = (yyvsp[-2].i); }
#line 1564 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 96 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "/"); (yyval.i) = (yyvsp[-2].i); }
#line 1570 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 97 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "*"); (yyval.i) = (yyvsp[-2].i); }
#line 1576 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "&&"); (yyval.i) = (yyvsp[-2].i); }
#line 1582 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 99 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "||"); (yyval.i) = (yyvsp[-2].i); }
#line 1588 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 100 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 1594 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 101 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 1600 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 102 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = primitiveExp(INT, (yyvsp[0].i)); }
#line 1606 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 103 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = primitiveExp(FLOAT, (yyvsp[0].f)); }
#line 1612 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 104 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = primitiveExp(DOUBLE, (yyvsp[0].d)); }
#line 1618 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 105 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = primitiveExp(LONG, (yyvsp[0].l)); }
#line 1624 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 106 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = primitiveExp(BOOL, (yyvsp[0].i)); }
#line 1630 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 107 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = primitiveExp(CHAR, (yyvsp[0].c)); }
#line 1636 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 108 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = primitiveExp(STRING); }
#line 1642 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 109 "miint.y" /* yacc.c:1646  */
    { memStack.load(scope->getVariable((yyvsp[0].str))->getId(), (yyval.i)); }
#line 1648 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 110 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[0].i); }
#line 1654 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 111 "miint.y" /* yacc.c:1646  */
    { //TODO corregir desplazamiento
						if(memStack.get((yyvsp[-1].i)).type->isTuple())
							memStack.load((yyvsp[-1].i), (yyvsp[0].i), (yyval.i));
						else
							logError("id:" + std::to_string(memStack.get((yyvsp[-1].i)).id) + " " + memStack.get((yyvsp[-1].i)).name + " isn't a tuple");
					}
#line 1665 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 119 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1671 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 120 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(INT); }
#line 1677 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 121 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(FLOAT); }
#line 1683 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 122 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(LONG); }
#line 1689 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 123 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(DOUBLE); }
#line 1695 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 124 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(BOOL); }
#line 1701 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 125 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(STRING); }
#line 1707 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 126 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = new PrimitiveType(CHAR); }
#line 1713 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 129 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1719 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 130 "miint.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type)->add((yyvsp[-2].type)); }
#line 1725 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 134 "miint.y" /* yacc.c:1646  */
    { std::vector<ParameterNode*> *vector = new std::vector<ParameterNode*>();
                          vector->push_back(new ParameterNode((yyvsp[-1].type), (yyvsp[0].str))); (yyval.args_v) = vector; }
#line 1732 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 136 "miint.y" /* yacc.c:1646  */
    { (yyvsp[0].args_v)->push_back(new ParameterNode((yyvsp[-3].type), (yyvsp[-2].str))); (yyval.args_v) = (yyvsp[0].args_v); }
#line 1738 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 139 "miint.y" /* yacc.c:1646  */
    {
                                                            if (scope->haveVariable((yyvsp[-3].str))) {
                                                                logError("Se intenta crear '" + std::string((yyvsp[-3].str)) + "', pero ya existe.");
                                                            } else {
                                                                int id = addNewVar((yyvsp[-4].type), (yyvsp[-3].str));
                                                                memStack.assign(id, (yyvsp[-1].i));
                                                            }
						}
#line 1751 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 149 "miint.y" /* yacc.c:1646  */
    {
                                                            if (!scope->existsVariable((yyvsp[-3].str))) {
                                                                logError("Se intenta usar '" + std::string((yyvsp[-3].str)) + "', pero no existe.");
                                                            } else {
                                                                memStack.assign(scope->getVariable((yyvsp[-3].str))->getId(), (yyvsp[-1].i));
                                                            }
							}
#line 1763 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 158 "miint.y" /* yacc.c:1646  */
    {
                                                            if (scope->haveVariable((yyvsp[-1].str))) {
                                                                logError("Se intenta crear '" + std::string((yyvsp[-1].str)) + "', pero ya existe.");
                                                            } else {
                                                                addNewVar((yyvsp[-2].type), (yyvsp[-1].str));
                                                            }
						}
#line 1775 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 168 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "<"); (yyval.i) = (yyvsp[-2].i); }
#line 1781 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 169 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), ">"); (yyval.i) = (yyvsp[-2].i); }
#line 1787 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 170 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "<="); (yyval.i) = (yyvsp[-2].i); }
#line 1793 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 171 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), ">="); (yyval.i) = (yyvsp[-2].i); }
#line 1799 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 172 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "=="); (yyval.i) = (yyvsp[-2].i); }
#line 1805 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 173 "miint.y" /* yacc.c:1646  */
    { opera((yyvsp[-2].i), (yyvsp[0].i), "!="); (yyval.i) = (yyvsp[-2].i); }
#line 1811 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 185 "miint.y" /* yacc.c:1646  */
    { generateReturn((yyvsp[-1].i)); }
#line 1817 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 193 "miint.y" /* yacc.c:1646  */
    {
            				    scope = new Scope(scope);
            				    memStack.enterBlock();
            				  }
#line 1826 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 199 "miint.y" /* yacc.c:1646  */
    {
            					Scope* oldScope = scope;
            					scope = scope->getParent();
            					memStack.exitBlock();
            					delete oldScope;
            				  }
#line 1837 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 210 "miint.y" /* yacc.c:1646  */
    {
                             (yyval.i) = createFunction((yyvsp[-2].str), (yyvsp[-3].type), NULL);
						}
#line 1845 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 213 "miint.y" /* yacc.c:1646  */
    {
                            (yyval.i) = createFunction((yyvsp[-3].str), (yyvsp[-4].type), (yyvsp[-1].args_v));
					        }
#line 1853 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 216 "miint.y" /* yacc.c:1646  */
    {
                            (yyval.i) = createFunction((yyvsp[-2].str), new PrimitiveType(VOID), NULL);
					        }
#line 1861 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 219 "miint.y" /* yacc.c:1646  */
    {
                            (yyval.i) = createFunction((yyvsp[-3].str), new PrimitiveType(VOID), (yyvsp[-1].args_v));
					        }
#line 1869 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 224 "miint.y" /* yacc.c:1646  */
    { functionEnd((yyvsp[(-3) - (0)].i)); }
#line 1875 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 227 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-6].i); }
#line 1881 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 230 "miint.y" /* yacc.c:1646  */
    { RegCode caseReg = memStack.load((yyvsp[0].i)); RegCode condReg = memStack.load((yyvsp[(-1) - (0)].i));
                        PrimitiveType b(BOOL);
                        RegCode condResult = memStack.getFreeRegister(&b);
                        gc << '\t' << condResult << " = " << caseReg << " == " << condReg << "; # Case check\n";
                        int nextCase = ne();
                        gc << "\tIF( !" << condResult << " ) GT( " << nextCase <<  " ); \n";
                        (yyval.i) = nextCase;

                        memStack.enterBlock();
                        gc.flush();
;
                      }
#line 1898 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 244 "miint.y" /* yacc.c:1646  */
    { memStack.exitBlock(); gc << "L " << (yyvsp[(-2) - (0)].i) << ":\n"; gc.flush(); }
#line 1904 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 247 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[-3].i); memStack.saveInStack((yyvsp[-3].i)); }
#line 1910 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 250 "miint.y" /* yacc.c:1646  */
    {
                            forInst((yyvsp[-6].str), (yyvsp[-4].valoresRango), (yyvsp[-3].i), (yyvsp[-2].i));
                        }
#line 1918 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 253 "miint.y" /* yacc.c:1646  */
    { gc << "\tGT(" << (yyvsp[-5].i) << ");\nL " << (yyvsp[-4].i) << ":\n"; }
#line 1924 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 260 "miint.y" /* yacc.c:1646  */
    {gc << "L " << (yyvsp[-2].i) << ":\t\t\t# Label salida if\n";}
#line 1930 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 262 "miint.y" /* yacc.c:1646  */
    { (yyval.i)=(yyvsp[-3].i); }
#line 1936 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 262 "miint.y" /* yacc.c:1646  */
    {gc << "L " << (yyvsp[-2].i) << ":\t\t\t\t\t\t# Label salida if\n"; }
#line 1942 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 269 "miint.y" /* yacc.c:1646  */
    {gc << "L %d:\t\t# Se termina el bloque del if y se sale\n", (yyvsp[-2].i);}
#line 1948 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 273 "miint.y" /* yacc.c:1646  */
    { gc << "\tGT(" << (yyvsp[(-1) - (3)].i) << ");\t\t\t\t\t# Ir a salida\nL " << (yyvsp[-3].i) << ":\t\t\t\t\t\t# Label del else\n";}
#line 1954 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 278 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = ne(); }
#line 1960 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 282 "miint.y" /* yacc.c:1646  */
    { gc << "\tGT  (" << (yyvsp[(-2) - (0)].i) << ");\t\t# Fin bloque y salida a fin del if\n"
                        "L " <<  (yyvsp[(-1) - (0)].i) << ":\t\t\t# Label de este elif\n";
                      }
#line 1968 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 287 "miint.y" /* yacc.c:1646  */
    {
                        gc << "\tIF(!" << memStack.load((yyvsp[(-3) - (0)].i)) << ") "
                          "GT(" << (yyvsp[0].i) << ");\t# Si no se cumple la condición se va al siguiente elif\n";
                           memStack.release((yyvsp[(-3) - (0)].i));
                      }
#line 1978 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 295 "miint.y" /* yacc.c:1646  */
    { gc << "\tIF(!" << memStack.load((yyvsp[(-3) - (0)].i)) << ") GT(" << (yyvsp[0].i) << ");\t\t\t# Comprobación condición if\n";
                        memStack.release((yyvsp[(-3) - (0)].i));
                      }
#line 1986 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 301 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[(-8) - (0)].i); /*($-1 del anterior)*/ }
#line 1992 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 305 "miint.y" /* yacc.c:1646  */
    { (yyval.i) = (yyvsp[(-3) - (0)].i); }
#line 1998 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 311 "miint.y" /* yacc.c:1646  */
    { gc << "L " << (yyvsp[0].i) << ":\n"; }
#line 2004 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 312 "miint.y" /* yacc.c:1646  */
    { gc << "\tIF( !" << memStack.load((yyvsp[-1].i)) << " ) GT(" << (yyvsp[-4].i) << ");\n"; }
#line 2010 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 313 "miint.y" /* yacc.c:1646  */
    { gc << "\tGT(" << (yyvsp[-6].i) << ");\nL " << (yyvsp[-7].i) << ":\n"; }
#line 2016 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 316 "miint.y" /* yacc.c:1646  */
    { ValoresRango valoresRango =
                            {memStack.getType((yyvsp[-2].i)), memStack.saveInStack((yyvsp[-2].i)), memStack.saveInStack((yyvsp[0].i)),
                            memStack.addToStack(new PrimitiveType(INT))};
                            memStack.assign(valoresRango.paso, "1");
                            (yyval.valoresRango)=valoresRango; }
#line 2026 "miint.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 321 "miint.y" /* yacc.c:1646  */
    { (yyval.valoresRango) = ValoresRango{memStack.getType((yyvsp[-4].i)),
					                                                memStack.saveInStack((yyvsp[-4].i)),
					                                                memStack.saveInStack((yyvsp[-2].i)),
					                                                memStack.saveInStack((yyvsp[0].i))}; }
#line 2035 "miint.tab.c" /* yacc.c:1646  */
    break;


#line 2039 "miint.tab.c" /* yacc.c:1646  */
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
#line 326 "miint.y" /* yacc.c:1906  */


int main(int argc, char **argv) {

    scope = new Scope();

//Funciones del sistema
    /*scope->defineFunction("print", new FunctionNode(new PrimitiveType(VOID)));
    scope->defineFunction("getchar", new FunctionNode(new PrimitiveType(CHAR)));*/
    if(argc <= 1) return -1;

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        return -2;
    }
    initQ();

    std::cout << "Compiling " << argv[1] << "...\n";
    try{
        yyparse();
    }catch(const std::exception& e) {
        std::cout << "Unexpected error" << e.what() << "\n";
        memStack.print();
        gc.flush();
        gc.close();
        fclose(yyin);
        exit(-3);
    }
    endQ();
    gc.close();
    fclose(yyin);
}


