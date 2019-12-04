# include "ass6_13CS10061_translator.h"
# include "y.tab.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <iostream>

using namespace std;

/* Implementation of symboltablerow */
symbolTableRow::symbolTableRow(char *name_f, tree_Node_Type *Type_f, void *initial_value_f, int size_f, int offset_f, symbolTable *nestedTable_f) : name(name_f), Type(Type_f), initial_value(initial_value_f), size(size_f), offset(offset_f), nestedTable(nestedTable_f) {}
void symbolTableRow::operator=(symbolTableRow &x){
	this->name = x.name;
	this->Type = x.Type;
	this->initial_value = x.initial_value;
	this->size = x.size;
	this->offset = x.offset;
	this->nestedTable = x.nestedTable;
}
symbolTableRow::~symbolTableRow(){}
void symbolTableRow::print_row(){
	//printf("Print row entered\n");
	printf("%s\t ",name);
	//printf("Name me hi load hai\n");
	print_Initial_Value(initial_value,Type);
	printf("\t");
	cout<<size<<"\t";
	cout<<offset<<"\t";
	if(nestedTable == NULL)
		cout<<"... \t";
	else
		printf("%s \t",(nestedTable->table)[0].name);
	print_Tree(Type);
}

/* Implementation of symbolTable */
symbolTable::symbolTable(unsigned int capacity){
	table = new symbolTableRow[capacity];
	curr_length = -1;
}
symbolTable::~symbolTable(){}
symbolTableRow *symbolTable::lookup(char *t){											// Returns 0 if that var or func is not present in the symbol table
	int i;
	//printf("%d\n",curr_length);
	for(i = 0;i<=curr_length;i++){
		//printf("%s\n",table[i].name);
		if(strcmp(table[i].name,t) == 0)
			return (table + i);
	}
	return 0;
}
void symbolTable::insert(symbolTableRow &x){												// Inserts a row in the symbol table. Also computes the offset
	if(curr_length == -1)
		x.offset = 0;
	else
		x.offset = table[curr_length].size + table[curr_length].offset;
	curr_length++;
	table[curr_length] = x;
	//printf("%d\n",table[0].offset);
}
void symbolTable::print_table(){															// Prints the symbol table
	int i;
	for(i=0;i<=(this->curr_length);i++){
		//printf("Yahan toh aya hai\n");
		//printf("%d\n",this->curr_length);
		table[i].print_row();
		//printf("Arre wah yahan bhi aya hai\n");
		cout<<endl;
	}
}
symbolTableRow *symbolTable::gentemp(typeEnum temp){
	tree_Node_Type *t = new_node(temp,-1);
	char *s = new char[10];
	sprintf(s,"t%d",temp_count);
	temp_count++;
	int temp_size = 0;
	switch(temp){
		case INT : temp_size = SIZE_OF_INT;
					break;
		case CHAR : temp_size = SIZE_OF_CHAR;
					break;
		case DOUBLE : temp_size = SIZE_OF_DOUBLE;
					break;
		case PTR : temp_size = SIZE_OF_PTR;
					break;
	}
	symbolTableRow x(s,t,0,temp_size,-1,0);
	this->insert(x);
	return &((this->table)[curr_length]);
}
symbolTableRow *symbolTable::gentemp_cmplx(tree_Node_Type *temp){
	tree_Node_Type *ti = duplicate_tree(temp);
	int siz = compute_width(ti);
	char *s = new char[10];
	sprintf(s,"t%d",temp_count);
	temp_count++;
	symbolTableRow x(s,ti,0,siz,-1,0);
	this->insert(x);
	return &((this->table)[curr_length]);
}
/* Implementation of quadArrayRow */

quadArrayRow::quadArrayRow(char *arg1_f, char *arg2_f, char *res_f, quadEnum op_f, symbolTableRow *arg1_loc_f, symbolTableRow *arg2_loc_f, symbolTableRow *res_loc_f) : arg1(arg1_f), arg2(arg2_f), res(res_f), op(op_f), arg1_loc(arg1_loc_f), arg2_loc(arg2_loc_f), res_loc(res_loc_f) {}

quadArrayRow::~quadArrayRow() {}

void quadArrayRow::operator=(quadArrayRow &x){
	this->arg1 = x.arg1;
	this->arg2 = x.arg2;
	this->res = x.res;
	this->op = x.op;
	this->arg1_loc = x.arg1_loc;
	this->arg2_loc = x.arg2_loc;
	this->res_loc = x.res_loc;
}

void quadArrayRow::print_quadArrayRow(int line){
	if(this->arg2){
		switch(this->op){
			/**/case PLUS : printf("%3d : %s = %s + %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case MINUS : printf("%3d : %s = %s - %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case INTO : printf("%3d : %s = %s * %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case DIV : printf("%3d : %s = %s / %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case PERCENT : printf("%3d : %s = %s %% %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case SL : printf("%3d : %s = %s << %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case SR : printf("%3d : %s = %s >> %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case LT : printf("%3d : %s = %s < %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case LTE : printf("%3d : %s = %s <= %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case GT : printf("%3d : %s = %s > %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case GTE : printf("%3d : %s = %s >= %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case EQ : printf("%3d : %s = %s == %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case NEQ : printf("%3d : %s = %s != %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case BW_AND : printf("%3d : %s = %s & %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case BW_XOR : printf("%3d : %s = %s ^ %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case BW_INOR : printf("%3d : %s = %s | %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/***/case LOG_AND : printf("%3d : %s = %s && %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/***/case LOG_OR : printf("%3d : %s = %s || %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case goto_LT : printf("%3d : if %s < %s goto %s\n",line,this->arg1,this->arg2,this->res);
						break;
			/**/case goto_LTE : printf("%3d : if %s <= %s goto %s\n",line,this->arg1,this->arg2,this->res);
						break;
			/**/case goto_GT : printf("%3d : if %s > %s goto %s\n",line,this->arg1,this->arg2,this->res);
						break;
			/**/case goto_GTE : printf("%3d : if %s >= %s goto %s\n",line,this->arg1,this->arg2,this->res);
						break;
			/**/case goto_EQ : printf("%3d : if %s == %s goto %s\n",line,this->arg1,this->arg2,this->res);
						break;
			/**/case goto_NEQ : printf("%3d : if %s != %s goto %s\n",line,this->arg1,this->arg2,this->res);
						break;
			/**/case call : printf("%3d : %s = call %s, %s\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case call_void : printf("%3d : call %s, %s\n",line,this->arg1,this->arg2);
						break;
			/**/case EQ_BRACKET : printf("%3d : %s = %s[%s]\n",line,this->res,this->arg1,this->arg2);
						break;
			/**/case BRACKET_EQ : printf("%3d : %s[%s] = %s\n",line,this->arg1,this->arg2,this->res);
						break;
		}
	}
	else{
		switch(this->op){
			/**/case U_PLUS : printf("%3d : %s = %s\n",line,this->res,this->arg1);
						break;
			/**/case U_MINUS : printf("%3d : %s = - %s\n",line,this->res,this->arg1);
						break;
			/**/case BW_U_NOT : printf("%3d : %s = ~%s\n",line,this->res,this->arg1);
						break;
			/**/case U_NEGATION : printf("%3d : %s = !%s\n",line,this->res,this->arg1);
						break;
			/**/case U_ADDR : printf("%3d : %s = & %s\n",line,this->res,this->arg1);
						break;
			/**/case U_STAR : printf("%3d : %s = * %s\n",line,this->res,this->arg1);
						break;
			/**/case ASSIGN : printf("%3d : %s = %s\n",line,this->res,this->arg1);
						break;
			/**/case GOTO : printf("%3d : goto %s\n",line,this->res);
						break;
			/**/case IF_GOTO : printf("%3d : if %s goto %s\n",line,this->arg1,this->res);
						break;
			/**/case IF_FALSE_GOTO : printf("%3d : ifFalse %s goto %s\n",line,this->arg1,this->res);
						break;
			/**/case PARAM : printf("%3d : param %s\n",line,this->arg1);
						break;
			/**/case RETURN_EXP : printf("%3d : return %s\n",line,this->arg1);
						break;
			/**/case RETURN : printf("%3d : return\n",line);
						break;
			/**/case Function : printf("%3d : %s : \n",line,arg1);
						break;
			/**/case LEFT_STAR : printf("%3d : * %s = %s\n",line,this->res,this->arg1);
						break;
		}
	}
}

/* Implementation of class quadArray */

quadArray::quadArray(unsigned int capacity = MAX_SIZE){
	quad_Table = new quadArrayRow[capacity];
	next_instr = 0;
}
void quadArray::emit(quadArrayRow &x){
	quad_Table[next_instr++] = x;
}

void quadArray::print_quadArray(){
	int i;
	for(i = 0;i < next_instr;i++){
		quad_Table[i].print_quadArrayRow(i);
	}
}

void quadArray::fill_dangling_goto(int index, int data){
	char *temp = new char[10];
	sprintf(temp,"%d",data);
	((this->quad_Table)[index]).res = temp;
}
/* Global Functions */
symbolTable *create_Symbol_Table(){										// Creates a symbol table and returns a pointer to it
	symbolTable *st = new symbolTable(MAX_SIZE);
	return st;
}

/* Prints the expression tree */
void print_Tree(tree_Node_Type *temp){
	while(temp){
		switch(temp->middle){
			case ARRAY : cout<<"array ";
			break;
			case VOID : cout<<"void ";
			break;
			case INT : cout<<"int ";
			break;
			case DOUBLE : cout<<"double ";
			break;
			case CHAR : cout<<"char ";
			break;
			case PTR : cout<<"ptr ";
			break;
			case FUNCTION : cout<<"function ";
			break;
			default : cout<<"No Type ";
		}
		if(temp->left)
			cout<<*(temp->left)<<" ";
		temp = temp->right;
	}
}
void print_Initial_Value(void *temp, tree_Node_Type *t){
	if(!temp)
		cout<<"... ";
	else{
		switch(t->middle){
			case INT : cout<<(*((int *)temp))<<" ";
						break;
			case DOUBLE : cout<<(*((double *)temp))<<" ";
						break;
			case CHAR : cout<<(*((char *)temp))<<" ";
						break;
		}
	}
}
tree_Node_Type *new_node(typeEnum t, int val){
	tree_Node_Type *temp = new tree_Node_Type;
	temp->middle = t;
	//printf("%d\n",temp->middle);
	if(t == ARRAY)
		temp->left = new int(val);
	else
		temp->left = 0;
	//printf("Cool\n");
	temp->right = 0;
	//printf("Hot\n");
	return temp;
}
tree_Node_Type *merge_node(tree_Node_Type *sub, tree_Node_Type *one_node){
	if(!sub) return one_node;
	tree_Node_Type *temp = sub;
	while(temp->right)
		temp = temp->right;
	temp->right = one_node;
	return sub;
}

list_node_Type *makelist(int id){
	list_node_Type *temp = new list_node_Type;
	temp->dangling_index = id;
	temp->next = 0;
	return temp;
}

list_node_Type *merge(list_node_Type *l1, list_node_Type *l2){
	if(!l1) return l2;
	if(!l2) return l1;
	list_node_Type *temp = l1;
	while(temp->next)
		temp = temp->next;
	temp->next = l2;
	return l1;
}

void backpatch(list_node_Type *l, int data){
	list_node_Type *temp = l;
	while(temp){
		quad_array->fill_dangling_goto(temp->dangling_index,data);
		temp = temp->next;
	}
}

int typecheck(tree_Node_Type *t1, tree_Node_Type *t2){
	if(!t1 && !t2) return 1;
	if(!t1) return 0;
	if(!t2) return 0;
	if((t1->middle == PTR && t2->middle == ARRAY) || (t1->middle == ARRAY && t2->middle == PTR) || t1->middle == t2->middle)
		return typecheck(t1->right,t2->right);
	return 0;
}

void conv2Bool(exp_attr_struct *E){
	if(((E->type)->middle) != BOOL){
		E->FL = makelist(next_instr);
		char *arg1 = strdup((E->loc)->name);
		/*char *arg2 = new char[10];
		sprintf(arg2,"0");*/
		quadArrayRow x(arg1,0,0,IF_FALSE_GOTO,E->loc,0,0);
		quad_array->emit(x);
		E->TL = makelist(next_instr);
		quadArrayRow y(0,0,0,GOTO,0,0,0);
		quad_array->emit(y);
	}
}

tree_Node_Type *duplicate_tree(tree_Node_Type *temp){
	if(!temp) return 0;
	tree_Node_Type *tu;
	if(temp->middle == ARRAY)
		tu = new_node(ARRAY,*(temp->left));
	else
		tu = new_node(temp->middle,-1);
	tu->right = duplicate_tree(temp->right);
	return tu;
}
int compute_width(tree_Node_Type *temp){
	if(!temp) return 0;
	int width = 1;
	while(temp){
		switch(temp->middle){
			case ARRAY : width *= (*temp->left);
						break;
			case INT : width *= 4;
						break;
			case DOUBLE : width *= 8;
						break;
			case CHAR : width *= 1;
						break;
			case PTR : width *= 4;
						break;
		}
		if(temp->middle == PTR)
			break;
		temp = temp->right;
	}
	return width;
}

list_param *make_param_list(symbolTableRow *p){
	list_param *temp = new list_param;
	temp->parameter = p;
	temp->next = 0;
	return temp;
}

list_param *merge_param_list(list_param *l1, list_param *l2){
	if(!l1) return l2;
	if(!l2) return l1;
	list_param *temp = l1;
	while(temp->next)
		temp = temp->next;
	temp->next = l2;
	return l1;
}

/* Global variables */
tree_Node_Type *t = 0;
int w;
symbolTable *global = 0;
symbolTable *current = 0;
symbolTable *temp_use = 0;
int flag1 = 0;
int flag2 = 0;
int c = 0;
char *func_name;								// May not be required
int line_count = 0;
int temp_count = 0;
int next_instr = 0;
quadArray *quad_array = 0;
int flag_array = 0;
int left_or_right = 1;					// 1 for left
int is_left = 0;						// Presently no dereferencing on the left side of expression
int star_count = 0;						// count of total no of dereferences
char **s;
char **toc;
int count_toc = 0;