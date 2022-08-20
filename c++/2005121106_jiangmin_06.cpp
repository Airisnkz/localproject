#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MaxSize 100 

typedef int ElemType;
typedef int Status;

typedef struct BTNode
{
    ElemType data; 
    struct BTNode *lchild;
    struct BTNode *rchild;
}BTree;
typedef struct St
{
    struct BTNode*data[MaxSize];
    int top;
}Stack; 
BTree* CreateT()
{
    BTree *BT;
    ElemType ch;
    scanf("%d",&ch); 
    if(ch==0)
        BT=NULL;
    else
    {
        BT=(BTree*)malloc(sizeof(BTree));
        //if(!BT){exit(overflow);}        
        BT->data=ch;
        BT->lchild=CreateT();
        BT->rchild=CreateT();
    }
    return BT;
} 
Status op(BTree *BT) 
{
    if(BT)
    {
        op(BT->lchild);
        op(BT->rchild);
        printf("%3d",BT->data);
        return OK;
    }
    else return ERROR;
}
Status op2(BTree *BT) 
{
    Stack s,s2;
    BTree *T;
    int flag[MaxSize]; 
    s.top=0;
    T=BT;
    while(s.top!=0||T)
    {
        while(T)
        {
            s.data[s.top++]=T;
            flag[s.top-1]=0;
            T=T->lchild;
         } 
         while(s.top!=0&&flag[s.top-1]==1)
         {
             T=s.data[--s.top];
             printf("%3d",T->data);
         }
         if(s.top!=0)
         {
             flag[s.top-1]=1;
             T=s.data[s.top-1];
             T=T->rchild;
         }
         else break;
    }
    return OK;
}
int main(){
    BTree *BT;
    BT=CreateT();
    if(op(BT))
    {
        printf("\n后序遍历完成\n");
    }    
    if(op2(BT))
    {
        printf("\n非递归后序遍历完成\n");
    }
    system("pause");
}