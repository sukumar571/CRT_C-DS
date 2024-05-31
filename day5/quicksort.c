#include <stdio.h>
void swap(int* a,int* b)
{
    int temp= *a;
    *a=*b;
    *b=temp;
}
int partitionindex(int a[],int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(a[i]<=pivot && i<=high-1)
        {
            i++;
        }
        while(a[j]>pivot && j>=low+1)
        {
            j--;
        }
        if(i<j)
        {
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[low],&a[j]);
    return j;
}
void quicksort(int *a,int low,int high)
{
    if(low<high)
    {
        int partition=partitionindex(a,low,high);
        quicksort(a,low,partition-1);
        quicksort(a,partition+1,high);
    }
}
int main()
{
    int a[6];
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,len-1);
    for(int i=0;i<len;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}