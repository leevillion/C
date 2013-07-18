#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	stack s;
	int num;
	s=(stack)malloc(sizeof(struct Node));
	printf("创建栈:输入正整数\n");
	s=createstack();
	ptinfstack(s);
	push(10,s);
	ptinfstack(s);

	getchar();
	getchar();
	return 0;

}