/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    AUTO_KEYWORD = 258,
    RESTRICT_KEYWORD = 259,
    UNSIGNED_KEYWORD = 260,
    BREAK_KEYWORD = 261,
    EXTERN_KEYWORD = 262,
    RETURN_KEYWORD = 263,
    VOID_KEYWORD = 264,
    CASE_KEYWORD = 265,
    FLOAT_KEYWORD = 266,
    SHORT_KEYWORD = 267,
    VOLATILE_KEYWORD = 268,
    CHAR_KEYWORD = 269,
    FOR_KEYWORD = 270,
    SIGNED_KEYWORD = 271,
    WHILE_KEYWORD = 272,
    CONST_KEYWORD = 273,
    GOTO_KEYWORD = 274,
    SIZEOF_KEYWORD = 275,
    BOOL_KEYWORD = 276,
    CONTINUE_KEYWORD = 277,
    IF_KEYWORD = 278,
    STATIC_KEYWORD = 279,
    COMPLEX_KEYWORD = 280,
    DEFAULT_KEYWORD = 281,
    INLINE_KEYWORD = 282,
    STRUCT_KEYWORD = 283,
    IMAGINARY_KEYWORD = 284,
    DO_KEYWORD = 285,
    INT_KEYWORD = 286,
    SWITCH_KEYWORD = 287,
    DOUBLE_KEYWORD = 288,
    LONG_KEYWORD = 289,
    TYPEDEF_KEYWORD = 290,
    ELSE_KEYWORD = 291,
    REGISTER_KEYWORD = 292,
    UNION_KEYWORD = 293,
    IDENTIFIER = 294,
    INTEGER_CONSTANT = 295,
    FLOAT_CONSTANT = 296,
    CHAR_CONSTANT = 297,
    STRING_LITERAL = 298,
    VAL_AT = 299,
    PLUS_PLUS = 300,
    MINUS_MINUS = 301,
    LEFT_SHIFT = 302,
    RIGHT_SHIFT = 303,
    LESS_EQUAL = 304,
    GREATER_EQUAL = 305,
    EQUAL_EQUAL = 306,
    NOT_EQUAL = 307,
    LOGICAL_AND = 308,
    LOGICAL_OR = 309,
    ELLIPSES = 310,
    STAR_EQUAL = 311,
    BY_EQUAL = 312,
    PERCENT_EQUAL = 313,
    PLUS_EQUAL = 314,
    MINUS_EQUAL = 315,
    LEFT_SHIFT_EQUAL = 316,
    RIGHT_SHIFT_EQUAL = 317,
    AND_EQUAL = 318,
    BITWISENOT_EQUAL = 319,
    OR_EQUAL = 320,
    IF_CONFLICT = 321
  };
#endif
/* Tokens.  */
#define AUTO_KEYWORD 258
#define RESTRICT_KEYWORD 259
#define UNSIGNED_KEYWORD 260
#define BREAK_KEYWORD 261
#define EXTERN_KEYWORD 262
#define RETURN_KEYWORD 263
#define VOID_KEYWORD 264
#define CASE_KEYWORD 265
#define FLOAT_KEYWORD 266
#define SHORT_KEYWORD 267
#define VOLATILE_KEYWORD 268
#define CHAR_KEYWORD 269
#define FOR_KEYWORD 270
#define SIGNED_KEYWORD 271
#define WHILE_KEYWORD 272
#define CONST_KEYWORD 273
#define GOTO_KEYWORD 274
#define SIZEOF_KEYWORD 275
#define BOOL_KEYWORD 276
#define CONTINUE_KEYWORD 277
#define IF_KEYWORD 278
#define STATIC_KEYWORD 279
#define COMPLEX_KEYWORD 280
#define DEFAULT_KEYWORD 281
#define INLINE_KEYWORD 282
#define STRUCT_KEYWORD 283
#define IMAGINARY_KEYWORD 284
#define DO_KEYWORD 285
#define INT_KEYWORD 286
#define SWITCH_KEYWORD 287
#define DOUBLE_KEYWORD 288
#define LONG_KEYWORD 289
#define TYPEDEF_KEYWORD 290
#define ELSE_KEYWORD 291
#define REGISTER_KEYWORD 292
#define UNION_KEYWORD 293
#define IDENTIFIER 294
#define INTEGER_CONSTANT 295
#define FLOAT_CONSTANT 296
#define CHAR_CONSTANT 297
#define STRING_LITERAL 298
#define VAL_AT 299
#define PLUS_PLUS 300
#define MINUS_MINUS 301
#define LEFT_SHIFT 302
#define RIGHT_SHIFT 303
#define LESS_EQUAL 304
#define GREATER_EQUAL 305
#define EQUAL_EQUAL 306
#define NOT_EQUAL 307
#define LOGICAL_AND 308
#define LOGICAL_OR 309
#define ELLIPSES 310
#define STAR_EQUAL 311
#define BY_EQUAL 312
#define PERCENT_EQUAL 313
#define PLUS_EQUAL 314
#define MINUS_EQUAL 315
#define LEFT_SHIFT_EQUAL 316
#define RIGHT_SHIFT_EQUAL 317
#define AND_EQUAL 318
#define BITWISENOT_EQUAL 319
#define OR_EQUAL 320
#define IF_CONFLICT 321

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 12 "ass6_13CS10061.y" /* yacc.c:1909  */

  int intval;
  float floatval;
  char charval;
  char *strval;
  struct id_attr_struct id_attr;
  struct exp_attr_struct exp_attr;
  struct var_decl_attr_struct var_decl_attr;
  union initializer_attr_struct initializer_attr;
  quadEnum u_op_attr;
  int instr;
  struct list_node_Type *N_attr;
  struct list_param *param_attr;

#line 201 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
