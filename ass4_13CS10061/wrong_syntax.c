int main()
{
    int array[10]={1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int start = 1; // 0 will give a syntax error
    int end = n-1;              
     
    for (int i = 1; i < n; i++)   {
        int middle = start+(end - start)/2;
        if (array[i] == value)  
            return 1;
        }
        else if (array[middle] > value)  {
            end = middle - 1;
        }
        else    {
            start = middle + 1;
        }
    }
    return -1;
}

/* run this file using test.y -> copy it into ass4_13CS10061.y and then run it or in make file change ass4_13CS10061.y to test.y*/
