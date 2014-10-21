#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

char a[1005], b[1005];

bool f[2002][2002];
int m[2002][2002];

int pts( char c )
{
	if( c == 'A' ) return 20;
	if( c == 'J' || c == 'Q' || c == 'K' ) return 15;
	if( c == 'T' ) return 10;
	return c - '0';
}

int pts( char c1, char c2 )
{
	if( c1 == 'R' && c2 == 'R' ) return 50;
	if( c1 == 'R' ) return pts( c2 );
	if( c2 == 'R' ) return pts( c1 );
	if( c1 == c2 ) return pts( c1 );
	return 0;
}

int len( int l, int r )
{
	if( l >= n || r >= n ) return 0;
	
	if( f[l][r] )
		return m[l][r];

	if( a[l] == b[r] || a[l] == 'R' || b[r] == 'R' ) 
	{
		m[l][r] = 2 * pts( a[l], b[r] ) + len( l+1, r+1 );
	}
	else m[l][r] = 0;
	m[l][r] = max( len( l+1, r ), m[l][r] );
	m[l][r] = max( len( l, r+1 ), m[l][r] ); 
	
	f[l][r] = true;	
	return m[l][r];
}

void clear()
{
	for( int i = 0; i < n; i++ )
	for( int j = 0; j < n; j++ )
		f[i][j] = false;
}

int main()
{
	while( cin >> n )
	{
		if( n == 0 )
			break;
		
		for( int i = 0; i < n; i++ )
		{
			cin >> a[i];
			//cout << a[i];
		}
		//cout << endl;
		for( int i = 0; i < n; i++ )
		{
			cin >> b[i];
			//cout << b[i];
		}
		//cout << endl;
		
		cout << len( 0, 0 ) << endl;
		clear();
	}

    return 0;
}