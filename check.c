#include <stdio.h>
#include <string.h>
#include "calc.h"

int check(pList expr){
	int dot = 0;
	int space = 0;
	int operator = 0;
	int left = 0;
	int right = 0;
	int count = 0;
	printList(expr);
	pNode curr = expr->head;
	if (curr->data == '.' || curr->data == ' ' || curr->data == '*') return 0; 
	printf("1\n");
	while(curr != NULL){
		count++;
		printf("char[%d] : [%c]   ----------------------------\n", count,curr->data);
		if (!(isdigit(curr->data) || curr->data == ' ' || curr->data == '.' || curr->data == '(' || curr->data == ')' || curr->data == '+' || curr->data == '-' || curr->data == '*')) return 0;
		printf("2\n");
		if (curr->data == '.'){ // .. , . 
			dot++;
			if (curr->next == NULL || !isdigit(curr->next->data)) return 0;
			if (dot >= 2) return 0;
		}
		printf("3\n");
		if (curr->data == ' '){  //    ,  (
			dot = 0;
			space++;
			if ((curr->next->data == ')' || curr->next->data == '.' ) && curr->next != NULL) return 0;
			if (space >= 2) return 0;
		}
		printf("4\n");
		if (isdigit(curr->data) ){ //123 ( , 123 123
			if (curr->next != NULL && curr->next->data == ' '){
				if ((curr->next->next->data == '(' || curr->next->next->data == ')' || isdigit(curr->next->next->data)) && curr->next->next != NULL) return 0;
			}
		}
		if (curr->data == '0')
			if (curr->next != NULL && curr->next->data != '.') return 0;
		printf("5\n");
		if (curr->data == '('){
			left++;
		}
		if (curr->data == ')'){
			right++;
			if (right >left) return 0;
		}
		printf("6\n");
		if (curr->data == '+' || curr->data == '-' || curr->data == '*'){
			operator++;
			if (operator >= 2) return 0;
			if (curr->next != NULL && curr->next->data == ' '){
				if ((curr->next->next->data == '+' || curr->next->next->data == '-' || curr->next->next->data == '*') && curr->next->next != NULL) return 0;
			}
		}
		if (curr->data == '(')
			if (curr->next != NULL && curr->next->data == '*') return 0;
		printf("7\n");
		if (curr->data != ' ') space = 0;
		if (!(curr->data == '+' || curr->data == '-' || curr->data == '*')) operator = 0;
    	curr = curr->next;
   }
	if (left != right) return 0;
	else return 1;
}

int main(void) {
	pList list = makeList();
	char expr[] = "1 - (*6 + 1)";
	printf("input : %s\n", expr);
	for (int i = 0; i<strlen(expr); i++) {
		insertBack(list, makeNode(expr[i]));
	}
	printList(list);
	printf("result : %d\n", check(list));
	return 0;
}
