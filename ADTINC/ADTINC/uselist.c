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
					case 5:printf("链表长度为%d\n",lengthlist(list));break;
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
			printf("请选择:");
		}
	getchar();
	return 0;
}

void printui(void)
{
	printf("输入数字选择需要的功能:\n");
	printf("1.初始化链表\t\t2.创建链表\n");
	printf("3.打印链表\t\t4.清空链表\n");
    printf("5.计算链表长度\t\t6.查找节点值\n");
	printf("7.查找元素\t\t8.修改节点\n");
	printf("9.向表头插入元素\t10.向表尾插入元素\n");
	printf("11.升序排序\t\t12.降序排序\n");
	printf("13.比较大小\t\t14.插入元素\n");
	printf("15.插入后依然有序\t16.删除元素\n");
}

void fnl(p list)
{   
	//p result;
	int node;
	printf("输入想要查找的节点数:\n");
	scanf("%d",&node);
	//result=findnodelist(list,node);
	printf("节点%d的值为%d\n",node,findnodelist(list,node)->data);
}

void fdl(p list)
{   
	int data;
	printf("输入想要查找的元素:\n");
	scanf("%d",&data);
	finddatalist(list,data);
}

void mn(p list)
{
	int node,data;
	printf("输入想要修改的节点数:\n");
	scanf("%d",&node);
	printf("输入值:\n");
	scanf("%d",&data);
	if(modifynode(list,node,data))
		printf("修改成功！\n");
	else 
		printf("Error\n");
}

void inh(p *list)
{
	int data;
	printf("输入想要插入的元素:\n");
	scanf("%d",&data);
	inserttohead(list,data);

}

void ine(p list)
{
	int data;
	printf("输入想要插入的元素:\n");
	scanf("%d",&data);
	inserttoend(list,data);
}

void cmpd(p list)
{
	int k,x;
	printf("输入想要比较的元素:\n");
	scanf("%d",&k);
	printf("输入想要比较的节点:\n");
	scanf("%d",&x);
	if(cmpdata(list,x,k))
		printf("元素%d小于于节点%d中的元素.\n",k,x);
	else
		printf("元素%d大于节点%d中的元素.\n",k,x);
}

void inmd(p list)
{
	int num,data,node;
	printf("输入数字:\n");
	printf("1:在前方插入\t\t2:在后方插入\n");
	while(scanf("%d",&num)==1&&num>0)
		{
			printf("输入想要插入的元素:\n");
			scanf("%d",&data);
			printf("输入想要插入的节点:\n");
			scanf("%d",&node);
				if(num==1)
					insertpre(list,node,data);
				else
					insertnext(list,node,data);
		}
	printf("插入完成.\n");
}

void ad(p *list)
{
	int data;
	printf("输入想要插入的元素:\n");
	scanf("%d",&data);
	adddata(list,data);
}

void dd(p *list)
{
	int data;
	printf("输入想要删除的元素:\n");
	scanf("%d",&data);
	if(findnodelist(*list,1)->data==data)
		deletehead(list);
	else if(findnodelist(*list,lengthlist(*list))->data==data)
		deleteend(*list);
	else
		delededata(*list,data);
}