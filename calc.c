#include "calc.h"

LINK add(LINK a, LINK b);
LINK minus(LINK a, LINK b);
LINK multiply(LINK a, LINK b);
LINK calc(LINK expr);

int check(LINK expr){
	return 1;
}
LINK calc(LINK expr)
{
	//재원이형 seccalc.c 
	return expr;
}

int main(int argc, char* argv[]){
	//1.    파일 입력받아서 연결리스트 저장받기
	char* ch = (char*)malloc(sizeof(char));
	LINK expr, temp;
	FILE *pFile = NULL;
	pFile = fopen(argv[1], "r");
	if(pFile != NULL)
	{
		*ch = fgetc(pFile);
		expr = string_to_list(ch);
		while(EOF != (*ch = fgetc(pFile))) {
			temp = string_to_list(ch);
			concatenate(expr,temp);
		}
	}
	free(temp);
	free(ch);
	fclose(pFile);
	//       2.메시지 출력하기
	printf("====== Welcome to infinite calculator! ======\n");
	printf("Enter the expression in infix notation.\n");
	printf("Input : ");
	print_list(expr);
	printf("\n");
	//       3.중위표기식인지 확인하기
	if (check(expr))
	{
		//       4.중위표기식 다듬기 (0 추가 등)
		//expr = change(expr);
		//       5.중위표기식을 후위표기식으로 변환하기
		//expr = postfix(expr);
		//       6.후위표기식을 계산하기
		//expr = calc(expr);            
		//       7.결과 출력하기
		printf("Result : ");
		print_list(expr);
	}
	free(expr);
	return 0;
}

