#include<stdio.h>
#include <stdlib.h>
void merge(int a[],int low,int mid,int high)
{
    //take a left sub array,right sub array strat comparing elements and merge
    int i,j,k;
    int n1=mid-low+1;
    int n2=high-mid;
    // creating a duplicate array with left sub array and right sub array
    int l[n1],r[n2];
    // copy the data into dupliacte array
    for (int i = 0; i < n1; i++)
    {
       l[i]=a[low+i];
    }
    // copy data to duplicate array to right subarray
    for(j=0;j<n2;j++)
    {
        r[i]=a[mid-low+i];
    }
    //merge the arrays
    i=0;
    j=0;
    k=low;
    while (i<n1 && j<n2)
    {
        // if your left sub array element is less than or equal to right sub array
        if (l[i]<=r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
        k++;
        
    }
    // copy the remaining 
    while (i<n1)
    {
        a[k]=l[i];
        i++;
        k++;
    }
    // copy the remaing elements
    while (j<n2)
    {
        a[k]=r[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int low,int high)
{
    if (low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,high);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
    
}
int main()
{
    int a[6];
    int len=sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < len; i++)
    {
        scanf("%d",a[i]);
    }
    mergesort(a,0,len-1);
    for (int i = 0; i < len; i++)
    {
        /* code */
    }
    
    
}