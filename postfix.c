#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calc.h" 

char *postfix(char *infix)
{
	char *str;
	str = (char *) malloc(sizeof(char)*strlen(infix)+1);
	memset(str, 0, sizeof(char)*strlen(infix)+1);
	struct node* head = NULL; //stack <char> operator;
	char temp;
	int count = 1;

	//push(&top, 'C');
	while (*infix != '\0') {
			printf("infix[%d]:%c\n",count,*infix);
		if (97 <= *infix && *infix <= 122) {
			strncat(str, infix, 1);
			printf("strncat:%s\n",str);
		}
		else {
			if (*infix == '+' || *infix == '-') {
				if (top(head) == '+' || top(head) == '-' || empty(head) || top(head) == '(') push(&head, *infix);
				else if (top(head) == '*' || top(head) == '/') {
					temp = top(head);
					pop(&head);
					strcat(str,&temp);
					push(&head, *infix);
				}
			}
			else if (*infix == '*' || *infix == '/') push(&head, *infix);
			else if (*infix == '(') push(&head, *infix);
			else if (*infix == ')') {
				while (top(head) != '(') {
					temp = top(head);
					pop(&head);
					strcat(str,&temp);
				}
				pop(&head);
			}
		}
		count++;
		infix++;
		display(head);
	}
	while (!empty(head)) {
		temp = top(head);
		pop(&head);
		strcat(str,&temp);
		printf("%s\n", str);
	}
	//free(str);
	return str;
}

int main(void) {
	char* result;
	printf("%s\n", result = postfix("a+b*c"));
	free(result);
	return 0;
}
