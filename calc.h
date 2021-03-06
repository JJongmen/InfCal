#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

typedef struct _node {
	char data;
	struct _node *next;
}Node, *pNode;

typedef struct _list {
	int count;
	pNode head;
	pNode tail;
}List, *pList;

pList makeList(void);
pNode makeNode(char);
void insertFront(pList, pNode);
void insertBack(pList, pNode);
void printList(pList);
void deleteData(pList,char);
void freeList(pList);
void deleteHead(pList);
void removeSpace(pList);
void insertMid(pList,int,pNode);
int isNode(pList,char);
int searchNode(pList,char);
int compareList(pList,pList);
pList postfix(pList expr);

struct node;
struct node* new_node(int data);
int empty(struct node* head);
void push(struct node** head, int data);
int pop(struct node** head);
int top(struct node* head);
void display(struct node* head);

int check(pList);
pList seccalc(pList);
void change(pList);

struct nodeL {
	pList data;
	struct nodeL* next;
};
struct nodeL* new_nodeL(pList);
int emptyL(struct nodeL*);
void pushL(struct nodeL**,pList);
pList popL(struct nodeL**);
pList topL(struct nodeL*);
void displayL(struct nodeL*);

pList add(pList,pList);
pList minus(pList,pList);
pList multiply(pList,pList);
