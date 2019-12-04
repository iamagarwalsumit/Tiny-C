/* Merge Sort code */

/* checks for passing int* as function parameter */

/* also uses recursive calls.. more complex code ! */

int main();
int readi(int *x);
int printi(int p);
int prints(char *s);
int merge(int *list, int low, int mid, int high);
int mergeSort(int *list,int low, int high);

int merge(int *list,int low,int mid,int high)
{
    int i, mi, k, lo;
    int temp[50];
    
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high))
    {
        if (list[lo] <= list[mi])
        {
            temp[i] = list[lo];
            lo++;
        }
        else
        {
            temp[i] = list[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid)
    {
        for (k = mi; k <= high; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    else
    {
        for (k = lo; k <= mid; k++)
        {
            temp[i] = list[k];
            i++;
        }
    }
    
    for (k = low; k <= high; k++)
    {
        list[k] = temp[k];
    }
    return 0;
}


int mergeSort(int *list,int low,int high)
{
    int mid,sum,temp_mid;
    
    if(low < high)
    {
        sum = low + high ;
        mid = sum/2;
        temp_mid = mid+1;
        
        mergeSort(list, low, mid);
        mergeSort(list, temp_mid, high);
        merge(list, low, mid, high);
    }
    return 0;
}



int main()
{
    int list[50];
    int i, size;
    int err;
    prints ("Enter the size of the array : ");
    size=readi(&err);
    prints ("Enter the elements by pressing enter one by one : \n");
    for(i = 0; i < size; i++)
    {
        list[i]=readi(&err);
    }
    int n;
    n= size-1;
    mergeSort(list, 0, n);
    prints ("The elements of the array after sorting : \n");
    for(i = 0;i < size; i++)
    {
        printi(list[i]);
	prints (" ");
    }
    
    prints ("\n");
    return 0;
}
