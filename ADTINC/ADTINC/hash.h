#ifndef _HASH_H
#define _HASH_H

struct ListNode;
typedef struct ListNode * ln;
struct HashList;
typedef struct HashList * hl;
struct ListNode{int element;ln next;};
struct HashList{int size;ln *pl};//plΪָ��ָ���ָ�룬�������Ϊָ�����飬��size��Ҫ������ʱָ���ʲ���д��ln pl[size]��ʽ


int HashtoList(int num,int size);
hl inithashlist(int tablesize);
ln findhashnode(int key,hl hashlist);
void addhashnode(int key,hl hashlist);


#endif