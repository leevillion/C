#ifndef _STACK_H
#define _STACK_H

struct Node;
typedef struct Node * p;
typedef p stack;
struct Node{int element;p next;};

void initialization(stack s);
int isempty(stack s);
stack createstack(void);
void freestack(stack s);
//void makeempty(stack s);
void push(int i,stack s);
int top(stack s);
void pop(stack s);
void ptinfstack(stack s);



#endif