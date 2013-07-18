#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

//ɢ�к���
int HashtoList(int num,int size)
{
	return num%size;
}

//��ʼ��
hl inithashlist(int tablesize)
{
	hl h;
	int i;
	h=(hl)malloc(sizeof(struct HashList));//����ɢ�пռ�
	if(h==NULL)
		printf("hERROR\n");
	h->size=tablesize;
	h->pl=(ln *)malloc(sizeof(ln)*h->size);//����ָ������ռ�
	if(h->pl==NULL)
		printf("h->plERROR\n");
	for(i=0;i<h->size;i++)
	{
		h->pl[i]=(ln)malloc(sizeof(struct ListNode));//����ڵ�ռ�
		if(h->pl[i]==NULL)
			printf("h->pl[%d]ERROR\n",i);
		else
		h->pl[i]->next=NULL;
	}
	return h;
}

//����
ln findhashnode(int key,hl hashlist)
{
	ln p,l;
	p=hashlist->pl[HashtoList(key,hashlist->size)];
	l=p->next;
	while(l->element!=key&&l!=NULL)
		l=l->next;
	return l;
}

//���
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
