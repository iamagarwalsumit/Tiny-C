#ifndef ASS5_13CS10061_TRANSLATOR_INCLUDED
#define ASS5_13CS10061_TRANSLATOR_INCLUDED


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <utility>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <fstream>

# define SIZE_OF_INT 4
# define SIZE_OF_DOUBLE 8
# define SIZE_OF_CHAR 1
# define SIZE_OF_PTR 4
# define MAX_SIZE 10000

using namespace std;

class symbolTableRow;
class symbolTable;
class quadArrayRow;
class quadArray;

/* Various structures */
typedef enum 
{ 
	VoidType, 
	IntType, 
	CharType, 
	DoubleType, 
	BoolType, 
	ArrayType, 
	PtrIntType, 
	PtrCharType,
	PtrDoubleType,
	PtrVoidType,
	FunctionType
} typeCode;

typedef enum 
{
	Undefined, Goto

	
} opCode;


/* Structure for Type */

typedef struct Type{
	typeCode first; // Used for the type 
	int second; 
	/* Used to store the size if type is Array and -1 if type is not array, For eg- array(5,array(int,4))) then type will look like : array,5 -> array,4 -> int, -1 */
	struct Type* next;
} Type;



/* Symbol Table Row Class */

class symbolTableRow{													
public:

	char *name;
	Type *type;
	void *init_value;
	unsigned int size;
	int offset; 
	symbolTable *nestedTable;
	symbolTableRow(char * = NULL , Type* = NULL, void * = NULL, int = -1, int = -1, symbolTable * = NULL); 
	//             name             type         init_value     size      offset    nestedTable
	~symbolTableRow();
	void operator=(const symbolTableRow &);
	//void print_row();

};


/* Symbol Table Class */
/* Symbol Table is actually an array of symbolTablerow */

class symbolTable{
public:

	vector<symbolTableRow> table;
	int current;
	symbolTable();
	~symbolTable();
	symbolTableRow *lookup(char *);
	void insert(symbolTableRow &);
	symbolTableRow *gentemp(typeCode);
	//void print_table();

};



/* Quad Array Row Class */
class quadArrayRow{
public:

	char *arg1;
	char *arg2;
	char *res;
	opCode op;
	symbolTableRow *loc_arg1;
	symbolTableRow *loc_arg2;
	symbolTableRow *loc_res;
	quadArrayRow(char * = NULL, char * = NULL, char * = NULL, opCode = Undefined, symbolTableRow * = NULL, symbolTableRow * = NULL, symbolTableRow * = NULL);
	~quadArrayRow();
	void operator=(const quadArrayRow &);
	//void print_quadArrayRow(int);

};


/* Quad Array class */
/* Quad Array is actually an array of quadArrayRow */


class quadArray{
public:

	quadArrayRow *quad_Array;
	quadArray(unsigned int);
	~quadArray();
	void emit(char * = NULL, char * = NULL, char * = NULL, opCode = Undefined, symbolTableRow * = NULL, symbolTableRow * = NULL, symbolTableRow * = NULL);
	//void print_quadArray();
	//void fill_dangling_goto(int,int);

};





/* Structure for node of a list (TL, FL, NL) */

typedef struct listNode{														
	int dangling_exit;
	struct listNode *next; 
}listNode;



/* Structure for list of function parameters */
typedef struct paramList{
	symbolTableRow *param;
	struct paramList *next;
}paramList;


/* Union used for various constants (Union is used so that at a time a variable is assigned to only one of these values) */
typedef union initAttr{ 
	int dataInt;
	double dataDouble;
	char dataChar;
}initAttr;

/* Attributes for expression */ 
typedef struct expAttr{                                                 
	symbolTableRow *loc;                                                                     // A.loc or E.loc as required  													
	listNode *TL;															             	 // E.truelist
	listNode *FL;                                                                            // E.falselist
	listNode *NL;																             // S.nextlist
	Type *type;												                                 // E.type 		                         
	symbolTableRow *array;                                                                   // A.array
	symbolTableRow *loc1;														
	initAttr val;										                                     // E.val							
}expAttr;

/* Attributes for variables declaration */ 
typedef struct varAttr{																	
	Type *type;                                                                              // Type of the variable
	int width;                                                                               // Width of the variable
	char *name;                                                                              // Name of the variable
}varAttr;

/* Attributes for identifiers */
typedef struct idAttr{																	
	symbolTableRow *loc;                                                                     // id.loc                                                                
	char *name;                                                                              // Name of the identifier 
}idAttr;



/* Global Declarations */

extern Type *t;                                      // global variable for Type (to prevent a grammer requiring inherited attributes)
extern int w;                                        // global variable for Width (to prevent a grammer requiring inherited attributes)
extern symbolTable *global;                          // global Symbol Table
extern symbolTable *current;                         // current Symbol Table
extern symbolTable *temp;                            // temp Symbol Table
extern bool declDone;                                // boolean used to indicate whether a declaration of a function is done or not !
extern bool mulDecl;                                 // boolean used to handle multiple declarations
extern int c;
//extern char *func_name;								
extern int lineCount;							     
extern int tempCount;								 // to keep track of temporaries
extern int nextInstr;								 // to keep track of the indexes of the 
extern quadArray *quad_array;					     // Next index of quad array
extern int flagArray;




/* Global Functions */

symbolTable *createSymbolTable();                  
Type* newType(typeCode ,int);
Type* mergeType(Type* ,Type *);
listNode *makeList(int);
listNode *mergeList(listNode*,listNode *);
paramList *makeParamList(symbolTableRow *);
paramList *mergeParamList(paramList *, paramList *);
void backpatch(listNode *, int);
int typecheck(Type *,Type *);
void conv2Bool(expAttr *);
int computeWidth(Type *);


#endif