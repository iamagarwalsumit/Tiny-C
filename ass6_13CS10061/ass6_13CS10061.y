%{
#include <stdio.h>
#include <iostream>
extern int yylex();
#include "ass6_13CS10061_translator.h"
#include <string.h>
void yyerror(const char* s);
%}



%union {
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
}

%token AUTO_KEYWORD;
%token RESTRICT_KEYWORD;
%token UNSIGNED_KEYWORD;
%token BREAK_KEYWORD;
%token EXTERN_KEYWORD;
%token RETURN_KEYWORD;
%token VOID_KEYWORD;
%token CASE_KEYWORD;
%token FLOAT_KEYWORD;
%token SHORT_KEYWORD;
%token VOLATILE_KEYWORD;
%token CHAR_KEYWORD;
%token FOR_KEYWORD;
%token SIGNED_KEYWORD;
%token WHILE_KEYWORD;
%token CONST_KEYWORD;
%token GOTO_KEYWORD;
%token SIZEOF_KEYWORD;
%token BOOL_KEYWORD;
%token CONTINUE_KEYWORD;
%token IF_KEYWORD;
%token STATIC_KEYWORD;
%token COMPLEX_KEYWORD;
%token DEFAULT_KEYWORD;
%token INLINE_KEYWORD;
%token STRUCT_KEYWORD;
%token IMAGINARY_KEYWORD;
%token DO_KEYWORD;
%token INT_KEYWORD;
%token SWITCH_KEYWORD;
%token DOUBLE_KEYWORD;
%token LONG_KEYWORD;
%token TYPEDEF_KEYWORD;
%token ELSE_KEYWORD;
%token REGISTER_KEYWORD;
%token UNION_KEYWORD;
%token <id_attr> IDENTIFIER;
%token <intval>  INTEGER_CONSTANT;
%token <floatval> FLOAT_CONSTANT;
%token <charval> CHAR_CONSTANT;
%token <strval> STRING_LITERAL;
%token VAL_AT;
%token PLUS_PLUS;
%token MINUS_MINUS;
%token LEFT_SHIFT;
%token RIGHT_SHIFT;
%token LESS_EQUAL;
%token GREATER_EQUAL;
%token EQUAL_EQUAL;
%token NOT_EQUAL;
%token LOGICAL_AND;
%token LOGICAL_OR;
%token ELLIPSES;
%token STAR_EQUAL;
%token BY_EQUAL;
%token PERCENT_EQUAL;
%token PLUS_EQUAL;
%token MINUS_EQUAL;
%token LEFT_SHIFT_EQUAL;
%token RIGHT_SHIFT_EQUAL;
%token AND_EQUAL;
%token BITWISENOT_EQUAL;
%token OR_EQUAL;


%type<exp_attr> primary_expression;
%type<exp_attr> expression;
%type<exp_attr> postfix_expression;
%type<exp_attr> constant_expression;
%type<exp_attr> statement;
%type<exp_attr> compound_statement;
%type<exp_attr> selection_statement;
%type<exp_attr> iteration_statement;
%type<exp_attr> jump_statement;
%type<exp_attr> block_item_list;
%type<exp_attr> block_item;
%type<exp_attr> expression_statement;
%type<exp_attr> unary_expression;
%type<exp_attr> cast_expression;
%type<exp_attr> multiplicative_expression;
%type<exp_attr> additive_expression;
%type<exp_attr> shift_expression;
%type<exp_attr> relational_expression;
%type<exp_attr> equality_expression;
%type<exp_attr> and_expression;
%type<exp_attr> exclusive_or_expression;
%type<exp_attr> inclusive_or_expression;
%type<exp_attr> logical_and_expression;
%type<exp_attr> logical_or_expression;
%type<exp_attr> conditional_expression;
%type<exp_attr> assignment_expression;
%type<var_decl_attr> type_specifier;
%type<var_decl_attr> declaration_specifiers;
%type<var_decl_attr> direct_declarator;
%type<var_decl_attr> declarator;
%type<var_decl_attr> parameter_declaration;
%type<var_decl_attr> init_declarator;
%type<initializer_attr> initializer;
%type<var_decl_attr> init_declarator_list;
%type<var_decl_attr> pointer;
%type<u_op_attr> unary_operator;
%type<instr> M;
%type<N_attr> N;
%type<param_attr> argument_expression_list;


%nonassoc IF_CONFLICT;
%nonassoc ELSE_KEYWORD;

%start translation_unit;
%%


primary_expression
	: IDENTIFIER
	  {
	  	$1.loc = current->lookup($1.var);
	  	if(!($1.loc))
	  		$1.loc = global->lookup($1.var);
	  	$$.loc = $1.loc;
	  	$$.type = ($1.loc)->Type;
	  	$$.array = $$.loc;
	  	$$.loc1 = 0;
	  }
	| INTEGER_CONSTANT
	  {
	  	$$.val.int_data = $1;
	  	$$.type = new_node(INT,-1);
	  	$$.loc = current->gentemp(INT);
	  	char *arg1 = new char[10];
	  	sprintf(arg1,"%d",$1);
	  	char *res = strdup(($$.loc)->name);
	  	quadArrayRow x(arg1,0,res,ASSIGN,0,0,$$.loc);
	  	quad_array->emit(x);
	  }
	| FLOAT_CONSTANT
	  {
		$$.val.double_data = $1;
		$$.type = new_node(DOUBLE,-1);
		$$.loc = current->gentemp(DOUBLE);
	  	char *arg1 = new char[10];
	  	sprintf(arg1,"%lf",$1);
	  	char *res = strdup(($$.loc)->name);
	  	quadArrayRow x(arg1,0,res,ASSIGN,0,0,$$.loc);
	  	quad_array->emit(x);
	  }
	| CHAR_CONSTANT
	  {
	  	$$.val.char_data = $1;
	  	$$.type = new_node(CHAR,-1);
	  	$$.loc = current->gentemp(CHAR);
	  	char *arg1 = new char[10];
	  	sprintf(arg1,"%d",$1);
	  	char *res = strdup(($$.loc)->name);
	  	quadArrayRow x(arg1,0,res,ASSIGN,0,0,$$.loc);
	  	quad_array->emit(x);
	  }
	| STRING_LITERAL
	  {
	  	toc[count_toc] = strdup($1);
	  	char *temp = new char[10];
	  	sprintf(temp,".LC%d",count_toc);
	  	count_toc++;
	  	$$.loc = new symbolTableRow(temp);
	  }
	| '(' expression ')'
	  {
	  		$$ = $2;
	  }
	;

postfix_expression
	: primary_expression
	  {
	  	$$ = $1;
	  }
	| postfix_expression '[' expression ']'
	  {
	  	$$.array = $1.array;
	  	$$.type = ($1.type)->right;
	  	if(!($1.loc1)){
	  		$$.loc1 = current->gentemp(INT);
	  		symbolTableRow *u = current->gentemp(INT);
	  		int m = compute_width(($1.type)->right);
	  		char *arg1 = new char[10];
	  		sprintf(arg1,"%d",m);
	  		char *res = strdup(u->name);
	  		quadArrayRow x(arg1,0,res,ASSIGN,0,0,u);
	  		quad_array->emit(x);
	  		arg1 = strdup(($3.loc)->name);
	  		char *arg2 = strdup(u->name);
	  		res = strdup(($$.loc1)->name);
	  		quadArrayRow y(arg1,arg2,res,INTO,$3.loc,u,$$.loc1);
	  		quad_array->emit(y);
	  	}
	  	else{
	  		symbolTableRow *temp = current->gentemp(INT);
		  	$$.loc1 = current->gentemp(INT);
		  	symbolTableRow *u = current->gentemp(INT);
		  	int n = compute_width($$.type);
		  	char *arg1 = new char[10];
		  	sprintf(arg1,"%d",n);
		  	char *res = strdup(u->name);
		  	quadArrayRow a(arg1,0,res,ASSIGN,0,0,u);
	  		quad_array->emit(a);
		  	arg1 = strdup(($3.loc)->name);
		  	char *arg2 = strdup(u->name);
		  	res = strdup(temp->name);
		  	quadArrayRow x(arg1,arg2,res,INTO,$3.loc,u,temp);
		  	quad_array->emit(x);
		  	arg1 = strdup(($1.loc1)->name);
		  	arg2 = strdup(temp->name);
		  	res = strdup(($$.loc1)->name);
		  	quadArrayRow y(arg1,arg2,res,PLUS,$1.loc1,temp,$$.loc1);
		  	quad_array->emit(y);
	  	}
	  	flag_array = 1;
	  }
	| postfix_expression '(' ')'
	  {
	  	int count = 0;
	  	symbolTableRow *t = global->lookup(($1.loc)->name);
	  	$$.loc = current->gentemp(((((t->nestedTable)->table)[count]).Type)->middle);
	  	char *res;
	  	quadEnum q;
	  	if((($$.loc)->Type)->middle == VOID){
	  		res = 0;
	  		q = call_void; 
	  	}
	  	else{
	  		res = strdup(($$.loc)->name);
	  		q = call;
	  	} 
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = new char[10];
	  	sprintf(arg2,"%d",count);
	  	quadArrayRow x(arg1,arg2,res,q,$1.loc,0,$$.loc);
	  	quad_array->emit(x);
	  	$$.type = ($$.loc)->Type;
	  }
	| postfix_expression '(' argument_expression_list ')'
	  {
	  	list_param *temp = $3;
	  	int count = 0;
	  	//printf("Yo\n");
	  	while(temp){
	  		char *arg1 = strdup((temp->parameter)->name);
	  		quadArrayRow x(arg1,0,0,PARAM,temp->parameter,0,0);
	  		quad_array->emit(x);
	  		count++;
	  		temp = temp->next;
	  	}
	  	symbolTableRow *t = global->lookup(($1.loc)->name);
	  	$$.loc = current->gentemp(((((t->nestedTable)->table)[count]).Type)->middle);
	  	char *res;
	  	quadEnum q;
	  	if((($$.loc)->Type)->middle == VOID){
	  		res = 0;
	  		q = call_void; 
	  	}
	  	else{
	  		res = strdup(($$.loc)->name);
	  		q = call;
	  	} 
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = new char[10];
	  	sprintf(arg2,"%d",count);
	  	quadArrayRow x(arg1,arg2,res,q,$1.loc,0,$$.loc);
	  	quad_array->emit(x);
	  	$$.type = ($$.loc)->Type;
	  	//printf("Yo\n");
	  }
	| postfix_expression '.' IDENTIFIER
	  {
	  	// not in use
	  }
	| postfix_expression VAL_AT IDENTIFIER
	  {
	  	// not in use
	  }
	| postfix_expression PLUS_PLUS
	  {
	  	$$.loc = current->gentemp(($1.type)->middle);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *res = strdup(($$.loc)->name);
	  	quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,$$.loc);
	  	quad_array->emit(x);
	  	symbolTableRow *u = current->gentemp(INT);
	  	arg1 = new char[10];
	  	sprintf(arg1,"1");
	  	res = strdup(u->name);
	  	quadArrayRow o(arg1,0,res,ASSIGN,0,0,u);
	  	quad_array->emit(o);
	  	arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(u->name);
	  	res = strdup(($1.loc)->name);
	  	quadArrayRow y(arg1,arg2,res,PLUS,$1.loc,u,$1.loc);
	  	quad_array->emit(y);
	  	$$.type = $1.type;
	  }
	| postfix_expression MINUS_MINUS
	  {
	  	$$.loc = current->gentemp(($1.type)->middle);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *res = strdup(($$.loc)->name);
	  	quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,$$.loc);
	  	quad_array->emit(x);
	  	symbolTableRow *u = current->gentemp(INT);
	  	arg1 = new char[10];
	  	sprintf(arg1,"1");
	  	res = strdup(u->name);
	  	quadArrayRow o(arg1,0,res,ASSIGN,0,0,u);
	  	quad_array->emit(o);
	  	arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(u->name);
	  	res = strdup(($1.loc)->name);
	  	quadArrayRow y(arg1,arg2,res,MINUS,$1.loc,u,$1.loc);
	  	quad_array->emit(y);
	  	$$.type = $1.type;
	  }
	| '(' type_name ')' '{' initializer_list '}'
	  {
	  	// not in use
	  }
	| '(' type_name ')' '{' initializer_list ',' '}'
	  {
	  	// not in use
	  }
	;

argument_expression_list
	: assignment_expression
	  {
	  	//printf("I am in trouble\n");
	  	//printf("%s\n",($1.loc)->name);
	  	$$ = make_param_list($1.loc);
	  	//printf("Help me\n");
	  }
	| argument_expression_list ',' assignment_expression
	  {
	  	//printf("Help me\n");
	  	$$ = merge_param_list($1,make_param_list($3.loc));
	  }
	;

unary_expression
	: postfix_expression
	  {
	  	$$ = $1;
	  	if($1.loc1){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.array)->name);
	  		char *arg2 = strdup(($1.loc1)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,EQ_BRACKET,$1.loc,$1.loc1,$$.loc);
	  		quad_array->emit(x);
	  		//$$.loc1 = 0;
	  	}
	  }
	| PLUS_PLUS unary_expression
	  {
	  	$$.loc = current->gentemp(($2.type)->middle);
	  	symbolTableRow *u = current->gentemp(INT);
	  	char *arg1 = new char[10];
	  	sprintf(arg1,"1");
	  	char *res = strdup(u->name);
	  	quadArrayRow o(arg1,0,res,ASSIGN,0,0,u);
	  	quad_array->emit(o);
	  	arg1 = strdup(($2.loc)->name);
	  	char *arg2 = strdup(u->name);
	  	res = strdup(($2.loc)->name);
	  	quadArrayRow y(arg1,arg2,res,PLUS,$2.loc,u,$2.loc);
	  	quad_array->emit(y);
	  	arg1 = strdup(($2.loc)->name);
	  	res = strdup(($$.loc)->name);
	  	quadArrayRow x(arg1,0,res,ASSIGN,$2.loc,0,$$.loc);
	  	quad_array->emit(x);
	  	$$.type = $2.type;
	  }
	| MINUS_MINUS unary_expression
	  {
	  	$$.loc = current->gentemp(($2.type)->middle);
	  	symbolTableRow *u = current->gentemp(INT);
	  	char *arg1 = new char[10];
	  	sprintf(arg1,"1");
	  	char *res = strdup(u->name);
	  	quadArrayRow o(arg1,0,res,ASSIGN,0,0,u);
	  	quad_array->emit(o);
	  	arg1 = strdup(($2.loc)->name);
	  	char *arg2 = strdup(u->name);
	  	res = strdup(($2.loc)->name);
	  	quadArrayRow y(arg1,arg2,res,MINUS,$2.loc,u,$2.loc);
	  	quad_array->emit(y);
	  	arg1 = strdup(($2.loc)->name);
	  	res = strdup(($$.loc)->name);
	  	quadArrayRow x(arg1,0,res,ASSIGN,$2.loc,0,$$.loc);
	  	quad_array->emit(x);
	  	$$.type = $2.type;
	  }
	| unary_operator cast_expression
	  {
	  	if(($1 == U_STAR) && ((star_count > 1 && left_or_right == 1)||(left_or_right == 2))){
	  		$$.loc = current->gentemp_cmplx(($2.type)->right);
	  		char *arg1 = strdup(($2.loc)->name);
		  	char *res = strdup(($$.loc)->name);
		  	quadArrayRow x(arg1,0,res,$1,$2.loc,0,$$.loc);
		  	quad_array->emit(x);
		  	$$.type = ($$.loc)->Type;
	  		star_count--;
	  	}
	  	else if($1 == U_ADDR){
	  		tree_Node_Type *tu = new_node(PTR,-1);
	  		tu->right = $2.type;
	  		$$.loc = current->gentemp_cmplx(tu);
	  		char *arg1 = strdup(($2.loc)->name);
		  	char *res = strdup(($$.loc)->name);
		  	quadArrayRow x(arg1,0,res,$1,$2.loc,0,$$.loc);
		  	quad_array->emit(x);
		  	$$.type = ($$.loc)->Type;
	  	}
	  	else if(!(star_count == 1 && left_or_right == 1)){
	  		$$.loc = current->gentemp(($2.type)->middle);
	  		char *arg1 = strdup(($2.loc)->name);
		  	char *res = strdup(($$.loc)->name);
		  	quadArrayRow x(arg1,0,res,$1,$2.loc,0,$$.loc);
		  	quad_array->emit(x);
		  	$$.type = ($$.loc)->Type;
	  	}
	  	else
	  		$$ = $2;	
	  }
	;

unary_operator
	: '&'
	  {
	  	$$ = U_ADDR;
	  }
	| '*'
	  {
	  	$$ = U_STAR;
	  	if(left_or_right == 1){
	  		is_left = 1;
	  	}
	  	star_count++;
	  }
	| '+'
	  {
	  	$$ = U_PLUS;
	  }
	| '-'
	  {
	  	$$ = U_MINUS;
	  }
	| '~'
	  {
	  	$$ = BW_U_NOT;
	  }
	| '!'
	  {
	  	$$ = U_NEGATION;
	  }
	;

cast_expression
	: unary_expression
	  {
	  	$$ = $1;
	  }
	| '(' type_name ')' cast_expression
	  {
	  	// not in use
	  }
	;

multiplicative_expression
	: cast_expression
	  {
	  	$$ = $1;
	  }
	| multiplicative_expression '*' cast_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,INTO,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->middle == INT && ($3.type)->middle == DOUBLE){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,INTO,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->middle == INT && ($3.type)->middle == CHAR){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,INTO,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == DOUBLE && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,INTO,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == CHAR && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,INTO,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	  }
	| multiplicative_expression '/' cast_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,DIV,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->middle == INT && ($3.type)->middle == DOUBLE){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,DIV,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->middle == INT && ($3.type)->middle == CHAR){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,DIV,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == DOUBLE && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,DIV,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == CHAR && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,DIV,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	  }
	| multiplicative_expression '%' cast_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,PERCENT,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->middle == INT && ($3.type)->middle == DOUBLE){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,PERCENT,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->middle == INT && ($3.type)->middle == CHAR){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,PERCENT,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == DOUBLE && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,PERCENT,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == CHAR && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,PERCENT,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	  }
	;

additive_expression
	: multiplicative_expression
	  {
	  	$$ = $1;
	  }
	| additive_expression '+' multiplicative_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		//printf("Help me\n");
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,PLUS,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		//printf("Help me\n");
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->middle == INT && ($3.type)->middle == DOUBLE){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,PLUS,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->middle == INT && ($3.type)->middle == CHAR){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,PLUS,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == DOUBLE && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,PLUS,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == CHAR && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,PLUS,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	  }
	| additive_expression '-' multiplicative_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,MINUS,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		$$.type = $1.type;
	  	}
	  	else{
	  		symbolTableRow *temp1, *temp2;
	  		if(($1.type)->middle == INT && ($3.type)->middle == DOUBLE){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,MINUS,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		else if(($1.type)->middle == INT && ($3.type)->middle == CHAR){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,MINUS,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == DOUBLE && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(DOUBLE);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"int2dbl(%s)",($3.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(DOUBLE);
	  			arg1 = strdup(($1.loc)->name);
	  			char *arg2 = strdup(temp1->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,MINUS,$1.loc,temp1,temp2);
	  			quad_array->emit(y);
	  			$$.type = $1.type;
	  		}
	  		else if(($1.type)->middle == CHAR && ($3.type)->middle == INT){
	  			temp1 = current->gentemp(INT);
	  			char *arg1 = new char[100];
	  			sprintf(arg1,"char2int(%s)",($1.loc)->name);
	  			char *res = strdup(temp1->name);
	  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
	  			quad_array->emit(x);
	  			temp2 = current->gentemp(INT);
	  			arg1 = strdup(temp1->name);
	  			char *arg2 = strdup(($3.loc)->name);
	  			res = strdup(temp2->name);
	  			quadArrayRow y(arg1,arg2,res,MINUS,temp1,$3.loc,temp2);
	  			quad_array->emit(y);
	  			$$.type = $3.type;
	  		}
	  		$$.loc = temp2;
	  	}
	  }
	;

shift_expression
	: additive_expression
	  {
	  	$$ = $1;
	  }
	| shift_expression LEFT_SHIFT additive_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,SL,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		$$.type = $1.type;
	  	}
	  }
	| shift_expression RIGHT_SHIFT additive_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,SR,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		$$.type = $1.type;
	  	}
	  }
	;

relational_expression
	: shift_expression
	  {
	  	$$ = $1;
	  }
	| relational_expression '<' shift_expression
	  {
	  	$$.TL = makelist(next_instr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArrayRow x(arg1,arg2,0,goto_LT,$1.loc,$3.loc,0);
	  	quad_array->emit(x);
	  	$$.FL = makelist(next_instr);
	  	quadArrayRow y(0,0,0,GOTO,0,0,0);
	  	quad_array->emit(y);
	  	$$.type = new_node(BOOL,-1);	
	  }
	| relational_expression '>' shift_expression
	  {
	  	$$.TL = makelist(next_instr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArrayRow x(arg1,arg2,0,goto_GT,$1.loc,$3.loc,0);
	  	quad_array->emit(x);
	  	$$.FL = makelist(next_instr);
	  	quadArrayRow y(0,0,0,GOTO,0,0,0);
	  	quad_array->emit(y);
	  	$$.type = new_node(BOOL,-1);
	  }
	| relational_expression LESS_EQUAL shift_expression
	  {
	  	$$.TL = makelist(next_instr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArrayRow x(arg1,arg2,0,goto_LTE,$1.loc,$3.loc,0);
	  	quad_array->emit(x);
	  	$$.FL = makelist(next_instr);
	  	quadArrayRow y(0,0,0,GOTO,0,0,0);
	  	quad_array->emit(y);
	  	$$.type = new_node(BOOL,-1);
	  }
	| relational_expression GREATER_EQUAL shift_expression
	  {
	  	$$.TL = makelist(next_instr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArrayRow x(arg1,arg2,0,goto_GTE,$1.loc,$3.loc,0);
	  	quad_array->emit(x);
	  	$$.FL = makelist(next_instr);
	  	quadArrayRow y(0,0,0,GOTO,0,0,0);
	  	quad_array->emit(y);
	  	$$.type = new_node(BOOL,-1);
	  }
	;

equality_expression
	: relational_expression
	  {
	  	$$ = $1;
	  }
	| equality_expression EQUAL_EQUAL relational_expression
	  {
	  	$$.TL = makelist(next_instr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArrayRow x(arg1,arg2,0,goto_EQ,$1.loc,$3.loc,0);
	  	quad_array->emit(x);
	  	$$.FL = makelist(next_instr);
	  	quadArrayRow y(0,0,0,GOTO,0,0,0);
	  	quad_array->emit(y);
	  	$$.type = new_node(BOOL,-1);
	  }
	| equality_expression NOT_EQUAL relational_expression
	  {
	  	$$.TL = makelist(next_instr);
	  	char *arg1 = strdup(($1.loc)->name);
	  	char *arg2 = strdup(($3.loc)->name);
	  	quadArrayRow x(arg1,arg2,0,goto_NEQ,$1.loc,$3.loc,0);
	  	quad_array->emit(x);
	  	$$.FL = makelist(next_instr);
	  	quadArrayRow y(0,0,0,GOTO,0,0,0);
	  	quad_array->emit(y);
	  	$$.type = new_node(BOOL,-1);
	  }
	;

and_expression
	: equality_expression
	  {
	  	$$ = $1;
	  }
	| and_expression '&' equality_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,BW_AND,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		$$.type = $1.type;
	  	}
	  }
	;

exclusive_or_expression
	: and_expression
	  {
	  	$$ = $1;
	  }
	| exclusive_or_expression '^' and_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,BW_XOR,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		$$.type = $1.type;
	  	}
	  }
	;

inclusive_or_expression
	: exclusive_or_expression
	  {
	  	$$ = $1;
	  }
	| inclusive_or_expression '|' exclusive_or_expression
	  {
	  	if(typecheck($1.type, $3.type)){
	  		$$.loc = current->gentemp(($1.type)->middle);
	  		char *arg1 = strdup(($1.loc)->name);
	  		char *arg2 = strdup(($3.loc)->name);
	  		char *res = strdup(($$.loc)->name);
	  		quadArrayRow x(arg1,arg2,res,BW_INOR,$1.loc,$3.loc,$$.loc);
	  		quad_array->emit(x);
	  		$$.type = $1.type;
	  	}
	  }
	;

logical_and_expression
	: inclusive_or_expression
	  {
	  	$$ = $1;
	  }
	| logical_and_expression LOGICAL_AND M inclusive_or_expression		// M augmented so that if $1 is true then it jumps to $3
	  {
	  	backpatch($1.TL,$3);
	  	$$.FL = merge($1.FL, $4.FL);
	  	$$.TL = $4.TL;
	  	$$.type = new_node(BOOL,-1);
	  }
	;

logical_or_expression
	: logical_and_expression
	  {
	  	$$ = $1;
	  }
	| logical_or_expression LOGICAL_OR M logical_and_expression			// M augmented so that if $1 is false then it jumps to $3
	  {
	  	backpatch($1.FL,$3);
	  	$$.TL = merge($1.TL,$4.TL);
	  	$$.FL = $4.FL;
	  	$$.type = new_node(BOOL,-1);
	  }
	;

conditional_expression
	: logical_or_expression
	  {
	  	$$ = $1;
	  }
	| logical_or_expression N '?' M expression N ':' M conditional_expression		// M and N augmented
	  {
	  	$$.loc = current->gentemp(($5.type)->middle);
	  	$$.type = $5.type;
	  	char *res = strdup(($$.loc)->name);
	  	char *arg1 = strdup(($9.loc)->name);
	  	quadArrayRow x(arg1,0,res,ASSIGN,$9.loc,0,$$.loc);
	  	quad_array->emit(x);
	  	list_node_Type *l = makelist(next_instr);
	  	quadArrayRow y(0,0,0,GOTO,0,0,0);
	  	quad_array->emit(y);
	  	backpatch($6,next_instr);
	  	res = strdup(($$.loc)->name);
	  	arg1 = strdup(($5.loc)->name);
	  	quadArrayRow z(arg1,0,res,ASSIGN,$5.loc,0,$$.loc);
	  	quad_array->emit(z);
	  	l = merge(l,makelist(next_instr));
	  	quadArrayRow a(0,0,0,GOTO,0,0,0);
	  	quad_array->emit(a);
	  	backpatch($2,next_instr);
	  	conv2Bool(&$1);
	  	backpatch($1.TL,$4);
	  	backpatch($1.FL,$8);
	  	backpatch(l,next_instr);

	  }
	;

assignment_expression
	: conditional_expression
	  {
	  	$$ = $1;
	  }
	| unary_expression assignment_operator assignment_expression
	  {
	  	if(is_left == 1){
	  		char *arg1 = strdup(($3.loc)->name);
		  	char *res = strdup(($1.loc)->name);
		  	quadArrayRow x(arg1,0,res,LEFT_STAR,$3.loc,0,$1.loc);
		  	quad_array->emit(x);
	  	}
	  	else{
	  		if(typecheck($1.type,$3.type)){
		  		if($1.loc1){
			  		//printf("%s\n",($1.loc)->name);
			  		char *arg1 = strdup(($1.array)->name);
			  		char *arg2 = strdup(($1.loc1)->name);
			  		char *res = strdup(($3.loc)->name);
			  		quadArrayRow x(arg1,arg2,res,BRACKET_EQ,$1.array,$1.loc1,$3.loc);
			  		quad_array->emit(x);
		  		}
		  		else{
			  		char *arg1 = strdup(($3.loc)->name);
				  	char *res = strdup(($1.loc)->name);
				  	quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,$1.loc);
				  	quad_array->emit(x);
		  		}
	  		}
		  	else{
		  		symbolTableRow *temp1, *temp2;
		  		if(($1.type)->middle == INT && ($3.type)->middle == DOUBLE){
		  			temp1 = current->gentemp(INT);
		  			char *arg1 = new char[100];
		  			sprintf(arg1,"dbl2int(%s)",($3.loc)->name);
		  			char *res = strdup(temp1->name);
		  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
		  			quad_array->emit(x);
		  		}
		  		else if(($1.type)->middle == INT && ($3.type)->middle == CHAR){
		  			temp1 = current->gentemp(CHAR);
		  			char *arg1 = new char[100];
		  			sprintf(arg1,"int2char(%s)",($1.loc)->name);
		  			char *res = strdup(temp1->name);
		  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
		  			quad_array->emit(x);
		  			
		  		}
		  		else if(($1.type)->middle == DOUBLE && ($3.type)->middle == INT){
		  			temp1 = current->gentemp(INT);
		  			char *arg1 = new char[100];
		  			sprintf(arg1,"dbl2int(%s)",($1.loc)->name);
		  			char *res = strdup(temp1->name);
		  			quadArrayRow x(arg1,0,res,ASSIGN,$1.loc,0,temp1);
		  			quad_array->emit(x);
		  		}
		  		else if(($1.type)->middle == CHAR && ($3.type)->middle == INT){
		  			temp1 = current->gentemp(CHAR);
		  			char *arg1 = new char[100];
		  			sprintf(arg1,"int2char(%s)",($3.loc)->name);
		  			char *res = strdup(temp1->name);
		  			quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,temp1);
		  			quad_array->emit(x);
		  		}
		  		if($1.loc1){
			  		//printf("%s\n",($1.loc)->name);
			  		char *arg1 = strdup(($1.array)->name);
			  		char *arg2 = strdup(($1.loc1)->name);
			  		char *res = strdup((temp1)->name);
			  		quadArrayRow x(arg1,arg2,res,BRACKET_EQ,$1.array,$1.loc1,$3.loc);
			  		quad_array->emit(x);
		  		}
		  		else{
			  		char *arg1 = strdup((temp1)->name);
				  	char *res = strdup(($1.loc)->name);
				  	quadArrayRow x(arg1,0,res,ASSIGN,$3.loc,0,$1.loc);
				  	quad_array->emit(x);
		  		}
		  	}
	  	}
	  	left_or_right = 1;
	  	is_left = 0;
	  	star_count = 0;
	  }
	;

assignment_operator
	: '='
	 {
	 	left_or_right = 2;
	 }
	|STAR_EQUAL
	 {
	 	// no action
	 }
	|BY_EQUAL
	 {
	 	// no action
	 }
        |PERCENT_EQUAL
         {
         	// no action
         }
        |PLUS_EQUAL
         {
         	// no action
         }
        |MINUS_EQUAL
         {
         	// no action
         }
        |LEFT_SHIFT_EQUAL
         {
         	// no action
         }
        |RIGHT_SHIFT_EQUAL
         {
         	// no action
         }
        |AND_EQUAL
         {
         	// no action
         }
        |BITWISENOT_EQUAL
         {
         	// no action
         }
        |OR_EQUAL
         {
         	// no action
         }
	;

expression
	: assignment_expression
	  {
	  	$$ = $1;
	  }
	| expression ',' assignment_expression
	  {
	  	// not to be used as comma is not to be used as an operator
	  }
	;

constant_expression
	: conditional_expression
	  {

	  }
	;

declaration
	: declaration_specifiers ';'
	  {
	  	// not in use
	  }
	| declaration_specifiers init_declarator_list ';'
	  {
	  	if(flag1 == 1 && flag2 == 0){
	  		tree_Node_Type *temp = new_node(($1.type)->middle,-1);
	  		char *temp1 = strdup("retVal");
	  		symbolTableRow x(temp1,temp,0,$1.width,-1,0);
	  		temp_use->insert(x);
	  		temp = new_node(FUNCTION,-1);
	  		symbolTableRow y($2.var,temp,0,0,-1,temp_use);
	  		global->insert(y);
	  	}
	  	flag1 = 0;
	  	flag2 = 0;
	  	c = 0;
	  }
	;

declaration_specifiers
	: storage_class_specifier {/* not in use*/}
	| storage_class_specifier declaration_specifiers {/* not in use*/}
	| type_specifier {/* not in use*/}
	  {
	  	if(flag1 == 0 || flag2 == 0){
	  		$$.type = $1.type;
	  		$$.width = $1.width;
	  		t = $$.type;
	  		w = $$.width;
	  	}
	  }
	| type_specifier declaration_specifiers {/* not in use*/}
	| type_qualifier {/* not in use*/}
	| type_qualifier declaration_specifiers {/* not in use*/}
	| function_specifier {/* not in use*/}
	| function_specifier declaration_specifiers {/* not in use*/}
	;

init_declarator_list
	: init_declarator
	  {
	  	if(flag1 == 1 && flag2 == 0)
	  		$$.var = $1.var;
	  }
	| init_declarator_list ',' init_declarator
	  {

	  }
	;

init_declarator
	: declarator
	  {
	  	if(flag1 == 0){
	  		tree_Node_Type *temp = new_node(t->middle,-1);
	  		temp = merge_node($1.type,temp);
	  		int temp_size;
	  		if(temp->middle == PTR)
	  			temp_size = SIZE_OF_PTR;
	  		else{
		  		switch(t->middle){
		  			case INT : temp_size = SIZE_OF_INT;
		  					   break;
		  			case DOUBLE : temp_size = SIZE_OF_DOUBLE;
		  						  break;
		  			case CHAR   : temp_size = SIZE_OF_CHAR;
		  						  break; 	
	  			}
	  		}
	  		temp_size = temp_size * $1.width;
	  		symbolTableRow x($1.var,temp,0,temp_size,-1,0);
	  		current->insert(x);
	  		//current->print_table();
	  	}
	  	else if(flag1 == 1 && flag2 == 0){
	  		$$.var = $1.var;
	  	}
	  }
	| declarator '=' initializer
	  {
	  	if(flag1 == 0){
	  		tree_Node_Type *temp = new_node(t->middle,-1);
	  		temp = merge_node($1.type,temp);
	  		void *value;
	  		int *v1;
	  		double *v2;
	  		char *v3;
	  		int temp_size;
	  		switch(t->middle){
	  			case INT : v1 = (int *)malloc(sizeof(int));
	  					   (*v1) = $3.int_data; 	
	  					   value = (void *)v1;
	  					   temp_size = SIZE_OF_INT;
	  					   break;
	  			case DOUBLE : v2 = (double *)malloc(sizeof(double));
		  					   (*v2) = $3.double_data;
		  					   //printf("%lf\n",$3.double_data); 	
		  					   value = (void *)v2;
		  					   //printf("%lf\n",*v2);
		  					   temp_size = SIZE_OF_DOUBLE;
		  					   break;
	  			case CHAR   :v3 = (char *)malloc(sizeof(char));
	  					   (*v3) = $3.char_data; 	
	  					   value = (void *)v3;
	  					   temp_size = SIZE_OF_CHAR;
	  					   break;
	  			default     : value = 0; 	
	  		}
	  		temp_size = temp_size * $1.width;
	  		symbolTableRow x($1.var,temp,value,temp_size,-1,0);
	  		current->insert(x);
	  	}
	  }
	;

storage_class_specifier
	: TYPEDEF_KEYWORD {/* not in use*/}
	| EXTERN_KEYWORD {/* not in use*/}
	| STATIC_KEYWORD {/* not in use*/}
	| AUTO_KEYWORD {/* not in use*/}
	| REGISTER_KEYWORD {/* not in use*/}
	;

type_specifier
	: VOID_KEYWORD
	  {
	  	if(flag2 == 0 || flag1 == 0){
	  		$$.type = new_node(VOID,-1);
	  		$$.width = 0;
	  	}
	  }
	| CHAR_KEYWORD
	  {
	  	if(flag2 == 0 || flag1 == 0){
	  		$$.type = new_node(CHAR,-1);
	  		$$.width = SIZE_OF_CHAR;
	  	}
	  }
	| SHORT_KEYWORD {/* not in use*/}
	| INT_KEYWORD
	  {
	  	if(flag2 == 0 || flag1 == 0){
	  		//printf("Yo1\n");
	  		$$.type = new_node(INT,-1);
	  		//printf("Yo2\n");
	  		$$.width = SIZE_OF_INT;
	  		//printf("Yo3\n");
	  	}
	  }
	| LONG_KEYWORD {/* not in use*/}
	| FLOAT_KEYWORD {/* not in use*/}
	| DOUBLE_KEYWORD
	  {
	  	if(flag2 == 0 || flag1 == 0){
	  		$$.type = new_node(DOUBLE,-1);
	  		$$.width = SIZE_OF_DOUBLE;
	  	}
	  }
	| SIGNED_KEYWORD {/* not in use*/}
	| UNSIGNED_KEYWORD {/* not in use*/}
	| BOOL_KEYWORD {/* not in use*/}
	| COMPLEX_KEYWORD {/* not in use*/}
	| IMAGINARY_KEYWORD {/* not in use*/}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	  {
	  	// not in use
	  }
	| type_specifier
	  {
	  	// not in use
	  }
	| type_qualifier specifier_qualifier_list
	  {
	  	// not in use
	  }
	| type_qualifier
	  {
	  	// not in use
	  }
	;

type_qualifier
	: CONST_KEYWORD
	  {
	  	// not in use
	  }
	| RESTRICT_KEYWORD
	  {
	  	// not in use
	  }
	| VOLATILE_KEYWORD
	  {
	  	// not in use
	  }
	;

function_specifier
	: INLINE_KEYWORD
	  {
	  	// not in use
	  }
	;

declarator
	: pointer direct_declarator
	  {
	  	if(flag1 == 0 || flag2 == 0){
	  		//printf("merge_node me load hai kya?\n");
	  		$$.type = merge_node($2.type,$1.type);
	  		$$.width = $2.width;
	  		$$.var = $2.var;
	  		//printf("%d\n",($$.type)->middle);
	  		//printf("%d\n",$$.width);
	  	}
	  }
	| direct_declarator
	  {
	  		$$.type = $1.type;
	  		$$.var = $1.var;
	  		$$.width = $1.width;
	  }
	;

direct_declarator
	: IDENTIFIER
	  {
	  	if(flag1 == 0 || flag2 == 0){
	  		$$.var = $1.var;
		  	$$.type = 0;
		  	$$.width = 1;
		  	if(c == 0){
		  		//printf("DD->Id me load hai kya?\n");
		  		symbolTableRow *t = current->lookup($1.var);
			  	if(t){
			  		flag2 = 1;
			  		temp_use = (t->nestedTable);	// Set flag to handle multiple declaration
			  		//printf("%s\n",(t->nestedTable)[0].name);
			  		//printf("%p\n",temp_use);
			  		//printf("%p\n",t->nestedTable);
			  		//if(!temp_use)
			  		//printf("Null hai\n");
			  		//printf("%d\n",temp_use->curr_length);
			  		//printf("%s\n",(temp_use->table)[0].name);
			  		//temp_use->print_table();
			  		//printf("Type casting ka load nahi hai\n");
			  	}												// (to be used in other actions)		
			  	else                                            
			  		flag2 = 0; 
			  	c++;	
		  	}
	  	}										
	  }
	| '(' declarator ')'
	  {
	  	// not in use
	  }
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	  {
	  	// not in use
	  }
	| direct_declarator '[' assignment_expression ']'
	  {
	  	if(flag1 == 0 || flag2 == 0){
	  		tree_Node_Type *temp = new_node(ARRAY,$3.val.int_data);
	  		$$.type = merge_node($1.type,temp);
	  		$$.width = $1.width * $3.val.int_data;
	  		$$.var = $1.var;
	  	}
	  }
	| direct_declarator '[' type_qualifier_list ']'
	  {
	  	// not in use
	  }
	| direct_declarator '[' ']'
	  {
	  	if(flag1 == 0 || flag2 == 0){
	  		$$.var = $1.var;
		  	$$.type = $1.type;
		  	$$.width = $1.width;
	  	}
	  }
	| direct_declarator '[' STATIC_KEYWORD type_qualifier_list assignment_expression ']'
	  {
	  	// not in use
	  }
	| direct_declarator '[' STATIC_KEYWORD assignment_expression ']'
	  {
	  	// not in use
	  }
	| direct_declarator '[' type_qualifier_list STATIC_KEYWORD assignment_expression ']'
	  {
	  	// not in use
	  }
	| direct_declarator '[' type_qualifier_list '*' ']'
	  {
	  	// not in use
	  }
	| direct_declarator '[' '*' ']'
	  {
	  	// not in use
	  }
	| direct_declarator '(' parameter_type_list ')'
	  {
	  	flag1 = 1;										// Flag1 is set for variable declaration
	  	$$.var = $1.var;
	  	$$.type = 0;
	  	$$.width = 1;
	  }
	| direct_declarator '(' identifier_list ')'
	  {
	  	// not in use
	  }
	| direct_declarator '(' ')'
	  {
	  	flag1 = 1;
	  	if(flag2 == 0)
	  		temp_use = create_Symbol_Table();
	  	$$.var = $1.var;
	  	$$.type = 0;
	  	$$.width = 1;
	  }
	;

pointer
	: '*'
	  {
	  	$$.type = new_node(PTR,-1);
	  	//printf("Wassup\n");
	  }
	| '*' type_qualifier_list
	  {
	  	// not in use
	  }
	| '*' pointer
	  {
	  	tree_Node_Type *temp = new_node(PTR,-1);
	  	$$.type = merge_node($2.type,temp);
	  }
	| '*' type_qualifier_list pointer
	  {
	  	// not in use
	  }
	;

type_qualifier_list
	: type_qualifier
	  {
	  	// not in use
	  }
	| type_qualifier_list type_qualifier
	  {
	  	// not in use
	  }
	;

parameter_type_list
	: parameter_list {}
	| parameter_list ',' ELLIPSES
	  {
	  	// not in use
	  }
	;

parameter_list
	: parameter_declaration
	  {
	  	if(flag2 == 0){										// An indication of the fact that function has not been
	  		temp_use = create_Symbol_Table();				// declared previously
	  		symbolTableRow x($1.var,$1.type,0,$1.width,-1,0); //Insert in sym tab of function(offset comp.in insert)
	  		temp_use->insert(x);
	  	}
	  }
	| parameter_list ',' parameter_declaration
	  {
	  	if(flag2 == 0){
	  		symbolTableRow x($3.var,$3.type,0,$3.width,-1,0); //Insert in sym tab of function(offset comp. in insert)
	  		temp_use->insert(x);
	  	}
	  }
	;

parameter_declaration
	: declaration_specifiers declarator
	  {
	  	if(flag2 == 0){										// An indication that function has not been declared prev
	  		$$.type = merge_node($2.type,$1.type);
	  		$$.var = $2.var;
	  		$$.width = $1.width*$2.width;
	  	}	
	  }
	| declaration_specifiers
	  {
	  	// not in use
	  }
	;

identifier_list
	: IDENTIFIER
	  {
	  	// not in use
	  }
	| identifier_list ',' IDENTIFIER
	  {
	  	// not in use
	  }
	;

type_name
	: specifier_qualifier_list
	  {
	  	// not in use
	  }
	;

initializer
	: assignment_expression
	  {
	  	$$ = $1.val;
	  }
	| '{' initializer_list '}'
	  {
	  	// not in use
	  }
	| '{' initializer_list ',' '}'
	  {
	  	// not in use
	  }
	;

initializer_list
	: initializer
	  {
	  	// not in use
	  }
	| initializer_list ',' initializer
	  {
	  	// not in use
	  }
	| initializer_list ',' designation initializer
	  {
	  	// not in use
	  }
	;

designation
	: designator_list '='
	  {
	  	// not in use
	  }
	;

designator_list
	: designator
	  {
	  	// not in use
	  }
	| designator_list designator
	  {
	  	// not in use
	  }
	;

designator
	: '[' constant_expression ']'
	  {
	  	// not in use
	  }
	| '.' IDENTIFIER
	  {
	  	// not in use
	  }
	;

statement
	: labeled_statement
	  {
	  	// not in use
	  }
	| compound_statement
	  {
	  	$$ = $1;
	  }
	| expression_statement
	  {
	  	$$ = $1;
	  }
	| selection_statement
	  {
	  	$$ = $1;
	  }
	| iteration_statement
	  {
	  	$$ = $1;
	  }
	| jump_statement
	  {
	  	$$ = $1;
	  }
	;
labeled_statement
	: IDENTIFIER ':' statement
	  {
	  	// not in use
	  }
	| CASE_KEYWORD constant_expression ':' statement
	  {
	  	// not in use
	  }
	| DEFAULT_KEYWORD ':' statement
	  {
	  	// not in use
	  }
	;

compound_statement
	: '{' '}'
	  {
	  	// not in use
	  }
	| '{' block_item_list '}'
	  { 
	  	$$ = $2;
	  }
	;

block_item_list
	: block_item
	  { 
	  	$$ = $1;
	  }
	| block_item_list M block_item 
	  { 
		backpatch($1.NL,$2);
		$$ = $3;
	  }
	;

block_item
	: declaration{ }
	| statement 
	  {
	  	$$ = $1;
	  }
	;

expression_statement
	: ';'
	  {
	  	// not in use
	  }
	| expression ';'
	  {
	  	$$ = $1;
	  }
	;

selection_statement
	: IF_KEYWORD '(' expression N')' M statement N  %prec IF_CONFLICT
	  {
	  	/*list_node_Type *l = 0;
	  	if(($3.type)->middle!=BOOL){
	  		//printf("Type is bool\n");
	  		l = makelist(next_instr);
	  		quadArrayRow x(0,0,0,GOTO,0,0,0);
	  		quad_array->emit(x);
	  	}*/
	  	backpatch($4,next_instr);
	  	conv2Bool(&$3);
	  	backpatch($3.TL,$6);
	  	$$.NL = merge($7.NL,$3.FL);
	  	$$.NL = merge($$.NL,$8);
	  }
	| IF_KEYWORD '(' expression N')' M statement N ELSE_KEYWORD M statement  
	  {
	  	list_node_Type *l = 0;
	  	if(($3.type)->middle!=BOOL){
	  		l = makelist(next_instr);
	  		quadArrayRow x(0,0,0,GOTO,0,0,0);
	  		quad_array->emit(x);
	  	}
	  	backpatch($4,next_instr);
	  	conv2Bool(&$3);
	  	backpatch($3.TL,$6);
	  	backpatch($3.FL,$10);
	  	list_node_Type *temp = merge($8,$7.NL);
	  	$$.NL = merge(temp,$11.NL);
	  	$$.NL = merge($$.NL,l);
	  }
	| SWITCH_KEYWORD '(' expression ')' statement
	  {
	  	// not in use
	  }
	;

iteration_statement
	: WHILE_KEYWORD M '(' expression N')' M statement              // M and N augmented
	  {
	  	char *res = new char[10];
	  	sprintf(res,"%d",$2);
	  	quadArrayRow x(0,0,res,GOTO,0,0,0);
	  	quad_array->emit(x);
	  	backpatch($5,next_instr);
	  	conv2Bool(&$4);
	  	backpatch($8.NL,$2);
	  	backpatch($4.TL,$7);
	  	$$.NL = $4.FL;
	  }
	| DO_KEYWORD M statement M WHILE_KEYWORD '(' expression N')' ';'		// M and N augmented
	  {
	  	backpatch($8,next_instr);
	  	conv2Bool(&$7);
	  	backpatch($7.TL,$2);
	  	backpatch($3.NL,$4);
	  	$$.NL = $7.FL;
	  }
	| FOR_KEYWORD '(' expression_statement M 
		expression_statement N M expression N')' M statement                    // M & N augmented
	  {
	  	backpatch($9,$4);
	  	list_node_Type *l = makelist(next_instr);
	  	quadArrayRow x(0,0,0,GOTO,0,0,0);
	  	quad_array->emit(x);
	  	$12.NL = merge($12.NL,l);
	  	backpatch($12.NL,$7);
	  	backpatch($6,next_instr);
	  	conv2Bool(&$5);
	  	backpatch($5.TL,$11);
	  	$$.NL = $5.FL;
	  }
	| FOR_KEYWORD '(' declaration expression_statement expression ')' statement
	  {
	  	// not in use
	  }
	;

jump_statement
	: GOTO_KEYWORD IDENTIFIER ';'
	  {
	  	// not in use
	  }
	| CONTINUE_KEYWORD ';'
	  {
	  	// not in use
	  }
	| BREAK_KEYWORD ';'
	  {
	  	// not in use
	  }
	| RETURN_KEYWORD ';'
	  {
	  	quadArrayRow x(0,0,0,RETURN,0,0,0);
	  	quad_array->emit(x);
	  }
	| RETURN_KEYWORD expression ';'
	  {
	  	char *arg1 = strdup(($2.loc)->name);
	  	quadArrayRow x(arg1,0,0,RETURN_EXP,$2.loc,0,0);
	  	quad_array->emit(x);
	  }
	;

translation_unit
	: external_declaration {}
	| translation_unit external_declaration { //Not used as multiple translation units are not supported
											}
	;

external_declaration
	: function_definition {}
	| declaration {}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	  {
	  	// Not used
	  }
	| declaration_specifiers declarator O compound_statement            	// O augmented
	  {
	  	current = global; // Exiting out of function so set current pointer to global symbol table 
	  }
	;

declaration_list
	: declaration
	  {
	  	// not in use
	  }
	| declaration_list declaration
	  {
	  	// not in use
	  }
M
	:
	{
		$$ = next_instr;
	}
	;
N
	:
	{
		$$ = makelist(next_instr);
		quadArrayRow x(0,0,0,GOTO,0,0,0);
		quad_array->emit(x);
	}
	;
O   
	:
	{
		current = temp_use; // As we are entering the function current should point to symbol table of function
		//current->print_table();
		//printf("Yes\n");
		int i;
		char *t;
		for(i=0;i<=global->curr_length;i++){
			if((((global->table)[i]).nestedTable) == current){
				t = strdup(((global->table)[i]).name);
				break;
			}
		}
		quadArrayRow x(t,0,0,Function,((global->table)+i),0,0);
		quad_array->emit(x);
		flag1 = 0;
		flag2 = 0;
		c = 0;
		//printf("Yes\n");
	}
	;

%%

void yyerror(const char* s) {
	printf("%s", s);
}