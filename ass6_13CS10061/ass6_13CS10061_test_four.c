/* Linear Search in Array */
/* Checking passing of int * as function and handling of arrays */
int readi(int *ep);
int printi(int n);
int prints(char *str);
int main();
int error;
int main(){
    int a[100];
    int n,i,s,index;
    index=-1;
    prints("Enter the size of Array :");
    n=readi(&error);
    prints("Enter elements of the array one per line :\n");
    for(i=0;i<n;i++)
    {
        a[i]=readi(&error);
    }
    prints("Enter the number that you want to search :\n");
    s=readi(&error);
    for(i=0;i<n;i++)
    {
        if(a[i]==s)
        {
            index=i;
            break;
        }
    }
    
    if(index!=-1)
    {
        prints("Found at index ");
        printi(index);
        prints("\n");
    }
    else
    {
        prints("Element Not Found\n");
    }
    return 0;
}
