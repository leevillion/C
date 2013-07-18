#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



//初始化栈
void initialization(stack s)
{
	if(s->next==NULL)
		printf("栈已初始化!\n");
	else
		s->next=NULL;
}


//创建栈
stack createstack(void)
{
	stack s,node;
	int a;

	s=(stack)malloc(sizeof(struct Node));
	node=(stack)malloc(sizeof(struct Node));
	initialization(s);
	if(s==NULL)
		printf("申请内存失败!\n");
    while(scanf("%d",&a)==1&&a>0)
	{
		node->next=s->next;
		node->element=a;
		s->next=node;
		node=(stack)malloc(sizeof(struct Node));
	}

	return s;
}

//检测是否是空栈
int isempty(stack s)
{
	if(s->next==NULL)
		return 1;
	else
		return 0;
}

//清空栈
void freestack(stack s)
{
	stack temp;
	if(isempty(s))
		printf("栈已清空!\n");
	while(isempty(s)==0)
	{
		temp=s->next;
		s->next=temp->next;
		free(temp);
	}
	printf("栈已清空!\n");

}

//入栈
void push(int i,stack s)
{
	stack temp=(stack)malloc(sizeof(struct Node));
	if(isempty(s))
		printf("ERROR!\n");
	else
	{	temp->element=i;
		temp->next=s->next;
		s->next=temp;
	}
}

//出栈
void pop(stack s)
{
	stack temp;
	if(isempty(s))
		printf("ERROR!\n");
	temp=s->next;
	s->next=s->next->next;
	free(temp);
}

//取栈顶元素
int top(stack s)
{
	if(isempty(s))
		printf("ERROR!\n");
	else
		return s->next->element;
}

//打印
void ptinfstack(stack s)
{
	stack temp;
	temp=s->next;
	if(temp==NULL)
		printf("ERROR!\n");
	else
		while(temp!=NULL)
		{
			printf("%d ",temp->element);
			temp=temp->next;
		}

}

