#include <stdio.h>
int main()
{
    int a[7];
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
        int search,count=0;
        scanf("%d",&search);
        int low=0;
        int high=len-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(search==a[mid])
            {
                printf("search element was found %d",mid);
                count++;
                break;
            }
            else if(a[mid]>search)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(count==0)
        {
            printf("search element was not found");
        }
}