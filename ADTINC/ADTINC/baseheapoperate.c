#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//��ʼ��
void initheap(heap curheap)
{
	curheap->capacity=MAXSIZE;
	curheap->size=0;
	curheap->element=(int *)malloc(sizeof(int)*(MAXSIZE+1);
	if(curheap->element==NULL)
		printf("ERROR!\n");
	curheap->element[0]=MINIMUM;
}

//���
void addheap(heap curheap,int num)
{
	int i;
	//curheap->element=(int *)malloc(sizeof(int)*MAXSIZE);
	//if(curheap->element==NULL)
	//	printf("ERROR!\n");
	if(curheap->size==MAXSIZE+1)
	{
		printf("FULL!\n");
		return;
	}
	if(curheap->size==0)
		curheap->element[++curheap->size]=num;
	for(i=++curheap->size;curheap->element[i/2]>num;i/=2)  //�Ƚ��븸�ڵ�Ĵ�С
		curheap->element[i]=curheap->element[i/2];
	curheap->element[i]=num;
}

//ɾ����С��Ԫ
int deletemin(heap curheap)
{
	int i,temp,lastelement;
	if(curheap->size==0)
		printf("Empty!\n");
	lastelement=curheap->element[curheap->size--]; //ɾ��Ԫ�أ�size��һ
	for(i=1;i*2<=curheap->size;i=temp)
	{
		temp=i*2;
		if(temp!=curheap->size&&curheap->element[temp+1]<curheap->element[temp]) //�Ƚ����ҽڵ��С
			temp++;
		if(lastelement>curheap->element[temp])  //�Ƚϵײ㵥Ԫ�����һ��Ԫ�صĴ�С
			curheap->element[i]=curheap->element[temp];
		else
			break;
	}
	curheap->element[i]=lastelement;
	return curheap->element[1];
}