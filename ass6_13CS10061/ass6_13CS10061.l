%{
#include "ass6_13CS10061_translator.h"
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
%}

AUTO			"auto"
RESTRICT		"restrict"
UNSIGNED		"unsigned"
BREAK			"break"
EXTERN			"extern"
RETURN			"return"
VOID			"void"
CASE			"case"
FLOAT			"float"
SHORT			"short"
VOLATILE		"volatile"
CHAR			"char"
FOR				"for"
SIGNED			"signed"
WHILE			"while"
CONST			"const"
GOTO			"goto"
SIZEOF			"sizeof"
_BOOL			"_Bool"
CONTINUE		"continue"
IF				"if"
STATIC			"static"
_COMPLEX		"_Complex"
DEFAULT			"default"
INLINE			"inline"
STRUCT			"struct"
_IMAGINARY		"_Imaginary"
DO				"do"
INT				"int"
SWITCH			"switch"
DOUBLE			"double"
LONG			"long"
TYPEDEF			"typedef"
ELSE			"else"
REGISTER		"register"
UNION			"union"
DIGIT					[0-9]
IDENTIFIER-NONDIGIT		[a-zA-Z_]
ID 						{IDENTIFIER-NONDIGIT}({DIGIT}|{IDENTIFIER-NONDIGIT})*
NONZERO-DIGIT 			[1-9]
INTEGER_CONST 	 		({NONZERO-DIGIT}({DIGIT}|{NONZERO-DIGIT})*)|"0"
DIGIT-SEQUENCE 			{DIGIT}+
SIGN 					[+-]
EXPONENT-PART 			[eE]{SIGN}?{DIGIT-SEQUENCE}
FRACTIONAL-CONSTANT 	({DIGIT-SEQUENCE}?"."{DIGIT-SEQUENCE}|{DIGIT-SEQUENCE}".")
FLOAT_CONST 			({FRACTIONAL-CONSTANT}{EXPONENT-PART}?)|({DIGIT-SEQUENCE}?{EXPONENT-PART})
ESCAPE-SEQUENCE 		\\['\"\?abfnrtv0\\]
C-CHAR 					([^\'\\\n]|{ESCAPE-SEQUENCE})
C-CHAR-SEQUENCE 		{C-CHAR}+
CHAR_CONST 				\'{C-CHAR-SEQUENCE}\'
S-CHAR 					([^\"\\\n]|{ESCAPE-SEQUENCE})
S-CHAR-SEQUENCE 		{S-CHAR}+
STRING 					\"{S-CHAR-SEQUENCE}?\"
MULTICOMMENT 			 "/"\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+"/"
SINGLECOMMENT			"//".*


%%
{MULTICOMMENT} ;
{SINGLECOMMENT} ;
{AUTO}			{return AUTO_KEYWORD;}
{RESTRICT}		{return RESTRICT_KEYWORD;}
{UNSIGNED}		{return UNSIGNED_KEYWORD;}
{BREAK}			{return BREAK_KEYWORD;}
{EXTERN}		{return EXTERN_KEYWORD;}
{RETURN}		{return RETURN_KEYWORD;}
{VOID}			{return VOID_KEYWORD;}
{CASE}			{return CASE_KEYWORD;}
{FLOAT}			{return FLOAT_KEYWORD;}
{SHORT}			{return SHORT_KEYWORD;}
{VOLATILE}		{return VOLATILE_KEYWORD;}
{CHAR}			{return CHAR_KEYWORD;}
{FOR}			{return FOR_KEYWORD;}
{SIGNED}		{return SIGNED_KEYWORD;}
{WHILE}			{return WHILE_KEYWORD;}
{CONST}			{return CONST_KEYWORD;}
{GOTO}			{return GOTO_KEYWORD;}
{SIZEOF}		{return SIZEOF_KEYWORD;}
{_BOOL}			{return BOOL_KEYWORD;}
{CONTINUE}		{return CONTINUE_KEYWORD;}
{IF}			{return IF_KEYWORD;}
{STATIC}		{return STATIC_KEYWORD;}
{_COMPLEX}		{return COMPLEX_KEYWORD;}
{DEFAULT}		{return DEFAULT_KEYWORD;}
{INLINE}		{return INLINE_KEYWORD;}
{STRUCT}		{return STRUCT_KEYWORD;}
{_IMAGINARY}		{return IMAGINARY_KEYWORD;}
{DO}			{return DO_KEYWORD;}
{INT}			{return INT_KEYWORD;}
{SWITCH}		{return SWITCH_KEYWORD;}
{DOUBLE}		{return DOUBLE_KEYWORD;}
{LONG}			{return LONG_KEYWORD;}
{TYPEDEF}		{return TYPEDEF_KEYWORD;}
{ELSE}			{return ELSE_KEYWORD;}
{REGISTER}		{return REGISTER_KEYWORD;}
{UNION}			{return UNION_KEYWORD;}
{ID}			{(yylval.id_attr).var = strdup(yytext); return IDENTIFIER;}								
[ \t\v]		;			/* Ignore blank spaces */
[\n]			{ line_count++; }
{INTEGER_CONST}		{yylval.intval = atoi(yytext); return INTEGER_CONSTANT;}
{FLOAT_CONST}		{yylval.floatval = atof(yytext);
						/*printf("%s\n",yytext); printf("%lf\n",yylval.floatval);*/ return FLOAT_CONSTANT;}
{CHAR_CONST}		{yylval.charval = yytext[1]; return CHAR_CONSTANT;}
{STRING}		{yylval.strval = strdup(yytext); return STRING_LITERAL;}
"<<="			{return LEFT_SHIFT_EQUAL;}
"..."			{return ELLIPSES;}
">>="			{return RIGHT_SHIFT_EQUAL;}
"->"			{return VAL_AT;}
"++"			{return PLUS_PLUS;}
"--"			{return MINUS_MINUS;}
"<<"			{return LEFT_SHIFT;}
">>"			{return RIGHT_SHIFT;}
"<="			{return LESS_EQUAL;}
">="			{return GREATER_EQUAL;}
"=="			{return EQUAL_EQUAL;}
"!="			{return NOT_EQUAL;}
"&&"			{return LOGICAL_AND;}
"||"			{return LOGICAL_OR;}
"*="			{return STAR_EQUAL;}
"/="			{return BY_EQUAL;}
"%="			{return PERCENT_EQUAL;}
"+="			{return PLUS_EQUAL;}
"-="			{return MINUS_EQUAL;}
"&="			{return AND_EQUAL;}
"^="			{return BITWISENOT_EQUAL;}
"|="			{return OR_EQUAL;}
"["			{return yytext[0];}
"]"			{return yytext[0];}
"("			{return yytext[0];}
")"			{return yytext[0];}
"{"			{return yytext[0];}
"}"			{return yytext[0];}
"."			{return yytext[0];}
"&"			{return yytext[0];}
"*"			{return yytext[0];}
"+"			{return yytext[0];}
"-"			{return yytext[0];}
"~"			{return yytext[0];}
"!"			{return yytext[0];}
"/"			{return yytext[0];}
"%"			{return yytext[0];}
"<"			{return yytext[0];}
">"			{return yytext[0];}
"^"			{return yytext[0];}
"|"			{return yytext[0];}
"?"			{return yytext[0];}
":"			{return yytext[0];}
";"			{return yytext[0];}
"="			{return yytext[0];}
","			{return yytext[0];}
"#"			{return yytext[0];}
%%
