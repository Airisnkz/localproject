
#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
//三元组的定义 
typedef struct
{
	int row, col;//表示行列 
	int e;		//表示值 
}Triple;
 
//三元组容器的定义 
typedef struct
{
	Triple data[MAXSIZE];
	int m,n,len;
}TSMatrix;
 
//实现转置 
void TransposeTSMatrix(TSMatrix A, TSMatrix* B)
{
	int i,j,k;
	B->m = A.n;
	B->n = A.m;
	B->len = A.len;
	j=0;
	
	for( k=0; k<A.len; ++k)
	{
		for( i=0; i<A.len; ++i)
		{
			if(A.data[i].col == k)
			{
				B->data[j].row = A.data[i].col;
				B->data[j].col = A.data[i].row;
				B->data[j].e = A.data[i].e;
				++j;
			}
		}
	}
	
}
 
//测试驱动函数 
int main()
{
	//将输入重定向到根目录下的data.txt 
	freopen("data.txt", "r", stdin);
	TSMatrix A,B;
	int i,j,e; 
	int k=0;
	while(scanf("%d%d%d", &i, &j, &e)!=EOF)
	{
		A.data[k].row = i-1;
		A.data[k].col = j-1;
		A.data[k].e = e;
		A.len = ++k;
	}
	printf("原始三元组:\n");
	for(i=0; i<A.len; ++i )
	{
		printf("%3d%3d%3d\n", A.data[i].row+1, A.data[i].col+1, A.data[i].e);
	}
	
	printf("\n转置后:\n");
	TransposeTSMatrix(A, &B);
	for(i=0; i<B.len; ++i )
	{
		printf("%3d%3d%3d\n", B.data[i].row+1, B.data[i].col+1, B.data[i].e);
	}
	system("pause");
	return 0;
	
}