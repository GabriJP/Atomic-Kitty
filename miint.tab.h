
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
     NOTIN = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 23 "miint.y"
 float f; double d; int i; long l; char c; char* str; Type* type; std::vector<ParameterNode*> *args_v;


/* Line 1676 of yacc.c  */
#line 93 "miint.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


