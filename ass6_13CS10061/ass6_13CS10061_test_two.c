/*** Tests pointer arithmetic including passing pointers to functions ***/
/*** Also test global variables ***/
/* Swapping by call by reference */
void swap(int *a, int *b);
void attempt_to_swap(int a, int b);
int main();
int readi(int *ep);
int printi(int n);
int prints(char *str);
int error;
void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void attempt_to_swap(int a, int b){
	int temp;
	temp = a;
	a = b;
	b = a;
	return;
}
int main(){
	prints("\nEnter the first number : ");
	int a,b,temp;
	a = readi(&error);
	if(error == 0){
		prints("\nEnter the second number : ");
		b = readi(&error);
		if(error == 0){
			
			prints("\nInline swapping");
			temp = a;
			a = b;
			b = temp;
			prints("\na = ");
			printi(a);
			prints("\nb = ");
			printi(b);
			prints("\n");
			prints("\nSwapping through call by reference (pointers)");
			swap(&a,&b);
			prints("\na = ");
			printi(a);
			prints("\nb = ");
			printi(b);
			prints("\n");
			prints("\nSwapping through call by value");
			attempt_to_swap(a,b);
			prints("\na = ");
			printi(a);
			prints("\nb = ");
			printi(b);
			prints("\nNumbers are swapped only through call by reference !\n"); 
		}
		else{
			prints("\nYou entered non numeral characters");
			prints("\nThe program is exiting");
		}
	}
	else{
		prints("\nYou entered non numeral characters");
		prints("\nThe program is exiting");
	}
	return 0;
}