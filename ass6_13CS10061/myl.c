# include "myl.h"
# define BUFF 100 
# include <stdio.h>
// Takes an array of characters and prints it
int prints(char *s){  //s is null terminated
    char buff[BUFF];
    int i=0,bytes=0;
    for (i=0;s[i]!='\0';i++)
    {
        buff[i]= s[i];
        bytes++;
    }
    __asm__ __volatile__(
          "movl $1, %%eax \n\t"
          "movq $1, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(bytes)
    ); // $1: write, $1: on stdin
    return bytes;
}

int printc(char c){
    char buff[BUFF];
    int i=0,bytes=0;
    buff[i++]=c;
    buff[i++]='\0';
    bytes = i;
    __asm__ __volatile__(
          "movl $1, %%eax \n\t"
          "movq $1, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(bytes)
    ); // $1: write, $1: on stdin
    return bytes;
}
// Takes an integer and converts it to a stream of characters and prints it
// Returns the number of characters
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
    buff[i++]='\0';
    bytes =i;
    __asm__ __volatile__(
          "movl $1, %%eax \n\t"
          "movq $1, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(i)
    ); // $1: write, $1: on stdin
    return i;
}

char readc(int *val){
    char buff[BUFF];
    int i=0,bytes=20;
    do{
        __asm__ __volatile__(
            "movl $0, %%eax \n\t"
            "movq $0, %%rdi \n\t"
            "syscall \n\t"
            :
            :"S"(buff+i), "d"(1)
        );
    }while(buff[i++]!='\n');
    buff[i++]='\0';
   // printf("This is %s\n",buff);
    if (buff[0])
        *val= buff[0];
    else
        *val= -1;
    return buff[0];
}
// Reads an integer and returns it
// (*eP) = 1 if the input character array contains non numeral characters otherwise (*eP) = 0
int readi(int *eP){
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

