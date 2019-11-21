#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

char *postfix(char *infix);
struct node;
struct node* new_node(int data);
int empty(struct node* head);
void push(struct node** head, int data);
int pop(struct node** head);
int top(struct node* head);
void display(struct node* head);
