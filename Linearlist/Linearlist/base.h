#ifndef BASE_H_
#define BASE_H_

struct Node;
typedef struct Node * p;
struct Node{int data;p next;}Node;

void initializelist(p *head);
int isempty(p list);
int isend(p node);
p createlist(p list);
void printlist(p list);
void clearlist(p *list);
int lengthlist(p list);
p findnodelist(p list,int k);
void finddatalist(p list,int x);
int modifynode(p list,int x,int k);
void inserttohead(p *list,int k);
p gotoend(p list);
void inserttoend(p list,int k);
void exdata(p p1,p p2);
void sortasc(p list);
void sortdesc(p list);
int cmpdata(p list,int x,int k);
void insertpre(p list,int x,int k);
void insertnext(p list,int x,int k);
void adddata(p *list,int k);
void deletehead(p *list);
void deleteend(p list);
p finddata(p list,int k);
void delededata(p list,int k);


void printui(void);
void fnl(p list);
void fdl(p list);
void mn(p list);
void inh(p *list);
void ine(p list);
void cmpd(p list);
void inmd(p list);
void ad(p *list);
void dd(p *list);
#endif