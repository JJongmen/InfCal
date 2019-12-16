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
	pNode curr = expr->head;
	if (curr->data == '.' || curr->data == ' ' || curr->data == '*') return 0; 
	while(curr != NULL){
		count++;
		if (!(isdigit(curr->data) || curr->data == ' ' || curr->data == '.' || curr->data == '(' || curr->data == ')' || curr->data == '+' || curr->data == '-' || curr->data == '*')) return 0;
		if (curr->data == '.'){ // .. , . 
			dot++;
			if (curr->next == NULL || !isdigit(curr->next->data)) return 0;
			if (dot >= 2) return 0;
		}
		if (curr->data == ' '){  //    ,  (
			dot = 0;
			space++;
			if ((curr->next->data == ')' || curr->next->data == '.' ) && curr->next != NULL) return 0;
			if (space >= 2) return 0;
		}
		if (isdigit(curr->data) ){ //123 ( , 123 123
			if (curr->next != NULL && curr->next->data == ' '){
				if ((curr->next->next->data == '(' || curr->next->next->data == ')' || isdigit(curr->next->next->data)) && curr->next->next != NULL) return 0;
			}
		}
		if (curr->data == '0'){
			if (curr->next != NULL && curr->next->data == '.'){
				if (curr->next->next != NULL && (!isdigit(curr->next->next->data))) return 0;
			}
		}
		if (curr->data == '('){
			dot = 0;
			left++;
		}
		if (curr->data == ')'){
			dot = 0;
			right++;
			if (right >left) return 0;
		}
		if (curr->data == '+' || curr->data == '-' || curr->data == '*'){
			operator++;
			dot = 0;
			if (operator >= 2) return 0;
			if (curr->next != NULL && curr->next->data == ' '){
				if ((curr->next->next->data == '+' || curr->next->next->data == '-' || curr->next->next->data == '*') && curr->next->next != NULL) return 0;
			}
		}
		if (curr->data == '(')
			if (curr->next != NULL && curr->next->data == '*') return 0;
		if (curr->data != ' ') space = 0;
		if (!(curr->data == '+' || curr->data == '-' || curr->data == '*')) operator = 0;
    	curr = curr->next;
   }
	if (left != right) return 0;
	else return 1;
}
/*
int main(void) {
	char expr[] = "120.123-10.12";
	pList list = makeList();
	for (int i =0; i<strlen(expr);i++) {
		insertBack(list, makeNode(expr[i]));
	}
	printf("%d \n",check(list));
	return 0;
}
*/
