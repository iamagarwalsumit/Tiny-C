#include <stdio.h>
#include <stdlib.h>

#define s(n) scanf("%lld",&n)
#define p(n) printf("%lld\n",n)
#define f(a,b,c) for(int a=b;a<c;a++)
#define ll long long int
#define z(a,n) for(int i=0;i<n;i++)a[i]=0;

using namespace std; 

typedef struct graph {
int nodes;
int edges[50];
} Graph;


union student {
char name[80];
float marks;
int age;
}


extern i=5;

void printarray (int n,int* array)
{
   int i;
   for (i=1;i<=10;++i){
    	if (i==3)
       	   continue;
    	else if (i==7)
       	   break;
    	printf("%d ",array[i]);
	}
    return;
}

enum enum_var{
   var1;
   var2;
   var3;
};

int main(){

	auto int var1;
	do{
	switch(option){
    		case 1:
    		//some statements to execute when 1
    		break;
    		case 5:
    		//some statements to execute when 5
    		break;
    		default:
    		//some statements to execute when default;
	}
	}while (option<6)
	//testing all the keywords here
	const char a='c';
	float variable0= 54.897
	int * variable1= &variable0;
	double double0 = 45678.55;
	short int var1;
	long int var2;
	signed int var3;
	unsigned int var4;
	register int var5;
	static int var;
	for(i=1;i<5;++i){
		if (i==10)
    			goto error;
	}
	printf("i is not 10");
	error:
   		printf("Error, count can't be 10");
	printf("%u bytes.",sizeof(char));			
	
	inline restrict volatile	 // checking for the remaining keywords
	_Bool	_Complex _Imaginary
	
	char *p = "String";
	p[2]='k';
	float value = 12+132*6.7/46-87;
	int m= 10%4;
	m*=2;
	i--;
	//testing every possible keyword,punctuator and identifier.
	
	student . marks = 5;
	a[12] == g[34.23];

	if(j==230||test>=23&&sd<23){*pt->ghj=12.22;}
	int a=5,c=8;
	int b= a&c;
	int d= b|a;
	d= b^a;
	d= 5 >> 2;

	int *st = constructST(a, n);

    	scanf("%d",&m);
    	while(m-->0){
    		int x,y;
    		x--;
		scanf("%d %d",&x,&y);
		printf("%d\n",getSum(st,n,x-1,y-1));
    	}
	...

	/*#define s(n) scanf("%lld",&n)
	#define p(n) printf("%lld\n",n)
	#define f(a,b,c) for(int a=b;a<c;a++)
	#define ll long long int
	#define z(a,n) for(int i=0;i<n;i++)a[i]=0;
	using namespace std;*/

	//comments are recognised
	
	return 0;
}

