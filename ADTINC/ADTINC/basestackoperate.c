#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



//��ʼ��ջ
void initialization(stack s)
{
	if(s->next==NULL)
		printf("ջ�ѳ�ʼ��!\n");
	else
		s->next=NULL;
}


//����ջ
stack createstack(void)
{
	stack s,node;
	int a;

	s=(stack)malloc(sizeof(struct Node));
	node=(stack)malloc(sizeof(struct Node));
	initialization(s);
	if(s==NULL)
		printf("�����ڴ�ʧ��!\n");
    while(scanf("%d",&a)==1&&a>0)
	{
		node->next=s->next;
		node->element=a;
		s->next=node;
		node=(stack)malloc(sizeof(struct Node));
	}

	return s;
}

//����Ƿ��ǿ�ջ
int isempty(stack s)
{
	if(s->next==NULL)
		return 1;
	else
		return 0;
}

//���ջ
void freestack(stack s)
{
	stack temp;
	if(isempty(s))
		printf("ջ�����!\n");
	while(isempty(s)==0)
	{
		temp=s->next;
		s->next=temp->next;
		free(temp);
	}
	printf("ջ�����!\n");

}

//��ջ
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

//��ջ
void pop(stack s)
{
	stack temp;
	if(isempty(s))
		printf("ERROR!\n");
	temp=s->next;
	s->next=s->next->next;
	free(temp);
}

//ȡջ��Ԫ��
int top(stack s)
{
	if(isempty(s))
		printf("ERROR!\n");
	else
		return s->next->element;
}

//��ӡ
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

