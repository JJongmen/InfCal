/*

add( +a , +b)
add( +a,  -b )  => minus( +a , +b )
add( -a , +b )  => minus( +b , +a )
add( -a , -b )  => - add( +a , +b )



minus( +a , +b )
minus( -a , +b ) => - add ( +a , +b )
minus( +a , -b ) => add9 +a , +b )
minus( -a , -b ) => minus( -a , +b ) => - add ( +b , +a )
*/

pList add (pList a , pList b ) {

int one,two;

one = (a-> head -> data != '-'?1:0);

two = (b-> head -> data != '-'?1:0);

a_head = (a -> head -> data)

b_head = (b -> head -> data)

if ( one == 1 && one == 1){
	if (a_count > b_count){
   		count = a_count;
   		a_point = searchNode(pList a, '.') 
   		b_point = searchNode(pList a, '.')
   		a_int_len = a_point - 1;
   		b_int_len = b_point - 1;
   		a_dec_len = b_count - a_point;
   		b_dec_len = b_count - b_point;
   		while ( a_int_len = b_int_len) // int 자리수 맞추기
		{
	   		if (a_int_len > b_int_len) {
		   		insertFront(pList b, makeNode('0'));
		   		b_int_len++;
			}
	   		else if (a_int_len < b_int_len) {
		   		insertFront(pList a, makeNode('0'));
		   		a_int_len++;
			}
		}
   		while (a_dec_len = b_dec_len) // dec 자리수 맞추기
		{
	   		if (a_dec_len > b_dec_len) {
		   		insertBack(pList b, makeNode('0'));
		   		b_dec_len++;
			}
	   		else if (a_dec_len < b_dec_len) {
		   		insertBack(pList a, makeNode('0'));
		   		a_dec_len++;
			}
		}
		// 함수로 만들거면 만들것 
		 // 999.9990 + 009.9999
		while (a_head = '\0'){
			if (a_head + b_head - 2 * '0' > 9) {
				pList pst = makeList();
				pList answer = makeList();
				insertBack(pList pst, makeNode('1'));
				insertBack(pList answer, makeNode(a_head + b_head - 2 * '0''));
				// head a b 제거
				}
			else if {
				insertBack(pList pst , makeNode('0'));
				insertBack(pList answer, makeNode(a_head + b_head));
				//head a b 제거
			}
			else if (a_head || b_head == '.') {
				insertBack(pList answer, makeNode('.'));
				//head a b 제거 
			}
		}
		if (pList pst-> head -> data == '0') {
			// 포인터 위치 그대로 . 삽입
		}
		else if (pList pst -> head -> data == '1') {
			// 포인터 위치 +1 후 . 삽입
		}
		if (searchNode(pList pst , '1') == 0) {
			//answer 값 연결리스트 에서 스트링으로 바꾸고 출력
		else if (searchNode(pList pst, '1') != 0) {
			return add(pList answer, pList pst);
	}

else if ( one == 1 && two == 0) { // add( a,-b )
	deleteData(pList b, char '-');
	return minus(a,b);
	}

else if ( one == 0 && two == 1) { // add(-a,b)
	deleteData(pList a, char'-');
	return minus(b,a);
	}

else if ( one == 0 && two == 0) { // add(-a,-b)
	deleteData(pList a, char'-');
	deleteData(pList b, char'-');
	return insertFront(pList add(a,b), makeNode('-'));
	}
}
minus (pList a , pList b ) {

int one,two;

one = (a-> head -> data != '-'?1:0);

two = (b-> head -> data != '-'?1:0);

if ( one == 1 && two == 1) {

//  계산 시작

else if ( one == 1 && two == 0) { // minus( a,-b )

	deleteData(Link b, char '-');

	return add (a, b);
	}		

else if ( one == 0 && two == 1) { // minus(-a,b)

	deleteData(Link a, char'-');

	return insertFront(List add(a, b), makeNode('-'));
	}

else if ( one == 0 && 가two == 0) { // minus( -a , +b )

	deleteData(Link b, char'-');

	return minus(a, b);
	}
}
