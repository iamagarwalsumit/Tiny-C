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
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT = 270,
    FOR = 271,
    GOTO = 272,
    IF = 273,
    INLINE = 274,
    INT = 275,
    LONG = 276,
    REGISTER = 277,
    RESTRICT = 278,
    RETURN = 279,
    SHORT = 280,
    SIGNED = 281,
    SIZEOF = 282,
    STATIC = 283,
    STRUCT = 284,
    SWITCH = 285,
    TYPEDEF = 286,
    UNION = 287,
    UNSIGNED = 288,
    VOID = 289,
    VOLATILE = 290,
    WHILE = 291,
    BOOL = 292,
    COMPLEX = 293,
    IMAGINARY = 294,
    ID = 295,
    INT_NO = 296,
    FLOAT_NO = 297,
    CHARACTER = 298,
    STRING = 299,
    LEFT_SQUARE_BRACE = 300,
    RIGHT_SQUARE_BRACE = 301,
    LEFT_ROUND_BRACE = 302,
    RIGHT_ROUND_BRACE = 303,
    LEFT_CURLY_BRACE = 304,
    RIGHT_CURLY_BRACE = 305,
    PERIOD = 306,
    ARROW = 307,
    INCREMENT = 308,
    DECREMENT = 309,
    AMPERSAND = 310,
    MULTIPLY = 311,
    ADD = 312,
    SUBTRACT = 313,
    TILDA = 314,
    NEGATION = 315,
    DIVIDE = 316,
    MODULUS = 317,
    LEFT_SHIFT = 318,
    RIGHT_SHIFT = 319,
    LESS_THAN = 320,
    GREATER_THAN = 321,
    LESS_THAN_EQUAL_TO = 322,
    GREATER_THAN_EQUAL_TO = 323,
    DOUBLE_EQUAL = 324,
    NOT_EQUAL = 325,
    XOR = 326,
    BITWISE_OR = 327,
    BINARY_AND = 328,
    BINARY_OR = 329,
    QUESTION_MARK = 330,
    COLON = 331,
    SEMI_COLON = 332,
    ELLIPSIS = 333,
    EQUAL = 334,
    MULTIPLY_EQUAL = 335,
    DIVIDE_EQUAL = 336,
    MODULUS_EQUAL = 337,
    PLUS_EQUAL = 338,
    MINUS_EQUAL = 339,
    LEFT_SHIFT_EQUAL = 340,
    RIGHT_SHIFT_EQUAL = 341,
    AND_EQUAL = 342,
    XOR_EQUAL = 343,
    OR_EQUAL = 344,
    COMMA = 345,
    HASH = 346
  };
#endif
/* Tokens.  */
#define AUTO 258
#define BREAK 259
#define CASE 260
#define CHAR 261
#define CONST 262
#define CONTINUE 263
#define DEFAULT 264
#define DO 265
#define DOUBLE 266
#define ELSE 267
#define ENUM 268
#define EXTERN 269
#define FLOAT 270
#define FOR 271
#define GOTO 272
#define IF 273
#define INLINE 274
#define INT 275
#define LONG 276
#define REGISTER 277
#define RESTRICT 278
#define RETURN 279
#define SHORT 280
#define SIGNED 281
#define SIZEOF 282
#define STATIC 283
#define STRUCT 284
#define SWITCH 285
#define TYPEDEF 286
#define UNION 287
#define UNSIGNED 288
#define VOID 289
#define VOLATILE 290
#define WHILE 291
#define BOOL 292
#define COMPLEX 293
#define IMAGINARY 294
#define ID 295
#define INT_NO 296
#define FLOAT_NO 297
#define CHARACTER 298
#define STRING 299
#define LEFT_SQUARE_BRACE 300
#define RIGHT_SQUARE_BRACE 301
#define LEFT_ROUND_BRACE 302
#define RIGHT_ROUND_BRACE 303
#define LEFT_CURLY_BRACE 304
#define RIGHT_CURLY_BRACE 305
#define PERIOD 306
#define ARROW 307
#define INCREMENT 308
#define DECREMENT 309
#define AMPERSAND 310
#define MULTIPLY 311
#define ADD 312
#define SUBTRACT 313
#define TILDA 314
#define NEGATION 315
#define DIVIDE 316
#define MODULUS 317
#define LEFT_SHIFT 318
#define RIGHT_SHIFT 319
#define LESS_THAN 320
#define GREATER_THAN 321
#define LESS_THAN_EQUAL_TO 322
#define GREATER_THAN_EQUAL_TO 323
#define DOUBLE_EQUAL 324
#define NOT_EQUAL 325
#define XOR 326
#define BITWISE_OR 327
#define BINARY_AND 328
#define BINARY_OR 329
#define QUESTION_MARK 330
#define COLON 331
#define SEMI_COLON 332
#define ELLIPSIS 333
#define EQUAL 334
#define MULTIPLY_EQUAL 335
#define DIVIDE_EQUAL 336
#define MODULUS_EQUAL 337
#define PLUS_EQUAL 338
#define MINUS_EQUAL 339
#define LEFT_SHIFT_EQUAL 340
#define RIGHT_SHIFT_EQUAL 341
#define AND_EQUAL 342
#define XOR_EQUAL 343
#define OR_EQUAL 344
#define COMMA 345
#define HASH 346

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 10 "ass5_13CS10061.y" /* yacc.c:1909  */

    int intval;
    double floatval;
    char charval;
    char *strval;
  	struct idAttr Id_Attr;
  	struct expAttr E;
  	struct varAttr VarDecl;
  	union initAttr Initialiser;
  	opCode U;
  	int I;
  	struct listNode *Next;
  	struct paramList *Param;

#line 251 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
