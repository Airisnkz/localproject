#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=0,m=0;
    int i=0,k=0,f=0;
    scanf("%d",&n);
    scanf("%d",&m);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    int sp=0,pp=0,sum=0;
    for(f=0;f<n;f++)
    {
        for(k=0;k<n;k++)
            sum=sum+a[k];
        if(sum==0)
        break;
        else
        sum=0;
        if(a[f]==0)
        {
            if(f!=(n-1))
                continue;
            else
            {
                f=(-1);continue;
            }
        }
        sp++;
        if(sp==m)
        {
            printf("%d  ",a[f]);
            a[f]=0;
            sp=0;
        }
        if(f==(n-1))
        {
            f=(-1);
        } 
    }
    system("pause");
}