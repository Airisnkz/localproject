#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int MaxSize=100;
int re[MaxSize];
int ps;                //长度
typedef struct 
{
    int data[MaxSize];
    int tou,wei;
}SqQuene;
void chushihua(SqQuene*&q)
{
    q=(SqQuene*)malloc(sizeof(SqQuene));
    q->tou=q->wei=-1;
}
void Destroy(SqQuene*&q)
{
    free(q);
}
bool Empty(SqQuene*&q)
{
    return(q->tou==q->wei);
}
bool rudui(SqQuene*&q,int s)
{
    if(q->wei==MaxSize-1)
    return false;
    q->wei++;
    q->data[q->wei]=s;
    return true;
}
bool chudui(SqQuene*&q)
{
    if(q->wei==q->tou)
    return false;
    q->tou++;
    return true;
}
int rek(int a[])
{
    int k=0;
    int i=0,j=0;
    for(i=0;;i++)
    {
        if(a[i]==0)
        {
            break;
        }
        if(a[i]<a[i+1])
        {
            continue;
        }
        else
        {
            k++;
            continue;
        }
    }
    printf("需要%d个缓冲轨道\n",k);
    return k;
}
int chongpai(int k,int a[])
{
    int sk=0,pp=0;
    int i=0,j=0;
    SqQuene*ds[50];
    for(sk=0;sk<k;sk++)
    {
        chushihua(ds[sk]);
    }
    for(i=0;;i++)
    {
        if(a[i+1]>a[i])
        {
            rudui(ds[pp],a[i]);
            continue;
        }
        else
        {
            rudui(ds[pp],a[i]);
            if(a[i+1]==0)
            {
                rudui(ds[pp],0);
                break;    
            }
            rudui(ds[pp],0);
            pp++;
            continue;
        }
    }
    int nowc=1;
    int num=0;
    for(j=0;j<k;j++)
    {
        if(nowc==ds[j]->data[ds[j]->tou+1])
        {
            re[num]=nowc;
            nowc++;
            num++;
            chudui(ds[j]);
            if(j==(k-1))
            {
                j=(-1);
                continue;
            }
            else
            continue;
        }
        if(j==(k-1))
        {
            j=(-1);
            continue;
        }
        if(nowc==ps)
        break;
    }
    int qr=0;
    for(int us=0;us<k;us++)
    {
        printf("轨道%d:",us+1);
        for(qr=0;;qr++)
        {
            
            if(ds[us]->data[qr]==0)
            {
                printf("\n");
                break;
            }
            else
            {
                printf("%d ",ds[us]->data[qr]);
            }
        }
    }
    return 0;
}
int main()
{
    int a[100];
    int k=0;
    printf("(头->尾):");
    for(int i=0;;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)
        {
            ps=i+1;
            break;
        }
    }
    k=rek(a);
    chongpai(k,a);
    for(int is=0;is<(ps-1);is++)
    {
        printf("%d  ",re[is]);
    }
    system("pause");
}