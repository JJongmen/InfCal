#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	char data;
	struct _node *next;
}Node, *pNode;

typedef struct _list {
	int count;  // 노드의 갯수를 저장한다.
	pNode head; // 첫번째 노드를 가리킨다.
	pNode tail; // 마지막 노드를 가리킨다.
}List, *pList;

//Linked List를 만들기 위한 함수. 
pList makeList() {
	pList list = (pList)malloc(sizeof(List));
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

//Node를 만드는 함수. Data를 입력 받아서 저장하고, 만든 node를 반환한다.
pNode makeNode(char data) {
	pNode node = (pNode)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//집어 넣을 노드인 N을 List L의 가장 처음, 즉 head에 집어 넣는 함수.
void insertFront(pList L, pNode N) {
	//이곳에 정답을 쓰시오!
	if(L->head == NULL) {
		L->head = N;
		L->tail = N;
		N->next = NULL;
	}
	else {
		N->next = L->head;
		L->head = N;
	}
	(L->count)++;
}
void insertMid(pList L, pNode F, pNode B) {
	pNode tmp = L->head;
	while(tmp != NULL) {
		if (tmp == F) {
			if(L->tail == F) {
				F->next = B;
				B->next = NULL;
				L->tail = B;
			}
			else {
				B->next = F->next;
				tmp->next = B;
			}
			break;
		}
		tmp = tmp->next;
	}
	(L->count)++;
}

int isNode(pList L, char data) {
	pNode tmp = L->head;
	while(tmp != NULL) {
		if (tmp->data == data) {
			free(tmp);
			return 1;
		}
	}
	free(tmp);
	return 0;
}

pNode searchNode(pList L, char data) {
	pNode tmp = L->head;
	while(tmp != NULL) {
		if(tmp->data == data) {
			return tmp;
		}
	}
}

void insertBack(pList L, pNode N) {
	if(L->head == NULL) {
		L->head = N;
		L->tail = N;
		N->next = NULL;
	}
	else {
		N->next = NULL;
		L->tail->next = N;
		L->tail = N;
	}
	(L->count)++;
}

void printList(pList L) {
	pNode tmp = L->head;
	for (size_t i = 1; i < L->count; i++)
	{
		printf("%c -> ", tmp->data);
		tmp = tmp->next;
	}
	printf("%d \n", tmp->data);
	//printf("Head : %d, Tail : %d", L->head->data, L->tail->data);
}

void deleteData(pList L, int data) {
	//이곳에 정답을 쓰시오!
	pNode tmp = L->head;
	pNode prev = NULL;
	for (size_t i = 0; i < L->count; i++) {
		if(tmp->data == data) {
			if(tmp == L->head) {
				L->head = tmp->next;
				free(tmp);
				pNode tmp = prev->next;
			}
			else if(tmp == L->tail) {
				L->tail = NULL;
				prev->next = NULL;
				free(tmp);
				pNode tmp = prev->next;
			}
			else {
				prev->next = tmp->next;
				free(tmp);
				pNode tmp = prev->next;
			}
			(L->count)--;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	free(prev);
}

void freeList(pList L) {
	pNode tmp = L->head;
	pNode prev = NULL;
	for (size_t i = 0; i < L->count; i++)
	{
		prev = tmp;			
		tmp = tmp->next;	
		free(prev);			
	}
}
/*
void main() {
	pList list = makeList();

	insertFront(list, makeNode(9));
	insertFront(list, makeNode(7));
	insertFront(list, makeNode(3));
	insertFront(list, makeNode(1));
	printList(list);

	freeList(list);
	free(list);
}
*/
