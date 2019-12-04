%{
#include <stdio.h>
#include <iostream>
extern int yylex();
#include "ass5_13CS10061_translator.h"
#include <string.h>
void yyerror(const char* s);
%}

%union{
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
}

%token AUTO
%token BREAK 
%token CASE 
%token CHAR
%token CONST 
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token ENUM
%token EXTERN
%token FLOAT
%token FOR
%token GOTO
%token IF
%token INLINE
%token INT
%token LONG
%token REGISTER
%token RESTRICT
%token RETURN
%token SHORT
%token SIGNED
%token SIZEOF
%token STATIC
%token STRUCT
%token SWITCH
%token TYPEDEF
%token UNION
%token UNSIGNED
%token VOID
%token VOLATILE
%token WHILE
%token BOOL
%token COMPLEX
%token IMAGINARY
%token <intval> ID
%token <intval> INT_NO
%token <floatval> FLOAT_NO
%token <charval> CHARACTER
%token <strval> STRING
%token LEFT_SQUARE_BRACE
%token RIGHT_SQUARE_BRACE
%token LEFT_ROUND_BRACE
%token RIGHT_ROUND_BRACE
%token LEFT_CURLY_BRACE
%token RIGHT_CURLY_BRACE
%token PERIOD
%token ARROW
%token INCREMENT
%token DECREMENT
%token AMPERSAND
%token MULTIPLY
%token ADD
%token SUBTRACT
%token TILDA
%token NEGATION
%token DIVIDE
%token MODULUS
%token LEFT_SHIFT
%token RIGHT_SHIFT
%token LESS_THAN
%token GREATER_THAN
%token LESS_THAN_EQUAL_TO
%token GREATER_THAN_EQUAL_TO
%token DOUBLE_EQUAL
%token NOT_EQUAL
%token XOR
%token BITWISE_OR
%token BINARY_AND
%token BINARY_OR
%token QUESTION_MARK
%token COLON
%token SEMI_COLON
%token ELLIPSIS
%token EQUAL
%token MULTIPLY_EQUAL
%token DIVIDE_EQUAL
%token MODULUS_EQUAL
%token PLUS_EQUAL
%token MINUS_EQUAL
%token LEFT_SHIFT_EQUAL
%token RIGHT_SHIFT_EQUAL
%token AND_EQUAL
%token XOR_EQUAL
%token OR_EQUAL
%token COMMA
%token HASH



%type<E> primary_expression expression postfix_expression constant_expression 
%type<E> unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression
%type<E> and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression
%type<E> statement compound_statement selection_statement iteration_statement jump_statement expression_statement block_item_list block_item
%type<VarDecl> type_specifier declaration_specifiers direct_declarator declarator parameter_declaration init_declarator init_declarator_list pointer
%type<Initialiser> initializer 
%type<U> unary_operator
%type<I> M
%type<Next> N
%type<Parameter> argument_expression_list

%expect 1

%start translation_unit
%%

primary_expression
	: ID    
	{
		//printf("       primary_expression->id\n");
		$1.loc = current->lookup($1.name);
	  	if(!($1.loc))
	  		$1.loc = global->lookup($1.name);
	  	$$.loc = $1.loc;
	  	$$.type = ($1.loc)->Type;
	  	$$.array = $$.loc;
	  	$$.loc1 = 0;
	}
	|INT_NO 
	{
		//printf ("       primary_expression->int_constant\n");
		$$.val.dataInt = $1;
	  	$$.type = newType(IntType,-1);
	  	$$.loc = current->gentemp(IntType);
	  	char *arg1 = new char[10];
	  	sprintf(arg1,"%d",$1);
	  	char *res = strdup(($$.loc)->name);
	  	quadArray->emit(arg1,0,res,Assign,0,0,$$.loc);
	}
	|FLOAT_NO 
	{
		//printf("       primary_expression->float_constant\n");
		$$.val.dataDouble = $1;
		$$.type = newType(DoubleType,-1);
		$$.loc = current->gentemp(DoubleType);
	  	char *arg1 = new char[10];
	  	sprintf(arg1,"%lf",$1);
	  	char *res = strdup(($$.loc)->name);
	  	quadArray->emit(arg1,0,res,Assign,0,0,$$.loc);
	}
	|STRING 
	{
		 //printf("       primary_expression->string\n");
		 /* no scope for string literal */
	}
	|CHARACTER 
	{
		//printf("       primary_expresion->character\n");
		$$.val.dataChar = $1;
	  	$$.type = new_node(CharType,-1);
	  	$$.loc = current->gentemp(CharType);
	  	char *arg1 = new char[10];
	  	sprintf(arg1,"%c",$1);
	  	char *res = strdup(($$.loc)->name);
	  	quadArray->emit(arg1,0,res,Assign,0,0,$$.loc);
	}
        |LEFT_ROUND_BRACE expression RIGHT_ROUND_BRACE 
        {
        	//printf("       primary_expression->(expression)\n");
        	$$ = $2;
        }
	;

postfix_expression
	: primary_expression 
	{
		//printf("       postfix_expression->primary_expression\n");
		$$=$1;
	}
    |
       postfix_expression LEFT_SQUARE_BRACE expression RIGHT_SQUARE_BRACE 
    {
    	// printf("       postfix_expression->postfix_expression[expression]\n");
    	$$.array = $1.array;
	  	$$.type = ($1.type)->next;
	  	if(!($1.loc1)){
	  		$$.loc1 = current->gentemp(IntType);
	  		int m = computeWidth(($1.type)->next);
	  		char *arg1 = strdup(($3.loc)->name);
	  		char *arg2 = new char[10];
	  		sprintf(arg2,"%d",m);
	  		char *res = strdup(($$.loc1)->name);
	  		quadArray->emit(arg1,arg2,res,Into,$3.loc,0,$$.loc1);
	  	}
	  	else{
	  		symbolTableRow *temp = current->gentemp(IntType);
		  	$$.loc1 = current->gentemp(IntType);
		  	int n = computeWidth($$.type);
		  	char *arg1 = strdup(($3.loc)->name);
		  	char *arg2 = new char[10];
		  	sprintf(arg2,"%d",n);
		  	char *res = strdup(temp->name);
		  	quadArray->emit(arg1,arg2,res,INTO,$3.loc,0,temp);
		  	arg1 = strdup(($1.loc1)->name);
		  	arg2 = strdup(temp->name);
		  	res = strdup(($$.loc1)->name);
		  	quadArray->emit(arg1,arg2,res,Plus,$1.loc1,temp,$$.loc1);
	  	}
	  	flagArray = 1;
    }
    |postfix_expression LEFT_ROUND_BRACE RIGHT_ROUND_BRACE
    {
    	int count = 0;
	  	symbolTableRow *t = global->lookup(($1.loc)->name);
	  	$$.loc = current->gentemp(((((t->nestedTable)->table)[count]).Type)->first);
	  	char *res = strdup(($$.loc)->name);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = new char[10];
	  	sprintf(arg2,"%d",count);
	  	quadArray->emit(arg1,arg2,res,Call,$1.loc,0,$$.loc);
	  	$$.type = ($$.loc)->Type;
    }
	|postfix_expression LEFT_ROUND_BRACE argument_expression_list RIGHT_ROUND_BRACE
	 {
	 	// printf("       postfix_expression->postfix_expression(argument_expression_listopt)\n");
	 	paramList *temp = $3;
	  	int count = 0;
	  	while(temp){
	  		char *arg1 = strdup((temp->param)->name);
	  		quadArray->emit(arg1,0,0,Param,temp->param,0,0);
	  		count++;
	  		temp = temp->next;
	  	}
	  	symbolTableRow *t = global->lookup(($1.loc)->name);
	  	$$.loc = current->gentemp(((((t->nestedTable)->table)[count]).Type)->first);
	  	char *res = strdup(($$.loc)->name);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = new char[10];
	  	sprintf(arg2,"%d",count);
	  	quadArray->emit(arg1,arg2,res,Call,$1.loc,0,$$.loc);
	  	$$.type = ($$.loc)->Type;
	 }
	|postfix_expression PERIOD ID 
	{
		//printf("       postfix_expression->postfix_expression.id\n");
		/* not in use */
	}
    |postfix_expression ARROW ID 
    {
    	//printf("       postfix_expression->postfix_expression->id\n");
    	/* not in use */
    }
    |postfix_expression INCREMENT 
    {
    	//printf("       postfix_expression->postfix_expression++\n");
    	$$.loc = current->gentemp(($1.type)->first);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *res = strdup(($$.loc)->name);
	  	quadArray->emit(arg1,0,res,Assign,$1.loc,0,$$.loc);
	  	arg1 = strdup(($1.loc)->name);
	  	char *arg2 = new char[10];
	  	sprintf(arg2,"1");
	  	res = strdup(($1.loc)->name);
	  	quadArray->emit(arg1,arg2,res,Plus,$1.loc,0,$1.loc);
	  	$$.type = $1.type;
    }
	|postfix_expression DECREMENT 
	{
		//printf("       postfix_expression->postfix_expression--\n");
		$$.loc = current->gentemp(($1.type)->first);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *res = strdup(($$.loc)->name);
	  	quadArray->emit(arg1,0,res,Assign,$1.loc,0,$$.loc);
	  	arg1 = strdup(($1.loc)->name);
	  	char *arg2 = new char[10];
	  	sprintf(arg2,"1");
	  	res = strdup(($1.loc)->name);
	  	quadArray->emit(arg1,arg2,res,Minus,$1.loc,0,$1.loc);
	  	$$.type = $1.type;
	}
	|LEFT_ROUND_BRACE type_name RIGHT_ROUND_BRACE LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE 
	{
		//printf("       postfix_expression->(type_name){initializer_list}\n");
		/* not in use */
	}
	|LEFT_ROUND_BRACE type_name RIGHT_ROUND_BRACE LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE
	{
		//printf("       postfix_expression->(type_name){initializer_list,}\n");
		/* not in use */
	}
	;

argument_expression_list
	: assignment_expression 
	{
		//printf("       argument_expression_list->assignment_expression\n");
		$$ = makeParamList($1.loc);
	}
	| argument_expression_list COMMA assignment_expression 
	{
		//printf("       argument_expression_list->assignment_expression,assignment_expression\n");
		$$ = mergeParamList($1,makeParamList($3.loc));
	}
	;

unary_expression
	: postfix_expression 
	{
		//printf("       unary_expression->postfix_expression\n");
		$$ = $1;
	  	if($1.loc1){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.array)->name);
	  		char *arg2 = strdup(($1.loc1)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArray->emit(arg1,arg2,res,EqBracket,$1.loc,$1.loc1,$$.loc);
	  	}
	}
	| INCREMENT unary_expression 
	{
		//printf("       unary_expression->++ unary_expression\n");
		$$.loc = current->gentemp(($2.type)->first);
	  	char *arg1 = strdup(($2.loc)->name);
	  	char *arg2 = new char[10];
	  	sprintf(arg2,"1");
	  	char *res = strdup(($2.loc)->name);
	  	quadArray->emit(arg1,arg2,res,Plus,$2.loc,0,$2.loc);
	  	arg1 = strdup(($2.loc)->name);
	  	res = strdup(($$.loc)->name);
	  	quadArray->emit(arg1,0,res,Assign,$2.loc,0,$$.loc);
	  	$$.type = $2.type;
	}
	| DECREMENT unary_expression 
	{
		//printf("       unary_expression->-- unary_expression\n");
		$$.loc = current->gentemp(($2.type)->first);
	  	char *arg1 = strdup(($2.loc)->name);
	  	char *arg2 = new char[10];
	  	sprintf(arg2,"1");
	  	char *res = strdup(($2.loc)->name);
	  	quadArray->emit(arg1,arg2,res,Minus,$2.loc,0,$2.loc);
	  	arg1 = strdup(($2.loc)->name);
	  	res = strdup(($$.loc)->name);
	  	quadArray->emit(arg1,0,res,Assign,$2.loc,0,$$.loc);
	  	$$.type = $2.type;
	}
	| unary_operator cast_expression 
	{
		//printf("       unary_expression->unary_operator cast_expression\n");
		$$.loc = current->gentemp(($2.type)->first);
	  	char *arg1 = strdup(($2.loc)->name);
	  	char *res = strdup(($$.loc)->name);
	  	quadArray->emit(arg1,0,res,$1,$2.loc,0,$$.loc);
	  	$$.type = $2.type;
	}
	| SIZEOF unary_expression 
	{
		//printf("       unary_expression->sizeof(unary_expression)\n");
		/* not in use */
	}
	| SIZEOF LEFT_ROUND_BRACE type_name RIGHT_ROUND_BRACE 
	{
		//printf("       unary_expression->(type_name)\n");
		/* not in use */
	}
	;

unary_operator
	: AMPERSAND 
	{
		//printf("       unary_operator->&\n");
		$$ = U_Addr;
	}
	| MULTIPLY 
	{
		//printf("       unary_operator->*\n");
		$$ = U_Multiply;
	}
	| ADD 
	{
		//printf("       unary_operator->+\n");
		$$ = U_Add;
	}
	| SUBTRACT 
	{
		//printf("       unary_operator->-\n");
		$$ = U_Sub;
	}
	| TILDA 
	{
		//printf("       unary_operator->~\n");
		$$ = U_Not;
	}
	| NEGATION 
	{
		//printf("       unary_operator->!\n");
		$$ = U_Negation;
	}
	;

cast_expression
	: unary_expression 
	{
		//printf("       cast_expression->unary_expression\n");
		$$ = $1;
	}
	|LEFT_ROUND_BRACE type_name RIGHT_ROUND_BRACE cast_expression 
	{
		//printf("       cast_expression->(type_name) cast_expression\n");
		/* not in use */
	}
	;

multiplicative_expression
	: cast_expression 
	{
		//printf("       multiplicative_expression->cast_expression\n");
		$$ = $1;
	}
	| multiplicative_expression MULTIPLY cast_expression 
	{
		//printf("       multiplicative_expression->multiplicative_expression * cast_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArray->emit(arg1,arg2,res,Multiply,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->first == IntType && ($3.type)->first == DoubleType){

	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$1.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Multiply,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->first == IntType && ($3.type)->first == CharType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Multiply,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == DoubleType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Multiply,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == CharType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,Assign,$1.loc,0,temp1);
	  			quadArray->emit(x);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Multiply,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	}
	| multiplicative_expression DIVIDE cast_expression 
	{
		//printf("       multiplicative_expression->multiplicative_expression / cast_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArray->emit(arg1,arg2,res,Divide,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->first == IntType && ($3.type)->first == DoubleType){

	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$1.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Divide,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->first == IntType && ($3.type)->first == CharType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Divide,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == DoubleType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Divide,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == CharType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,Assign,$1.loc,0,temp1);
	  			quadArray->emit(x);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Divide,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	}
	| multiplicative_expression MODULUS cast_expression 
	{
		//printf("       multiplicative_expression->multiplicative_expression %% cast_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArray->emit(arg1,arg2,res,Modulus,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->first == IntType && ($3.type)->first == DoubleType){

	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$1.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Modulus,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->first == IntType && ($3.type)->first == CharType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Multiply,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == DoubleType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Modulus,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == CharType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,Assign,$1.loc,0,temp1);
	  			quadArray->emit(x);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Modulus,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	}
	;

additive_expression
	: multiplicative_expression 
	{
		//printf("       additive_expression->multiplicative_expression\n");
		$$ = $1;
	}
	| additive_expression ADD multiplicative_expression 
	{
		//printf("       additive_expression->additive expression + multiplicative_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArray->emit(arg1,arg2,res,Plus,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->first == IntType && ($3.type)->first == DoubleType){

	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$1.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Plus,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->first == IntType && ($3.type)->first == CharType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Plus,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == DoubleType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Plus,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == CharType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,Assign,$1.loc,0,temp1);
	  			quadArray->emit(x);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Plus,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	}
	| additive_expression SUBTRACT multiplicative_expression 
	{
		//printf("       additive_expression->additive expression - multiplicative_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArray->emit(arg1,arg2,res,Minus,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->first == IntType && ($3.type)->first == DoubleType){

	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$1.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Minus,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->first == IntType && ($3.type)->first == CharType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Minus,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == DoubleType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(DoubleType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArray->emit(arg1,0,res,Assign,$3.loc,0,temp1);
	  			temp2 = current->gentemp(DoubleType);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Minus,$1.loc,temp1,temp2);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->first == CharType && ($3.type)->first == IntType){
	  			temp1 = current->gentemp(IntType);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,Assign,$1.loc,0,temp1);
	  			quadArray->emit(x);
	  			temp2 = current->gentemp(IntType);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArray->emit(arg1,arg2,res,Minus,temp1,$3.loc,temp2);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	}
	;

shift_expression
	: additive_expression 
	{
		//printf("       shift_expression->additive_expression\n");
		$$ = $1;
	}
	| shift_expression LEFT_SHIFT additive_expression 
	{
		//printf("       shift_expression->shift_expression << additive_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArray->emit(arg1,arg2,res,ShiftLeft,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	}
	| shift_expression RIGHT_SHIFT additive_expression 
	{
		//printf("       shift_expression->shift_expression >> additive_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArray->emit(arg1,arg2,res,ShiftRight,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	}
	;

relational_expression
	: shift_expression 
	{
		//printf("       relational_expression->shift_expression\n");
	}
	| relational_expression LESS_THAN shift_expression 
	{
		//printf("       relational_expression->relational_expression < shift_expression\n");
		$$.TL = makeList(nextInstr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArray->emit(arg1,arg2,0,gotoLT,$1.loc,$3.loc,0);
	  	$$.FL = makeList(nextInstr);
	  	quadArray->emit(0,0,0,Goto,0,0,0);
	  	$$.type = newType(BoolType,-1);
	}
	| relational_expression GREATER_THAN shift_expression 
	{
		//printf("       relational_expression->relational_expression > shift_expression\n");
		$$.TL = makeList(nextInstr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArray->emit(arg1,arg2,0,gotoGT,$1.loc,$3.loc,0);
	  	$$.FL = makeList(nextInstr);
	  	quadArray->emit(0,0,0,Goto,0,0,0);
	  	$$.type = newType(BoolType,-1);
	}
	| relational_expression LESS_THAN_EQUAL_TO shift_expression 
	{
		//printf("       relational_expression->relational_expression <= shift_expression\n");
		$$.TL = makeList(nextInstr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArray->emit(arg1,arg2,0,gotoLTE,$1.loc,$3.loc,0);
	  	$$.FL = makeList(nextInstr);
	  	quadArray->emit(0,0,0,Goto,0,0,0);
	  	$$.type = newType(BoolType,-1);
	}
	| relational_expression GREATER_THAN_EQUAL_TO shift_expression 
	{
		//printf("        relational_expression->relational_expression >= shift_expression\n");
		$$.TL = makeList(nextInstr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArray->emit(arg1,arg2,0,gotoGTE,$1.loc,$3.loc,0);
	  	$$.FL = makeList(nextInstr);
	  	quadArray->emit(0,0,0,Goto,0,0,0);
	  	$$.type = newType(BoolType,-1);
	}
	;

equality_expression
	: relational_expression 
	{
		//printf("        equality_expression->relational_expression\n");
		$$ = $1;
	}
	| equality_expression DOUBLE_EQUAL relational_expression 
	{
		//printf("        equality_expression->equality_expression == relational_expression\n");
		$$.TL = makeList(nextInstr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArray->emit(arg1,arg2,0,gotoEQ,$1.loc,$3.loc,0);
	  	$$.FL = makeList(nextInstr);
	  	quadArray->emit(0,0,0,Goto,0,0,0);
	  	$$.type = newType(BoolType,-1);
	}
	| equality_expression NOT_EQUAL relational_expression 
	{
		//printf("       equality_expression->equality_expression != relational_expression\n");
		$$.TL = makeList(nextInstr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArray->emit(arg1,arg2,0,gotoNEQ,$1.loc,$3.loc,0);
	  	$$.FL = makeList(nextInstr);
	  	quadArray->emit(0,0,0,Goto,0,0,0);
	  	$$.type = newType(BoolType,-1);
	}
	;

and_expression
	: equality_expression 
	{
		//printf("       and_expression->equality_expression\n");
		$$ = $1;
	}
	| and_expression AMPERSAND equality_expression 
	{
		//printf("       and_expression->and_expression & equality_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quad_array->emit(arg1,arg2,res,BW_And,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	}
	;

exclusive_or_expression
	: and_expression 
	{
		//printf("       exclusive_or_expression->and_expression\n");
		$$ = $1;
	}
	| exclusive_or_expression XOR and_expression 
	{
		//printf("       exclusive_or_expression->exclusive_or_expression ^ and_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quad_array->emit(arg1,arg2,res,BW_Xor,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	}
	;

inclusive_or_expression
	: exclusive_or_expression 
	{
		//printf("       inclusive_or_expression->exclusive_or_expression\n");
		$$ = $1;
	}
	| inclusive_or_expression BITWISE_OR exclusive_or_expression 
	{
		//printf("       inclusive_or_expression->inclusive_or_expression | exclusive_or_expression\n");
		if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->first);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quad_array->emit(arg1,arg2,res,BW_Or,$1.loc,$3.loc,$$.loc);
	  		$$.type = $1.type;
	  	}
	}
	;

logical_and_expression
	: inclusive_or_expression 
	{
		//printf("       logical_and_expression->inclusive_or_expression\n");
		$$ = $1;
	}
	| logical_and_expression BINARY_AND inclusive_or_expression 
	{
		//printf("       logical_and_expression->logical_and_expression && inclusive_or_expression\n");
		backpatch($1.TL,$3);
	  	$$.FL = merge($1.FL, $4.FL);
	  	$$.TL = $4.TL;
	  	$$.type = newType(BoolType,-1);
	}
	;

logical_or_expression
	: logical_and_expression 
	{
		//printf("       logical_or_expression->logical_and_expression\n");
		$$ = $1;
	}
	| logical_or_expression BINARY_OR logical_and_expression
	{
		//printf("       logical_or_expression->logical_or_expression || logical_and_expression\n");
	}
	;

conditional_expression
	: logical_or_expression {printf("       conditional_expression->logical_or_expression\n");}
	| logical_or_expression QUESTION_MARK expression COLON conditional_expression
	{printf("       conditional_expression->logical_or_expression ? expression : conditional_expression\n");}
	;

assignment_expression
	: conditional_expression {printf("       assignment_expression->conditional_expression\n");}
	| unary_expression assignment_operator assignment_expression
	{printf("       assignment_expression->unary_expression assignment_operator assignment_expression\n");}
	;
assignment_expressionopt
	:assignment_expression
	|
	;

assignment_operator
	: EQUAL {printf("       assignment_operator-> =\n");}
	|MULTIPLY_EQUAL {printf("       assignment_operator-> *=\n");}
	|DIVIDE_EQUAL {printf("       assignment_operator-> /=\n");}
	|MODULUS_EQUAL {printf("       assignment_operator-> %%=\n");}
	|PLUS_EQUAL {printf("       assignment_operator-> +=\n");}
	|MINUS_EQUAL {printf("       assignment_operator-> -=\n");}
	|LEFT_SHIFT_EQUAL {printf("       assignment_operator-> <<=\n");}
	|RIGHT_SHIFT_EQUAL {printf("       assignment_operator-> >>=\n");}
	|AND_EQUAL {printf("       assignment_operator-> &=\n");}
	|XOR_EQUAL {printf("       assignment_operator-> ^=\n");}
	|OR_EQUAL {printf("       assignment_operator-> |=\n");}
	;

expression
	: assignment_expression {printf("       expression->assignment_expression\n");}
	| expression COMMA assignment_expression {printf("       expression->expression,assignment_expression\n");}
	;

expressionopt
	:expression
	|
	;

constant_expression
	: conditional_expression {printf("       constant_expression->conditional_expression\n");}
	;
declaration
	: declaration_specifiers init_declarator_listopt SEMI_COLON 
	{printf("       declaration->declaration_specifiers init_declarator_listopt ;\n");}	  
	;

declaration_specifiers
	: storage_class_specifier {printf("       declaration_specifiers->storage_class_specifier\n");}
	| storage_class_specifier declaration_specifiers 
	{printf("       declaration_specifiers->storage_class_specifier declaration_specifiers\n");}
	| type_specifier {printf("       declaration_specifiers->type_specifier");}
	| type_specifier declaration_specifiers {printf("       declaration_specifiers->type_specifier declaration_specifiers\n");}
	| type_qualifier {printf("       declaration_specifiers->type_qualifier");}
	| type_qualifier declaration_specifiers {printf("       declaration_specifiers->type_qualifier declaration_specifiers\n");}
	| function_specifier {printf("       declaration_specifiers->function_specifier");}
	| function_specifier declaration_specifiers {printf("       declaration_specifiers->function_specifier declaration_specifiers\n");}
	;

init_declarator_listopt
	:init_declarator_list
	|
	;

init_declarator_list
	: init_declarator {printf("       init_declarator_list->init_declarator\n");}
	| init_declarator_list COMMA init_declarator {printf("       init_declarator_list->init_declarator_list , init_declarator\n");}
	;

init_declarator
	: declarator {printf("       init_declarator->declarator\n");}
	| declarator EQUAL initializer {printf("       init_declarator->declarator = initializer\n");}	  
	;

storage_class_specifier
	: EXTERN {printf("       storage_class_specifier-> extern\n");}
	| STATIC {printf("       storage_class_specifier-> static\n");}
	| AUTO {printf("       storage_class_specifier-> auto\n");}
	| REGISTER {printf("       storage_class_specifier-> register\n");}
	;

type_specifier
	: VOID {printf("       type_specifier->void\n");}
	| CHAR {printf("       type_specifier->char\n");}
	| SHORT {printf("       type_specifier->short\n");}
	| INT {printf("       type_specifier->int\n");}
	| LONG {printf("       type_specifier->long\n");}
	| FLOAT {printf("       type_specifier->float\n");}
	| DOUBLE {printf("       type_specifier->double\n");}
	| SIGNED {printf("       type_specifier->signed\n");}
	| UNSIGNED {printf("       type_specifier->unsigned\n");}
	| BOOL {printf("       type_specifier->bool\n");}
	| COMPLEX {printf("       type_specifier->complex\n");}
	| IMAGINARY {printf("       type_specifier->imaginary\n");}
	| enum_specifier {printf("       type_specifier->enum_specifier\n");}
	;


specifier_qualifier_list
	: type_specifier specifier_qualifier_listopt {printf("       specifier_qualifier_list->type_specifier specifier_qualifier_listopt\n");}
	| type_qualifier specifier_qualifier_listopt {printf("       specifier_qualifier_list->type_qualifier specifier_qualifier_listopt\n");}
	;
specifier_qualifier_listopt
	: specifier_qualifier_list
	|
	;

enum_specifier
	: ENUM identifieropt LEFT_CURLY_BRACE enumerator_list RIGHT_CURLY_BRACE 
	{printf("       enum_specifier->enum idopt {enumerator_list}\n");} 
	| ENUM identifieropt LEFT_CURLY_BRACE enumerator_list COMMA RIGHT_CURLY_BRACE 
	{printf("       enum_specifier->enum idopt {enumerator_list , }\n");}
	| ENUM ID {printf("       enum_specifier->enum id\n");}
	;

enumerator_list
	: enumerator {printf("       enumerator_list->enumerator\n");}
	| enumerator_list COMMA enumerator {printf("       enumerator_list->enumerator_list, enumerator\n");}
	;

enumerator
	: ID {printf("       enumerator->id\n");}
	| ID EQUAL constant_expression {printf("       enumerator->id = constant_expression\n");}
	;

type_qualifier
	: CONST {printf("       type_qualifier-> const\n");}
	| VOLATILE {printf("       type_qualifier-> volatile\n");}
	| RESTRICT {printf("       type_qualifier-> restrict\n");}
	;
function_specifier
	:INLINE {printf("       function_specifier->inline\n");}
	;
declarator
	: pointer direct_declarator {printf("       declarator->pointer direct_declarator\n");}
	| direct_declarator {printf("       declarator->direct_declarator\n");}
	;

direct_declarator
	: ID 
	{
		printf("       direct_declarator->id\n");

		if(!declDone || !mulDecl){
	  		$$.name = $1.name;
		  	$$.type = 0;
		  	$$.width = 1;
		  	if(c == 0){
		  		symbolTableRow *loc_id = current->lookup($1.name);
			  	if(t){
			  		mulDecl = 1;    // Set flag to handle multiple declaration
			  		temp = (loc_id->nestedTable);	
			  	}		
			  	else                                            
			  		mulDecl = 0; 
			  	c++;	
		  	}
	  	}
	}
	| LEFT_ROUND_BRACE declarator RIGHT_ROUND_BRACE {printf("       direct_declarator->(declarator)\n");} 
	|direct_declarator LEFT_SQUARE_BRACE type_qualifier_list assignment_expressionopt RIGHT_SQUARE_BRACE
	{printf("       direct_declarator->[type_qualifier_listopt assignment_expressionopt]\n");}
	|direct_declarator LEFT_SQUARE_BRACE assignment_expressionopt RIGHT_SQUARE_BRACE
	{
		printf("       direct_declarator->[assignment_expressionopt]\n");
		if(!declDone|| !mulDecl){
	  		Type *arr_type = newType(ArrayType,$3.val.dataInt);
	  		$$.type = mergeType($1.type,arr_type);
	  		$$.width = $1.width * $3.val.dataInt;
	  		$$.name = $1.name;
	  	}
	}
	|direct_declarator LEFT_SQUARE_BRACE STATIC type_qualifier_listopt assignment_expression RIGHT_SQUARE_BRACE
	{printf("       direct_declarator->[static type_qualifier_listopt assignment_expression]\n");}
	|direct_declarator LEFT_SQUARE_BRACE type_qualifier_list STATIC assignment_expression RIGHT_SQUARE_BRACE
	{printf("       direct_declarator->[type_qualifier_list static assignment_expression]\n");}	
	|direct_declarator LEFT_SQUARE_BRACE type_qualifier_listopt MULTIPLY RIGHT_SQUARE_BRACE
	{printf("       direct_declarator->[type_qualifier_listopt *]\n");}
	|direct_declarator LEFT_ROUND_BRACE parameter_type_list RIGHT_ROUND_BRACE
	{printf("       direct_declarator->(parameter_type_list)\n");}
	|direct_declarator LEFT_ROUND_BRACE identifier_listopt RIGHT_ROUND_BRACE
	{printf("       direct_declarator->(identifier_listopt)\n");}
	;
pointer
	:MULTIPLY 
	{
		printf ("	 	pointer-> *\n ");
		$$.type = newType (PtrVoidType,-1);
	}
	|MULTIPLY type_qualifier_list 
	{
		printf("       pointer-> * type_qualifier_listopt\n");
	}
	|MULTIPLY pointer 
	{
		printf("       pointer-> * type_qualifier_listopt pointer\n");
		$$.type = mergeType($2.type,newType(PtrVoidType,-1));
	}
	|MULTIPLY type_qualifier_list pointer 
	{
		printf("       pointer-> * type_qualifier_listopt pointer\n");
	}
	; 


type_qualifier_list
	:type_qualifier 
	{
		printf("       type_qualifier_list->type_qualifier\n");
	}
	|type_qualifier_list type_qualifier 
	{
		printf("       type_qualifier_list->type_qualifier_list type_qualifier\n");
	}
	;

type_qualifier_listopt
	:type_qualifier_list
	|
	;
parameter_type_list
	:parameter_list 
	{
		printf("       parameter_type_list->parameter_list\n");
	}
	|parameter_list COMMA ELLIPSIS 
	{
		printf("       parameter_type_list->parameter_list, ...\n");
	}
	;				   			  

parameter_list
	: parameter_declaration
	{
		printf("       parameter_list->parameter_declaration\n");

		if (!mulDecl)                                            // The rule indicates the function has not been declared previously 
		{
			temp = createSymbolTable();
			symbolTableRow row($1.name,$1.type,0,$1.width,-1,0);   
			temp->insert (row);                                   // offset is calculated in the insert function (which is easier) !
 
		}
	}
	| parameter_list COMMA parameter_declaration
	{
		printf("       parameter_list->parameter_list, parameter_declaration\n");
		
		if (!mulDecl)
		{
			symbolTableRow row($3.name,$3.type,0,$3.width,-1,0);
			temp-> insert (row);
		}
	}
	;
parameter_declaration
	:declaration_specifiers declarator 
	{
		printf("       parameter_declaration->declaration_specifiers declarator");
		
		if (!mulDecl) // function has not been declared previously
		{
			$$.name = $2.name ;
			$$.width = $1.width * $2.width;
			$$.type = mergeType ($2.type,$1.type); 
		}
	}
	|declaration_specifiers 
	{
		printf("       parameter_declaration->declaration_specifiers");
	}
	;
identifier_list
	: ID 
	{
		printf("       identifier_list->id\n");
	}
	| identifier_list COMMA ID 
	{
		printf("       identifier_list->identifier_list, id\n");
	}
	;

identifier_listopt
	:identifier_list
	|
	;

type_name
	: specifier_qualifier_list 
	{
		printf("       type_name->specifier_qualifier_list\n");
	}
	;

initializer
	:assignment_expression 
	{
		printf("       initializer->assignment_expression\n");
		$$ = $1.val;
	}
	|LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE 
	{	
		printf("       initializer->{initializer_list}\n");
	}
	|LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE 
	{	
		printf("       initializer->{initializer_list ,  }\n");
	} 
	;

initializer_list
	:designationopt initializer 
	{	
		printf("       initializer_list->designationopt initializer\n");
	}
	|initializer_list COMMA designationopt initializer 
	{
		printf("       initializer_list->initializer_list , designationopt initializer\n");
	}
	;

designation
	:designator_list EQUAL 
	{
		printf("       designation-> designator_list =\n");
	}
	;

designationopt
	:designation
	|
	;

designator_list
	:designator 
	{
		printf("       designator_list->designator\n");
	}
	|designator_list designator  
	{
		printf("       designator_list->designator_list designator\n");
	}
	;

designator
	:LEFT_SQUARE_BRACE constant_expression RIGHT_SQUARE_BRACE 
	{
		printf("       designator->[constant_expression]\n");
	}
	|PERIOD ID  
	{
		printf("       designator->.id\n");
	}
	;

statement
	:labeled_statement 
	{
		printf("       statement-> labeled_statement\n");
	}
	|compound_statement 
	{
		printf("       statement-> compound_statement\n");
		$$ = $1;
	}
	|expression_statement 
	{
		printf("       statement-> expression_statement\n");
		$$ = $1;
	}
	|selection_statement 
	{
		printf("       statement-> selection_statement\n");
		$$ = $1;
	}
	|iteration_statement 
	{
		printf("       statement-> iteration_statement\n");\
		$$ = $1;
	}
	|jump_statement 
	{
		printf("       statement-> jump_statement\n");
		$$ = $1;
	}
	;

labeled_statement
	:ID COLON statement 
	{
		printf("       labeled_statement-> id : statement\n"); /* Labeled statements are not handled */
	}
	|CASE constant_expression COLON statement 
	{
		printf("       case constant_expression: statement\n"); /* Labeled statements are not handled */
	}
	|DEFAULT COLON statement
	{
		printf("       default : statement\n"); /* Labeled statements are not handled */
	}
	;

compound_statement
	: LEFT_CURLY_BRACE RIGHT_CURLY_BRACE 
	{
		printf("       compound_statement->{ }\n");
	}
	| LEFT_CURLY_BRACE block_item_list RIGHT_CURLY_BRACE 
	{
		printf("       compound_statement->{block_item_listopt}\n");
		$$ = $2;
	}
	;

block_item_list
	:block_item 
	{
		printf("       block_item_list->block_item\n");
		$$ = $1;
	}
	|block_item_list M block_item 
	{
		printf("       block_item_list-> block_item_list block_item\n");
		// backpatch($1.NL,$2);
		$$ = $3;
	}
	;


block_item
	:declaration 
	{
		printf("       block_item->declaration\n");
	}
	|statement 
	{
		printf("       block_item->statement\n");
		$$ = $1;
	}
	;

expression_statement
	:SEMI_COLON {printf("       expression_statement->;\n");}
	| expression SEMI_COLON
	{
		printf("       expression_statement->expression ;\n");
		$$= $1;
	}
	;

selection_statement
	:IF LEFT_ROUND_BRACE expression RIGHT_ROUND_BRACE statement {printf("       selection_statement->if (expression) statement\n");}
	|IF LEFT_ROUND_BRACE expression RIGHT_ROUND_BRACE statement ELSE statement 
	{printf("       selection_statement->if (expression) statement else statement\n");}
	|SWITCH LEFT_ROUND_BRACE expression RIGHT_ROUND_BRACE statement 
	{printf("       selection_statement->switch (expression) statement\n");}
	;

iteration_statement
	: WHILE LEFT_ROUND_BRACE expression RIGHT_ROUND_BRACE statement {printf("       iteration_statement->while (expression) statement\n");}
	|DO statement WHILE LEFT_ROUND_BRACE expression RIGHT_ROUND_BRACE SEMI_COLON  
	{printf("       iteration_statement->do statement while (expression) ;\n");}
	|FOR LEFT_ROUND_BRACE expressionopt SEMI_COLON expressionopt SEMI_COLON expressionopt RIGHT_ROUND_BRACE statement
	{printf("       iteration_statement->for (expressionopt;expressionopt;expressionopt) statement\n");} 
	|FOR LEFT_ROUND_BRACE declaration expressionopt SEMI_COLON expressionopt RIGHT_ROUND_BRACE statement
	{printf("       iteration_statement->for (declaration expressionopt;expressionopt;expressionopt) statement\n");} 	
	;

jump_statement
	: GOTO ID SEMI_COLON {printf("       jump_statement-> goto id;\n");}
	|CONTINUE SEMI_COLON {printf("       jump_statement-> continue;\n");}
	|BREAK SEMI_COLON {printf("       jump_statement-> break;\n");}
	|RETURN expressionopt SEMI_COLON {printf("       jump_statement-> return expressionopt;\n");}
	;

translation_unit
	:external_declaration 
	{
		printf("       translation_unit->external_declaration\n");
	}
	|translation_unit external_declaration
	{
		printf("       translation_unit->translation_unit external_declaration\n");
		/* multiple translation units are not supported */
	}
	;

external_declaration
	:function_definition 
	{
		printf("       external_declaration->function_definition\n");
	}
	|declaration 
	{
		printf("       external_declaration->declaration\n");
	}
	;

function_definition	  
	: declaration_specifiers declarator declaration_list compound_statement
	  {
	  	printf("       function_definition->declaration_specifiers declarator declaration_list compound_statement;\n");
	  }
	 | declaration_specifiers declarator K compound_statement
	 {
	 	printf("       function_definition->declaration_specifiers declarator compound_statement;\n");
	 	current = global;

	 	/* exiting out of the function scope so the current symbol table should be restored back to global */
	 }
	;

declaration_list
	: declaration 
	{
		printf("       declaration_list->declaration\n");
	}
	| declaration_list declaration 
	{
		printf("       declaration_list->declaration_list declaration\n");
	}
	;


identifieropt
	:ID
	|
	;


M
	:
	{
		$$ = nextInstr; // augmentation to store the value of the nextInstr
	}
	;
N
	:
	{
		$$ = makelist(next_instr);  // list of exits for statements or list of statements
		quadArray->emit(0,0,0,Goto,0,0,0);
	}
	;
K
	:
	{

	}

%%


extern char yytext[];
extern int column;

void yyerror(const char *s)
{
	fflush(stdout);
	printf("       \n%*s\n%*s\n", column, "^", column, s);
}
