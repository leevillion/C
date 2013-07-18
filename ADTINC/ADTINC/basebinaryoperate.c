#include <stdio.h>
#include <stdlib.h>
#include "binaryfindtree.h"

//初始化
void inittree(tree *t)
{
	*t=NULL;
}

//右
int toright(tree t,int num)
{
	if(num>t->element)
		return 1;
	else
		return 0;
}

//左
int toleft(tree t,int num)
{
	if(num<t->element)
		return 1;
	else
		return 0;
}

//添加
node addtree(tree t,int num)
{
	if(t==NULL)
	{
		t=(node)malloc(sizeof(struct Node));
		t->element=num;
		t->left=t->right=NULL;
	}
	else if(toright(t,num))  //比对右子树
	{
		t->right=addtree(t->right,num);
	}
	else if(toleft(t,num))  //比对左子树
	{
		t->left=addtree(t->left,num);
	}

	return t;
}
 /*独立添加根节点，其余用递归添加
void additem(tree *t,int num)
{
	node temp;
	temp=(node)malloc(sizeof(struct Node));
	temp->element=num;
	temp->left=temp->right=NULL;
	if(*t==NULL)
	{
		*t=temp;
	}
	else
		addnode(t,temp);
}

void addnode(tree *t,node n)
{
	if(toright(*t,n->element))
	{
		if((*t)->right==NULL)
			(*t)->right=n;
		else
			addnode(&(*t)->right,n);
	}
	else if(toleft(*t,n->element))
	{
		if((*t)->left==NULL)
			(*t)->left=n;
		else
			addnode(&(*t)->left,n);
	}

}*/


//查找
node findtree(tree t,int num)
{
	if(t==NULL)
		return NULL;
	else if(toright(t,num))
	{
		return findtree(t->right,num);
	}
	else if(toleft(t,num))
	{
		return findtree(t->left,num);
	}
	else
		return t;
}

//查找最小元素
node findmin(tree t)
{
	if(t==NULL)
		return NULL;
	else if(t->left==NULL)
		return t;
	else
		return findmin(t->left);
}

//查找最大元素
node findmax(tree t)
{
	if(t==NULL)
		return NULL;
	else if(t->right==NULL)
		return t;
	else
		return findmax(t->right);
}

//删除--若删除节点有两个子节点，使用右子树最小元素代替当前节点，删除右子树最小元素
node deletetree(tree t,int num)
{
	node temp;
	if(t==NULL)
		printf("ERROR!\n");
	else if(num<t->element)
		t->left=deletetree(t->left,num);
	else if(num>t->element)
		t->right=deletetree(t->right,num);
	else if(t->left&&t->right)
	{
		temp=findmin(t->right);
		t->element=temp->element;
		t->right=deletetree(t->right,t->element);
	}
	else
	{
		temp=t;
		if(t->left==NULL)
			t=t->right;
		else if(t->right==NULL)
			t=t->left;
		free(temp);
	}
	return t;
}