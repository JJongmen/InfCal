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

LINK add ( LINK a , LINK b ) {

int one,two;

one = (a-> head -> data != '-'?1:0);

two = (b-> head -> data != '-'?1:0);

if ( one == 1 && one == 1);

if (a_count > b_count){
   count = a_count;
   a_point =  
   b_point = 
   a_int_len = a_point - 1;
   b_int_len = b_point - 1;
   a_dec_len = b_count - a_point;
   b_dec_len = b_count - b_point;
   while ( a_int_len = b_int_len) // int 자리수 맞추기
   {
	   if (a_int_len > b_int_len) {
		   b head 에 0 추가;
		   b_int_len++;
	   }
	   else if (a_int_len < b_int_len) {
		   a head 에 0추가;
		   a_int_len++;
	   }
	}
   while (a_dec_len = b_dec_len) // dec 자리수 맞추기
   {
	   if (a_dec_len > b_dec_len) {
		   b tail 에 0 추가;
		   b_dec_len++;
	   }
	   else if (a_dec_len < b_dec_len) {
		   a tail 에 0 추가;
		   a_dec_len++;
	   }
   }
 // 999.9990 + 009.9999
   LINK c = 연결리스트 생성 count +1 개수  만큼 0으로 채워야 한다.
   for 문으로 a_head + b_head 덧셈 
   if a_head + b_head >= 10
   
   }

else if ( one == 1 && two == 0) { // add( a,-b )

	deleteData(Link b, char '-')
	return minus(a,b);
	}

else if ( one == 0 && two == 1) { // add(-a,b)

	deleteData(Link a, char'-')

	return minus(b,a);
	}

else if ( one == 0 && two == 0) { // add(-a,-b)

	deleteData(Link a, char'-');

	deleteData(Link b, char'-');

	return insertFront(List add(a,b), // 노드 '-');
	}
}
minus ( LINK a , LINK b ) {

int one,two;

one = (a-> head -> data != '-'?1:0)

two = (b-> head -> data != '-'?1:0)

if ( one == 1 && two == 1)

//  계산 시작

else if ( one == 1 && two == 0) { // minus( a,-b )

	deleteData(Link b, char '-')

	return add ( +a , +b )
	}		

else if ( one == 0 && two == 1) { // minus(-a,b)

	deleteData(Link a, char'-')

	return insertFront(List add( +a ,+b ), # 노드 '-')
	}

else if ( one == 0 && 가two == 0) { // minus( -a , +b )

	deleteData(Link b, char'-')

	return minus( -a , +b )
	}
}
