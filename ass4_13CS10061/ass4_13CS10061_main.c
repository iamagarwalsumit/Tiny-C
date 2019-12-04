#include <stdio.h>
#include "y.tab.h"
int main(){
	yyparse();
	 // printf("Returned value is %d\n",val);
	return 0;
}



