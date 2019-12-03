#include<stdio.h>
#include<stdlib.h>
#inlcude "calc.h"
char *seccalc(char *str){
	struct node* head = NULL;
	char* front;
	char* rear;
	char final;
	front = (char*) malloc(sizeof(char));
	rear = (char*) malloc(sizeof(char));
	while (*str != '\0'){
		printf("str[%d]:%c\n",count,*str);
		if (97 <= *str && *str <= 122){
			push(&head, *str);
		}
		else if( *str = ' ')continue;
		else if ( *str = '+' || *str = '-' || *str = '*'){
			front = top(head);
			pop(&head);
			rear = top(&head);
			pop(&head);
			if( *str = '+'){
				push(&head, *ans);
			}
			else if( *str = '-'){
				push(&head, *ans);
			}
			else if( *str = '*'){
				push(&head, *ans);
			}
		}
	}
	free(front);
	free(rear);
	final = pop(&head);
	return final;
}
			

int main(void){


}
