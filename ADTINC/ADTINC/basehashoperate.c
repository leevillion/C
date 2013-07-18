#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

//散列函数
int HashtoList(int num,int size)
{
	return num%size;
}

//初始化
hl inithashlist(int tablesize)
{
	hl h;
	int i;
	h=(hl)malloc(sizeof(struct HashList));//申请散列空间
	if(h==NULL)
		printf("hERROR\n");
	h->size=tablesize;
	h->pl=(ln *)malloc(sizeof(ln)*h->size);//申请指针数组空间
	if(h->pl==NULL)
		printf("h->plERROR\n");
	for(i=0;i<h->size;i++)
	{
		h->pl[i]=(ln)malloc(sizeof(struct ListNode));//申请节点空间
		if(h->pl[i]==NULL)
			printf("h->pl[%d]ERROR\n",i);
		else
		h->pl[i]->next=NULL;
	}
	return h;
}

//查找
ln findhashnode(int key,hl hashlist)
{
	ln p,l;
	p=hashlist->pl[HashtoList(key,hashlist->size)];
	l=p->next;
	while(l->element!=key&&l!=NULL)
		l=l->next;
	return l;
}

//添加
void addhashnode(int key,hl hashlist)
{
	ln p;
	ln l,temp;
	p=findhashnode(key,hashlist);
	if(p==NULL)
	{
		l=hashlist->pl[HashtoList(key,hashlist->size)];
		temp=(ln)malloc(sizeof(struct ListNode));
		temp->next=l->next;
		temp->element=key;
		l->next=temp;
	}
}
