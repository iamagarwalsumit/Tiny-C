/* 
 * main_print_int.c 
 * A system call to print an integer 
 */

#include "my_stdio.h"
#define MAX 100
# define ERR 1
# define OK 0

int main()
{ 
    int n;
    float f;
    prints("Enter an integer: ");
    int ep;     
    n=readi(&ep);
    if (ep== ERR )
    	prints("Error in input");
    else
    	printi(n);   
    prints("\n"); 
    prints("Enter a float: ");   
    ep=readf(&f);
    if (ep== ERR )
    	prints("Error in input");
    else
    	printf(f);   
    prints("\n");
    return 0;
}