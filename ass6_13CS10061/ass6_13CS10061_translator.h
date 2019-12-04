#ifndef ASS6_13CS10061_TRANSLATOR_INCLUDED
#define ASS6_13CS30061_TRANSLATOR_INCLUDED



# define SIZE_OF_INT 4
# define SIZE_OF_DOUBLE 8
# define SIZE_OF_CHAR 4 
# define SIZE_OF_PTR 8
# define MAX_SIZE 10000


/* Various structures */
typedef enum { VOID, INT, CHAR, DOUBLE, BOOL, ARRAY, PTR, FUNCTION }typeEnum;

typedef enum {DEFAULT, PLUS, MINUS, INTO, DIV, PERCENT,
 SL, SR, LT, LTE, GT, GTE, EQ, NEQ, BW_AND, BW_XOR,
  BW_INOR, LOG_AND, LOG_OR, goto_LT, goto_LTE,
   goto_GT, goto_GTE, goto_EQ, goto_NEQ, call, call_void,
    EQ_BRACKET, BRACKET_EQ, U_PLUS, U_MINUS, BW_U_NOT,
     U_NEGATION, U_ADDR, U_STAR, LEFT_STAR, ASSIGN, GOTO, IF_GOTO, 
     IF_FALSE_GOTO, PARAM, RETURN_EXP, RETURN, Function}quadEnum;						// To be updated with more entries

typedef struct tree_Node_Type{													// One node of type expression tree
	typeEnum middle;
	int *left;
	struct tree_Node_Type *right;
}tree_Node_Type;

typedef struct list_node_Type{														// Structure of a node of the list
	int dangling_index;
	struct list_node_Type *next; 
}list_node_Type;

class symbolTableRow; 
class symbolTable;
class symbolTableRow{													// One row of the symbol table
	public:
	char *name;
	tree_Node_Type *Type;
	void *initial_value;
	int size;
	int offset; 
	symbolTable *nestedTable;
	symbolTableRow(char * = 0 , tree_Node_Type * = 0, void * = 0, int = -1, int = -1, symbolTable * = 0); 
	~symbolTableRow();
	void operator=(symbolTableRow &);
	void print_row();
};

typedef struct list_param{
	symbolTableRow *parameter;
	struct list_param *next;
}list_param;

typedef struct quadArrayRow{
	char *arg1;
	char *arg2;
	char *res;
	quadEnum op;
	symbolTableRow *arg1_loc;
	symbolTableRow *arg2_loc;
	symbolTableRow *res_loc;
	quadArrayRow(char * = 0, char * = 0, char * = 0, quadEnum = DEFAULT, symbolTableRow * = 0, symbolTableRow * = 0, symbolTableRow * = 0);
	~quadArrayRow();
	void operator=(struct quadArrayRow &);
	void print_quadArrayRow(int);
}quadArrayRow;

/* Structures for various attributes */
typedef union initializer_attr_struct{										// Union for various constants
	int int_data;
	double double_data;
	char char_data;
}initializer_attr_struct;

typedef struct exp_attr_struct{                                                 // Structure for the attribute of expression grammar{
	symbolTableRow *loc;														// E.loc or A.loc as need be
	list_node_Type *TL;															// B.TL
	list_node_Type *FL;
	list_node_Type *NL;															// B.FL	
	tree_Node_Type *type;														// A.type
	symbolTableRow *array;
	symbolTableRow *loc1;														// A.array
	initializer_attr_struct val;																	// E.val for storing the value of the expression
}exp_attr_struct;

typedef struct var_decl_attr_struct{																	// Structure for attributes of variable declaration grammar
	tree_Node_Type *type;
	int width;
	char *var;
}var_decl_attr_struct;

typedef struct id_attr_struct{																	// Attribute of identifier
	symbolTableRow *loc;
	char *var;
}id_attr_struct;

/* Symbol Table Class */
class symbolTable{
public:
	symbolTableRow *table;
	int curr_length;
	symbolTable(unsigned int);
	~symbolTable();
	symbolTableRow *lookup(char *);
	void insert(symbolTableRow &);
	symbolTableRow *gentemp(typeEnum);
	symbolTableRow *gentemp_cmplx(tree_Node_Type *);
	void print_table();
};
/* Quad array class */
class quadArray{
public:
	quadArrayRow *quad_Table;
	quadArray(unsigned int);
	~quadArray();
	void emit(quadArrayRow &);
	void print_quadArray();
	void fill_dangling_goto(int,int);
};

/* Global Functions */

symbolTable *create_Symbol_Table();
void print_Tree(tree_Node_Type *);
void print_Initial_Value(void *,tree_Node_Type *);
tree_Node_Type *new_node(typeEnum ,int);
tree_Node_Type *merge_node(tree_Node_Type *, tree_Node_Type *);
list_node_Type *makelist(int);
list_node_Type *merge(list_node_Type *, list_node_Type *);
void backpatch(list_node_Type *, int);
int typecheck(tree_Node_Type *,tree_Node_Type *);
void conv2Bool(exp_attr_struct *);
int compute_width(tree_Node_Type *);
list_param *make_param_list(symbolTableRow *);
tree_Node_Type *duplicate_tree(tree_Node_Type *);
list_param *merge_param_list(list_param *, list_param *);
void update_offsets();

/* Global Variables */

extern tree_Node_Type *t;
extern int w;
extern symbolTable *global;
extern symbolTable *current;
extern symbolTable *temp_use;
extern int flag1;
extern int flag2;
extern int c;
extern char *func_name;								// May not be required
extern int line_count;
extern int temp_count;								// Count of temporaries
extern int next_instr;
extern quadArray *quad_array;			// Next index of quad array
extern int flag_array;
/* Global variables for handling pointer arithmetic */
extern int star_count;
extern int left_or_right;
extern int is_left;
extern char **s;
extern char **toc;
extern int count_toc;
#endif