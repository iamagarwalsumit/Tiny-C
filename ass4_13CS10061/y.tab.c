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
#line 1 "ass4_13CS10061.y" /* yacc.c:339  */

#include <stdio.h>
extern int yylex();

#line 71 "y.tab.c" /* yacc.c:339  */

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
#line 6 "ass4_13CS10061.y" /* yacc.c:355  */

    int intval;

#line 297 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 312 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   874

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  337

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
       0,   104,   104,   105,   106,   107,   108,   109,   113,   114,
     116,   118,   119,   120,   121,   122,   124,   128,   129,   133,
     134,   139,   140,   141,   142,   143,   144,   148,   149,   150,
     151,   152,   153,   157,   158,   162,   163,   165,   167,   172,
     173,   175,   180,   181,   182,   186,   187,   189,   191,   193,
     198,   199,   201,   206,   207,   211,   212,   216,   217,   222,
     223,   228,   229,   234,   235,   240,   241,   245,   246,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     264,   265,   269,   270,   274,   277,   282,   283,   285,   286,
     287,   288,   289,   290,   294,   295,   299,   300,   304,   305,
     309,   310,   311,   312,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   333,   334,   337,
     338,   342,   344,   346,   350,   351,   355,   356,   360,   361,
     362,   365,   368,   369,   373,   374,   375,   377,   379,   381,
     383,   385,   389,   390,   395,   396,   400,   401,   404,   405,
     409,   410,   413,   414,   417,   418,   422,   423,   427,   431,
     432,   433,   437,   438,   443,   447,   448,   452,   453,   457,
     458,   462,   463,   464,   465,   466,   467,   471,   472,   473,
     477,   481,   482,   486,   487,   491,   492,   496,   500,   501,
     503,   508,   509,   511,   513,   518,   519,   520,   521,   525,
     526,   531,   532,   536,   541,   542,   546,   547,   551,   552
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
  "block_item_listopt", "block_item", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "declaration_list", "declaration_listopt", "identifieropt", YY_NULLPTR
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

#define YYPACT_NINF -224

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-224)))

#define YYTABLE_NINF -209

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     682,  -224,  -224,  -224,  -224,   -22,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,    84,   682,   682,  -224,   682,   682,   607,
    -224,  -224,   -26,    20,  -224,    84,    67,     7,   -46,  -224,
     235,    83,    47,  -224,  -224,  -224,  -224,  -224,  -224,    52,
      48,  -224,    67,    79,  -224,    84,   684,  -224,    84,   682,
      55,    63,   644,    83,    68,   -36,  -224,  -224,  -224,  -224,
    -224,    78,   163,  -224,  -224,  -224,  -224,  -224,   546,    -5,
     761,   761,  -224,  -224,  -224,  -224,  -224,  -224,  -224,   120,
     785,   782,  -224,    27,    42,    89,   111,    76,   100,    71,
      94,    95,    87,  -224,  -224,  -224,  -224,   318,  -224,    67,
     116,   803,  -224,    84,   122,   105,  -224,   110,   144,   782,
    -224,     1,   546,  -224,  -224,   -37,   739,  -224,   739,   154,
     782,   173,   -29,  -224,   684,    -6,  -224,   546,  -224,  -224,
     782,   782,   174,   186,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,   782,  -224,  -224,
     782,   782,   782,   782,   782,   782,   782,   782,   782,   782,
     782,   782,   782,   782,   782,   782,   782,   782,   782,   150,
     782,   152,   156,   491,   187,   193,   196,   782,   197,   198,
     164,   157,   175,  -224,  -224,  -224,  -224,   376,   201,  -224,
    -224,  -224,  -224,  -224,   782,   782,   207,  -224,   213,  -224,
    -224,   272,   222,  -224,  -224,  -224,  -224,  -224,   216,  -224,
     782,  -224,  -224,  -224,   740,   219,  -224,  -224,    -2,  -224,
    -224,  -224,   218,   -19,   223,   177,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,    27,    27,    42,    42,    89,    89,    89,
      89,   111,   111,    76,   100,    71,    94,    95,   -52,  -224,
     200,  -224,   491,   241,   434,   203,   782,   204,   782,   782,
     491,  -224,  -224,  -224,   236,   242,  -224,  -224,  -224,  -224,
    -224,   240,  -224,    -5,  -224,  -224,  -224,   684,   240,  -224,
    -224,   782,   782,   491,  -224,   243,   224,   782,  -224,   -33,
    -224,   -18,   -14,  -224,  -224,  -224,    -8,  -224,  -224,  -224,
    -224,   782,   782,   225,   491,   491,   491,  -224,    82,   -13,
     226,   782,   284,  -224,  -224,  -224,   227,   782,   251,   491,
    -224,   260,   491,  -224,   491,  -224,  -224
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   102,   105,   128,   110,   209,   100,   109,   131,   107,
     108,   103,   130,   106,   111,   101,   112,   104,   129,   113,
     114,   115,   202,    95,    86,    88,   116,    90,    92,     0,
     199,   201,   123,     0,   134,     0,   147,     0,    94,    96,
      98,   133,     0,    87,    89,    91,    93,     1,   200,     0,
       0,   144,   146,   142,    85,     0,     0,   204,    95,   206,
       0,   147,   157,   132,   126,     0,   124,   135,   145,   143,
      97,    98,     0,     2,     3,     4,     6,     5,     0,   166,
       0,     0,    27,    28,    29,    30,    31,    32,     8,    21,
      33,     0,    35,    39,    42,    45,    50,    53,    55,    57,
      59,    61,    63,    65,   159,    99,   205,    83,   203,   147,
     146,    68,   154,   153,     0,   148,   150,   156,     0,     0,
     121,     0,     0,    25,    80,     0,   120,   158,   120,     0,
       0,     0,     0,   165,     0,     0,   167,     0,    22,    23,
       0,    18,     0,     0,    13,    14,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,    33,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,     0,     0,    83,     0,     0,
       2,    82,     0,   185,   186,   171,   172,    83,     0,   181,
     173,   174,   175,   176,     0,     0,    28,    67,     0,   152,
     140,     0,     0,   141,    84,   127,   122,   125,     0,     7,
       0,   119,   117,   118,     0,     0,   170,   160,   166,   162,
     164,   168,     0,     0,     0,    17,    19,    11,    12,    66,
      36,    37,    38,    40,    41,    43,    44,    46,    47,    48,
      49,    51,    52,    54,    56,    58,    60,    62,     0,   197,
       0,   196,    83,     0,    83,     0,     0,     0,     0,     0,
      83,   187,   182,   180,     0,     0,   139,   136,   149,   151,
     155,    26,    81,   166,    34,   169,   161,     0,     0,     9,
      10,     0,     0,    83,   179,     0,     0,    83,   195,     0,
     198,     0,     0,   177,   137,   138,     0,   163,    20,    64,
     178,     0,    83,     0,    83,    83,    83,    15,   166,     0,
       0,    83,   188,   190,   191,    16,     0,    83,     0,    83,
     192,     0,    83,   189,    83,   194,   193
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,  -224,  -224,  -224,   -55,  -224,   -81,    25,    32,
      17,    37,   139,   141,   138,   140,   142,  -224,  -117,   -56,
    -224,  -224,   -75,  -171,  -121,   -39,     4,  -224,  -224,   262,
    -224,   -70,     8,   190,  -224,  -224,   199,   102,  -224,   -16,
     288,   294,   302,   -49,  -224,  -224,   153,  -224,  -224,  -100,
    -128,    66,  -224,  -223,  -224,   231,  -133,  -224,   309,  -224,
    -224,   191,  -224,  -224,  -224,  -224,  -224,   341,  -224,  -224,
    -224,  -224
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    88,    89,   234,   235,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   124,
     208,   157,   191,   192,   215,    22,    58,    37,    38,    39,
      24,    25,   127,   222,    26,    65,    66,    27,    28,    71,
      41,    42,    52,    53,   114,   115,   116,   117,   118,   129,
     105,   132,   133,   134,   135,   136,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,    29,    30,    31,    59,
      60,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     104,    57,   214,   125,    23,   287,   229,    40,   126,   225,
     159,   219,   111,   214,   120,   314,   267,   123,    32,    50,
     106,   227,   218,  -208,   292,   138,   139,   289,    43,    44,
     315,    45,    46,    23,   316,   326,   158,   232,   220,   130,
     130,    64,   317,   130,    55,   131,   131,   125,   286,   131,
     263,   216,   126,   220,   121,   207,   126,   220,   126,   260,
     204,   228,   125,   214,   158,   233,   113,   126,   193,    49,
       3,   220,   220,   230,     3,   158,   220,   220,   104,   240,
     241,   242,   318,   160,    54,   236,    12,    34,   161,   162,
      12,   109,    64,   296,    35,   287,    67,   209,    18,   163,
     164,   239,    18,   258,   107,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,     3,    34,   158,   313,   130,    61,   294,
      62,    35,   325,   131,   221,    36,   221,   303,    51,    12,
      36,   320,   174,   284,   205,   171,   172,   119,   274,   275,
     328,    18,   165,   166,    68,   173,   331,    56,   193,   307,
     310,   177,   178,    51,   282,   140,   175,   141,   176,   158,
     210,   142,   143,   144,   145,   309,   167,   168,   169,   170,
     128,   322,   323,   324,   247,   248,   249,   250,   243,   244,
      72,   299,   213,   301,   302,   211,   333,   245,   246,   335,
     212,   336,   224,    73,    74,    75,    76,    77,   251,   252,
     122,    51,    68,   226,   237,   113,    80,    81,    82,    83,
      84,    85,    86,    87,   128,   297,   238,   259,   128,   261,
     128,   104,   262,   265,   264,   308,   319,   158,     1,   128,
     270,     2,     3,   266,   268,   269,     4,   220,     5,     6,
       7,   273,   271,   276,     8,     9,    10,    11,    12,   277,
      13,    14,   280,    15,   281,   285,   288,   291,    16,    17,
      18,   290,    19,    20,    21,     1,   293,   295,     2,     3,
     298,   300,   304,     4,  -207,     5,     6,     7,   305,   283,
     311,     8,     9,    10,    11,    12,   329,    13,    14,   332,
      15,   312,   321,   327,   330,    16,    17,    18,   334,    19,
      20,    21,   253,   255,    56,   254,   256,    70,   223,   257,
     217,     1,   179,   180,     2,     3,   181,   182,   183,     4,
      63,     5,     6,     7,   184,   185,   186,     8,     9,    10,
      11,    12,   187,    13,    14,    72,    15,    69,   188,   306,
     278,    16,    17,    18,   189,    19,    20,    21,   190,    74,
      75,    76,    77,   110,   279,    78,   231,   107,  -184,   108,
      48,    80,    81,    82,    83,    84,    85,    86,    87,     1,
     179,   180,     2,     3,   181,   182,   183,     4,   272,     5,
       6,     7,   184,   185,   186,     8,     9,    10,    11,    12,
     187,    13,    14,    72,    15,     0,   188,     0,     0,    16,
      17,    18,   189,    19,    20,    21,   190,    74,    75,    76,
      77,     0,     0,    78,     0,   107,  -183,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,    72,    15,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,    73,    74,    75,    76,    77,     0,
       0,    78,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,   179,   180,     0,     0,   181,
     182,   183,     0,     0,     0,     0,     0,   184,   185,   186,
       0,     0,     0,     0,     0,   187,     0,     0,    72,     0,
       0,   188,     0,     0,     0,     0,     0,   189,     0,     0,
       0,   190,    74,    75,    76,    77,     0,     0,    78,     0,
     107,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,     2,     3,     0,     0,     0,     4,     0,     5,
       0,     7,     0,     0,     0,     0,     9,    10,     0,    12,
       0,    13,    14,    72,     0,     0,     0,     0,     0,    16,
      17,    18,     0,    19,    20,    21,    73,    74,    75,    76,
      77,     0,     0,    78,     0,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    47,     0,     0,
       1,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    14,     0,    15,     0,     0,     0,     0,
      16,    17,    18,     0,    19,    20,    21,     1,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,     0,    15,     0,     0,     0,     0,    16,    17,    18,
       0,    19,    20,    21,   112,     1,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,    11,    12,     0,    13,    14,     0,
      15,    72,     0,     0,     0,    16,    17,    18,     0,    19,
      20,    21,     0,     0,    73,    74,    75,    76,    77,     0,
       0,    78,     0,    79,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,     2,     3,     0,     0,     0,
       4,     0,     5,     0,     7,     0,     0,     0,     0,     9,
      10,     0,    12,     0,    13,    14,     0,    72,     0,     0,
       0,     0,    16,    17,    18,     0,    19,    20,    21,     0,
      73,    74,    75,    76,    77,     0,     0,    78,    72,   283,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    73,    74,    75,    76,    77,     0,     0,   137,    72,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    87,    73,    74,    75,    76,    77,     0,     0,    78,
      72,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    73,    74,    75,    76,    77,     0,     0,
      78,     0,     0,     0,     0,     0,    80,    81,    82,   206,
      84,    85,    86,    87,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156
};

static const yytype_int16 yycheck[] =
{
      56,    40,   119,    78,     0,   228,   134,    23,    78,   130,
      91,    48,    61,   130,    50,    48,   187,    72,    40,    35,
      59,    50,   122,    49,    76,    80,    81,    46,    24,    25,
      48,    27,    28,    29,    48,    48,    91,   137,    90,    45,
      45,    40,    50,    45,    90,    51,    51,   122,    50,    51,
     183,    50,   122,    90,    90,   111,   126,    90,   128,   180,
     109,    90,   137,   180,   119,   140,    62,   137,   107,    49,
       7,    90,    90,    79,     7,   130,    90,    90,   134,   160,
     161,   162,    90,    56,    77,   141,    23,    40,    61,    62,
      23,    28,    40,   264,    47,   318,    48,   113,    35,    57,
      58,   157,    35,   178,    49,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     7,    40,   180,   297,    45,    45,   262,
      47,    47,    50,    51,   126,    56,   128,   270,    36,    23,
      56,   312,    71,   224,    28,    69,    70,    79,   204,   205,
     321,    35,    63,    64,    52,    55,   327,    79,   197,   287,
     293,    74,    75,    61,   220,    45,    72,    47,    73,   224,
      48,    51,    52,    53,    54,   292,    65,    66,    67,    68,
      78,   314,   315,   316,   167,   168,   169,   170,   163,   164,
      27,   266,    48,   268,   269,    90,   329,   165,   166,   332,
      90,   334,    48,    40,    41,    42,    43,    44,   171,   172,
      47,   109,   110,    40,    40,   211,    53,    54,    55,    56,
      57,    58,    59,    60,   122,   264,    40,    77,   126,    77,
     128,   287,    76,    40,    47,   291,   311,   292,     3,   137,
      76,     6,     7,    47,    47,    47,    11,    90,    13,    14,
      15,    50,    77,    46,    19,    20,    21,    22,    23,    46,
      25,    26,    40,    28,    48,    46,    48,    90,    33,    34,
      35,    48,    37,    38,    39,     3,    76,    36,     6,     7,
      77,    77,    46,    11,    49,    13,    14,    15,    46,    49,
      47,    19,    20,    21,    22,    23,    12,    25,    26,    48,
      28,    77,    77,    77,    77,    33,    34,    35,    48,    37,
      38,    39,   173,   175,    79,   174,   176,    55,   128,   177,
     121,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      42,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    53,    30,   283,
      78,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    61,   211,    47,   135,    49,    50,    60,
      29,    53,    54,    55,    56,    57,    58,    59,    60,     3,
       4,     5,     6,     7,     8,     9,    10,    11,   197,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    -1,    49,    50,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,     4,     5,    -1,    -1,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    47,    -1,
      49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,
      -1,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,     0,    -1,    -1,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    -1,    37,    38,    39,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    -1,    25,
      26,    -1,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      -1,    37,    38,    39,    40,     3,    -1,    -1,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      28,    27,    -1,    -1,    -1,    33,    34,    35,    -1,    37,
      38,    39,    -1,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    47,    -1,    49,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,     6,     7,    -1,    -1,    -1,
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
      47,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     7,    11,    13,    14,    15,    19,    20,
      21,    22,    23,    25,    26,    28,    33,    34,    35,    37,
      38,    39,   117,   118,   122,   123,   126,   129,   130,   158,
     159,   160,    40,   163,    40,    47,    56,   119,   120,   121,
     131,   132,   133,   118,   118,   118,   118,     0,   159,    49,
     131,   129,   134,   135,    77,    90,    79,   117,   118,   161,
     162,    45,    47,   132,    40,   127,   128,    48,   129,   133,
     121,   131,    27,    40,    41,    42,    43,    44,    47,    49,
      53,    54,    55,    56,    57,    58,    59,    60,    93,    94,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   142,   117,    49,   150,    28,
     134,   135,    40,   118,   136,   137,   138,   139,   140,    79,
      50,    90,    47,    97,   111,   114,   123,   124,   129,   141,
      45,    51,   143,   144,   145,   146,   147,    47,    97,    97,
      45,    47,    51,    52,    53,    54,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   113,    97,    99,
      56,    61,    62,    57,    58,    63,    64,    65,    66,    67,
      68,    69,    70,    55,    71,    72,    73,    74,    75,     4,
       5,     8,     9,    10,    16,    17,    18,    24,    30,    36,
      40,   114,   115,   117,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   135,    28,    56,   111,   112,   131,
      48,    90,    90,    48,   110,   116,    50,   128,   141,    48,
      90,   124,   125,   125,    48,   116,    40,    50,    90,   142,
      79,   147,   141,   114,    95,    96,   111,    40,    40,   111,
      99,    99,    99,   100,   100,   101,   101,   102,   102,   102,
     102,   103,   103,   104,   105,   106,   107,   108,   114,    77,
     116,    77,    76,   148,    47,    40,    47,   115,    47,    47,
      76,    77,   153,    50,   111,   111,    46,    46,    78,   138,
      40,    48,   111,    49,    99,    46,    50,   145,    48,    46,
      48,    90,    76,    76,   148,    36,   115,   117,    77,   114,
      77,   114,   114,   148,    46,    46,   143,   142,   111,   110,
     148,    47,    77,   115,    48,    48,    48,    50,    90,   114,
     115,    77,   148,   148,   148,    50,    48,    77,   115,    12,
      77,   115,    48,   148,    48,   148,   148
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
     132,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   137,   138,   138,   139,   139,   140,   140,   141,   142,
     142,   142,   143,   143,   144,   145,   145,   146,   146,   147,
     147,   148,   148,   148,   148,   148,   148,   149,   149,   149,
     150,   151,   151,   152,   152,   153,   153,   154,   155,   155,
     155,   156,   156,   156,   156,   157,   157,   157,   157,   158,
     158,   159,   159,   160,   161,   161,   162,   162,   163,   163
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
       4,     4,     2,     3,     1,     2,     1,     0,     1,     3,
       1,     3,     2,     1,     1,     3,     1,     0,     1,     1,
       3,     4,     2,     4,     2,     1,     0,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       3,     1,     2,     1,     0,     1,     1,     2,     5,     7,
       5,     5,     7,     9,     8,     3,     2,     2,     3,     1,
       2,     1,     1,     4,     1,     2,     1,     0,     1,     0
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
#line 104 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expression->id\n");}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 105 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf ("       primary_expression->int_constant\n");}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 106 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expression->float_constant\n");}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expression->string\n");}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expresion->character\n");}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       primary_expression->(expression)\n");}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 113 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->primary_expression\n");}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 115 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression[expression]\n");}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 117 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression(argument_expression_listopt)\n");}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 118 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression.id\n");}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 119 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression->id\n");}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression++\n");}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 121 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->postfix_expression--\n");}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 123 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->(type_name){initializer_list}\n");}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 125 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       postfix_expression->(type_name){initializer_list,}\n");}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 133 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       argument_expression_list->assignment_expression\n");}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       argument_expression_list->assignment_expression,assignment_expression\n");}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 139 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->postfix_expression\n");}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->++ unary_expression\n");}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 141 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->-- unary_expression\n");}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 142 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->unary_operator cast_expression\n");}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 143 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->sizeof(unary_expression)\n");}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 144 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_expression->(type_name)\n");}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 148 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->&\n");}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 149 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->*\n");}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 150 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->+\n");}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 151 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->-\n");}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 152 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->~\n");}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 153 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       unary_operator->!\n");}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 157 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       cast_expression->unary_expression\n");}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 158 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       cast_expression->(type_name) cast_expression\n");}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 162 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       multiplicative_expression->cast_expression\n");}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 164 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       multiplicative_expression->multiplicative_expression * cast_expression\n");}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 166 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       multiplicative_expression->multiplicative_expression / cast_expression\n");}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 168 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       multiplicative_expression->multiplicative_expression %% cast_expression\n");}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 172 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       additive_expression->multiplicative_expression\n");}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 174 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       additive_expression->additive expression + multiplicative_expression\n");}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 176 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       additive_expression->additive expression - multiplicative_expression\n");}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 180 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       shift_expression->additive_expression\n");}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 181 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       shift_expression->shift_expression << additive_expression\n");}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 182 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       shift_expression->shift_expression >> additive_expression\n");}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 186 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       relational_expression->shift_expression\n");}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 188 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       relational_expression->relational_expression < shift_expression\n");}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 190 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       relational_expression->relational_expression > shift_expression\n");}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 192 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       relational_expression->relational_expression <= shift_expression\n");}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 194 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("        relational_expression->relational_expression >= shift_expression\n");}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 198 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("        equality_expression->relational_expression\n");}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 200 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("        equality_expression->equality_expression == relational_expression\n");}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 202 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       equality_expression->equality_expression != relational_expression\n");}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 206 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       and_expression->equality_expression\n");}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 207 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       and_expression->and_expression & equality_expression\n");}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 211 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       exclusive_or_expression->and_expression\n");}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 212 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       exclusive_or_expression->exclusive_or_expression ^ and_expression\n");}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 216 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       inclusive_or_expression->exclusive_or_expression\n");}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 218 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       inclusive_or_expression->inclusive_or_expression | exclusive_or_expression\n");}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 222 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       logical_and_expression->inclusive_or_expression\n");}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 224 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       logical_and_expression->logical_and_expression && inclusive_or_expression\n");}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 228 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       logical_or_expression->logical_and_expression\n");}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 230 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       logical_or_expression->logical_or_expression || logical_and_expression\n");}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 234 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       conditional_expression->logical_or_expression\n");}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 236 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       conditional_expression->logical_or_expression ? expression : conditional_expression\n");}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 240 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_expression->conditional_expression\n");}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 242 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_expression->unary_expression assignment_operator assignment_expression\n");}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 250 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> =\n");}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 251 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> *=\n");}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 252 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> /=\n");}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 253 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> %%=\n");}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 254 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> +=\n");}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 255 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> -=\n");}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 256 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> <<=\n");}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 257 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> >>=\n");}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 258 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> &=\n");}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 259 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> ^=\n");}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 260 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       assignment_operator-> |=\n");}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 264 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       expression->assignment_expression\n");}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 265 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       expression->expression,assignment_expression\n");}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 274 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       constant_expression->conditional_expression\n");}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 278 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration->declaration_specifiers init_declarator_listopt ;\n");}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 282 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->storage_class_specifier\n");}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 284 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->storage_class_specifier declaration_specifiers\n");}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 285 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->type_specifier");}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 286 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->type_specifier declaration_specifiers\n");}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 287 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->type_qualifier");}
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 288 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->type_qualifier declaration_specifiers\n");}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 289 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->function_specifier");}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 290 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_specifiers->function_specifier declaration_specifiers\n");}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 299 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       init_declarator_list->init_declarator\n");}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 300 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       init_declarator_list->init_declarator_list , init_declarator\n");}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 304 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       init_declarator->declarator\n");}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 305 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       init_declarator->declarator = initializer\n");}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 309 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       storage_class_specifier-> extern\n");}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 310 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       storage_class_specifier-> static\n");}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 311 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       storage_class_specifier-> auto\n");}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 312 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       storage_class_specifier-> register\n");}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 316 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->void\n");}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 317 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->char\n");}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 318 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->short\n");}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 319 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->int\n");}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 320 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->long\n");}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 321 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->float\n");}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 322 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->double\n");}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 323 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->signed\n");}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 324 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->unsigned\n");}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 325 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->bool\n");}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 326 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->complex\n");}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 327 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->imaginary\n");}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 328 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_specifier->enum_specifier\n");}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 333 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       specifier_qualifier_list->type_specifier specifier_qualifier_listopt\n");}
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 334 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       specifier_qualifier_list->type_qualifier specifier_qualifier_listopt\n");}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 343 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       enum_specifier->enum idopt {enumerator_list}\n");}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 345 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       enum_specifier->enum idopt {enumerator_list , }\n");}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 346 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       enum_specifier->enum id\n");}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 350 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       enumerator_list->enumerator\n");}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 351 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       enumerator_list->enumerator_list, enumerator\n");}
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 355 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       enumerator->id\n");}
#line 2465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 356 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       enumerator->id = constant_expression\n");}
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 360 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_qualifier-> const\n");}
#line 2477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 361 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_qualifier-> volatile\n");}
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 362 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_qualifier-> restrict\n");}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 365 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       function_specifier->inline\n");}
#line 2495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 368 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declarator->pointer direct_declarator\n");}
#line 2501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 369 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declarator->direct_declarator\n");}
#line 2507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 373 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->id\n");}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 374 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->(declarator)\n");}
#line 2519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 376 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->[type_qualifier_listopt assignment_expressionopt]\n");}
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 378 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->[static type_qualifier_listopt assignment_expression]\n");}
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 380 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->[type_qualifier_list static assignment_expression]\n");}
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 382 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->[type_qualifier_listopt *]\n");}
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 384 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->(parameter_type_list)\n");}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 386 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       direct_declarator->(identifier_listopt)\n");}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 389 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       pointer-> * type_qualifier_listopt\n");}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 390 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       pointer-> * type_qualifier_listopt pointer\n");}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 395 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_qualifier_list->type_qualifier\n");}
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 396 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_qualifier_list->type_qualifier_list type_qualifier\n");}
#line 2579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 404 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       parameter_type_list->parameter_list\n");}
#line 2585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 405 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       parameter_type_list->parameter_list, ...\n");}
#line 2591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 409 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       parameter_list->parameter_declaration\n");}
#line 2597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 410 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       parameter_list->parameter_list, parameter_declaration\n");}
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 413 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       parameter_declaration->declaration_specifiers declarator");}
#line 2609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 414 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       parameter_declaration->declaration_specifiers");}
#line 2615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 417 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       identifier_list->id\n");}
#line 2621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 418 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       identifier_list->identifier_list, id\n");}
#line 2627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 427 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       type_name->specifier_qualifier_list\n");}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 431 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       initializer->assignment_expression\n");}
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 432 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       initializer->{initializer_list}\n");}
#line 2645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 433 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       initializer->{initializer_list ,  }\n");}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 437 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       initializer_list->designationopt initializer\n");}
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 439 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       initializer_list->initializer_list , designationopt initializer\n");}
#line 2663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 443 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       designation-> designator_list =\n");}
#line 2669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 452 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       designator_list->designator\n");}
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 453 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       designator_list->designator_list designator\n");}
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 457 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       designator->[constant_expression]\n");}
#line 2687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 458 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       designator->.id\n");}
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 462 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       statement-> labeled_statement\n");}
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 463 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       statement-> compound_statement\n");}
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 464 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       statement-> expression_statement\n");}
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 465 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       statement-> selection_statement\n");}
#line 2717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 466 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       statement-> iteration_statement\n");}
#line 2723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 467 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       statement-> jump_statement\n");}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 471 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       labeled_statement-> id : statement\n");}
#line 2735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 472 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       case constant_expression: statement\n");}
#line 2741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 473 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       default : statement\n");}
#line 2747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 477 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       compound_statement->{block_item_listopt}\n");}
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 481 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       block_item_list->block_item\n");}
#line 2759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 482 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       block_item_listopt-> block_item_list block_item\n");}
#line 2765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 491 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       block_item->declaration\n");}
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 492 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       block_item->statement\n");}
#line 2777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 496 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       expression_statement->expressionopt ;\n");}
#line 2783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 500 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       selection_statement->if (expression) statement\n");}
#line 2789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 502 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       selection_statement->if (expression) statement else statement\n");}
#line 2795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 504 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       selection_statement->switch (expression) statement\n");}
#line 2801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 508 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       iteration_statement->while (expression) statement\n");}
#line 2807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 510 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       iteration_statement->do statement while (expression) ;\n");}
#line 2813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 512 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       iteration_statement->for (expressionopt;expressionopt;expressionopt) statement\n");}
#line 2819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 514 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       iteration_statement->for (declaration expressionopt;expressionopt;expressionopt) statement\n");}
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 518 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       jump_statement-> goto id;\n");}
#line 2831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 519 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       jump_statement-> continue;\n");}
#line 2837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 520 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       jump_statement-> break;\n");}
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 521 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       jump_statement-> return expressionopt;\n");}
#line 2849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 525 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       translation_unit->external_declaration\n");}
#line 2855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 527 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       translation_unit->translation_unit external_declaration\n");}
#line 2861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 531 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       external_declaration->function_definition\n");}
#line 2867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 532 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       external_declaration->declaration\n");}
#line 2873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 537 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       function_definition->declaration_specifiers declarator declaration_listopt compound_statement;\n");}
#line 2879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 541 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_list->declaration\n");}
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 542 "ass4_13CS10061.y" /* yacc.c:1646  */
    {printf("       declaration_list->declaration_list declaration\n");}
#line 2891 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2895 "y.tab.c" /* yacc.c:1646  */
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
#line 555 "ass4_13CS10061.y" /* yacc.c:1906  */

#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("       \n%*s\n%*s\n", column, "^", column, s);
}
