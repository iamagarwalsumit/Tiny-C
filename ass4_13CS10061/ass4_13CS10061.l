%{
	#include <stdio.h>
	#include <math.h>
	#include <string.h>
	#include "y.tab.h"
	void count();
%}

SINGLE_LINE_COMMENT	\/\/.*
MULTI_LINE_COMMENT	\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*\/
ID 			[_a-zA-Z][_a-zA-Z0-9]*
DIGIT_SEQUENCE 		[0-9]+
INTEGER_CONST		[1-9]{DIGIT_SEQUENCE}*
FRACTIONAL_CONST	[0-9]*?\.{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}\.
EXPONENT_PART		[Ee][+-]?{DIGIT_SEQUENCE}
FLOATING_CONST		{FRACTIONAL_CONST}{EXPONENT_PART}?|{DIGIT_SEQUENCE}{EXPONENT_PART}
ENUMERATION_CONST	{ID}
ESCAPE_SEQUENCE		\\['"?\\abfnrtv]
C_CHAR				[^'\\\n]|{ESCAPE_SEQUENCE}
C_CHAR_SEQUENCE		{C_CHAR}+
CHARACTER_CONST		\'{C_CHAR_SEQUENCE}\'
S_CHAR				[^"\\\n]|{ESCAPE_SEQUENCE}
S_CHAR_SEQUENCE		{S_CHAR}+
STRING_LITERAL		\"{S_CHAR_SEQUENCE}?\"

%%
"auto"				{count();return AUTO;}
"break"				{count();return BREAK;}
"case"				{count();return CASE;}
"char"				{count();return CHAR;}
"const"				{count();return CONST;}
"continue"			{count();return CONTINUE;}
"default"			{count();return DEFAULT;}
"do"				{count();return DO;}
"double"			{count();return DOUBLE;}
"else"				{count();return ELSE;}
"enum"				{count();return ENUM;}
"extern"			{count();return EXTERN;}
"float"				{count();return FLOAT;}
"for"				{count();return FOR;}
"goto"				{count();return GOTO;}
"if"				{count();return IF;}
"inline"			{count();return INLINE;}
"int"				{count();return INT;}
"long"				{count();return LONG;}
"register"			{count();return REGISTER;}
"restrict"			{count();return RESTRICT;}
"return"			{count();return RETURN;}
"short"				{count();return SHORT;}
"signed"			{count();return SIGNED;}
"sizeof"			{count();return SIZEOF;}
"static"			{count();return STATIC;}
"struct"			{count();return STRUCT;}
"switch"			{count();return SWITCH;}
"typedef"			{count();return TYPEDEF;}
"union"				{count();return UNION;}
"unsigned"			{count();return UNSIGNED;}
"void"				{count();return VOID;}
"volatile"			{count();return VOLATILE;}
"while"				{count();return WHILE;}
"_Bool"				{count();return BOOL;}
"_Complex"			{count();return COMPLEX;}
"_Imaginary"			{count();return IMAGINARY;}
{SINGLE_LINE_COMMENT} 		{}
{MULTI_LINE_COMMENT}		{}
{ID}				{count();return ID;}
{INTEGER_CONST}			{yylval.intval= atoi(yytext);count();return INT_NO;}
{FLOATING_CONST}		{count();return FLOAT_NO;}
{CHARACTER_CONST}		{count();return CHARACTER;}
{STRING_LITERAL}		{count();return STRING;}
"["				{count();return LEFT_SQUARE_BRACE;}
"]"				{count();return RIGHT_SQUARE_BRACE;}
"("				{count();return LEFT_ROUND_BRACE;}
")"				{count();return RIGHT_ROUND_BRACE;}
"{"				{count();return LEFT_CURLY_BRACE;}
"}"				{count();return RIGHT_CURLY_BRACE;}
"."				{count();return PERIOD;}
"->"				{count();return ARROW;}
"++"				{count();return INCREMENT;}
"--"				{count();return DECREMENT;}
"&"				{count();return AMPERSAND;}
"*"				{count();return MULTIPLY;}
"+"				{count();return ADD;}
"-"				{count();return SUBTRACT;}
"~"				{count();return TILDA;}
"!"				{count();return NEGATION;}
"/"				{count();return DIVIDE;}
"%"				{count();return MODULUS;}
"<<"				{count();return LEFT_SHIFT;}
">>"				{count();return RIGHT_SHIFT;}
"<"				{count();return LESS_THAN;}
">"				{count();return GREATER_THAN;}
"<="				{count();return LESS_THAN_EQUAL_TO;}
">="				{count();return GREATER_THAN_EQUAL_TO;}
"=="				{count();return DOUBLE_EQUAL;}
"!="				{count();return NOT_EQUAL;}
"^"				{count();return XOR;}
"|"				{count();return BITWISE_OR;}
"&&"				{count();return BINARY_AND;}
"||"				{count();return BINARY_OR;}
"?"				{count();return QUESTION_MARK;}
":"				{count();return COLON;}
";"				{count();return SEMI_COLON;}
"..."				{count();return ELLIPSIS;}
"="				{count();return EQUAL;}
"*="				{count();return MULTIPLY_EQUAL;}
"/="				{count();return DIVIDE_EQUAL;}
"%="				{count();return MODULUS_EQUAL;}
"+="				{count();return PLUS_EQUAL;}
"-="				{count();return MINUS_EQUAL;}
"<<="				{count();return LEFT_SHIFT_EQUAL;}
">>="				{count();return RIGHT_SHIFT_EQUAL;}
"&="				{count();return AND_EQUAL;}
"^="				{count();return XOR_EQUAL;}
"|="				{count();return OR_EQUAL;}
","				{count();return COMMA;}
"#"				{count();return HASH;}
[ \t\v\n\f]			{ count(); }
.				{ /* ignore bad characters */ }
%%


yywrap()
{
	return(1);
}


int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}




