#include "calc.h"

int main(void){
	int ch;
	ch = getc(stdin);
	while(1){
		if (ch == EOF) break;
		printf("ch: %c\n", ch);
		ch = getc(stdin);
	}
	return 0;
}
