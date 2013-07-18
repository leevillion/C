#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

//初始化
void initheap(heap curheap)
{
	curheap->capacity=MAXSIZE;
	curheap->size=0;
	curheap->element=(int *)malloc(sizeof(int)*(MAXSIZE+1);
	if(curheap->element==NULL)
		printf("ERROR!\n");
	curheap->element[0]=MINIMUM;
}

//添加
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
	for(i=++curheap->size;curheap->element[i/2]>num;i/=2)  //比较与父节点的大小
		curheap->element[i]=curheap->element[i/2];
	curheap->element[i]=num;
}

//删除最小单元
int deletemin(heap curheap)
{
	int i,temp,lastelement;
	if(curheap->size==0)
		printf("Empty!\n");
	lastelement=curheap->element[curheap->size--]; //删除元素，size减一
	for(i=1;i*2<=curheap->size;i=temp)
	{
		temp=i*2;
		if(temp!=curheap->size&&curheap->element[temp+1]<curheap->element[temp]) //比较左右节点大小
			temp++;
		if(lastelement>curheap->element[temp])  //比较底层单元与最后一个元素的大小
			curheap->element[i]=curheap->element[temp];
		else
			break;
	}
	curheap->element[i]=lastelement;
	return curheap->element[1];
}