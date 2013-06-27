#include <stdio.h>
#include <stdlib.h>
#include "base.h"

//初始化列表
void initializelist(p *head)
{  if(*head!=NULL)
     {   
		 printf("正在初始化列表...\n");
		 *head=NULL;
     }
  printf("初始化完成.\n");
}

//检测链表是否为空
int isempty(p list)
{
	return (list==NULL)?1:0;
}
//检测是否是表尾
int isend(p node)
{
	return (node->next==NULL)?1:0;
}
//创建列表
p createlist(p list)
{  p node,temp;
   int i=0; 
   printf("输入整数(负数停止):\n");

   node=temp=(p)malloc(sizeof(Node));//申请内存空间

   if(node==NULL||temp==NULL)
    {  
		printf("申请内存空间失败.");
		exit(0);
	}
    
   while(scanf("%d",&temp->data)==1&&temp->data>0)  //输入正整数
   {   temp->next=NULL;
       if(isempty(list))
	   {
		   list=temp;//空表接入表头
		   i++;
	       printf("添加链表第一项，数值为%d\n",list->data);
	   }
	   else
	   {
		   node->next=temp; //非空表接入表尾
	       i++;
		   printf("添加第%d项，数值为%d\n",i,node->next->data);
       }
       node=temp;//node移到表尾,存储追加元素
	   temp=(p)malloc(sizeof(Node));
	   if(temp==NULL)
	   {
		   printf("申请内存失败");
	       exit(0);
	   }
     }
   free(temp);
   printf("表尾next为%d",node->next);
   printf("链表已创建.\n");
   return list;
}


//打印列表
void printlist(p list)
{  if(isempty(list))
       printf("链表为空.\n");
   else
   {   while(!isempty(list))
       {
	      printf("链表内容为%d\n",list->data);
          list=list->next;
        }
        printf("\n");
   }
	 
}

//清空列表，释放内存空间
void clearlist(p *list)  //void clearlist(p list)会造成实参list变成野指针，因为free函数释放了list指向的
{   p p1;                //内存空间，实参list的值依然是原来的值，也就是依然指向原来的节点，实参list指向的链表中的数据变成随机的数据
	if(isempty(*list))
       printf("链表已清空.");
   else
   {   while(!isempty(*list))
       {
		   p1=(*list)->next;//保存下一节点地址
		   free(*list);
		   *list=p1;  //表头下移
        }
   }
	printf("链表已清空.\n");
	//return list;
}

//返回链表长度
int lengthlist(p list)
{  int i=0;
   if(isempty(list))
	   return 0;
   else
   { 
	   while(!isempty(list))
	   {
		   i++;
           list=list->next;
	   }
	  // printf("链表长度为%d",i);
       return i;
   }
}

//查找第k个节点，并返回值，超出范围返回NULL
p findnodelist(p list,int k)
{   int i,j;
 	if(isempty(list))
		 printf("链表为空.\n");
    else
     { 
		 if(isempty(list)==0&&(j=lengthlist(list))<k)
	      {
		     printf("超出链表长度,输入小于链表长度%d的值\n",j);
	         return NULL;
	      }
	     else 
		  {
			 for(i=1;i<k;i++)
			    list=list->next;
	      }
	     return list;
	  }
}

//查找元素X
void finddatalist(p list,int x)
{	int i=0,k,m;
	int *j;  //int动态数组存放X地址
	k=lengthlist(list);
	j=(int *)malloc(k*sizeof(int));  //动态分配数组长度
	if(isempty(list))
		printf("链表为空.\n");
	else
		{
			while(isempty(list)==0)
				{
					if(list->data==x)
						{
							j[i]=(int)list;
							i++;
						}
					list=list->next;
				}
		}
	if(i==0)
		printf("没有找到元素%d",x);
	else
		{
			printf("找到%d个%d,",i,x);
			for(m=1;m<=i;m++)
				printf("第%d个,地址是%d",m,j[m-1]);
		}
}

//将第X个节点的值改为K，成功返回1，否则返回0
int modifynode(p list,int x,int k)
{
	if(findnodelist(list,x)==NULL)
		return 0;
	else
		{
			findnodelist(list,x)->data=k;
			return 1;
		}
}

//向表头插入元素K
void inserttohead(p *list,int k)
{   p temp;
	temp=(p)malloc(sizeof(Node));
	if(temp==NULL)
		{
			printf("申请内存失败.");
			exit(0);
		}
	temp->data=k;
	temp->next=*list;
	*list=temp;   
}
/*int  inserttohead(p * list,int k)
{   //函数都为值传递，若用p list做形参不能改变实参中list的值，实参依然指向原表头
	p temp;
	temp=(p)malloc(sizeof(Node));
	if(temp==NULL)
		{
			printf("申请内存失败.");
			exit(0);
		}
	temp->data=k;
	temp->next=*list;
	*list=temp;   
	return 1; 
}*/

//移到表尾
p gotoend(p list)
{
	while(!isend(list))
		list=list->next;
	return list;
}
//向表尾插入元素K
void inserttoend(p list,int k)
{
	p temp;
	temp=(p)malloc(sizeof(Node));//存储新节点
	if(temp==NULL)
		{
			printf("申请内存空间失败.");
	        exit(0);
		}
	temp->data=k;
	temp->next=NULL;
	list=gotoend(list); //移到表尾
	list->next=temp;
	//return 1;
}

//交换链表中的两个元素
void exdata(p p1,p p2)
{
	int temp;
	temp=p1->data;
	p1->data=p2->data;
	p2->data=temp;
}
//链表升序排序
void sortasc(p list)
{
	int i,j;
	p listnext,head;
	for(i=0;i<lengthlist(list)-1;i++)  //冒泡排序
		{
			head=list;
			listnext=list->next;
			for(j=1;j<lengthlist(list)-i;j++)
				{
					if(head->data>listnext->data)
						{
							exdata(head,listnext);
						}
					head=listnext;
					listnext=listnext->next;
				}
		}
}

//链表降序排序
void sortdesc(p list)
{
	int i,j;
	p listnext,head;
	for(i=0;i<lengthlist(list)-1;i++)     //冒泡排序
		{
			head=list;
			listnext=list->next;
			for(j=1;j<lengthlist(list)-i;j++)
				{
					if(head->data<listnext->data)
						{
							exdata(head,listnext);
						}
					head=listnext;
					listnext=listnext->next;
				}
		}
}
//比较链表中第X个元素与元素K的大小，大于返回1，小于返回0
int cmpdata(p list,int x,int k)
{   //printf("findnodelist(list,x)->data=%d",findnodelist(list,x)->data);
	return ((findnodelist(list,x)->data)>k)?1:0;
}


//在第X个节点前方插入元素K
void insertpre(p list,int x,int k)
{
	p temp;
	temp=(p)malloc(sizeof(Node));
	temp->data=k;
	temp->next=findnodelist(list,x);
	findnodelist(list,x-1)->next=temp;
}

//在第X个节点后方插入元素K
void insertnext(p list,int x,int k)
{
	p temp;
	temp=(p)malloc(sizeof(Node));
	temp->data=k;
	temp->next=findnodelist(list,x+1);
	findnodelist(list,x)->next=temp;
}
//向有序链表插入元素K后依然有序
void adddata(p *list,int k)
{   int high=lengthlist(*list);
	int mid,low=1; 
	if(isempty(*list))
		{
			printf("链表为空");
			exit(0);
		}
	mid=(low+high)/2;
	while(low<=high)  //二分法查找插入点
		{
			if(cmpdata(*list,mid,k))
				high=mid-1;
			else if(cmpdata(*list,mid,k)==0)
				low=mid+1;
			if(high==0||low==high+1)
				break;
			else
				mid=(low+high)/2;
		}
	if(high==0)  
		inserttohead(list,k); //插入表头
	else if(cmpdata(*list,mid,k))
		insertpre(*list,mid,k); //mid前方
	else if(cmpdata(*list,mid,k)==0&&low<high+1)
		insertnext(*list,mid,k);   //mid后方
	else if(low==high+1)
		inserttoend(*list,k); //插入表尾
	else 
		printf("Error.\n");
}

//删除表头节点
void deletehead(p *list)
{
	p temp;
	temp=(*list)->next;
	free(*list);
	*list=temp;
}

//删除表尾节点
void deleteend(p list)
{
	int i=lengthlist(list);
	p temp=findnodelist(list,i);
	findnodelist(list,i-1)->next=NULL;
	free(temp);
	//free(findnodelist(list,i));
}

//查找元素K，返回位置
p finddata(p list,int k)
{
	while(list!=NULL&&list->data!=k)
		list=list->next;
	return list;
}

//从链表中删除元素K
void delededata(p list,int k)
{
	p temp,p1;
	p1=list;
	while(p1->next!=NULL&&p1->next->data!=k)
		p1=p1->next;
	temp=finddata(list,k);
	if(temp==NULL&&isempty(list))
		printf("Error");
	else if(isend(temp))
		deleteend(list);
	else 
		{
			p1->next=temp->next;
			free(temp);
		}
}