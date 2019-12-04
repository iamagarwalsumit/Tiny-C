/** Simple code to test all possible arithmetic operations **/
/* A basic calculator */
int main();
int prints(char *s);
int printi(int n);
int readi(int *eP);
/* checking for global variables as well */
int a; 
int b;

int main()
{
	prints ("Enter the first operand : ");
	int err;
	int choice,res;
	a = readi(&err);
	prints ("Enter the second operand : ");
	b = readi(&err);
	prints ("1 for addition\n");
	prints ("2 for subtraction\n"); 
	prints ("3 for multiplication\n");
	prints ("4 for division\n");
	prints ("5 for modulus\n");
	prints ("61 for unary plus to first variable\n");
	prints ("62 for unary plus to first variable\n");
	prints ("71 for unary minus to first variable\n");
	prints ("72 for unary minus to first variable\n");
	prints ("-1 for exit\n");

	do{
		prints("Enter your choice\n");
		choice = readi(&err);
		if(choice == 1){
			res = a + b;
			prints("Result : ");
			printi(res);
			prints("\n");
		}
		else if(choice == 2){
			res = a - b;
			prints("Result : ");
			printi(res);
			prints("\n");
		}
		else if(choice == 3){
			res = a*b;
			prints("Result : ");
			printi(res);
			prints("\n");
		}
		else if(choice == 4){
			res = a/b;
			prints("Result : ");
			printi(res);
			prints("\n");
		}
		else if(choice == 5){
			res = a%b;
			prints("Result : ");
			printi(res);
			prints("\n");
		}
		else if(choice == 61){
			res = +a;
			prints("Result : ");
			printi(res);
			prints("\n");
		}
		else if(choice == 62){
			res = +b;
			prints("Result : ");
			printi(res);
			prints("\n");
		}
		else if(choice == 71){
			res = -a;
			prints("Result : ");
			printi(res);
			prints("\n");
		}
		else if(choice == 72){
			res = -b;
			prints("Result : ");
			printi(res);
			prints("\n");
		}
		else{
			prints("Try another option !\n");
		}
	}while(choice!=-1);
	
	return 0;
}

/*
void bubble_srt(int *array, int n);
void bubble_srt(int *array, int n){
	int c = 0;
	int d;
	int swap;
	for (c = 0 ; c < ( n - 1 ); c++)
  	{
    	for (d = 0 ; d < n - c - 1; ++d)
    	{
      		if (array[d] > array[d+1]) 
      		{
        		swap       = array[d];
        		array[d]   = array[d+1];
        		array[d+1] = swap;
      		}
    	}
  	}
	return;
}
int main(){
	int a[1000];
	int b,n;
	int i,u;
	u = prints("Enter the size of the array\n");
	n = readi(&b);
	u = prints("Enter the elements of the array one by one\n");
	for(i=0;i<n;i++){
		u = readi(&b);
		a[i] = u;
	}
	bubble_srt(a,n);
	u = prints("Sorted array is : \n");
	for(i=0;i<n;i++){
		u = printi(a[i]);
		prints(" ");
	}
	prints("\n");
	return 0;
}
*/