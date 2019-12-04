#include <stdio.h>
#include "y.tab.h"
extern char* yytext;
main(){
	int token;
	while(token=yylex()){
        switch (token) {
	    case AUTO:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case BREAK:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case CASE:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case CHAR:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case CONST:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case CONTINUE:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case DEFAULT:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case DO:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case DOUBLE:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case ELSE:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case ENUM:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case EXTERN:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case FLOAT:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case FOR:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case GOTO:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case IF:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case INLINE:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case INT:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case LONG:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case REGISTER:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case RESTRICT:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case RETURN:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case SHORT:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case SIGNED:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case SIZEOF:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case STATIC:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case STRUCT:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case SWITCH:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case TYPEDEF:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case UNION:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case UNSIGNED:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case VOID:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case VOLATILE:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case WHILE:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case BOOL:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case COMPLEX:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case IMAGINARY:
                printf("< KEYWORD, %d, %s>\n",token,yytext);
                break;
            case SINGLELINECOMMENT:
                printf("< SINGLE_COMMENT, %d >\n",token);
                break;
            case MULTILINECOMMENT:
                printf("< MULTI_COMMENT, %d >\n",token);
                break;
            case ID:
                printf("< IDENTIFIER, %d, %s >\n",token,yytext);
                break;
            case INT_NO:
                printf("< INTEGER, %d, %d >\n",token,yylval.intval);
                break;
            case FLOAT_NO:
                printf("< FLOAT, %d, %s >\n",token,yytext);
                break;
            case CHARACTER:
                printf("< CHAR, %d, %s >\n",token,yytext);
                break;
            case STRING:
               printf("< STRING, %d, %s >\n",token,yytext);
                break;
            case LEFT_SQUARE_BRACE:
                printf("< LEFT_SQUARE_BRACE, %d, %s>\n",token,yytext);
                break;
            case RIGHT_SQUARE_BRACE:
                printf("< RIGHT_SQUARE_BRACE, %d, %s>\n",token,yytext);
                break;
            case LEFT_ROUND_BRACE:
                printf("< LEFT_ROUND_BRACE, %d, %s>\n",token,yytext);
                break;
            case RIGHT_ROUND_BRACE:
                printf("< RIGHT_ROUND_BRACE, %d, %s>\n",token,yytext);
                break;
            case LEFT_CURLY_BRACE:
                printf("< LEFT_CURLY_BRACE, %d, %s>\n",token,yytext);
                break;
            case RIGHT_CURLY_BRACE:
                printf("< RIGHT_CURLY_BRACE, %d, %s>\n",token,yytext);
                break;
            case PERIOD:
                printf("< PERIOD, %d, %s>\n",token,yytext);
                break;
            case ARROW:
                printf("< ARROW, %d, %s>\n",token,yytext);
                break;
            case INCREMENT:
                printf("< INCREMENT, %d, %s>\n",token,yytext);
                break;
            case DECREMENT:
                printf("< DECREMENT, %d, %s>\n",token,yytext);
                break;
            case AMPERSAND:
                printf("< ADDRESS/BIWISE_AND, %d, %s>\n",token,yytext); // have to be checked by the syntax
                break;
            case MULTIPLY:
                printf("< MULTIPLY/POINTER, %d, %s>\n",token,yytext); // have to be checked by the syntax
                break;
            case ADD:
                printf("< ADD, %d, %s>\n",token,yytext);
                break;
            case SUBTRACT:
                printf("< SUBTRACT, %d, %s>\n",token,yytext);
                break;
            case TILDA:
                printf("< TILDA, %d, %s>\n",token,yytext);
                break;
            case NEGATION:
                printf("< NEGATION, %d, %s>\n",token,yytext);
                break;
            case DIVIDE:
                printf("< FORWARD_SLASH, %d, %s>\n",token,yytext);
                break;
            case MODULUS:
                printf("< PERCENTAGE, %d, %s>\n",token,yytext);
                break;
            case LEFT_SHIFT:
                printf("< LEFT_SHIFT, %d, %s>\n",token,yytext);
                break;
            case RIGHT_SHIFT:
                printf("< RIGHT_SHIFT, %d, %s>\n",token,yytext);
                break;
            case LESS_THAN:
                printf("< LESS_THAN, %d, %s>\n",token,yytext);
                break;
            case GREATER_THAN:
                printf("< GREATER_THAN, %d, %s>\n",token,yytext);
                break;
            case LESS_THAN_EQUAL_TO:
                printf("< LESS_THAN_EQUAL_TO, %d, %s>\n",token,yytext);
                break;
            case GREATER_THAN_EQUAL_TO:
                printf("< GREATER_THAN_EQUAL_TO, %d, %s>\n",token,yytext);
                break;
            case NOT_EQUAL:
                printf("< NOT_EQUAL, %d, %s>\n",token,yytext);
                break;
            case XOR:
                printf("< XOR, %d, %s>\n",token,yytext);
                break;
            case BITWISE_OR:
                printf("< BITWISE_OR, %d, %s>\n",token,yytext);
                break;
            case BINARY_AND:
                printf("< BINARY_AND, %d, %s>\n",token,yytext);
                break;
            case BINARY_OR:
                printf("< BINARY_OR, %d, %s>\n",token,yytext);
                break;
            case QUESTION_MARK:
                printf("< QUESTION_MARK, %d, %s>\n",token,yytext);
                break;
            case COLON:
                printf("< COLON, %d, %s>\n",token,yytext);
                break;
            case SEMI_COLON:
                printf("< SEMI_COLON, %d, %s>\n",token,yytext);
                break;
            case ELLIPSIS:
                printf("< ELLIPSIS, %d, %s>\n",token,yytext);
                break;
            case EQUAL:
                printf("< EQUAL_ASSIGN, %d, %s>\n",token,yytext);
                break;
	    case DOUBLE_EQUAL:
                printf("< EQUAL_CHECK, %d, %s>\n",token,yytext);
                break;
            case MULTIPLY_EQUAL:
                printf("< MULTIPLY_EQUAL, %d, %s>\n",token,yytext);
                break;
            case DIVIDE_EQUAL:
                printf("< DIVIDE_EQUAL, %d, %s>\n",token,yytext);
                break;
            case MODULUS_EQUAL:
                printf("< MODULUS_EQUAL, %d, %s>\n",token,yytext);
                break;
            case PLUS_EQUAL:
                printf("< PLUS_EQUAL, %d, %s>\n",token,yytext);
                break;
            case MINUS_EQUAL:
                printf("< MINUS_EQUAL, %d, %s>\n",token,yytext);
                break;
            case LEFT_SHIFT_EQUAL:
                printf("< LEFT_SHIFT_EQUAL, %d, %s>\n",token,yytext);
                break;
            case RIGHT_SHIFT_EQUAL:
                printf("< RIGHT_SHIFT_EQUAL, %d, %s>\n",token,yytext);
                break;
            case AND_EQUAL:
                printf("< AND_EQUAL, %d, %s>\n",token,yytext);
                break;
            case XOR_EQUAL:
                printf("< XOR_EQUAL, %d, %s>\n",token,yytext);
                break;
            case OR_EQUAL:
                printf("< OR_EQUAL, %d, %s>\n",token,yytext);
                break;
            case COMMA:
                printf("< COMMA, %d, %s>\n",token,yytext);
                break;
            case HASH:
                printf("< HASH, %d, %s>\n",token,yytext);
                break;
            default:
		printf("No token matched for %s\n",yytext);
                break;
        }
	}
}
