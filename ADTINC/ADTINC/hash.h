#ifndef _HASH_H
#define _HASH_H

struct ListNode;
typedef struct ListNode * ln;
struct HashList;
typedef struct HashList * hl;
struct ListNode{int element;ln next;};
struct HashList{int size;ln *pl};//pl为指向指针的指针，可以理解为指针数组，因size需要在运行时指定故不能写成ln pl[size]形式


int HashtoList(int num,int size);
hl inithashlist(int tablesize);
ln findhashnode(int key,hl hashlist);
void addhashnode(int key,hl hashlist);


#endif