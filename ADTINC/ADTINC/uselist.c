#include <stdio.h>
#include "base.h"
#include <stdlib.h>
//#include <windows.h>
//#include <iostream>
int main(void)
{
	p list;
	int option;
	list=(p)malloc(sizeof(Node));
	printui();
	while(scanf("%d",&option)==1)
		{   
			while(getchar()!='\n')
				continue;
			switch(option)
				{
					case 1:initializelist(&list);break;
					case 2:list=createlist(list);break;
					case 3:printlist(list);break;
					case 4:clearlist(&list);break;
					case 5:printf("������Ϊ%d\n",lengthlist(list));break;
					case 6:fnl(list);break;
					case 7:fdl(list);break;
					case 8:mn(list);break;
					case 9:inh(&list);break;
					case 10:ine(list);break;
					case 11:sortasc(list);break;
					case 12:sortdesc(list);break;
					case 13:cmpd(list);break;
					case 14:inmd(list);break;
					case 15:ad(&list);break;
					case 16:dd(&list);break;
				}
			printf("��ѡ��:");
		}
	getchar();
	return 0;
}

void printui(void)
{
	printf("��������ѡ����Ҫ�Ĺ���:\n");
	printf("1.��ʼ������\t\t2.��������\n");
	printf("3.��ӡ����\t\t4.�������\n");
    printf("5.����������\t\t6.���ҽڵ�ֵ\n");
	printf("7.����Ԫ��\t\t8.�޸Ľڵ�\n");
	printf("9.���ͷ����Ԫ��\t10.���β����Ԫ��\n");
	printf("11.��������\t\t12.��������\n");
	printf("13.�Ƚϴ�С\t\t14.����Ԫ��\n");
	printf("15.�������Ȼ����\t16.ɾ��Ԫ��\n");
}

void fnl(p list)
{   
	//p result;
	int node;
	printf("������Ҫ���ҵĽڵ���:\n");
	scanf("%d",&node);
	//result=findnodelist(list,node);
	printf("�ڵ�%d��ֵΪ%d\n",node,findnodelist(list,node)->data);
}

void fdl(p list)
{   
	int data;
	printf("������Ҫ���ҵ�Ԫ��:\n");
	scanf("%d",&data);
	finddatalist(list,data);
}

void mn(p list)
{
	int node,data;
	printf("������Ҫ�޸ĵĽڵ���:\n");
	scanf("%d",&node);
	printf("����ֵ:\n");
	scanf("%d",&data);
	if(modifynode(list,node,data))
		printf("�޸ĳɹ���\n");
	else 
		printf("Error\n");
}

void inh(p *list)
{
	int data;
	printf("������Ҫ�����Ԫ��:\n");
	scanf("%d",&data);
	inserttohead(list,data);

}

void ine(p list)
{
	int data;
	printf("������Ҫ�����Ԫ��:\n");
	scanf("%d",&data);
	inserttoend(list,data);
}

void cmpd(p list)
{
	int k,x;
	printf("������Ҫ�Ƚϵ�Ԫ��:\n");
	scanf("%d",&k);
	printf("������Ҫ�ȽϵĽڵ�:\n");
	scanf("%d",&x);
	if(cmpdata(list,x,k))
		printf("Ԫ��%dС���ڽڵ�%d�е�Ԫ��.\n",k,x);
	else
		printf("Ԫ��%d���ڽڵ�%d�е�Ԫ��.\n",k,x);
}

void inmd(p list)
{
	int num,data,node;
	printf("��������:\n");
	printf("1:��ǰ������\t\t2:�ں󷽲���\n");
	while(scanf("%d",&num)==1&&num>0)
		{
			printf("������Ҫ�����Ԫ��:\n");
			scanf("%d",&data);
			printf("������Ҫ����Ľڵ�:\n");
			scanf("%d",&node);
				if(num==1)
					insertpre(list,node,data);
				else
					insertnext(list,node,data);
		}
	printf("�������.\n");
}

void ad(p *list)
{
	int data;
	printf("������Ҫ�����Ԫ��:\n");
	scanf("%d",&data);
	adddata(list,data);
}

void dd(p *list)
{
	int data;
	printf("������Ҫɾ����Ԫ��:\n");
	scanf("%d",&data);
	if(findnodelist(*list,1)->data==data)
		deletehead(list);
	else if(findnodelist(*list,lengthlist(*list))->data==data)
		deleteend(*list);
	else
		delededata(*list,data);
}