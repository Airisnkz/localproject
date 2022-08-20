#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int coef;
    int exp;
    struct LNode *next;
}LinkNode;
int dc=0,dv=0;
void CreateListF(LinkNode *&L,int a[])
{
    int i=0,p=0,j=0;
    LinkNode* s,*r;
    L=(LinkNode*)malloc(sizeof(LinkNode));
    r=L;
    for(i=0;;i++)
    {
        if(a[i]==0)
        {
            p=i;
            break;
        }
    }
    for(j=1;j<=p;j++)
    {
        s=(LinkNode*)malloc(sizeof(LinkNode));
        if(j%2!=0)
        {
            s->coef=a[j-1];
            s->exp=a[j];
            r->next=s;
            r=s;
            j++;
            continue;
        }
        else
        {
            continue;
        }
    }
    r->next=NULL;
}
LinkNode *L1;
LinkNode *L2;
int x[10];
int max_rt=0;
void suanfa()
{
    int i=0,ff=0;
    int gk=0,gp=0;
    LinkNode* s,*r;
    if(dc>=dv)
    {
        s=L1->next;r=L2->next;
        max_rt=dc;
    }
    else
    {
        r=L1->next;s=L2->next;
        max_rt=dv;
    }
    int hh=0;int sum=0;
    for(i=0;;i++)
    {
        gk=s->exp;
        gp=r->exp;
        if(gk==gp)
        {
            sum=(s->coef)+(r->coef);
            x[hh]=sum;
            hh++;
            x[hh]=s->exp;
            hh++;
            sum=0;
            if(s->next==NULL)
            {
                break;
            }
            else 
            {
                s=s->next;
                if(dc>=dv)
                {
                    r=L2->next;
                    continue;
                }
                else
                {
                    r=L1->next;
                    continue;
                }
            }
            s=s->next;
            if(dc>=dv)
            {
                r=L2->next;
                continue;
            }
            else
            {
                r=L1->next;
                continue;
            }
        }
        else
        {
            if(r->next==NULL)
            {
                if(s->next==NULL)
                {
                    x[hh]=s->coef;
                    hh++;
                    x[hh]=s->exp;
                    hh++;
                    break;
                }
                else
                {
                    x[hh]=s->coef;
                    hh++;
                    x[hh]=s->exp;
                    hh++;
                    if(dc>=dv)
                    {
                        r=L2->next;
                        s=s->next;
                        continue;
                    }
                    else
                    {
                        r=L1->next;
                        s=s->next;
                        continue;
                    }
                    continue;
                }
            }
            else
            {
                r=r->next;
                continue;
            }
        }
    }
    for(ff=0;ff<max_rt;ff++)
    {
        printf("%d  ",x[ff]);
    }
}
int main()
{
    int i=0;
    int a[100];
    int b[100];
    for(i;;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)
        {
            dc=i;
            break;
        }
    }
    i=0;
    for(i;;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]==0)
        {
            dv=i;
            break;
        }
    }
    CreateListF(L1,a);
    CreateListF(L2,b);
    suanfa();
    system("pause");
}