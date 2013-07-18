#ifndef _BINARYFINDTREE_H
#define _BINARYFINDTREE_H

struct Node;
typedef struct Node * node;
typedef struct Node * tree;
struct Node{int element;node left;node right;};


void inittree(tree *t);
int toright(tree t,int num);
int toleft(tree t,int num);
node addtree(tree t,int num);
node findtree(tree t,int num);
node findmin(tree t);
node findmax(tree t);
node deletetree(tree t,int num);





#endif