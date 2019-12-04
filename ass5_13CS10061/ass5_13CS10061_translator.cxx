# include "ass5_13CS10061_translator.h"
# include "y.tab.h"
# include <iostream>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <vector>

/* Global Functions */
symbolTable *createSymbolTable(){										// Creates a symbol table and returns a pointer to it
	symbolTable *st = new symbolTable();
	return st;
}

/********************************************** Symbol Table Row ***********************************************/
symbolTableRow::symbolTableRow(char * NAME , Type* TYPE , void * INIT_VALUE, int SIZE, int OFFSET, symbolTable* NESTED_TABLE) 
: name(NAME), type(TYPE), init_value(INIT_VALUE), size (SIZE) , offset (OFFSET), nestedTable(NESTED_TABLE)
{

}

symbolTableRow::~symbolTableRow()
{

}

void symbolTableRow::operator= (const symbolTableRow &row)
{
	this->name= row.name;
	this->type = row.type;
	this->init_value = row.init_value;
	this->size= row.size;
	this->offset = row.offset;
	this->nestedTable = row.nestedTable;
}

/**************************************************** Symbol Table **************************************************/

symbolTable::symbolTable()
{
	vector<symbolTableRow> v;
	this->table= v;
	current=-1; // -1 indicates no elements in the symbol table (actually current stores vector.size()-1)
}

symbolTable::~symbolTable()
{

}

symbolTableRow* symbolTable::lookup (char* find)
{
	for (int i=0;i<=current;i++){
		if (strcmp(table[i].name,find)==0)
			return &(table[i]);
	}
	return 0;
}

void symbolTable::insert(symbolTableRow &row){												
	if(current == -1)    // No entry in the symbol table yet !
		row.offset = 0;
	else
		row.offset = table[current].size + table[current].offset;  // calculates the offset for each new in the symbol table
	current++;  
	table.push_back(row);
}

symbolTableRow *symbolTable::gentemp(typeCode temp){
	Type *T = newType(temp,-1);
	char *temp_name = new char[10];
	sprintf(temp_name,"t%d",tempCount++);
	int sizeOfTemp = 0;
	if (temp==1)
		sizeOfTemp = SIZE_OF_INT;
	
	else if (temp == 2)
		sizeOfTemp = SIZE_OF_CHAR;

	else if (temp == 3)
		sizeOfTemp = SIZE_OF_DOUBLE;

	else if (temp== 6 || temp== 7 || temp == 8)
		sizeOfTemp = SIZE_OF_PTR;

	symbolTableRow row(temp_name,T,0,sizeOfTemp,-1,0);
	this->insert(row);
	return &(table[current]);
}


/**************************************************** Quad Array Row **************************************************/


quadArrayRow::quadArrayRow(char *ARG1, char *ARG2, char *RES, opCode OP, symbolTableRow *LOC_ARG1, symbolTableRow *LOC_ARG2, symbolTableRow *LOC_RES) 
: arg1(ARG1), arg2(ARG2), res(RES), op(OP), loc_arg1(LOC_ARG1), loc_arg2(LOC_ARG2), loc_res(LOC_RES) 
{

}

quadArrayRow::~quadArrayRow()
{

}

void quadArrayRow::operator= (const quadArrayRow &row)
{
	this->arg1= row.arg1;
	this->arg2= row.arg2;
	this->res= row.res;
	this->op =row.op;
	this->loc_arg1 = row.loc_arg1;
	this->loc_arg2 = row.loc_arg2;
	this->loc_res = row.loc_res;
 } 


/************************************************** Quad Array **********************************************************/ 

quadArray::quadArray(unsigned int length = MAX_SIZE)
{
	this->quad_Array = new quadArrayRow[length];
	nextInstr = 0;
}

void quadArray:: emit (char *ARG1, char *ARG2, char *RES, opCode OP, symbolTableRow *LOC_ARG1, symbolTableRow *LOC_ARG2, symbolTableRow *LOC_RES)
{
	quadArrayRow x(ARG1,ARG2,RES,OP,LOC_ARG1,LOC_ARG2,LOC_RES);
	quad_Array[nextInstr]= x;
	nextInstr++;
}


/*************************************************** Global Functions *****************************************************/

Type* newType(typeCode t,int size_of_arr)
{
	Type *temp = new Type;
	temp->first = t;
	if(t == ArrayType)
		temp->second= size_of_arr;
	else
		temp->second = -1;
	temp->next= NULL;
	return temp;
}

Type* mergeType(Type* parent, Type* child)
{
	if (parent == NULL) 
		return child;
	Type* temp = parent;
	while (temp->next)
		temp=temp->next;
	temp->next = child;
	return temp;
}

listNode *makeList(int id)
{
	listNode* list = new listNode;
	list->dangling_exit = id;
	list->next = NULL;
	return list;
}

listNode * mergeList (listNode* list_1, listNode* list_2)
{
	if (list_1==NULL)
		return list_2;
	if (list_2==NULL)
		return list_1;
	listNode* list = list_1;
	while (list->next)
	{
		list=list->next;
	}
	list->next= list_2;
	return list;
}


paramList *makeParamList(symbolTableRow* p)
{
	paramList *list = new paramList;
	list->param = p;
	list->next = 0;
	return list;
}


paramList * mergeParamList(paramList* list_1,paramList* list_2)
{
	if (list_1==NULL)
		return list_2;
	if (list_2==NULL)
		return list_1;
	paramList* list = list_1;
	while (list->next)
	{
		list=list->next;
	}
	list->next= list_2;
	return list;
}


/* Global variables */


Type* t = 0;
int w;
symbolTable *global = NULL;
symbolTable *current = NULL;
symbolTable *temp = NULL;
bool declDone = false;                                // boolean used to indicate whether a declaration of a function is done or not !
bool mulDecl = false;                                 // boolean used to handle multiple declarations
int c;								
int lineCount = 0;
int tempCount = 0;
int nextInstr = 0;
quadArray *quad_array = NULL;
int flagArray = 0;

/* And the main function finally */
int main(){
  yyparse();
  /*global = create_Symbol_Table();
  current = global;
  quad_array = new quadArray(10000);
  int x = yyparse();
  printf("Global Symbol Table : \n");
  global->print_table();
  int i,j;
  for(i=0;i<=global->curr_length;i++){
  	if((global->table[i]).nestedTable){
  		printf("%s Symbol table :  \n",(global->table[i]).name);
  		((global->table[i]).nestedTable)->print_table();
  	}
  }
  quad_array->print_quadArray();*/
  return 0;
}