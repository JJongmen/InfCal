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

// 계산

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

else if ( one == 0 && two == 0) { // minus( -a , +b )

	deleteData(Link b, char'-')

	return minus( -a , +b )
	}
}
