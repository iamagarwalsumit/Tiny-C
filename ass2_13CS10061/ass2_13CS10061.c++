# include "my_stdio.h"
# define BUFF 20
# define ERR 1
# define OK 0
# include <iostream>
# include <stdio.h>

using namespace std;

int prints(char * s)
{
	char buff[BUFF];
	int i=0,bytes=0;
	for (i=0;s[i]!='\0';i++)
	{
		buff[i]= s[i];
		bytes++;
	}
	 __asm__ __volatile__ (
          "movl $1, %%eax \n\t"
          "movq $1, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(bytes)
    ) ; // $1: write, $1: on stdin

	return bytes;
}



int printi(int n){
    char buff[BUFF], zero='0';
    int i=0, j, k, bytes;

    if(n == 0) buff[i++]=zero;
    else{
       if(n < 0) {
          buff[i++]='-';
          n = -n;
       }
       while(n){
          int dig = n%10;
          buff[i++] = (char)(zero+dig);
          n /= 10;
       }
       if(buff[0] == '-') j = 1;
       else j = 0;
       k=i-1;
       while(j<k){
          char temp=buff[j];
          buff[j++] = buff[k];
          buff[k--] = temp;
       }
    } 
    bytes =i;

     __asm__ __volatile__ (
          "movl $1, %%eax \n\t"
          "movq $1, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(bytes)
    ) ;  // $1: write, $1: on stdin
    return bytes;
}




int readi(int *eP)
{
	char buff[BUFF];
	//buff[0]={'\0'};
  	int i=0,k,bytes=20,n=0;
  	__asm__ __volatile__ (
          "movl $0, %%eax \n\t"
          "movq $0, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(bytes)
    ) ;  // $1: read, $0: on stdin
  if(buff[i]=='-')
  {	
  	k=-1;
    i++;
  }
  else if (buff[i]=='+')
  {	
  	i++;
    k=1;
  }
  else 
  	k=1;
  while (buff[i]-'0'==0)
  {
  	i++;
  }
  while(buff[i]!='\n'){
    if(buff[i]<48||buff[i]>57){(*eP)=ERR;
      return 0;
    }
    n*=10;
    n+=buff[i]-'0';
    i++;
  }
  n*=k;
  (*eP)=OK;
  return n;
}





int readf(float *f)
{
	char buff[BUFF];
  	int i=0,k,bytes=20;
  	long long int n=0; 
  	__asm__ __volatile__ (
          "movl $0, %%eax \n\t"
          "movq $0, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(bytes)
    ) ;  // $0: read, $0: on stdin
 
  	if(buff[i]=='-')
  	{	
  		k=-1;
    	i++;
  	}
  	else if (buff[i]=='+')
  	{	
  		i++;
    	k=1;
  	}
  	else 
  		k=1;
  	while (buff[i]-'0'==0)
  		i++;

  	int flag=0;
  	int saved_i= i;
  	while (buff[i]!='\n')
  		i++;

  	int power=0;
  	for (int k=saved_i;k<i;k++){

  		if (buff[k]==46 && flag==0)
  		{
  			flag=1;
  			continue;
  		}
   
  		if(buff[k]<48||buff[k]>57) {

  			(*f)=0;
    		return ERR;
    	} 
  		n*=10;
  		n+=buff[k]-'0';
  		if (flag==1)
    		power+=1;
  	}

  	double pow_10 = 1;
  	
  	for (int i=1;i<=power;i++)
  		pow_10*=10.0;
  		//cout<<pow_10<<endl;

  	(*f)= n/pow_10;
  	 
  	if(k==-1)(*f)*=-1.0;
  	return OK;
}




int printf(float f)
{
	cout<<f<<endl;
	char buff[BUFF],zero='0';
	long long int i=0,j,k,bytes;

	if (f<0){
		buff[i++]='-';
		f=-f;
	}
	long long int temp_int= (long long int) f;
	long long int n;
	if (temp_int == f)
	{
		n= f*10;
		n*=100000;
	}
	else
	{
		n = f*1000000;
	}

	while (n)
	{
	    int dig = n%10;
        buff[i++] = (char)(zero+dig);
        n /= 10;
	}
	

	if (temp_int==0)
	{
		buff[i++]='0';
	}
	if(buff[0] == '-') j = 1;
        else j = 0;
        k=i-1;
        while(j<k){
           char temp=buff[j];
           buff[j++] = buff[k];
           buff[k--] = temp;
        }
        int no_digit=0;
	if (temp_int==0) no_digit++; // to handle 0.25641 case to print '0.'
	else
	{
		while (temp_int)
    	{
			no_digit++;
			temp_int/=10;	
    	}
	}
	
    k=0,j=0;
    if (buff[0] == '-') j++;
	for (;j<i;j++)
	{
		if (k==no_digit)
		{
			break;
		} 
		k++;
	}
	buff[i++]='.';
    for (k=i-1;k>j;k--)
    {
    	char temp=buff[k];
    	buff[k]=buff[k-1];
    	buff[k-1]=temp;
    }

    for ( k=0;k<i;k++)
		cout<<buff[k]<<" ";
   	cout <<endl;

	bytes=i;

	 __asm__ __volatile__ (
          "movl $1, %%eax \n\t"
          "movq $1, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(bytes)
    ) ;  // $1: write, $1: on stdin
    return bytes;

}
