/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ass5_13CS10061.y" /* yacc.c:339  */

#include <stdio.h>
#include <iostream>
extern int yylex();
#include "ass5_13CS10061_translator.h"
#include <string.h>
void yyerror(const char* s);

#line 75 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
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
#line 10 "ass5_13CS10061.y" /* yacc.c:355  */

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

#line 312 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 327 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   914

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  341

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   346

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   135,   136,   137,   138,   139,   143,   144,
     146,   148,   149,   150,   151,   152,   154,   158,   159,   163,
     164,   169,   170,   171,   172,   173,   174,   178,   179,   180,
     181,   182,   183,   187,   188,   192,   193,   195,   197,   202,
     203,   205,   210,   211,   212,   216,   217,   219,   221,   223,
     228,   229,   231,   236,   237,   241,   242,   246,   247,   252,
     253,   258,   259,   264,   265,   270,   271,   275,   276,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     294,   295,   299,   300,   304,   307,   312,   313,   315,   316,
     317,   318,   319,   320,   324,   325,   329,   330,   334,   335,
     339,   340,   341,   342,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   363,   364,   367,
     368,   372,   374,   376,   380,   381,   385,   386,   390,   391,
     392,   395,   398,   399,   403,   404,   405,   407,   409,   411,
     413,   415,   419,   424,   428,   432,   440,   444,   451,   452,
     455,   459,   466,   478,   490,   501,   507,   511,   518,   519,
     523,   530,   535,   539,   546,   550,   557,   564,   565,   569,
     573,   580,   584,   591,   595,   600,   605,   610,   615,   623,
     627,   631,   638,   642,   650,   655,   665,   669,   677,   678,
     686,   687,   689,   694,   695,   697,   699,   704,   705,   706,
     707,   711,   715,   723,   727,   734,   738,   748,   752,   760,
     761,   767,   780
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "BOOL",
  "COMPLEX", "IMAGINARY", "ID", "INT_NO", "FLOAT_NO", "CHARACTER",
  "STRING", "LEFT_SQUARE_BRACE", "RIGHT_SQUARE_BRACE", "LEFT_ROUND_BRACE",
  "RIGHT_ROUND_BRACE", "LEFT_CURLY_BRACE", "RIGHT_CURLY_BRACE", "PERIOD",
  "ARROW", "INCREMENT", "DECREMENT", "AMPERSAND", "MULTIPLY", "ADD",
  "SUBTRACT", "TILDA", "NEGATION", "DIVIDE", "MODULUS", "LEFT_SHIFT",
  "RIGHT_SHIFT", "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQUAL_TO",
  "GREATER_THAN_EQUAL_TO", "DOUBLE_EQUAL", "NOT_EQUAL", "XOR",
  "BITWISE_OR", "BINARY_AND", "BINARY_OR", "QUESTION_MARK", "COLON",
  "SEMI_COLON", "ELLIPSIS", "EQUAL", "MULTIPLY_EQUAL", "DIVIDE_EQUAL",
  "MODULUS_EQUAL", "PLUS_EQUAL", "MINUS_EQUAL", "LEFT_SHIFT_EQUAL",
  "RIGHT_SHIFT_EQUAL", "AND_EQUAL", "XOR_EQUAL", "OR_EQUAL", "COMMA",
  "HASH", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_listopt", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression",
  "assignment_expressionopt", "assignment_operator", "expression",
  "expressionopt", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_listopt",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_listopt", "enum_specifier", "enumerator_list",
  "enumerator", "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "type_qualifier_listopt", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "identifier_listopt",
  "type_name", "initializer", "initializer_list", "designation",
  "designationopt", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list",
  "identifieropt", "M", "K", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346
};
# endif

#define YYPACT_NINF -258

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-258)))

#define YYTABLE_NINF -213

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     735,  -258,  -258,  -258,  -258,    14,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,   135,   735,   735,  -258,   735,   735,   660,
    -258,  -258,   -10,    20,  -258,   135,    15,    11,     6,  -258,
     243,   -28,    64,  -258,  -258,  -258,  -258,  -258,  -258,    52,
      -6,  -258,  -258,    15,  -258,   135,   106,  -258,   135,   620,
      56,   150,   697,   -28,    29,   -35,  -258,  -258,  -258,  -258,
    -258,    34,   791,  -258,  -258,  -258,  -258,  -258,   562,    91,
     812,   812,  -258,  -258,  -258,  -258,  -258,  -258,  -258,   173,
     123,   833,  -258,    76,    82,    80,   166,   174,   101,   103,
      63,    99,   177,  -258,  -258,  -258,   326,  -258,  -258,  -258,
     163,   161,   854,  -258,   135,   133,    93,  -258,    97,   144,
     833,  -258,    35,   562,  -258,  -258,   -11,   769,  -258,   769,
     147,   833,   157,    17,  -258,   106,     7,  -258,   562,  -258,
    -258,   833,   833,   176,   181,  -258,  -258,  -258,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,   833,  -258,
    -258,   833,   833,   833,   833,   833,   833,   833,   833,   833,
     833,   833,   833,   833,   833,   833,   833,   833,   833,   833,
     136,   833,   168,   179,   448,   214,   227,   223,   833,   232,
     251,   228,  -258,  -258,   -37,  -258,  -258,  -258,  -258,   240,
    -258,  -258,  -258,  -258,  -258,   163,   833,   833,   261,  -258,
     263,  -258,  -258,   280,   270,  -258,  -258,  -258,  -258,  -258,
     264,  -258,   833,  -258,  -258,  -258,   770,   265,  -258,  -258,
     178,  -258,  -258,  -258,   268,   -34,   272,   231,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,    76,    76,    82,    82,    80,
      80,    80,    80,   166,   166,   174,   101,   103,    63,    99,
     -62,  -258,   247,  -258,   448,   288,   507,   248,   833,   236,
     250,   833,   833,   448,  -258,  -258,   391,   282,   292,  -258,
    -258,  -258,  -258,  -258,   306,  -258,    91,  -258,  -258,  -258,
     106,   306,  -258,  -258,   833,   833,   448,  -258,   310,   294,
     833,  -258,    -7,  -258,    -1,     0,  -258,  -258,  -258,  -258,
      22,  -258,  -258,  -258,  -258,   833,   833,   295,   448,   448,
     448,  -258,   191,     3,   297,   833,   365,  -258,  -258,  -258,
     301,   833,   339,   448,  -258,   340,   448,  -258,   448,  -258,
    -258
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   102,   105,   128,   110,   210,   100,   109,   131,   107,
     108,   103,   130,   106,   111,   101,   112,   104,   129,   113,
     114,   115,   204,    95,    86,    88,   116,    90,    92,     0,
     201,   203,   123,     0,   134,     0,   142,     0,    94,    96,
      98,   133,     0,    87,    89,    91,    93,     1,   202,     0,
       0,   146,   144,   143,    85,     0,     0,   207,    95,     0,
       0,   149,   159,   132,   126,     0,   124,   135,   147,   145,
      97,    98,     0,     2,     3,     4,     6,     5,     0,   168,
       0,     0,    27,    28,    29,    30,    31,    32,     8,    21,
      33,     0,    35,    39,    42,    45,    50,    53,    55,    57,
      59,    61,    63,    65,   161,    99,     0,   208,   205,   206,
     149,   148,    68,   156,   155,     0,   150,   152,   158,     0,
       0,   121,     0,     0,    25,    80,     0,   120,   160,   120,
       0,     0,     0,     0,   167,     0,     0,   169,     0,    22,
      23,     0,    18,     0,     0,    13,    14,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,    33,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     2,   182,   188,     0,   186,   187,   173,   174,   211,
     184,   175,   176,   177,   178,   148,     0,     0,    28,    67,
       0,   154,   140,     0,     0,   141,    84,   127,   122,   125,
       0,     7,     0,   119,   117,   118,     0,     0,   172,   162,
     168,   164,   166,   170,     0,     0,     0,    17,    19,    11,
      12,    66,    36,    37,    38,    40,    41,    43,    44,    46,
      47,    48,    49,    51,    52,    54,    56,    58,    60,    62,
       0,   199,     0,   198,     0,     0,    83,     0,     0,    82,
       0,     0,     0,     0,   189,   183,     0,     0,     0,   139,
     136,   151,   153,   157,    26,    81,   168,    34,   171,   163,
       0,     0,     9,    10,     0,     0,     0,   181,     0,     0,
      83,   197,     0,   200,     0,     0,   179,   185,   137,   138,
       0,   165,    20,    64,   180,     0,    83,     0,     0,     0,
       0,    15,   168,     0,     0,    83,   190,   192,   193,    16,
       0,    83,     0,     0,   194,     0,     0,   191,     0,   196,
     195
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -258,  -258,  -258,  -258,  -258,   -47,  -258,   -85,    95,   118,
     104,   116,   215,   216,   217,   213,   242,  -258,  -115,   -55,
    -258,  -258,   -78,  -257,  -120,   -36,     2,  -258,  -258,   337,
    -258,   -32,    42,   293,  -258,  -258,   314,   -29,  -258,   -15,
     381,   -18,   -48,   327,  -258,  -258,   226,  -258,  -258,  -102,
    -132,   155,  -258,  -220,  -258,   307,  -119,  -258,   237,  -258,
     183,  -258,  -258,  -258,  -258,  -258,   413,  -258,  -258,  -258,
    -258,  -258
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    88,    89,   236,   237,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   125,
     210,   158,   194,   270,   217,    22,    58,    37,    38,    39,
      24,    25,   128,   224,    26,    65,    66,    27,    28,    71,
      41,    42,    53,   112,   115,   116,   117,   118,   119,   130,
     105,   133,   134,   135,   136,   137,   196,   197,   198,   199,
     200,   201,   202,   203,   204,    29,    30,    31,    59,    33,
     276,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     126,   104,    23,   231,    57,   216,   160,    51,    40,   299,
     290,   227,   292,   111,   295,   121,   216,    61,    52,    62,
      50,   220,     3,   107,    68,   124,    43,    44,   222,    45,
      46,    23,    51,   139,   140,    69,   234,   221,    12,  -209,
     274,   318,    67,   317,   159,   126,   127,   319,   320,   129,
      18,   330,   131,   222,    32,   122,   222,   209,   132,   324,
     126,   262,   205,   235,   114,   265,   216,   229,   332,    49,
     195,    36,   321,   159,   335,    64,   242,   243,   244,   222,
     104,    51,    68,   222,   159,   218,   232,   238,    54,   222,
     222,   127,    64,   222,   129,   127,    55,   127,   129,   211,
     129,   260,   290,   241,    34,   106,   127,   230,   120,   129,
     269,    35,   322,    56,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   161,    72,   159,   176,   131,   162,   163,   164,
     165,   287,   132,   166,   167,   297,    73,    74,    75,    76,
      77,   277,   278,    78,   306,    79,   174,     3,   311,    80,
      81,    82,    83,    84,    85,    86,    87,   285,     3,   223,
       3,   223,   177,    12,   175,    34,    68,   314,   110,   159,
     313,   212,    35,   213,    12,    18,    12,   214,   269,   207,
     302,    36,   215,   304,   305,   226,    18,   228,    18,   326,
     327,   328,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   261,   337,   114,   239,   339,   141,   340,
     142,   240,   269,   131,   143,   144,   145,   146,   289,   132,
     300,   168,   169,   170,   171,   104,   131,   323,   269,   312,
     195,   329,   132,   172,   173,   263,     1,   269,   159,     2,
       3,   178,   179,   269,     4,   264,     5,     6,     7,   245,
     246,   266,     8,     9,    10,    11,    12,   267,    13,    14,
     268,    15,   249,   250,   251,   252,    16,    17,    18,   271,
      19,    20,    21,     1,   247,   248,     2,     3,   253,   254,
     275,     4,  -212,     5,     6,     7,   108,   109,   272,     8,
       9,    10,    11,    12,   273,    13,    14,   279,    15,   280,
     283,   288,   284,    16,    17,    18,   291,    19,    20,    21,
     293,   294,    56,   296,   298,   301,   222,   303,   308,     1,
     180,   181,     2,     3,   182,   183,   184,     4,   309,     5,
       6,     7,   185,   186,   187,     8,     9,    10,    11,    12,
     188,    13,    14,    72,    15,   286,   189,   315,   281,    16,
      17,    18,   190,    19,    20,    21,   191,    74,    75,    76,
      77,   316,   325,    78,   331,   106,   192,   333,   334,    80,
      81,    82,    83,    84,    85,    86,    87,   336,   338,   255,
     258,   256,    70,   257,     1,   180,   181,     2,     3,   182,
     183,   184,     4,   193,     5,     6,     7,   185,   186,   187,
       8,     9,    10,    11,    12,   188,    13,    14,    72,    15,
     259,   189,   225,    63,    16,    17,    18,   190,    19,    20,
      21,   191,    74,    75,    76,    77,   219,   206,    78,   282,
     106,   310,    48,   233,    80,    81,    82,    83,    84,    85,
      86,    87,   180,   181,     0,     0,   182,   183,   184,   307,
       0,     0,     0,     0,   185,   186,   187,     0,   193,     0,
       0,     0,   188,     0,     0,    72,     0,     0,   189,     0,
       0,     0,     0,     0,   190,     0,     0,     0,   191,    74,
      75,    76,    77,     0,     0,    78,     0,   106,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,   193,     8,     9,    10,    11,
      12,     0,    13,    14,    72,    15,     0,     0,     0,     0,
      16,    17,    18,     0,    19,    20,    21,    73,    74,    75,
      76,    77,     0,     0,    78,     0,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,     2,     3,
       0,     0,     0,     4,     0,     5,     0,     7,     0,     0,
       0,     0,     9,    10,     0,    12,     0,    13,    14,    72,
       0,     0,     0,     0,     0,    16,    17,    18,     0,    19,
      20,    21,    73,    74,    75,    76,    77,     0,     0,    78,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,     1,     0,     0,     2,     3,     0,     0,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21,
      47,     0,     0,     1,     0,     0,     2,     3,     0,   106,
       0,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,     0,
       0,     0,     0,    16,    17,    18,     0,    19,    20,    21,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    14,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,    19,    20,    21,   113,     1,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,     0,     0,     0,     0,    16,    17,
      18,     0,    19,    20,    21,     2,     3,     0,     0,     0,
       4,     0,     5,     0,     7,     0,     0,     0,     0,     9,
      10,     0,    12,     0,    13,    14,     0,    72,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     0,
      73,    74,    75,    76,    77,     0,     0,    78,    72,   286,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    73,    74,    75,    76,    77,     0,     0,   123,    72,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    73,    74,    75,    76,    77,     0,     0,   138,
      72,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    73,    74,    75,    76,    77,     0,     0,
      78,    72,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    73,    74,    75,    76,    77,     0,
       0,    78,     0,     0,     0,     0,     0,    80,    81,    82,
     208,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
      78,    56,     0,   135,    40,   120,    91,    36,    23,   266,
     230,   131,    46,    61,    76,    50,   131,    45,    36,    47,
      35,   123,     7,    59,    53,    72,    24,    25,    90,    27,
      28,    29,    61,    80,    81,    53,   138,    48,    23,    49,
      77,    48,    48,   300,    91,   123,    78,    48,    48,    78,
      35,    48,    45,    90,    40,    90,    90,   112,    51,   316,
     138,   181,   110,   141,    62,   184,   181,    50,   325,    49,
     106,    56,    50,   120,   331,    40,   161,   162,   163,    90,
     135,   110,   111,    90,   131,    50,    79,   142,    77,    90,
      90,   123,    40,    90,   123,   127,    90,   129,   127,   114,
     129,   179,   322,   158,    40,    49,   138,    90,    79,   138,
     188,    47,    90,    79,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    56,    27,   181,    72,    45,    61,    62,    57,
      58,   226,    51,    63,    64,   264,    40,    41,    42,    43,
      44,   206,   207,    47,   273,    49,    55,     7,   290,    53,
      54,    55,    56,    57,    58,    59,    60,   222,     7,   127,
       7,   129,    73,    23,    71,    40,   205,   296,    28,   226,
     295,    48,    47,    90,    23,    35,    23,    90,   266,    28,
     268,    56,    48,   271,   272,    48,    35,    40,    35,   318,
     319,   320,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    77,   333,   213,    40,   336,    45,   338,
      47,    40,   300,    45,    51,    52,    53,    54,    50,    51,
     266,    65,    66,    67,    68,   290,    45,   315,   316,   294,
     276,    50,    51,    69,    70,    77,     3,   325,   295,     6,
       7,    74,    75,   331,    11,    76,    13,    14,    15,   164,
     165,    47,    19,    20,    21,    22,    23,    40,    25,    26,
      47,    28,   168,   169,   170,   171,    33,    34,    35,    47,
      37,    38,    39,     3,   166,   167,     6,     7,   172,   173,
      50,    11,    49,    13,    14,    15,    59,    60,    47,    19,
      20,    21,    22,    23,    76,    25,    26,    46,    28,    46,
      40,    46,    48,    33,    34,    35,    48,    37,    38,    39,
      48,    90,    79,    76,    36,    77,    90,    77,    46,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    46,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    49,    30,    47,    78,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    77,    77,    47,    77,    49,    50,    12,    77,    53,
      54,    55,    56,    57,    58,    59,    60,    48,    48,   174,
     177,   175,    55,   176,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    77,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     178,    30,   129,    42,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   122,   110,    47,   213,
      49,   286,    29,   136,    53,    54,    55,    56,    57,    58,
      59,    60,     4,     5,    -1,    -1,     8,     9,    10,   276,
      -1,    -1,    -1,    -1,    16,    17,    18,    -1,    77,    -1,
      -1,    -1,    24,    -1,    -1,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    -1,    -1,    47,    -1,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    77,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,
      -1,    -1,    20,    21,    -1,    23,    -1,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
       0,    -1,    -1,     3,    -1,    -1,     6,     7,    -1,    49,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    38,    39,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    37,    38,    39,    40,     3,    -1,
      -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,
      25,    26,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    37,    38,    39,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    27,    -1,    -1,
      -1,    -1,    33,    34,    35,    -1,    37,    38,    39,    -1,
      40,    41,    42,    43,    44,    -1,    -1,    47,    27,    49,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    40,    41,    42,    43,    44,    -1,    -1,    47,    27,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    40,    41,    42,    43,    44,    -1,    -1,    47,
      27,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    40,    41,    42,    43,    44,    -1,    -1,
      47,    27,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    40,    41,    42,    43,    44,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   117,   118,   122,   123,   126,   129,   130,   157,
     158,   159,    40,   161,    40,    47,    56,   119,   120,   121,
     131,   132,   133,   118,   118,   118,   118,     0,   158,    49,
     131,   129,   133,   134,    77,    90,    79,   117,   118,   160,
     163,    45,    47,   132,    40,   127,   128,    48,   129,   133,
     121,   131,    27,    40,    41,    42,    43,    44,    47,    49,
      53,    54,    55,    56,    57,    58,    59,    60,    93,    94,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   142,    49,   117,   150,   150,
      28,   134,   135,    40,   118,   136,   137,   138,   139,   140,
      79,    50,    90,    47,    97,   111,   114,   123,   124,   129,
     141,    45,    51,   143,   144,   145,   146,   147,    47,    97,
      97,    45,    47,    51,    52,    53,    54,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   113,    97,
      99,    56,    61,    62,    57,    58,    63,    64,    65,    66,
      67,    68,    69,    70,    55,    71,    72,    73,    74,    75,
       4,     5,     8,     9,    10,    16,    17,    18,    24,    30,
      36,    40,    50,    77,   114,   117,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   134,   135,    28,    56,   111,
     112,   131,    48,    90,    90,    48,   110,   116,    50,   128,
     141,    48,    90,   124,   125,   125,    48,   116,    40,    50,
      90,   142,    79,   147,   141,   114,    95,    96,   111,    40,
      40,   111,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   102,   102,   103,   103,   104,   105,   106,   107,   108,
     114,    77,   116,    77,    76,   148,    47,    40,    47,   114,
     115,    47,    47,    76,    77,    50,   162,   111,   111,    46,
      46,    78,   138,    40,    48,   111,    49,    99,    46,    50,
     145,    48,    46,    48,    90,    76,    76,   148,    36,   115,
     117,    77,   114,    77,   114,   114,   148,   152,    46,    46,
     143,   142,   111,   110,   148,    47,    77,   115,    48,    48,
      48,    50,    90,   114,   115,    77,   148,   148,   148,    50,
      48,    77,   115,    12,    77,   115,    48,   148,    48,   148,
     148
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    97,    97,    98,    98,    98,
      98,    98,    98,    99,    99,   100,   100,   100,   100,   101,
     101,   101,   102,   102,   102,   103,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     114,   114,   115,   115,   116,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   125,
     125,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   130,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   132,   133,   133,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   140,   140,
     141,   142,   142,   142,   143,   143,   144,   145,   145,   146,
     146,   147,   147,   148,   148,   148,   148,   148,   148,   149,
     149,   149,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   154,   155,   155,   155,   155,   156,   156,   156,
     156,   157,   157,   158,   158,   159,   159,   160,   160,   161,
     161,   162,   163
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       4,     3,     3,     2,     2,     6,     7,     1,     0,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     1,     3,     1,     2,     1,     2,
       1,     2,     1,     2,     1,     0,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       0,     5,     6,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     3,     5,     6,     6,     5,
       4,     4,     1,     2,     2,     3,     1,     2,     1,     0,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     0,
       1,     1,     3,     4,     2,     4,     2,     1,     0,     1,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     1,     3,     1,     1,     1,     2,
       5,     7,     5,     5,     7,     9,     8,     3,     2,     2,
       3,     1,     2,     1,     1,     4,     4,     1,     2,     1,
       0,     0,     0
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
#line 134 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expression->id\n");}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 135 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf ("       primary_expression->int_constant\n");}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 136 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expression->float_constant\n");}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 137 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expression->string\n");}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 138 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expresion->character\n");}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 139 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expression->(expression)\n");}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 143 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->primary_expression\n");}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 145 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression[expression]\n");}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 147 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression(argument_expression_listopt)\n");}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression.id\n");}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 149 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression->id\n");}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 150 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression++\n");}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 151 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression--\n");}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 153 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->(type_name){initializer_list}\n");}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 155 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->(type_name){initializer_list,}\n");}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 163 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       argument_expression_list->assignment_expression\n");}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 165 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       argument_expression_list->assignment_expression,assignment_expression\n");}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 169 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->postfix_expression\n");}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 170 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->++ unary_expression\n");}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 171 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->-- unary_expression\n");}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 172 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->unary_operator cast_expression\n");}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->sizeof(unary_expression)\n");}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 174 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->(type_name)\n");}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 178 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->&\n");}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 179 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->*\n");}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 180 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->+\n");}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 181 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->-\n");}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 182 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->~\n");}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 183 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->!\n");}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 187 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       cast_expression->unary_expression\n");}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 188 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       cast_expression->(type_name) cast_expression\n");}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 192 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       multiplicative_expression->cast_expression\n");}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 194 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       multiplicative_expression->multiplicative_expression * cast_expression\n");}
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 196 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       multiplicative_expression->multiplicative_expression / cast_expression\n");}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 198 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       multiplicative_expression->multiplicative_expression %% cast_expression\n");}
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 202 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       additive_expression->multiplicative_expression\n");}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 204 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       additive_expression->additive expression + multiplicative_expression\n");}
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 206 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       additive_expression->additive expression - multiplicative_expression\n");}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 210 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       shift_expression->additive_expression\n");}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 211 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       shift_expression->shift_expression << additive_expression\n");}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 212 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       shift_expression->shift_expression >> additive_expression\n");}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 216 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       relational_expression->shift_expression\n");}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 218 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       relational_expression->relational_expression < shift_expression\n");}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 220 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       relational_expression->relational_expression > shift_expression\n");}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 222 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       relational_expression->relational_expression <= shift_expression\n");}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 224 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("        relational_expression->relational_expression >= shift_expression\n");}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 228 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("        equality_expression->relational_expression\n");}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 230 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("        equality_expression->equality_expression == relational_expression\n");}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 232 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       equality_expression->equality_expression != relational_expression\n");}
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 236 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       and_expression->equality_expression\n");}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 237 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       and_expression->and_expression & equality_expression\n");}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 241 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       exclusive_or_expression->and_expression\n");}
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 242 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       exclusive_or_expression->exclusive_or_expression ^ and_expression\n");}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 246 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       inclusive_or_expression->exclusive_or_expression\n");}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 248 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       inclusive_or_expression->inclusive_or_expression | exclusive_or_expression\n");}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 252 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       logical_and_expression->inclusive_or_expression\n");}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 254 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       logical_and_expression->logical_and_expression && inclusive_or_expression\n");}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 258 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       logical_or_expression->logical_and_expression\n");}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 260 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       logical_or_expression->logical_or_expression || logical_and_expression\n");}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 264 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       conditional_expression->logical_or_expression\n");}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 266 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       conditional_expression->logical_or_expression ? expression : conditional_expression\n");}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 270 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_expression->conditional_expression\n");}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 272 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_expression->unary_expression assignment_operator assignment_expression\n");}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 280 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> =\n");}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 281 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> *=\n");}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 282 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> /=\n");}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 283 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> %%=\n");}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 284 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> +=\n");}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 285 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> -=\n");}
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 286 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> <<=\n");}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 287 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> >>=\n");}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 288 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> &=\n");}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 289 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> ^=\n");}
#line 2242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 290 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> |=\n");}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 294 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       expression->assignment_expression\n");}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 295 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       expression->expression,assignment_expression\n");}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 304 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       constant_expression->conditional_expression\n");}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 308 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration->declaration_specifiers init_declarator_listopt ;\n");}
#line 2272 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 312 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->storage_class_specifier\n");}
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 314 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->storage_class_specifier declaration_specifiers\n");}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 315 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->type_specifier");}
#line 2290 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 316 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->type_specifier declaration_specifiers\n");}
#line 2296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 317 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->type_qualifier");}
#line 2302 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 318 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->type_qualifier declaration_specifiers\n");}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 319 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->function_specifier");}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 320 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->function_specifier declaration_specifiers\n");}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 329 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       init_declarator_list->init_declarator\n");}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 330 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       init_declarator_list->init_declarator_list , init_declarator\n");}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 334 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       init_declarator->declarator\n");}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 335 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       init_declarator->declarator = initializer\n");}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 339 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       storage_class_specifier-> extern\n");}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 340 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       storage_class_specifier-> static\n");}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 341 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       storage_class_specifier-> auto\n");}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 342 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       storage_class_specifier-> register\n");}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 346 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->void\n");}
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 347 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->char\n");}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 348 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->short\n");}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 349 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->int\n");}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 350 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->long\n");}
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 351 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->float\n");}
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 352 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->double\n");}
#line 2410 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 353 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->signed\n");}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 354 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->unsigned\n");}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 355 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->bool\n");}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 356 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->complex\n");}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 357 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->imaginary\n");}
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 358 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->enum_specifier\n");}
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 363 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       specifier_qualifier_list->type_specifier specifier_qualifier_listopt\n");}
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 364 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       specifier_qualifier_list->type_qualifier specifier_qualifier_listopt\n");}
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 373 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       enum_specifier->enum idopt {enumerator_list}\n");}
#line 2464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 375 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       enum_specifier->enum idopt {enumerator_list , }\n");}
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 376 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       enum_specifier->enum id\n");}
#line 2476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 380 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       enumerator_list->enumerator\n");}
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 381 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       enumerator_list->enumerator_list, enumerator\n");}
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 385 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       enumerator->id\n");}
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 386 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       enumerator->id = constant_expression\n");}
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 390 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_qualifier-> const\n");}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 391 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_qualifier-> volatile\n");}
#line 2512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 392 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_qualifier-> restrict\n");}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 395 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       function_specifier->inline\n");}
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 398 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declarator->pointer direct_declarator\n");}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 399 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       declarator->direct_declarator\n");}
#line 2536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 403 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->id\n");}
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 404 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->(declarator)\n");}
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 406 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->[type_qualifier_listopt assignment_expressionopt]\n");}
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 408 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->[static type_qualifier_listopt assignment_expression]\n");}
#line 2560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 410 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->[type_qualifier_list static assignment_expression]\n");}
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 412 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->[type_qualifier_listopt *]\n");}
#line 2572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 414 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->(parameter_type_list)\n");}
#line 2578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 416 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->(identifier_listopt)\n");}
#line 2584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 420 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf ("	 	pointer-> *\n ");
		(yyval.VarDecl).type = newType (PtrVoidType,-1);
	}
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 425 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       pointer-> * type_qualifier_listopt\n");
	}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 429 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       pointer-> * type_qualifier_listopt pointer\n");
	}
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 433 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       pointer-> * type_qualifier_listopt pointer\n");
	}
#line 2617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 441 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       type_qualifier_list->type_qualifier\n");
	}
#line 2625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 445 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       type_qualifier_list->type_qualifier_list type_qualifier\n");
	}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 456 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       parameter_type_list->parameter_list\n");
	}
#line 2641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 460 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       parameter_type_list->parameter_list, ...\n");
	}
#line 2649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 467 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       parameter_list->parameter_declaration\n");

		if (!declDone)
		{
			temp = createSymbolTable();
			symbolTableRow row((yyvsp[0].VarDecl).name,(yyvsp[0].VarDecl).type,0,(yyvsp[0].VarDecl).width,-1,0);
			temp->insert (row);

		}
	}
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 479 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       parameter_list->parameter_list, parameter_declaration\n");
		
		if (!declDone)
		{
			symbolTableRow row((yyvsp[0].VarDecl).name,(yyvsp[0].VarDecl).type,0,(yyvsp[0].VarDecl).width,-1,0);
			temp-> insert (row);
		}
	}
#line 2679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 491 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       parameter_declaration->declaration_specifiers declarator");
		
		if (!declDone) // function has not been declared previously
		{
			(yyval.VarDecl).name = (yyvsp[0].VarDecl).name ;
			(yyval.VarDecl).width = (yyvsp[-1].VarDecl).width * (yyvsp[0].VarDecl).width;
			(yyval.VarDecl).type = mergeType ((yyvsp[0].VarDecl).type,(yyvsp[-1].VarDecl).type); 
		}
	}
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 502 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       parameter_declaration->declaration_specifiers");
	}
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 508 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       identifier_list->id\n");
	}
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 512 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       identifier_list->identifier_list, id\n");
	}
#line 2718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 524 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       type_name->specifier_qualifier_list\n");
	}
#line 2726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 531 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       initializer->assignment_expression\n");
		(yyval.Initialiser) = (yyvsp[0].E).val;
	}
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 536 "ass5_13CS10061.y" /* yacc.c:1646  */
    {	
		printf("       initializer->{initializer_list}\n");
	}
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 540 "ass5_13CS10061.y" /* yacc.c:1646  */
    {	
		printf("       initializer->{initializer_list ,  }\n");
	}
#line 2751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 547 "ass5_13CS10061.y" /* yacc.c:1646  */
    {	
		printf("       initializer_list->designationopt initializer\n");
	}
#line 2759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 551 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       initializer_list->initializer_list , designationopt initializer\n");
	}
#line 2767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 558 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       designation-> designator_list =\n");
	}
#line 2775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 570 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       designator_list->designator\n");
	}
#line 2783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 574 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       designator_list->designator_list designator\n");
	}
#line 2791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 581 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       designator->[constant_expression]\n");
	}
#line 2799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 585 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       designator->.id\n");
	}
#line 2807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 592 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       statement-> labeled_statement\n");
	}
#line 2815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 596 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       statement-> compound_statement\n");
		(yyval.E) = (yyvsp[0].E);
	}
#line 2824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 601 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       statement-> expression_statement\n");
		(yyval.E) = (yyvsp[0].E);
	}
#line 2833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 606 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       statement-> selection_statement\n");
		(yyval.E) = (yyvsp[0].E);
	}
#line 2842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 611 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       statement-> iteration_statement\n");\
		(yyval.E) = (yyvsp[0].E);
	}
#line 2851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 616 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       statement-> jump_statement\n");
		(yyval.E) = (yyvsp[0].E);
	}
#line 2860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 624 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       labeled_statement-> id : statement\n"); /* Labeled statements are not handled */
	}
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 628 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       case constant_expression: statement\n"); /* Labeled statements are not handled */
	}
#line 2876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 632 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       default : statement\n"); /* Labeled statements are not handled */
	}
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 639 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       compound_statement->{ }\n");
	}
#line 2892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 643 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       compound_statement->{block_item_listopt}\n");
		(yyval.E) = (yyvsp[-1].E);
	}
#line 2901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 651 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       block_item_list->block_item\n");
		(yyval.E) = (yyvsp[0].E);
	}
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 656 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       block_item_list-> block_item_list block_item\n");
		// backpatch($1.NL,$2);
		(yyval.E) = (yyvsp[0].E);
	}
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 666 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       block_item->declaration\n");
	}
#line 2928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 670 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       block_item->statement\n");
		(yyval.E) = (yyvsp[0].E);
	}
#line 2937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 677 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       expression_statement->;\n");}
#line 2943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 679 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       expression_statement->expression ;\n");
		(yyval.E)= (yyvsp[-1].E);
	}
#line 2952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 686 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       selection_statement->if (expression) statement\n");}
#line 2958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 688 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       selection_statement->if (expression) statement else statement\n");}
#line 2964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 690 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       selection_statement->switch (expression) statement\n");}
#line 2970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 694 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       iteration_statement->while (expression) statement\n");}
#line 2976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 696 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       iteration_statement->do statement while (expression) ;\n");}
#line 2982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 698 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       iteration_statement->for (expressionopt;expressionopt;expressionopt) statement\n");}
#line 2988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 700 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       iteration_statement->for (declaration expressionopt;expressionopt;expressionopt) statement\n");}
#line 2994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 704 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       jump_statement-> goto id;\n");}
#line 3000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 705 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       jump_statement-> continue;\n");}
#line 3006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 706 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       jump_statement-> break;\n");}
#line 3012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 707 "ass5_13CS10061.y" /* yacc.c:1646  */
    {printf("       jump_statement-> return expressionopt;\n");}
#line 3018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 712 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       translation_unit->external_declaration\n");
	}
#line 3026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 716 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       translation_unit->translation_unit external_declaration\n");
		/* multiple translation units are not supported */
	}
#line 3035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 724 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       external_declaration->function_definition\n");
	}
#line 3043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 728 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       external_declaration->declaration\n");
	}
#line 3051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 735 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
	  	printf("       function_definition->declaration_specifiers declarator declaration_list compound_statement;\n");
	  }
#line 3059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 739 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
	 	printf("       function_definition->declaration_specifiers declarator compound_statement;\n");
	 	current = global;

	 	/* exiting out of the function scope so the current symbol table should be restored back to global */
	 }
#line 3070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 749 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       declaration_list->declaration\n");
	}
#line 3078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 753 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		printf("       declaration_list->declaration_list declaration\n");
	}
#line 3086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 767 "ass5_13CS10061.y" /* yacc.c:1646  */
    {
		(yyval.I) = nextInstr; // augmentation to store the value of the nextInstr
	}
#line 3094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 780 "ass5_13CS10061.y" /* yacc.c:1646  */
    {

	}
#line 3102 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3106 "y.tab.c" /* yacc.c:1646  */
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
#line 784 "ass5_13CS10061.y" /* yacc.c:1906  */



extern char yytext[];
extern int column;

void yyerror(const char *s)
{
	fflush(stdout);
	printf("       \n%*s\n%*s\n", column, "^", column, s);
}
