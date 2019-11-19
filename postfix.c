#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *postfix(char *infix)
{
	char *str;
	str = malloc(sizeof(char)*strlen(infix));
	stack <char> operator;
	for(infix; infix != '\0'; infix++) {
		if (97 <= *infix <= 122) strncat(str, infix, 1);
		else {
			if (*infix == '+' || *infix == '-') {
				if (operator.top() == '+' || operator.top() == '-') operator.push(*infix);
				else if (operator.top()  == '*' || operator.top() == '/') {
					temp = operator.top();
					operator.pop();
					str += temp;
					operator.push(*infix);
				}
			else if (*infix == '*' || *infix == '/') operator.push(*infix);
			else if (*infix == '(') operator.push(*infix);
			else if (*infix == ')') {
				while (operator.top() != '(') {
					temp = operator.top();
					operator.pop();
					str += temp;
				}
				operator.pop();
			}
	}
	free(str);
	return str;
}
