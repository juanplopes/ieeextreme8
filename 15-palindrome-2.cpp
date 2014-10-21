#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string s;

bool f[2002][2002];
int m[2002][2002];

int len( int l, int r )
{
	if( f[l][r] )
		return m[l][r];

	if( l == r ) m[l][r] = 1;
	else if( l > r ) m[l][r] = 0;
	else if( s[l] == s[r] ) m[l][r] = 2 + len( l+1, r-1 );
	else m[l][r] = max( len( l+1, r ), len( l, r-1 ) ); 
	
	f[l][r] = true;	
	return m[l][r];
}

void clear()
{
	for( int i = 0; i < s.length(); i++ )
	for( int j = 0; j < s.length(); j++ )
		f[i][j] = false;
}

int main()
{
	while( cin >> s )
	{
		//cout << s << endl;
		cout << len( 0, s.length() - 1 ) << endl;
		clear();
	}

    return 0;
}