void change(int* a,int m,int n)
{
    int temp;
    temp = a[m];
    a[m] = a[n];
    a[n] = temp;
}
int partition(int* arr,int left,int right)
{
    int pivot = arr[right];
    int l = left;
    int r = right-1;
    while(true)
    {
        while(arr[l] < pivot){l++;};
        while(arr[r] > pivot){r--;};
        if(l>=r)
            break;
        change(arr,l,r);
    }

    change(arr,l,right);
    return l;
}

void quicksort(int* arr,int left,int right )
{
    if(left>=right)
        return;
    int part = partition(arr,left,right);
    quicksort(arr,left,part-1);
    quicksort(arr,part+1,right);
}
