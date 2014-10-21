#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

int n;
ull t[5050][5050];

int main()
{
	while( cin >> n )
	{
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= n; j++ )
			{
				cin >> t[i][j];
			}
		}
		
		ull sum = 0;
		for( int i = 1; i <= n; i++ ) sum += t[i][i];
		
		int fails = 0;
		for( int i = n; i > 0; i-- )
		{
			ull s1 = 0;
			ull s2 = 0;
			for( int j = 1; j <= n; j++ )
			{
			 	s1 += t[j][i];
			 	s2 += t[i][j];
			}
			if( s1 != sum ) fails++;
			if( s2 != sum ) fails++;
		}
		
		ull asum = 0;
		for( int i = 1; i <= n; i++ ) 
		{
			 asum += t[i][(n+1)-i];
		}
		if( asum != sum ) fails++;
		
		cout << fails << endl;
		
		for( int i = n; i > 0; i-- )
		{
			ull s = 0;
			for( int j = 1; j <= n; j++ )
			{
			 	s += t[j][i];
			}
			
			if( s != sum ) cout << -i << endl;
		}
		
		if( asum != sum ) cout << 0 << endl;
		
		for( int i = 1; i <= n; i++ )
		{
			ull s = 0;
			for( int j = 1; j <= n; j++ )
			{
			 	s += t[i][j];
			}
			
			if( s != sum ) cout << i << endl;
		}
	}

	return 0;
}