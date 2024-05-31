#include<stdio.h>
#include <conio.h>
void DFS(int);
int a[20][20],reach[20],n;    
void dfs(int v)
{
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
    {
       if(a[v][i] && !reach[i])
       {
            printf("%d->%d",v,i);
            dfs(i);
       }
    }
}
int main(int argc,char **argv)
{
    int i,j,count=0;
    printf("enter the number of vertices:");
    scanf("%d",&n);
    for (i = 1; i <=n; i++)
    {
        reach[i]=0;
        for (j = 1; j <=n; j++)
        {
            a[i][j]=0;
        }
        
    }
    printf("enter the adjucency matrix:");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    int v;
    printf("enter the starting vertex:");
    scanf("%d",&v);
    dfs(v);
    for (i = 1; i <= n; i++)
    {
        if (reach[i])
        {
            count++;
        }
        if (count==n)
        {
            printf("graph is connected");
        }
        else
        {
            printf("graph is not connected");
        }
        return 0;
        
    }
    
    
    
}