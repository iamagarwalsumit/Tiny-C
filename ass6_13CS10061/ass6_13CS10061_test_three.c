/* Tests for char , char[] and passing char* through functions */
/* Palindrome testing of a string */

int main();
int palindrome(char *str,int *val,int len);
int prints(char *s);
int printi(int n);
int readi(int *eP);
int printc(char c);
char readc(int *val);
int palindrome (char *str,int *val,int len)
{
	int l,h,flag;
   	l=0;
   	h=len-1;
   	flag=1;
   	while (h > l)
   	{
      if (val[l] != val[h])
      {
            flag= 0;
	    break;
      }
      l++;
      h--;
   	}
   	return flag;
}


int main()
{
	char str[1000];
	int val_str[1000];
	int err;
	int size;
	prints("Enter the size: ");
	size=readi(&err);
	prints("Enter the string by entering the characters separated by \\n : ");
	int i;
	for (i=0;i<size;i++){
		str[i]=readc(&err);
		val_str[i]=err;
	}

	int res;
	res = palindrome(str,val_str,size);
	//printi(res);
	
   	prints ("The string ");
	for (i=0;i<size;i++)
		printc(str[i]);
	if (res==1)
		prints (" is palindrome.\n");
	else
		prints (" is not palindrome.\n");
	return 0;
}
