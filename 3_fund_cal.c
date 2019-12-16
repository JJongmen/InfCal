#include "calc.h"

/*

add( +a , +b)
add( +a,  -b )  => minus( +a , +b )
add( -a , +b )  => minus( +b , +a )
add( -a , -b )  => - add( +a , +b )



minus( +a , +b )
minus( -a , +b ) => - add ( +a , +b )
minus( +a , -b ) => add ( +a , +b )
minus( -a , -b ) => minus( -a , +b ) => - add ( +b , +a )
*/
pList minus(pList a, pList b);

pList add(pList a , pList b ) {

	int one,two;

	one = (a-> head -> data != '-'?1:0);

	two = (b-> head -> data != '-'?1:0);

	if ( one == 1 && two == 1){
		if (isNode(a, '.') == 0){
			insertBack(a, makeNode('.'));
		}
		else if (isNode(b, '.') == 0){
			insertBack(b, makeNode('.'));
		}
	// 자연수일 경우 . 추가
		int a_count = a->count;
		int b_count = b->count;
   		int a_point = searchNode(a, '.');
   		int b_point = searchNode(b, '.');
   		int a_int_len = a_point - 1;
   		int b_int_len = b_point - 1;
   		int a_dec_len = a_count - a_point;
   		int b_dec_len = b_count - b_point;
   		while ( a_int_len != b_int_len) // int 자리수 맞추기
		{
	   		if (a_int_len > b_int_len) {
		   		insertFront(b, makeNode('0'));
		   		b_int_len++;
			}
	   		else if (a_int_len < b_int_len) {
		   		insertFront(a, makeNode('0'));
		   		a_int_len++;
			}
		}
   		while (a_dec_len != b_dec_len) // dec 자리수 맞추기
		{
	   		if (a_dec_len > b_dec_len) {
		   		insertBack(b, makeNode('0'));
		   		b_dec_len++;
			}
	   		else if (a_dec_len < b_dec_len) {
		   		insertBack(a, makeNode('0'));
		   		a_dec_len++;
			}
		}
		 // 999.9990 + 009.9999
		pList pst = makeList();
		pList answer = makeList();
		// 123.40   001.2
		while (a->head != NULL){
			if ((a->head->data - '0' + b->head->data - '0') > 9) {
				insertBack(pst, makeNode('1'));
				insertBack(answer, makeNode(a->head->data - '0' + b->head->data - '0' -10 + '0'));
				deleteHead(a);
				deleteHead(b);
			}
			else if ((a->head->data - '0' + b->head->data - '0')  < 10 && a->head->data - '0' + b->head->data - '0' > 0) {
				insertBack(pst , makeNode('0'));
				insertBack(answer, makeNode(a->head->data -'0' + b->head->data-'0'+'0'));
				deleteHead(a);
				deleteHead(b);
			}
			else if ((a->head->data - '0' + b->head->data -'0') == 0){
				insertBack(pst, makeNode('0'));
				insertBack(answer, makeNode('0'));
				deleteHead(a);
				deleteHead(b);
			}
			else if ((a->head->data - '0' +b->head->data - '0') == 10){
				insertBack(pst, makeNode('1'));
				insertBack(answer, makeNode('0'));
				deleteHead(a);
				deleteHead(b);
			}
			else if (a->head->data == '.' && b->head->data  == '.') {
				insertBack(answer, makeNode('.'));
				deleteHead(a);
				deleteHead(b);
			}
		} 
		insertBack(pst, makeNode('0'));
		int answer_Pointer = searchNode(answer,'.');
		insertMid(pst, answer_Pointer, makeNode('.'));
		// . 삽입 clea	
		printList(answer);
		printList(pst);
		if (isNode(pst, '1') == 0) {
			return answer;
		}
		else if (isNode(pst, '1') == 1) {
			return add(answer, pst);
		}
	}

	else if ( one == 1 && two == 0) { // add( a,-b )
		deleteData(b,'-');
		return minus(a,b);
	}
	else if ( one == 0 && two == 1) { // add(-a,b)
		deleteData(a, '-');
		printf("-----------------\n");
		return minus(b,a);
	}

	else if ( one == 0 && two == 0) { // add(-a,-b)
		deleteHead(a);
		deleteHead(b);
		pList ans = add(a,b);
		insertFront(ans,makeNode('-'));
		return ans;	
	}
}
pList minus(pList a , pList b ) {

	int one,two;
	one = (a-> head -> data != '-'?1:0);
	two = (b-> head -> data != '-'?1:0);
	char a_head = (a -> head -> data);
	char b_head = (b -> head -> data);

	if ( one == 1 && two == 1) {
		if (searchNode(a, '.') == 0){
			insertBack(a, makeNode('.'));
		}
		else if(searchNode(b, '.') == 0){
			insertBack(b, makeNode('.'));
		}
		// 자연수일 경우 뒤에 . 추가
		int a_count = a->count;
		int b_count = b->count;
		int a_point = searchNode(a, '.');
		int b_point = searchNode(b, '.');
		int a_int_len = a_point -1;
		int b_int_len = b_point -1;
		int a_dec_len = a_count - a_point;
		int b_dec_len = b_count - b_point;
		while (a_int_len = b_int_len) {
			if (a_int_len > b_int_len) {
				insertFront(b, makeNode('0'));
				b_int_len++;
			}	
			else if (a_int_len < b_int_len) {
				insertFront(a, makeNode('0'));
				a_int_len++;
			}
		}
		while (a_dec_len = b_dec_len) {
			if (a_dec_len > b_dec_len) {
				insertBack(b, makeNode('0'));
				b_dec_len++;
			}
			else if (a_dec_len < b_dec_len) {
				insertBack(a, makeNode('0'));
				a_dec_len++;
			}
		}
		//999.9 - 009.9
		// a 와 b 중 누가 더 큰지 구별 해야함
			// head 에서 따와서 빼기
		pList pst = makeList();
		pList answer = makeList();
		while (a->head != NULL) {
			if (a->head->data - b->head->data < 0) {
				insertBack(pst,makeNode('1'));
				insertBack(answer, makeNode(b->head->data - a->head->data + '0'));
				deleteHead(a);
				deleteHead(b);
			}
			else if (a->head->data - b->head->data > 0) {
				insertBack(pst, makeNode('0'));
				insertBack(answer, makeNode(a->head->data - b->head->data +'0'));
				deleteHead(a);
				deleteHead(b);
			}
			else if (a->head->data && b->head->data =='.') {
				insertBack(answer, makeNode('.'));
				deleteHead(a);
				deleteHead(b);
			}
		}	
		insertBack(pst, makeNode('0'));
		int pst_Pointer = searchNode(answer, '.');
		insertMid(pst,pst_Pointer,makeNode('.'));
			// answer - 내림수 빼는 재귀 함수 호출
			// 내림수 에 1 없을때 그냥 값 도출
		if (isNode(pst, '1') == 0) {
			return answer;
		}
		else if (isNode(pst, '1') != 0) {
			return add(answer, pst);
		}
	}
	else if ( one == 1 && two == 0) { // minus( a,-b )
		deleteData(b, '-');
		return add(a, b);
	}		
	else if ( one == 0 && two == 1) { // minus(-a,b)
		deleteData(a, '-');
		pList ans = add(a,b);
		insertFront(ans,makeNode('-'));
		return ans;
	}
	else if ( one == 0 && two == 0) { // minus( -a , +b )
		deleteData(b, '-');
		return minus(a, b);
	}
}

int main(void) {
	char expr1[] = "-24.56";
	char expr2[] = "-129.999";
	pList a = makeList();
	pList b = makeList();
	for (int i = 0; i<strlen(expr1);i++) {
		insertBack(a,makeNode(expr1[i]));
	}
	for(int i = 0; i<strlen(expr2);i++) {
		insertBack(b,makeNode(expr2[i]));
	}
	printList(a);
	printList(b);
	pList ans = add(a,b);
	printList(ans);
	freeList(a);
	freeList(b);
	freeList(ans);
	free(a);
	free(b);
	free(ans);
	return 0;
}
