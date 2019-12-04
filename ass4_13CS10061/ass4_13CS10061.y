%{
#include <stdio.h>
extern int yylex();
%}

%union{
    int intval;
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

%start translation_unit
%%

primary_expression
	: ID    {printf("       primary_expression->id\n");}
	|INT_NO {printf ("       primary_expression->int_constant\n");}
	|FLOAT_NO {printf("       primary_expression->float_constant\n");}
	|STRING {printf("       primary_expression->string\n");}
	|CHARACTER {printf("       primary_expresion->character\n");}
        |LEFT_ROUND_BRACE expression RIGHT_ROUND_BRACE {printf("       primary_expression->(expression)\n");}
	;

postfix_expression
	: primary_expression {printf("       postfix_expression->primary_expression\n");}
        |postfix_expression LEFT_SQUARE_BRACE expression RIGHT_SQUARE_BRACE 
	{printf("       postfix_expression->postfix_expression[expression]\n");}
	|postfix_expression LEFT_ROUND_BRACE argument_expression_listopt RIGHT_ROUND_BRACE
	 {printf("       postfix_expression->postfix_expression(argument_expression_listopt)\n");}
	|postfix_expression PERIOD ID {printf("       postfix_expression->postfix_expression.id\n");}
        |postfix_expression ARROW ID {printf("       postfix_expression->postfix_expression->id\n");}
        |postfix_expression INCREMENT {printf("       postfix_expression->postfix_expression++\n");}
	|postfix_expression DECREMENT {printf("       postfix_expression->postfix_expression--\n");}
	|LEFT_ROUND_BRACE type_name RIGHT_ROUND_BRACE LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE 
	{printf("       postfix_expression->(type_name){initializer_list}\n");}
	|LEFT_ROUND_BRACE type_name RIGHT_ROUND_BRACE LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE
	{printf("       postfix_expression->(type_name){initializer_list,}\n");}
	;
argument_expression_listopt
	:argument_expression_list
	|
	;

argument_expression_list
	: assignment_expression {printf("       argument_expression_list->assignment_expression\n");}
	| argument_expression_list COMMA assignment_expression 
	{printf("       argument_expression_list->assignment_expression,assignment_expression\n");}
	;

unary_expression
	: postfix_expression {printf("       unary_expression->postfix_expression\n");}
	| INCREMENT unary_expression {printf("       unary_expression->++ unary_expression\n");}
	| DECREMENT unary_expression {printf("       unary_expression->-- unary_expression\n");}
	| unary_operator cast_expression {printf("       unary_expression->unary_operator cast_expression\n");}
	| SIZEOF unary_expression {printf("       unary_expression->sizeof(unary_expression)\n");}
	| SIZEOF LEFT_ROUND_BRACE type_name RIGHT_ROUND_BRACE {printf("       unary_expression->(type_name)\n");}
	;

unary_operator
	: AMPERSAND {printf("       unary_operator->&\n");}
	| MULTIPLY {printf("       unary_operator->*\n");}
	| ADD {printf("       unary_operator->+\n");}
	| SUBTRACT {printf("       unary_operator->-\n");}
	| TILDA {printf("       unary_operator->~\n");}
	| NEGATION {printf("       unary_operator->!\n");}
	;

cast_expression
	: unary_expression {printf("       cast_expression->unary_expression\n");}
	|LEFT_ROUND_BRACE type_name RIGHT_ROUND_BRACE cast_expression {printf("       cast_expression->(type_name) cast_expression\n");}
	;

multiplicative_expression
	: cast_expression {printf("       multiplicative_expression->cast_expression\n");}
	| multiplicative_expression MULTIPLY cast_expression 
	{printf("       multiplicative_expression->multiplicative_expression * cast_expression\n");}
	| multiplicative_expression DIVIDE cast_expression 
	{printf("       multiplicative_expression->multiplicative_expression / cast_expression\n");}
	| multiplicative_expression MODULUS cast_expression 
	{printf("       multiplicative_expression->multiplicative_expression %% cast_expression\n");}
	;

additive_expression
	: multiplicative_expression {printf("       additive_expression->multiplicative_expression\n");}
	| additive_expression ADD multiplicative_expression 
	{printf("       additive_expression->additive expression + multiplicative_expression\n");}
	| additive_expression SUBTRACT multiplicative_expression 
	{printf("       additive_expression->additive expression - multiplicative_expression\n");}
	;

shift_expression
	: additive_expression {printf("       shift_expression->additive_expression\n");}
	| shift_expression LEFT_SHIFT additive_expression {printf("       shift_expression->shift_expression << additive_expression\n");}
	| shift_expression RIGHT_SHIFT additive_expression {printf("       shift_expression->shift_expression >> additive_expression\n");}
	;

relational_expression
	: shift_expression {printf("       relational_expression->shift_expression\n");}
	| relational_expression LESS_THAN shift_expression 
	{printf("       relational_expression->relational_expression < shift_expression\n");}
	| relational_expression GREATER_THAN shift_expression 
	{printf("       relational_expression->relational_expression > shift_expression\n");}
	| relational_expression LESS_THAN_EQUAL_TO shift_expression 
	{printf("       relational_expression->relational_expression <= shift_expression\n");}
	| relational_expression GREATER_THAN_EQUAL_TO shift_expression 
	{printf("        relational_expression->relational_expression >= shift_expression\n");}
	;

equality_expression
	: relational_expression {printf("        equality_expression->relational_expression\n");}
	| equality_expression DOUBLE_EQUAL relational_expression 
	{printf("        equality_expression->equality_expression == relational_expression\n");}
	| equality_expression NOT_EQUAL relational_expression 
	{printf("       equality_expression->equality_expression != relational_expression\n");}
	;

and_expression
	: equality_expression {printf("       and_expression->equality_expression\n");}
	| and_expression AMPERSAND equality_expression {printf("       and_expression->and_expression & equality_expression\n");}
	;

exclusive_or_expression
	: and_expression {printf("       exclusive_or_expression->and_expression\n");}
	| exclusive_or_expression XOR and_expression {printf("       exclusive_or_expression->exclusive_or_expression ^ and_expression\n");}
	;

inclusive_or_expression
	: exclusive_or_expression {printf("       inclusive_or_expression->exclusive_or_expression\n");}
	| inclusive_or_expression BITWISE_OR exclusive_or_expression 
	{printf("       inclusive_or_expression->inclusive_or_expression | exclusive_or_expression\n");}
	;

logical_and_expression
	: inclusive_or_expression {printf("       logical_and_expression->inclusive_or_expression\n");}
	| logical_and_expression BINARY_AND inclusive_or_expression 
	{printf("       logical_and_expression->logical_and_expression && inclusive_or_expression\n");}
	;

logical_or_expression
	: logical_and_expression {printf("       logical_or_expression->logical_and_expression\n");}
	| logical_or_expression BINARY_OR logical_and_expression
	{printf("       logical_or_expression->logical_or_expression || logical_and_expression\n");}
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
	: ID {printf("       direct_declarator->id\n");}
	| LEFT_ROUND_BRACE declarator RIGHT_ROUND_BRACE {printf("       direct_declarator->(declarator)\n");} 
	|direct_declarator LEFT_SQUARE_BRACE type_qualifier_listopt assignment_expressionopt RIGHT_SQUARE_BRACE
	{printf("       direct_declarator->[type_qualifier_listopt assignment_expressionopt]\n");}
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
	:MULTIPLY type_qualifier_listopt {printf("       pointer-> * type_qualifier_listopt\n");}
	|MULTIPLY type_qualifier_listopt pointer {printf("       pointer-> * type_qualifier_listopt pointer\n");}
	; 


type_qualifier_list
	:type_qualifier {printf("       type_qualifier_list->type_qualifier\n");}
	|type_qualifier_list type_qualifier {printf("       type_qualifier_list->type_qualifier_list type_qualifier\n");}
	;

type_qualifier_listopt
	:type_qualifier_list
	|
	;
parameter_type_list
	:parameter_list {printf("       parameter_type_list->parameter_list\n");}
	|parameter_list COMMA ELLIPSIS {printf("       parameter_type_list->parameter_list, ...\n");}
	;				   			  

parameter_list
	: parameter_declaration{printf("       parameter_list->parameter_declaration\n");}
	| parameter_list COMMA parameter_declaration{printf("       parameter_list->parameter_list, parameter_declaration\n");}
	;
parameter_declaration
	:declaration_specifiers declarator {printf("       parameter_declaration->declaration_specifiers declarator");}
	|declaration_specifiers {printf("       parameter_declaration->declaration_specifiers");}
	;
identifier_list
	: ID {printf("       identifier_list->id\n");}
	| identifier_list COMMA ID {printf("       identifier_list->identifier_list, id\n");}
	;

identifier_listopt
	:identifier_list
	|
	;

type_name
	: specifier_qualifier_list {printf("       type_name->specifier_qualifier_list\n");}
	;

initializer
	:assignment_expression {printf("       initializer->assignment_expression\n");}
	|LEFT_CURLY_BRACE initializer_list RIGHT_CURLY_BRACE {printf("       initializer->{initializer_list}\n");}
	|LEFT_CURLY_BRACE initializer_list COMMA RIGHT_CURLY_BRACE {printf("       initializer->{initializer_list ,  }\n");} 
	;

initializer_list
	:designationopt initializer {printf("       initializer_list->designationopt initializer\n");}
	|initializer_list COMMA designationopt initializer 
	{printf("       initializer_list->initializer_list , designationopt initializer\n");}
	;

designation
	:designator_list EQUAL {printf("       designation-> designator_list =\n");}
	;

designationopt
	:designation
	|
	;

designator_list
	:designator {printf("       designator_list->designator\n");}
	|designator_list designator  {printf("       designator_list->designator_list designator\n");}
	;

designator
	:LEFT_SQUARE_BRACE constant_expression RIGHT_SQUARE_BRACE {printf("       designator->[constant_expression]\n");}
	|PERIOD ID  {printf("       designator->.id\n");}
	;

statement
	:labeled_statement {printf("       statement-> labeled_statement\n");}
	|compound_statement {printf("       statement-> compound_statement\n");}
	|expression_statement {printf("       statement-> expression_statement\n");}
	|selection_statement {printf("       statement-> selection_statement\n");}
	|iteration_statement {printf("       statement-> iteration_statement\n");}
	|jump_statement {printf("       statement-> jump_statement\n");}
	;

labeled_statement
	:ID COLON statement {printf("       labeled_statement-> id : statement\n");}
	|CASE constant_expression COLON statement {printf("       case constant_expression: statement\n");}
	|DEFAULT COLON statement{printf("       default : statement\n");}
	;

compound_statement
	:LEFT_CURLY_BRACE block_item_listopt RIGHT_CURLY_BRACE {printf("       compound_statement->{block_item_listopt}\n");}
	;

block_item_list
	:block_item {printf("       block_item_list->block_item\n");}
	|block_item_list block_item {printf("       block_item_listopt-> block_item_list block_item\n");}
	;

block_item_listopt
	:block_item_list
	|
	;

block_item
	:declaration {printf("       block_item->declaration\n");}
	|statement {printf("       block_item->statement\n");}
	;

expression_statement
	:expressionopt SEMI_COLON {printf("       expression_statement->expressionopt ;\n");}
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
	:external_declaration {printf("       translation_unit->external_declaration\n");}
	|translation_unit external_declaration
	{printf("       translation_unit->translation_unit external_declaration\n");}
	;

external_declaration
	:function_definition {printf("       external_declaration->function_definition\n");}
	|declaration {printf("       external_declaration->declaration\n");}
	;

function_definition	  
	: declaration_specifiers declarator declaration_listopt compound_statement
	{printf("       function_definition->declaration_specifiers declarator declaration_listopt compound_statement;\n");}
	;

declaration_list
	: declaration {printf("       declaration_list->declaration\n");}
	| declaration_list declaration {printf("       declaration_list->declaration_list declaration\n");}
	;

declaration_listopt
	: declaration_list
	|
	;

identifieropt
	:ID
	|
	;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("       \n%*s\n%*s\n", column, "^", column, s);
}
