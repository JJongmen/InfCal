#include "calc.h"

struct nodeL { 
	pList data; 
	struct nodeL* next; 
}; 

struct nodeL* new_nodeL(pList L) 
{ 
	struct nodeL* temp_node = (struct nodeL*)malloc(sizeof(struct nodeL)); 
	temp_node->data = L; 
	temp_node->next = NULL; 
	return temp_node; 
} 

int emptyL(struct nodeL* head) 
{ 
	if(!head){ 
		printf("stack is empty\n");
		return 1;
	}
	return 0; 
} 

void pushL(struct nodeL** head, pList L) 
{ 
	struct nodeL* temp_node = new_nodeL(L); 
	temp_node->next = *head; 
	*head = temp_node; 
	printf("PUSH: ");
	printList(L);
} 

pList popL(struct nodeL** head) 
{ 
	pList L = makeList();
	insertBack(L,makeNode('#'));
	if (emptyL(*head)){
		return L;
	}
	struct nodeL* temp = *head; 
	*head = (*head)->next; 
	pList element = temp->data; 
	free(temp); 

	printf("POP: ");
	printList(element);
	return element; 
} 

pList topL(struct nodeL* head) 
{ 
	pList L = makeList();
	insertBack(L, makeNode('#'));
	if(emptyL(head)) 
		return L;
	return head->data; 
}

void displayL(struct nodeL* head){

	if(emptyL(head)){
		return;
	}
	struct nodeL* cursor = NULL;
	cursor = head;

	printf("STACK:");
	while (cursor != NULL) {
		printList(cursor->data);
		cursor = cursor->next;
	}
	printf("\n");
	return;
}
/*
int main() 
{ 
	struct node* head = NULL; 

	push(&head, 10); 
	push(&head, 20); 
	push(&head, 30); 

	display(head);

	pop(&head); 

	display(head);

	printf("TOP: [%d]\n", top(head)); 
	
	display(head);

	pop(&head); 
	pop(&head); 
	pop(&head); 

	return 0; 
}
*/
/*
int main() {
	struct node* head = NULL;
	pList L = makeList();
	pList M = makeList();
	insertBack(L,makeNode('1'));
	insertBack(L,makeNode('2'));
	insertBack(M,makeNode('3'));
	pushL(&head, L);
	pushL(&head, M);
	displayL(head);
	popL(&head);
	displayL(head);
	popL(&head);
	return 0;
}
*/
