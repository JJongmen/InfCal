#include "calc.c"

pList add(pList a, pList b) {
	pList ans = makeList();
	insertBack(ans,makeNode('1'));
	return ans;
}
pList minus(pList a, pList b) {
	pList ans = makeList();
	insertBack(ans,makeNode('1'));
	return ans;
}
pList multiply(pList a, pList b) {
	pList ans = makeList();
	insertBack(ans,makeNode('1'));
	return ans;
}
pList seccalc(pList expr) {
	pNode curr = expr->head;
	struct nodeL* head = NULL; //make stack
	int word = 0;
	pList tempList = makeList();
	while(curr != NULL) {
		if((isdigit(curr->data) || curr->data == '.') && word == 0) {
			pList tempList = makeList();
			insertBack(tempList, makeNode(curr->data));
			word = 1;
		}
		else if((isdigit(curr->data) || curr->data == '.') && word == 1) {
			insertBack(tempList, makeNode(curr->data));
		}
		else if(isspace(curr->data)) {
			pList pushList = tempList;
			pushL(&head,pushList);//stack push
			word = 0;
			freeList(tempList);
			free(tempList);
		}
		else if(curr->data == '+') {
			pList a = popL(&head); //pop
			pList b = popL(&head); //pop
			pList temp = add(a,b);
			pushL(&head, temp);//push temp
		}
		else if(curr->data == '-') {
			pList b = popL(&head); //pop
			pList a = popL(&head); //pop
			pList temp = minus(a,b);
			pushL(&head, temp);//push temp
		}
		else if(curr->data == '*') {
			pList a = popL(&head); //pop
			pList b = popL(&head); //pop
			pList temp = multiply(a,b);
			pushL(&head, temp); //push temp
		}
		curr = curr->next;
	}
	pList ans = topL(head); //stack top
	return ans;
}
