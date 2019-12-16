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

pList add(pList a , pList b ) {

	int one,two;

	one = (a-> head -> data != '-'?1:0);

	two = (b-> head -> data != '-'?1:0);

	a_head = (a -> head -> data)

	b_head = (b -> head -> data)

	if ( one == 1 && one == 1){
		if (searchNode(pList a, '.') == 0){
			insertBack(pList a, makeNode('.'));
		}
		if (searchNode(pList b, '.') == 0){
			insertBack(pList b, makeNode('.'));
		}
	// 자연수일 경우 . 추가

		if (a_count > b_count){
   			count = a_count;
		}
		if (a_count < b_count){
			count = b_count;
		}
   		a_point = searchNode(pList a, '.') 
   		b_point = searchNode(pList a, '.')
   		a_int_len = a_point - 1;
   		b_int_len = b_point - 1;
   		a_dec_len = a_count - a_point;
   		b_dec_len = b_count - b_point;
   		while ( a_int_len != b_int_len) // int 자리수 맞추기
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
   		while (a_dec_len != b_dec_len) // dec 자리수 맞추기
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
		 // 999.9990 + 009.9999
		pList pst = makeList();
		pList answer = makeList();
		while (a_head != '\0'){
			if (a_head - '0' + b_head - '0'  > 9) {
				insertBack(pList pst, makeNode('1'));
				insertBack(pList answer, makeNode(a_head + b_head - 2 * '0'));
				deleteHead(pList a);
				deleteHead(pList b);
			}
			else if (a_head - '0' + b_head - '0'  < 10) {
				insertBack(pList pst , makeNode('0'));
				insertBack(pList answer, makeNode(a_head + b_head));
				deleteHead(pList a);
				deleteHead(pList b);
			}
			else if (a_head && b_head == '.') {
				insertBack(pList answer, makeNode('.'));
				deleteHead(pList a);
				deleteHead(pList b);
			}
		}
		insertBack(pst, makeNode('0'));
		// . 삽입

		if (searchNode(pList pst , '1') == 0) {
			return printList(answer);
		}
		else if (searchNode(pList pst, '1') != 0) {
			return add(pList answer, pList pst);
		}
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
pList minus(pList a , pList b ) {

	int one,two;
	one = (a-> head -> data != '-'?1:0);
	two = (b-> head -> data != '-'?1:0);
	a_head = (a -> head -> data)
	b_head = (b -> head -> data)

	if ( one == 1 && two == 1) {
		if (searchNode(pList a, '.') == 0){
			insertBack(pList a, makeNode('.'));
		}
		if (searchNode(pList b, '.') == 0){
			insertBack(pList b, makeNode('.'));
		}
		// 자연수일 경우 뒤에 . 추가 
		if (a_count > b_count) {
			count = a_count;
		}
		if (a_count < b_count) {
			count = b_count;
		}
		a_point = searchNode(pList a, '.')
		b_point = searchNode(pList b, '.')
		a_int_len = a_point -1;
		b_int_len = b_point -1;
		a_dec_len = a_count - a_point;
		b_dec_len = b_count - b_point;
		while (a_int_len = b_int_len) {
			if (a_int_len > b_int_len) {
				insertFront(pList b, makeNode('0'));
				b_int_len++;
			}	
			else if (a_int_len < b_int_len) {
				insertFront(pList a, makeNode('0'));
				a_int_len++;
			}
		}
		while (a_dec_len = b_dec_len) {
			if (a_dec_len > b_dec_len) {
				insertBack(pList b, makeNode('0'));
				b_dec_len++;
			}
			else if (a_dec_len < b_dec_len) {
				insertBack(pList a, makeNode('0'));
				a_dec_len++;
			}
		}
		//999.9 - 009.9
		// a 와 b 중 누가 더 큰지 구별 해야함
			// head 에서 따와서 빼기
		pList pst = makeList();
		pList answer = makeList();
		while ( a_head != '\0') {
			if (a_head - b_head < 0) {
				insertBack(pst,makeNode('1'));
				insertBack(answer, makeNode(b_head - a_head + '0'));
				deletHead(a);
				deletHead(b);
			}
			else if (a_head - b_head > 0) {
				insertBack(pst, makeNode('0'));
				insertBack(answer, makeNode(a_head - b_head +'0'));
				deletHead(a);
				deletHead(b);
			}
			else if (a_head && b_head =='.') {
				insertBack(answer, makeNode('.'));
				deletHead(a);
				deletHead(b);
			}
		}	
		insertBack(pst, makeNode('0'));
		// pst 맨뒤 0 추가해 자리수 맞추기
			// answer - 내림수 빼는 재귀 함수 호출
			// 내림수 에 1 없을때 그냥 값 도출
		if (searchNode(pst, '1') == 0) {
			return printList(answer);
		}
		if (searchNode(pst, '1') != 0) {
			return minus(answer, pst);
		}
	}
	else if ( one == 1 && two == 0) { // minus( a,-b )
		deleteData( pList b, char '-');
		return add (a, b);
	}		
	else if ( one == 0 && two == 1) { // minus(-a,b)
		deleteData(pList a, char'-');
		return insertFront(pList add(a, b), makeNode('-'));
	}
	else if ( one == 0 && two == 0) { // minus( -a , +b )
		deleteData(pList b, char'-');
		return minus(a, b);
	}
}
