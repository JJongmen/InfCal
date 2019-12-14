#include "calc.h"

pList postfix(pList infix)
{
	pList list = makeList(); 
	struct node* head = NULL; //stack <char> operator;
	char temp;
	pNode start = infix->head;

	//push(&top, 'C');
	while (start != NULL) {
		if (isdigit(start->data) || start->data == '.') {
			insertBack(list,makeNode(start->data));
		}
		else if (start->data == '+' || start->data == '-' || start->data == '*'
				|| start->data == '(' || start->data == ')' )
		{
			insertBack(list,makeNode(' '));
			if (start->data == '+' || start->data == '-') {
				if (top(head) == '+' || empty(head) || top(head) == '(') push(&head, start->data);
				else if (top(head) == '-') {
					temp = top(head);
					pop(&head);
					insertBack(list,makeNode(temp));
					insertBack(list,makeNode(' '));
					push(&head, start->data);
				}
				else if (top(head) == '*') {
					while (top(head) == '*') {
						temp = top(head);
						pop(&head);
						insertBack(list,makeNode(temp));
						insertBack(list,makeNode(' '));
					}
					push(&head, start->data);
				}
			}
			else if (start->data == '*') push(&head, start->data);
			else if (start->data == '(') push(&head, start->data);
			else if (start->data == ')') {
				while (top(head) != '(') {
					temp = top(head);
					pop(&head);
					insertBack(list,makeNode(temp));
					insertBack(list,makeNode(' '));

				}
				pop(&head);
			}
		}
		start = start->next;
		display(head);
	}
	insertBack(list,makeNode(' '));
	while (!empty(head)) {
		temp = top(head);
		pop(&head);
		insertBack(list,makeNode(temp));
		insertBack(list,makeNode(' '));
	}
	printf("escape!!\n");
	return list;
}

int main(void) {
	pList infix = makeList();
	char expr[] = "123+41232";
	printf("expr : %s\n",expr);
	for (int i = 0; i<strlen(expr); i++) {
		insertBack(infix,makeNode(expr[i]));
	}
	printList(infix);
	printList(postfix(infix));
	freeList(infix);
	free(infix);
	return 0;
}
