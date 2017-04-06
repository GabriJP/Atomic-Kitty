
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
     VALOR_LONG = 262,
     VALOR_CHAR = 263,
     VALOR_STRING = 264,
     IDENTIFICADOR = 265,
     FIN_DE_LINEA = 266,
     INT = 267,
     LONG = 268,
     FLOAT = 269,
     DOUBLE = 270,
     BOOL = 271,
     STRING = 272,
     VOID = 273,
     CHAR = 274,
     WHEN = 275,
     WHEN_CASE = 276,
     IF = 277,
     ELIF = 278,
     ELSE = 279,
     WHILE = 280,
     FOR = 281,
     NOTIS = 282,
     IS = 283,
     OR = 284,
     AND = 285,
     RANGE = 286,
     RETURN = 287,
     ABREBLOQUE = 288,
     CIERRABLOQUE = 289,
     IN = 290,
     NOTIN = 291,
     ACCESO = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 15 "miint.y"
 float f; double d; int i; long l; char c; char* str; 


/* Line 1676 of yacc.c  */
#line 93 "miint.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


