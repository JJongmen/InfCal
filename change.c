#include "calc.h"

void change(pList expr) {
	pNode curr = expr->head;
	// -1   3+(-1)
	int count = 1;
	while (curr != NULL) {
		if(curr == expr->head && ( curr->data == '-' || curr->data == '+')) {
			insertFront(expr,makeNode('0'));
		}
		else if(curr->next != NULL && curr->data=='(' && (curr->next->data=='-' || curr->next->data == '+')) {
			insertMid(expr,count+1,makeNode('0'));
		}
		curr = curr->next;
		count++;
	}
}
