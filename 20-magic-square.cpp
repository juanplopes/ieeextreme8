#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool t[102][12];

int main()
{
	while( cin >> n >> m )
	{
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= m; j++ )
			{
				cin >> t[i][j];
			}
		}
		
		int fails = 0;
		
		for( int i1 = 1; i1 < n; i1++ )
		{
			bool pass1 = false;
			for( int j = 1; j <= m; j++ )
			{
				if( t[i1][j] != t[i1+1][j] && t[i1+1][j] == t[n][j] )				
				{
					pass1 = true;
					break;
				}
			}
			if( !pass1 ) fails++;
			
			for( int i2 = i1 + 1; i2 < n; i2++ )
			{
				bool pass2 = false;
				for( int j = 1; j <= m; j++ )
				{
					if( t[i1][j] != t[i1+1][j] && t[i1+1][j] == t[i2][j] && t[i2][j] == t[i2+1][j] )		
					{
						pass2 = true;
						break;
					}
				}
				if( !pass2 ) fails++;
			}
		}
		
		cout << fails << endl;
		
		for( int i1 = 1; i1 < n; i1++ )
		{
			bool pass1 = false;
			for( int j = 1; j <= m; j++ )
			{
				if( t[i1][j] != t[i1+1][j] && t[i1+1][j] == t[n][j] )				
				{
					pass1 = true;
					break;
				}
			}
			if( !pass1 ) 
			{
				cout << "i1=" << i1 << endl;
			}
        }
			
		for( int i1 = 1; i1 < n; i1++ )
        {
			for( int i2 = i1 + 1; i2 < n; i2++ )
			{
				bool pass2 = false;
				for( int j = 1; j <= m; j++ )
				{
					if( t[i1][j] != t[i1+1][j] && t[i1+1][j] == t[i2][j] && t[i2][j] == t[i2+1][j] )		
					{
						pass2 = true;
						break;
					}
				}
				if( !pass2 ) 
				{
					cout << "i1=" << i1 << " i2=" << i2 << endl;
				}
			}
		}
	}

	return 0;
}