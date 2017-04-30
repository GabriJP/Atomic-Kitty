
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 6 "miint.y"

#include <stdio.h>
#include <stdlib.h>
#include "Scope.h"
Scope *scope;
extern  void  yyerror(char *);
extern FILE *yyin;
int yydebug = 1;
#if YYBISON
union YYSTYPE;
int yylex();
#endif
extern int fines;
void  logError(std::string str);
void creaFuncion(char* nombre, Type* returnType, std::vector<ParameterNode*> *v = new std::vector<ParameterNode*>());
bool isNumberType(Type* tipo);


/* Line 189 of yacc.c  */
#line 92 "miint.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     MENORQUE = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 24 "miint.y"
 float f; double d; int i; long l; char c; char* str; Type* type; std::vector<ParameterNode*> *args_v;


/* Line 214 of yacc.c  */
#line 173 "miint.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 185 "miint.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   535

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,    49,    46,    45,    43,    44,     2,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,     2,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     9,    12,    13,    16,    20,    22,
      24,    28,    32,    36,    39,    43,    47,    51,    55,    59,
      63,    67,    69,    71,    73,    75,    77,    79,    81,    83,
      85,    87,    89,    92,    94,    96,    98,   100,   102,   104,
     106,   108,   110,   114,   117,   122,   127,   131,   134,   138,
     142,   146,   150,   154,   158,   162,   166,   169,   172,   175,
     178,   180,   182,   184,   186,   188,   192,   194,   197,   198,
     203,   205,   206,   215,   216,   226,   227,   236,   237,   247,
     251,   257,   265,   273,   279,   285,   292,   299,   307,   313,
     320,   325,   331,   335
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    -1,     1,    12,    53,    52,    -1,    12,
      52,    -1,    -1,    72,    52,    -1,    68,    12,    52,    -1,
      68,    -1,    58,    -1,    58,    43,    54,    -1,    48,    54,
      49,    -1,    48,    60,    49,    -1,    11,    55,    -1,    11,
      48,    49,    -1,    58,    44,    58,    -1,    58,    45,    58,
      -1,    58,    47,    58,    -1,    58,    46,    58,    -1,    58,
      31,    58,    -1,    58,    30,    58,    -1,    66,    -1,    57,
      -1,     5,    -1,     3,    -1,     4,    -1,     8,    -1,     6,
      -1,     9,    -1,    10,    -1,    11,    -1,    55,    -1,    11,
       7,    -1,    56,    -1,    13,    -1,    15,    -1,    14,    -1,
      16,    -1,    17,    -1,    18,    -1,    20,    -1,    59,    -1,
      59,    43,    60,    -1,    59,    11,    -1,    59,    11,    43,
      61,    -1,    59,    11,    42,    58,    -1,    11,    42,    58,
      -1,    59,    11,    -1,    11,    36,    84,    -1,    11,    37,
      84,    -1,    58,    41,    58,    -1,    58,    40,    58,    -1,
      58,    39,    58,    -1,    58,    38,    58,    -1,    58,    29,
      58,    -1,    58,    28,    58,    -1,    58,    12,    -1,    62,
      12,    -1,    63,    12,    -1,    64,    12,    -1,    78,    -1,
      79,    -1,    83,    -1,    80,    -1,    69,    -1,    33,    58,
      12,    -1,    67,    -1,    67,    68,    -1,    -1,    34,    70,
      71,    35,    -1,    68,    -1,    -1,    59,    11,    48,    49,
      73,    50,    12,    69,    -1,    -1,    59,    11,    48,    61,
      49,    74,    50,    12,    69,    -1,    -1,    19,    11,    48,
      49,    75,    50,    12,    69,    -1,    -1,    19,    11,    48,
      61,    49,    76,    50,    12,    69,    -1,    58,    22,    58,
      -1,    58,    22,    58,    12,    77,    -1,    21,    58,    50,
      12,    34,    77,    35,    -1,    21,    84,    50,    12,    34,
      77,    35,    -1,    27,    65,    50,    12,    69,    -1,    23,
      58,    50,    12,    69,    -1,    23,    58,    50,    12,    69,
      82,    -1,    23,    58,    50,    12,    69,    81,    -1,    23,
      58,    50,    12,    69,    81,    82,    -1,    24,    58,    50,
      12,    69,    -1,    24,    58,    50,    12,    69,    81,    -1,
      25,    50,    12,    69,    -1,    26,    58,    50,    12,    69,
      -1,    58,    32,    58,    -1,    58,    32,    58,    43,    58,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    48,    49,    50,    51,    52,    53,    56,
      57,    60,    63,    65,    66,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    96,    97,    98,    99,   100,   101,   102,
     103,   106,   107,   110,   111,   114,   123,   130,   139,   144,
     151,   152,   153,   154,   155,   156,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   171,   172,   176,   175,
     186,   189,   189,   192,   192,   195,   195,   198,   198,   203,
     204,   207,   208,   211,   214,   215,   216,   217,   220,   221,
     224,   227,   230,   231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "MENORIGUAL", "MAYORQUE", "MENORQUE", "'='", "','", "'-'", "'+'", "'*'",
  "'/'", "'('", "')'", "':'", "$accept", "lista", "$@1", "exp_l", "tupla",
  "tupla_decl", "func_call", "exp", "tipo", "tipo_l", "args", "init",
  "asign", "decl", "in", "comp", "inst", "inst_l", "bloque", "$@2",
  "dentroBloque", "func", "$@3", "$@4", "$@5", "$@6", "cases", "when",
  "for", "if", "elif_l", "else", "while", "rango", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    61,    44,    45,    43,    42,    47,    40,    41,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    53,    52,    52,    52,    52,    52,    52,    54,
      54,    55,    56,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    62,    63,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    70,    69,
      71,    73,    72,    74,    72,    75,    72,    76,    72,    77,
      77,    78,    78,    79,    80,    80,    80,    80,    81,    81,
      82,    83,    84,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     2,     0,     2,     3,     1,     1,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     4,     4,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     3,     1,     2,     0,     4,
       1,     0,     8,     0,     9,     0,     8,     0,     9,     3,
       5,     7,     7,     5,     5,     6,     6,     7,     5,     6,
       4,     5,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    24,    25,    23,    27,    26,    28,    29,    30,
       0,    34,    36,    35,    37,    38,    39,     0,    40,     0,
       0,     0,     0,     0,    68,     0,     0,    31,    33,    22,
       0,     0,     0,     0,     0,    21,    66,     8,    64,     0,
      60,    61,    63,    62,     2,    32,     0,     0,    13,     4,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    41,     0,     1,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      57,    58,    59,     0,    67,     0,     6,     0,    46,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      70,     0,    11,     0,     0,    12,    55,    54,    20,    19,
      53,    52,    51,    50,    15,    16,    18,    17,     0,     0,
      47,     7,     3,     0,    75,     0,     0,    92,     0,     0,
       0,     0,     0,    48,    49,     0,    69,    10,    42,    45,
      71,     0,     0,    43,    77,     0,     0,     0,    84,    91,
      83,     0,    73,     0,     0,     0,    93,     0,     0,     0,
       0,     0,    86,    85,     0,     0,     0,    44,     0,     0,
      81,    82,     0,     0,    87,     0,     0,    76,     0,    79,
       0,     0,    72,     0,    78,     0,     0,    90,    74,    80,
      88,    89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    87,    61,    27,    28,    29,    30,    31,    64,
     126,    32,    33,    34,    58,    35,    36,    37,    38,    60,
     101,    39,   151,   165,   142,   155,   158,    40,    41,    42,
     162,   163,    43,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -141
static const yytype_int16 yypact[] =
{
     159,     1,  -141,  -141,  -141,  -141,  -141,  -141,  -141,    22,
     159,  -141,  -141,  -141,  -141,  -141,  -141,     5,  -141,    83,
      83,    83,    10,    83,  -141,   231,    30,  -141,  -141,  -141,
     226,    21,    57,    59,    61,  -141,   195,    64,  -141,   159,
    -141,  -141,  -141,  -141,  -141,  -141,    83,    14,  -141,  -141,
      33,    19,    83,   322,    40,   345,   368,   -25,    45,   246,
     195,    49,   414,    63,    51,  -141,  -141,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,   -33,
    -141,  -141,  -141,    93,  -141,   159,  -141,   159,   474,  -141,
      26,    83,    95,    97,   100,   103,    83,    83,   111,  -141,
    -141,    75,  -141,    83,   301,  -141,    98,    98,   488,   488,
     102,   102,   102,   102,   -11,   -11,  -141,  -141,    83,   104,
      72,  -141,  -141,   301,  -141,   114,    80,   434,    96,    99,
     101,   101,   454,  -141,  -141,   101,  -141,  -141,  -141,   474,
    -141,    85,    90,   108,  -141,    83,    83,    83,    55,  -141,
    -141,   105,  -141,   142,   301,   106,   474,   298,   122,   123,
      83,   131,   136,  -141,   171,   134,   101,  -141,   175,    83,
    -141,  -141,   391,   176,  -141,   101,   177,  -141,   101,   266,
     178,   101,  -141,   101,  -141,    83,   101,  -141,  -141,  -141,
     167,  -141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,    -2,  -141,    91,    -4,  -141,  -141,   -19,   -22,    92,
     -88,  -141,  -141,  -141,  -141,  -141,  -141,   -26,   -70,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -140,  -141,  -141,  -141,
       7,    52,  -141,     6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -6
static const yytype_int16 yytable[] =
{
      53,    55,    56,    63,    59,    48,    62,   159,    49,   118,
      84,    96,    97,    44,    83,   119,    50,     2,     3,     4,
       5,    57,     6,     7,     8,    51,    45,    88,    62,    45,
      65,   141,    79,    62,   100,    77,    78,    86,    83,    11,
      12,    13,    14,    15,    16,   189,    18,    48,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     148,   149,    52,    89,    46,   150,   167,    47,   125,    80,
      47,    81,   127,    82,   123,   124,    85,   132,   132,   160,
     161,    90,    63,   121,    62,   122,     2,     3,     4,     5,
      93,     6,     7,     8,    51,    98,   177,   125,   102,   139,
     105,    63,   133,   134,   120,   182,   104,   128,   184,   129,
     136,   187,   130,   188,   118,   131,   190,    11,    12,    13,
      14,    15,    16,   135,    18,   143,   156,   157,   157,   144,
     146,    52,   125,   147,   152,    24,    71,    72,    73,    74,
     153,   172,    75,    76,    77,    78,    75,    76,    77,    78,
     179,   154,   123,   140,   166,   164,   168,   170,   171,    -5,
       1,   161,     2,     3,     4,     5,   157,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   173,    20,   175,   176,    21,    22,   178,   181,   183,
     186,   160,    23,    24,   137,     0,   138,   191,     2,     3,
       4,     5,     0,     6,     7,     8,     9,    25,    11,    12,
      13,    14,    15,    16,   174,    18,    19,     0,    20,     0,
       0,    21,    22,     0,     0,     0,     0,     0,    23,    24,
       0,     0,     0,     0,     2,     3,     4,     5,    66,     6,
       7,     8,    51,    25,    11,    12,    13,    14,    15,    16,
       0,    18,     0,     0,    67,    68,    69,    70,    99,     0,
       0,     0,     0,     0,    71,    72,    73,    74,     0,     0,
      75,    76,    77,    78,    67,    68,    69,    70,   185,    25,
       0,     0,     0,     0,    71,    72,    73,    74,     0,     0,
      75,    76,    77,    78,    67,    68,    69,    70,     0,     0,
       0,     0,     0,     0,    71,    72,    73,    74,     0,     0,
      75,    76,    77,    78,    11,    12,    13,    14,    15,    16,
     169,    18,     0,     0,     0,     0,    67,    68,    69,    70,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
       0,     0,    75,    76,    77,    78,     0,     0,     0,   123,
      67,    68,    69,    70,    91,     0,     0,     0,     0,     0,
      71,    72,    73,    74,     0,     0,    75,    76,    77,    78,
       0,     0,    92,    67,    68,    69,    70,     0,     0,     0,
       0,     0,     0,    71,    72,    73,    74,     0,     0,    75,
      76,    77,    78,     0,     0,    94,    67,    68,    69,    70,
       0,     0,     0,     0,     0,     0,    71,    72,    73,    74,
       0,     0,    75,    76,    77,    78,     0,     0,    95,    67,
      68,    69,    70,     0,     0,     0,     0,     0,     0,    71,
      72,    73,    74,     0,     0,    75,    76,    77,    78,     0,
       0,   180,    67,    68,    69,    70,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,     0,   103,    75,    76,
      77,    78,    67,    68,    69,    70,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,     0,   145,    75,    76,
      77,    78,    67,    68,    69,    70,    91,     0,     0,     0,
       0,     0,    71,    72,    73,    74,     0,     0,    75,    76,
      77,    78,    67,    68,    69,    70,     0,     0,     0,     0,
       0,     0,    71,    72,    73,    74,    67,    68,    75,    76,
      77,    78,     0,     0,     0,     0,    71,    72,    73,    74,
       0,     0,    75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,    25,    23,     9,    25,   147,    10,    42,
      36,    36,    37,    12,    36,    48,    11,     3,     4,     5,
       6,    11,     8,     9,    10,    11,     7,    46,    47,     7,
       0,   119,    11,    52,    60,    46,    47,    39,    60,    13,
      14,    15,    16,    17,    18,   185,    20,    51,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
     130,   131,    48,    49,    42,   135,   154,    48,    90,    12,
      48,    12,    91,    12,    48,    49,    12,    96,    97,    24,
      25,    48,   104,    85,   103,    87,     3,     4,     5,     6,
      50,     8,     9,    10,    11,    50,   166,   119,    49,   118,
      49,   123,    96,    97,    11,   175,    43,    12,   178,    12,
      35,   181,    12,   183,    42,    12,   186,    13,    14,    15,
      16,    17,    18,    12,    20,    11,   145,   146,   147,    49,
      34,    48,   154,    34,    49,    34,    38,    39,    40,    41,
      50,   160,    44,    45,    46,    47,    44,    45,    46,    47,
     169,    43,    48,    49,    12,    50,    50,    35,    35,     0,
       1,    25,     3,     4,     5,     6,   185,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    50,    23,    12,    50,    26,    27,    12,    12,    12,
      12,    24,    33,    34,   103,    -1,   104,   190,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    48,    13,    14,
      15,    16,    17,    18,   162,    20,    21,    -1,    23,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    12,     8,
       9,    10,    11,    48,    13,    14,    15,    16,    17,    18,
      -1,    20,    -1,    -1,    28,    29,    30,    31,    12,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    28,    29,    30,    31,    12,    48,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      44,    45,    46,    47,    13,    14,    15,    16,    17,    18,
      22,    20,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    -1,    48,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
      -1,    -1,    50,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    -1,    -1,    50,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    -1,    -1,    50,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    44,    45,
      46,    47,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    41,    28,    29,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      23,    26,    27,    33,    34,    48,    52,    55,    56,    57,
      58,    59,    62,    63,    64,    66,    67,    68,    69,    72,
      78,    79,    80,    83,    12,     7,    42,    48,    55,    52,
      11,    11,    48,    58,    84,    58,    58,    11,    65,    58,
      70,    54,    58,    59,    60,     0,    12,    28,    29,    30,
      31,    38,    39,    40,    41,    44,    45,    46,    47,    11,
      12,    12,    12,    59,    68,    12,    52,    53,    58,    49,
      48,    32,    50,    50,    50,    50,    36,    37,    50,    12,
      68,    71,    49,    43,    43,    49,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    42,    48,
      11,    52,    52,    48,    49,    59,    61,    58,    12,    12,
      12,    12,    58,    84,    84,    12,    35,    54,    60,    58,
      49,    61,    75,    11,    49,    43,    34,    34,    69,    69,
      69,    73,    49,    50,    43,    76,    58,    58,    77,    77,
      24,    25,    81,    82,    50,    74,    12,    61,    50,    22,
      35,    35,    58,    50,    82,    12,    50,    69,    12,    58,
      50,    12,    69,    12,    69,    12,    12,    69,    69,    77,
      69,    81
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 48 "miint.y"
    {printf(" en expresión\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 56 "miint.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 57 "miint.y"
    { (yyval.type) = (yyvsp[(3) - (3)].type)->add((yyvsp[(1) - (3)].type)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 60 "miint.y"
    { (yyval.type) = (yyvsp[(2) - (3)].type); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 63 "miint.y"
    { (yyval.type) = (yyvsp[(2) - (3)].type); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 65 "miint.y"
    { printf("%s----------------------------------------------------\n", (yyvsp[(1) - (2)].str)); (yyval.str) = (yyvsp[(1) - (2)].str); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 66 "miint.y"
    { (yyval.str) = (yyvsp[(1) - (3)].str); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 69 "miint.y"
    { if ((yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) { (yyval.type) = (yyvsp[(1) - (3)].type); } else { yyerror((char*) ((std::string("Tipos diferentes: '") + (yyvsp[(1) - (3)].type)->toString() + "' y '" + (yyvsp[(3) - (3)].type)->toString() + "'").c_str())); } ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 70 "miint.y"
    { if ((yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) { (yyval.type) = (yyvsp[(1) - (3)].type); } else { yyerror("Tipos diferentes"); } ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 71 "miint.y"
    { if ((yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) { (yyval.type) = (yyvsp[(1) - (3)].type); } else { yyerror("Tipos diferentes"); } ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 72 "miint.y"
    { if ((yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) { (yyval.type) = (yyvsp[(1) - (3)].type); } else { yyerror("Tipos diferentes"); } ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 73 "miint.y"
    { PrimitiveType* booleano = new PrimitiveType(BOOL);  if ((yyvsp[(1) - (3)].type)->equals(booleano) && (yyvsp[(3) - (3)].type)->equals(booleano)) { (yyval.type) = (yyvsp[(1) - (3)].type); } else { yyerror("Expresiones no booleanas"); } delete booleano; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 74 "miint.y"
    { PrimitiveType* booleano = new PrimitiveType(BOOL); if ((yyvsp[(1) - (3)].type)->equals(booleano) && (yyvsp[(3) - (3)].type)->equals(booleano)) { (yyval.type) = (yyvsp[(1) - (3)].type); } else { yyerror("Expresiones no booleanas"); } delete booleano; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 75 "miint.y"
    { (yyval.type) = new PrimitiveType(BOOL); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 76 "miint.y"
    { (yyval.type) = scope->getFunction((yyvsp[(1) - (1)].str))->getType(); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 77 "miint.y"
    { (yyval.type) = new PrimitiveType(INT); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 78 "miint.y"
    { (yyval.type) = new PrimitiveType(FLOAT); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 79 "miint.y"
    { (yyval.type) = new PrimitiveType(DOUBLE); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 80 "miint.y"
    { (yyval.type) = new PrimitiveType(LONG); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 81 "miint.y"
    { (yyval.type) = new PrimitiveType(BOOL); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 82 "miint.y"
    { (yyval.type) = new PrimitiveType(CHAR); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 83 "miint.y"
    { (yyval.type) = new PrimitiveType(STRING); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 84 "miint.y"
    { (yyval.type) = scope->getVariable((yyvsp[(1) - (1)].str))->getType(); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 85 "miint.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 86 "miint.y"
    { 
						Type* type = scope->getVariable((yyvsp[(1) - (2)].str))->getType();
						if(type->isTuple())
							(yyval.type) = ((TupleType*)type)->getSubType((yyvsp[(2) - (2)].i)); 
						else
							yyerror("Acceso a una tupla");
					
					;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 96 "miint.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 97 "miint.y"
    { (yyval.type) = new PrimitiveType(INT); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 98 "miint.y"
    { (yyval.type) = new PrimitiveType(FLOAT); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 99 "miint.y"
    { (yyval.type) = new PrimitiveType(LONG); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 100 "miint.y"
    { (yyval.type) = new PrimitiveType(DOUBLE); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 101 "miint.y"
    { (yyval.type) = new PrimitiveType(BOOL); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 102 "miint.y"
    { (yyval.type) = new PrimitiveType(STRING); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 103 "miint.y"
    { (yyval.type) = new PrimitiveType(CHAR); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 106 "miint.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 107 "miint.y"
    { (yyval.type) = (yyvsp[(3) - (3)].type)->add((yyvsp[(1) - (3)].type)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 110 "miint.y"
    { std::vector<ParameterNode*> *vector = new std::vector<ParameterNode*>(); vector->push_back(new ParameterNode((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].str))); (yyval.args_v) = vector; ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 111 "miint.y"
    { (yyvsp[(4) - (4)].args_v)->push_back(new ParameterNode((yyvsp[(1) - (4)].type), (yyvsp[(2) - (4)].str))); (yyval.args_v) = (yyvsp[(4) - (4)].args_v); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 114 "miint.y"
    {
                                                            if (scope->haveVariable((yyvsp[(2) - (4)].str))) {
                                                                logError("Se intenta crear '" + std::string((yyvsp[(2) - (4)].str)) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineVariable((yyvsp[(2) - (4)].str), new VariableNode((yyvsp[(1) - (4)].type)));
                                                            }
						;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 123 "miint.y"
    {
                                                            if (!scope->existsVariable((yyvsp[(1) - (3)].str))) {
                                                                logError("Se intenta usar '" + std::string((yyvsp[(1) - (3)].str)) + "', pero no existe."); 
                                                            }
							;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 130 "miint.y"
    {
                                                            if (scope->haveVariable((yyvsp[(2) - (2)].str))) {
                                                                logError("Se intenta crear '" + std::string((yyvsp[(2) - (2)].str)) + "', pero ya existe."); 
                                                            } else {
                                                                scope->defineVariable((yyvsp[(2) - (2)].str), new VariableNode((yyvsp[(1) - (2)].type)));
                                                            }
						;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 139 "miint.y"
    {
                                                            if (!scope->existsVariable((yyvsp[(1) - (3)].str))) {
                                                                logError("Se intenta usar '" + std::string((yyvsp[(1) - (3)].str)) + "', pero no existe."); 
                                                            }
						;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 144 "miint.y"
    {
                                                            if (!scope->existsVariable((yyvsp[(1) - (3)].str))) {
                                                                logError("Se intenta usar '" + std::string((yyvsp[(1) - (3)].str)) + "', pero no existe."); 
                                                            }
						;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 151 "miint.y"
    { if (isNumberType((yyvsp[(1) - (3)].type)) && (yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) (yyval.type) = new PrimitiveType(BOOL); else logError("Expresiones no booleanas") ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 152 "miint.y"
    { if (isNumberType((yyvsp[(1) - (3)].type)) && (yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) (yyval.type) = new PrimitiveType(BOOL); else logError("Expresiones no booleanas") ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 153 "miint.y"
    { if (isNumberType((yyvsp[(1) - (3)].type)) && (yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) (yyval.type) = new PrimitiveType(BOOL); else logError("Expresiones no booleanas") ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 154 "miint.y"
    { if (isNumberType((yyvsp[(1) - (3)].type)) && (yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) (yyval.type) = new PrimitiveType(BOOL); else logError("Expresiones no booleanas") ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 155 "miint.y"
    { if (isNumberType((yyvsp[(1) - (3)].type)) && (yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) (yyval.type) = new PrimitiveType(BOOL); else logError("Expresiones no booleanas") ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 156 "miint.y"
    { if (isNumberType((yyvsp[(1) - (3)].type)) && (yyvsp[(1) - (3)].type)->equals((yyvsp[(3) - (3)].type))) (yyval.type) = new PrimitiveType(BOOL); else logError("Expresiones no booleanas") ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 176 "miint.y"
    { if (!scope->isEmpty()) scope = new Scope(scope); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 179 "miint.y"
    { 
            					Scope* oldScope = scope;
            					scope = scope->getParent();
            					delete oldScope; 
            				  ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 189 "miint.y"
    {
                                                            creaFuncion((yyvsp[(2) - (4)].str), (yyvsp[(1) - (4)].type), NULL);
						;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 192 "miint.y"
    {
                                                            creaFuncion((yyvsp[(2) - (5)].str), (yyvsp[(1) - (5)].type), (yyvsp[(4) - (5)].args_v));
					        ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 195 "miint.y"
    {
                                                            creaFuncion((yyvsp[(2) - (4)].str), new PrimitiveType(VOID), NULL);
					        ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 198 "miint.y"
    {
                                                            creaFuncion((yyvsp[(2) - (5)].str), new PrimitiveType(VOID), (yyvsp[(4) - (5)].args_v));
					        ;}
    break;



/* Line 1455 of yacc.c  */
#line 2041 "miint.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 233 "miint.y"


PrimitiveType nums[] = {PrimitiveType(INT), PrimitiveType(LONG), PrimitiveType(FLOAT), PrimitiveType(DOUBLE)};
std::vector<PrimitiveType> numeros (nums, nums + sizeof(PrimitiveType) / sizeof(Type));

bool isNumberType(Type* tipo){
	for(std::vector<PrimitiveType>::iterator i = numeros.begin(); i != numeros.end(); i++) {
		if ((*i).equals(tipo)) {
			return true;
		}
	}
	return false;
}

int main(int argc, char** argv) {
	scope = new Scope();
//Funciones del sistema
	scope->defineFunction("print", new FunctionNode(new PrimitiveType(VOID)));
	scope->defineFunction("getchar", new FunctionNode(new PrimitiveType(CHAR)));
	if (argc>1) yyin=fopen(argv[1],"r");
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

