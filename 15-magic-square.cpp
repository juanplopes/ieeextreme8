#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

ull t, a, l, n;

int main()
{
	cin >> t;
	while( t-- )
	{
		scanf( "%llu %llu %llu", &a, &l, &n );
		//cin >> a >> l >> n;
		
		ull link = 1;
		ull pot = 1;
	
		
		for( int i = 0; i < l; i++ )
		{
			pot *= a;
			if( pot < n )
			{
				link += pot;
			}
			else
			{
			    link += ( l-i ) * n;
			    break;
			}
		}
		
		
		printf( "%llu\n", link * a * 4 );
		//cout <<  << endl;
	}

	return 0;
}