#include <stdio.h>
#include <stdlib.h>
#include "base.h"

//��ʼ���б�
void initializelist(p *head)
{  if(*head!=NULL)
     {   
		 printf("���ڳ�ʼ���б�...\n");
		 *head=NULL;
     }
  printf("��ʼ�����.\n");
}

//��������Ƿ�Ϊ��
int isempty(p list)
{
	return (list==NULL)?1:0;
}
//����Ƿ��Ǳ�β
int isend(p node)
{
	return (node->next==NULL)?1:0;
}
//�����б�
p createlist(p list)
{  p node,temp;
   int i=0; 
   printf("��������(����ֹͣ):\n");

   node=temp=(p)malloc(sizeof(Node));//�����ڴ�ռ�

   if(node==NULL||temp==NULL)
    {  
		printf("�����ڴ�ռ�ʧ��.");
		exit(0);
	}
    
   while(scanf("%d",&temp->data)==1&&temp->data>0)  //����������
   {   temp->next=NULL;
       if(isempty(list))
	   {
		   list=temp;//�ձ�����ͷ
		   i++;
	       printf("��������һ���ֵΪ%d\n",list->data);
	   }
	   else
	   {
		   node->next=temp; //�ǿձ�����β
	       i++;
		   printf("��ӵ�%d���ֵΪ%d\n",i,node->next->data);
       }
       node=temp;//node�Ƶ���β,�洢׷��Ԫ��
	   temp=(p)malloc(sizeof(Node));
	   if(temp==NULL)
	   {
		   printf("�����ڴ�ʧ��");
	       exit(0);
	   }
     }
   free(temp);
   printf("��βnextΪ%d",node->next);
   printf("�����Ѵ���.\n");
   return list;
}


//��ӡ�б�
void printlist(p list)
{  if(isempty(list))
       printf("����Ϊ��.\n");
   else
   {   while(!isempty(list))
       {
	      printf("��������Ϊ%d\n",list->data);
          list=list->next;
        }
        printf("\n");
   }
	 
}

//����б��ͷ��ڴ�ռ�
void clearlist(p *list)  //void clearlist(p list)�����ʵ��list���Ұָ�룬��Ϊfree�����ͷ���listָ���
{   p p1;                //�ڴ�ռ䣬ʵ��list��ֵ��Ȼ��ԭ����ֵ��Ҳ������Ȼָ��ԭ���Ľڵ㣬ʵ��listָ��������е����ݱ�����������
	if(isempty(*list))
       printf("���������.");
   else
   {   while(!isempty(*list))
       {
		   p1=(*list)->next;//������һ�ڵ��ַ
		   free(*list);
		   *list=p1;  //��ͷ����
        }
   }
	printf("���������.\n");
	//return list;
}

//����������
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
	  // printf("������Ϊ%d",i);
       return i;
   }
}

//���ҵ�k���ڵ㣬������ֵ��������Χ����NULL
p findnodelist(p list,int k)
{   int i,j;
 	if(isempty(list))
		 printf("����Ϊ��.\n");
    else
     { 
		 if(isempty(list)==0&&(j=lengthlist(list))<k)
	      {
		     printf("����������,����С��������%d��ֵ\n",j);
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

//����Ԫ��X
void finddatalist(p list,int x)
{	int i=0,k,m;
	int *j;  //int��̬������X��ַ
	k=lengthlist(list);
	j=(int *)malloc(k*sizeof(int));  //��̬�������鳤��
	if(isempty(list))
		printf("����Ϊ��.\n");
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
		printf("û���ҵ�Ԫ��%d",x);
	else
		{
			printf("�ҵ�%d��%d,",i,x);
			for(m=1;m<=i;m++)
				printf("��%d��,��ַ��%d",m,j[m-1]);
		}
}

//����X���ڵ��ֵ��ΪK���ɹ�����1�����򷵻�0
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

//���ͷ����Ԫ��K
void inserttohead(p *list,int k)
{   p temp;
	temp=(p)malloc(sizeof(Node));
	if(temp==NULL)
		{
			printf("�����ڴ�ʧ��.");
			exit(0);
		}
	temp->data=k;
	temp->next=*list;
	*list=temp;   
}
/*int  inserttohead(p * list,int k)
{   //������Ϊֵ���ݣ�����p list���ββ��ܸı�ʵ����list��ֵ��ʵ����Ȼָ��ԭ��ͷ
	p temp;
	temp=(p)malloc(sizeof(Node));
	if(temp==NULL)
		{
			printf("�����ڴ�ʧ��.");
			exit(0);
		}
	temp->data=k;
	temp->next=*list;
	*list=temp;   
	return 1; 
}*/

//�Ƶ���β
p gotoend(p list)
{
	while(!isend(list))
		list=list->next;
	return list;
}
//���β����Ԫ��K
void inserttoend(p list,int k)
{
	p temp;
	temp=(p)malloc(sizeof(Node));//�洢�½ڵ�
	if(temp==NULL)
		{
			printf("�����ڴ�ռ�ʧ��.");
	        exit(0);
		}
	temp->data=k;
	temp->next=NULL;
	list=gotoend(list); //�Ƶ���β
	list->next=temp;
	//return 1;
}

//���������е�����Ԫ��
void exdata(p p1,p p2)
{
	int temp;
	temp=p1->data;
	p1->data=p2->data;
	p2->data=temp;
}
//������������
void sortasc(p list)
{
	int i,j;
	p listnext,head;
	for(i=0;i<lengthlist(list)-1;i++)  //ð������
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

//����������
void sortdesc(p list)
{
	int i,j;
	p listnext,head;
	for(i=0;i<lengthlist(list)-1;i++)     //ð������
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
//�Ƚ������е�X��Ԫ����Ԫ��K�Ĵ�С�����ڷ���1��С�ڷ���0
int cmpdata(p list,int x,int k)
{   //printf("findnodelist(list,x)->data=%d",findnodelist(list,x)->data);
	return ((findnodelist(list,x)->data)>k)?1:0;
}


//�ڵ�X���ڵ�ǰ������Ԫ��K
void insertpre(p list,int x,int k)
{
	p temp;
	temp=(p)malloc(sizeof(Node));
	temp->data=k;
	temp->next=findnodelist(list,x);
	findnodelist(list,x-1)->next=temp;
}

//�ڵ�X���ڵ�󷽲���Ԫ��K
void insertnext(p list,int x,int k)
{
	p temp;
	temp=(p)malloc(sizeof(Node));
	temp->data=k;
	temp->next=findnodelist(list,x+1);
	findnodelist(list,x)->next=temp;
}
//�������������Ԫ��K����Ȼ����
void adddata(p *list,int k)
{   int high=lengthlist(*list);
	int mid,low=1; 
	if(isempty(*list))
		{
			printf("����Ϊ��");
			exit(0);
		}
	mid=(low+high)/2;
	while(low<=high)  //���ַ����Ҳ����
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
		inserttohead(list,k); //�����ͷ
	else if(cmpdata(*list,mid,k))
		insertpre(*list,mid,k); //midǰ��
	else if(cmpdata(*list,mid,k)==0&&low<high+1)
		insertnext(*list,mid,k);   //mid��
	else if(low==high+1)
		inserttoend(*list,k); //�����β
	else 
		printf("Error.\n");
}

//ɾ����ͷ�ڵ�
void deletehead(p *list)
{
	p temp;
	temp=(*list)->next;
	free(*list);
	*list=temp;
}

//ɾ����β�ڵ�
void deleteend(p list)
{
	int i=lengthlist(list);
	p temp=findnodelist(list,i);
	findnodelist(list,i-1)->next=NULL;
	free(temp);
	//free(findnodelist(list,i));
}

//����Ԫ��K������λ��
p finddata(p list,int k)
{
	while(list!=NULL&&list->data!=k)
		list=list->next;
	return list;
}

//��������ɾ��Ԫ��K
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