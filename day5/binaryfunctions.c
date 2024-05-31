#include<stdio.h>
int binarysearch();
int main()
{
    int a[6];
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    int search, count=0;
    scanf("%d",&search);
    int low=0;
    int high=len-1;
    int result=binarysearch(a,search,low,high);
    if(result==-1)
    {
        printf("searching element was not found");
    }
    else
    {
        printf("searching element was found");
    }
    
}
int binarysearch(int a[6],int search,int low,int high)
{
    while(low<=high)
        {
            int mid=(low+high)/2;
            if(a[mid]==search)
            {
                return mid;
            }
            else if (a[mid>search])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return -1;
}