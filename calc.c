#include "calc.h"

int main(int argc, char* argv[]){
	//1.    파일 입력받아서 연결리스트 저장받기
	char ch;
	pList expr = makeList();
	FILE *pFile = NULL;
	pFile = fopen(argv[1], "r");
	if(pFile != NULL)
	{
		ch = fgetc(pFile);
		insertBack(expr,makeNode(ch));
		printf("%d\n",ch);
		while(EOF != (ch = fgetc(pFile)) && ch != 10) {
			insertBack(expr,makeNode(ch));
		}
	}
	fclose(pFile);
	//       2.메시지 출력하기
	printf("====== Welcome to infinite calculator! ======\n");
	printf("Enter the expression in infix notation.\n");
	printf("Input : ");
	printList(expr);
	printf("\n");
	//       3.중위표기식인지 확인하기
	if (check(expr))
	{
		//       4.중위표기식 다듬기 (0 추가 등)
		change(expr);
		//       5.중위표기식을 후위표기식으로 변환하기
		pList pos = postfix(expr);
		//       6.후위표기식을 계산하기
		pList answer = seccalc(pos);            
		//       7.결과 출력하기
		printf("Result : ");
		printList(answer);
	}
	freeList(expr);
	free(expr);
	return 0;
}
