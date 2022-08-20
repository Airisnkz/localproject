#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
int Delete(BiTree *p)
{
	BiTree q, s;
	if(  !(*p)->lchild && !(*p)->rchild )
		*p = NULL;
	else if( !(*p)->lchild )
	{
		q = *p;	
		*p = (*p)->rchild;
		free(q);
	}
	else if( !(*p)->rchild )
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if( q != *p )		
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return TRUE;
}
int SearchBST( BiTree T, int key, BiTree f, BiTree *p )
{
	if( !T )
	{	
		*p = f;
		return FALSE;	
	}
	else
	{
		if( key == T->data )
		{	*p = T;		return TRUE; }
		else if( key > T->data )
			return SearchBST( T->rchild, key, T, p );
		else	
			return SearchBST( T->lchild, key, T, p );
		}
}

int InsertBST1( BiTree *T, int key )
{
	BiTree p, s;
	if( !SearchBST( *T, key, NULL, &p ) )
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if( !p )
			*T = s;
		else if( key > p->data )
			p->rchild = s;
		else
			p->lchild = s;
		return TRUE;
	}
	return FALSE;
}

void order(BiTree t)
{  
    if(t == NULL)  
        return ;  
    order(t->lchild);  
    printf("%d ", t->data);  
    order(t->rchild);  
} 

int DeleteBST(BiTree *T, int key)
{
	if( !(*T))
		return FALSE;
	else
	{
		if( key == (*T)->data )
			Delete(T);
		else if( key < (*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);
	}
}
 

int main()
{
	int i,key=0;
	int a[10] = {6,8,5,4,3,10,1,9,2,11};
	BiTree T = NULL;
	for( i = 0; i < 10; i++ )
		InsertBST1(&T, a[i]);
	printf("中序遍历二叉排序树：\n");
	order(T);
	printf("\n请输入要删除的元素：");
    scanf("%d",&key);
	printf("删除%d后，中序遍历二叉排序树：\n",key);
	DeleteBST(&T,key);
	order(T);
	printf("\n");
    system("pause");
    return 0;
}
