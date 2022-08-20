#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define Maxsize 100
typedef struct
{
	char data[Maxsize];
	int top;
}SqStack;

typedef struct
{
	double data[Maxsize];
	int top;
}SqStack1;

void InitStack(SqStack * &s)
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
void InitStack1(SqStack1 * &s)
{
	s=(SqStack1 *)malloc(sizeof(SqStack1));
	s->top=-1;
}
bool StackEmpty(SqStack * &s)
{
	return(s->top==-1);
}
bool StackEmpty1(SqStack1 * &s)
{
	return(s->top==-1);
}
void DestroyStack(SqStack * &s)
{
	free(s);
}
void DestroyStack1(SqStack1 * &s)
{
	free(s);
}
bool GetTop(SqStack *s,char &e)
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}
bool GetTop1(SqStack1 *s,double &e)
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	return true;
}
bool Pop(SqStack * &s,char &e)
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
bool Pop1(SqStack1 * &s,double &e)
{
	if(s->top==-1)
		return false;
	e=s->data[s->top];
	s->top--;
	return true;
}
bool Push(SqStack * &s,char &e)
{
	if(s->top==Maxsize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
bool Push1(SqStack1 * &s,double &e)
{
	if(s->top==Maxsize-1)
		return false;
	s->top++;
	s->data[s->top]=e;
	return true;
}
void trans(char * exp,char postexp[])
{
	int i=0;
	char e;
	SqStack * Op;
	InitStack(Op);
	while(* exp!='\0')
	{
		switch(* exp)
		{
		case '+':
		case '-':
			while(!StackEmpty(Op))
			{
				GetTop(Op,e);
			if(e!='(')
			{
				postexp[i++]=e;
				Pop(Op,e);
			}
			else
				break;
			}
			Push(Op,* exp);
			exp++;
			break;
		case '*':
		case '/':
			while(!StackEmpty(Op))
			{
				GetTop(Op,e);
			if(e=='*'||e=='/')
			{
				postexp[i++]=e;
				Pop(Op,e);
			}
			else
				break;
			}
			Push(Op,* exp);
			exp++;
			break;

		case '(':
			Push(Op,* exp);
			exp++;
			break;
		case ')':
			Pop(Op,e);
			while(e!='(')
			{
				postexp[i++]=e;
				Pop(Op,e);
			}
			exp++;
			break;

		default:
				while(* exp>='0'&&* exp<='9')
					{
						postexp[i++]=* exp;
						exp++;
				}
				postexp[i++]='#';
		}
	}
	while(!StackEmpty(Op))
	{
		Pop(Op,e);
		postexp[i++]=e;
	}
	postexp[i]='\0';
	DestroyStack(Op);
}
double jisuan(char * postexp)
{
	double a,b,c,d,e;
	SqStack1 * Op;
	InitStack1(Op);
	while(* postexp!='\0')
	{
		switch(* postexp)
		{
		case '+':
			Pop1(Op,a);
			Pop1(Op,b);
			c=b+a;
			Push1(Op,c);
			break;

		case '-':
			Pop1(Op,a);
			Pop1(Op,b);
			c=b-a;
			Push1(Op,c);
			break;

		case '*':
			Pop1(Op,a);
			Pop1(Op,b);
			c=b*a;
			Push1(Op,c);
			break;

		case '/':
			Pop1(Op,a);
			Pop1(Op,b);
			if(a==0)
			{
				printf("0异常\n");
				exit(0);
			}
			else
				{
					c=b/a;
					Push1(Op,c);
					break;
			}
			break;
			
		default:
			d=0;
			while(* postexp>='0'&&* postexp<='9')
			{
				d=10*d+* postexp-'0';
				postexp++;
			}
			Push1(Op,d);
			break;
		}
		postexp++;
	}
	GetTop1(Op,e);
	DestroyStack1(Op);
	return e;
}
int main()
{
	char postexp[Maxsize];
	char exp[Maxsize];
	printf("表达式：");
	gets(exp);
	trans(exp,postexp);
	//printf("%s\n",exp);
	//printf("%s\n",postexp);
	printf("%g\n",jisuan(postexp));
    system("pause");
}