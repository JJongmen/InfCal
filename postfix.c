#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calc.h" 

char *postfix(char *infix)
{
	char *str;
	str = (char *) malloc(2*sizeof(char)*strlen(infix)+1);
	memset(str, 0, 2*sizeof(char)*strlen(infix)+1);
	printf("str:%s\n", str);
	struct node* head = NULL; //stack <char> operator;
	char* temp;
	temp = (char *) malloc(sizeof(char));
	//char space = ' ';
	char* space = " ";
	int count = 1;

	//push(&top, 'C');
	while (*infix != '\0') {
			printf("infix[%d]:%c\n",count,*infix);
		if (97 <= *infix && *infix <= 122) {
			strncat(str, infix, 1);
			strncat(str, space, 1);
		}
		else {
			if (*infix == '+' || *infix == '-') {
				if (top(head) == '+' || empty(head) || top(head) == '(') push(&head, *infix);
				else if (top(head) == '-') {
					*temp = top(head);
					pop(&head);
					strncat(str,temp,1);
					strncat(str,space,1);
					push(&head, *infix);
				}
				else if (top(head) == '*') {
					while (top(head) == '*') {
						*temp = top(head);
						pop(&head);
						strncat(str,temp,1);
						strncat(str,space,1);
					}
					push(&head, *infix);
				}
			}
			else if (*infix == '*') push(&head, *infix);
			else if (*infix == '(') push(&head, *infix);
			else if (*infix == ')') {
				while (top(head) != '(') {
					*temp = top(head);
					pop(&head);
					strncat(str,temp,1);
					strncat(str,space,1);

				}
				pop(&head);
			}
		}
		count++;
		infix++;
		display(head);
	}
	while (!empty(head)) {
		*temp = top(head);
		pop(&head);
		strncat(str,temp,1);
		strncat(str,space,1);
		printf("%s\n", str);
	}
	//free(str);
	return str;
}


int main(int argc, char* argv[]) {
	char* result;
	printf("%s\n", result = postfix(argv[1]));
	free(result);
	return 0;
}
/*
int main(void) {
	char* result;
	printf("%s\n", result = postfix("a-(b+c)"));
	free(result);
	return 0;
}
*/
