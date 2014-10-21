#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long init;
int it, rule, n;

bool life( int v ) { return rule & ( 1ull << v ); }

unsigned long long Evolve( unsigned long long init )
{
	unsigned long long sample = 0;

	for( int i = 0; i < n; i++ )
	{
		int v = 0;
		if( i > 0 && ( init & ( 1ull << ( i - 1 ) ) ) ) v += 1;
		if( init & ( 1ull << ( i ) ) )  v += 2;
		if( i < ( n - 1 ) && ( init & ( 1ull << ( i + 1ull ) ) ) ) v += 4;

		if( life( v ) ) sample += 1ull << i;
	}

	return sample;
}

void Print( int i, unsigned long long sample )
{
	cout << ( i ) << " ";
	if( i < 10 ) cout << " ";
	if( i < 100 ) cout << " ";

	cout << "-";
	for( int i = n - 1; i >= 0; i-- )
	{
		cout << ( ( sample & ( 1ull << i ) ) ? '*' : ' ' );
	}
	cout << "-" << endl;
}

int main() 
{
    cin >> rule >> it >> n >> init;

    Print( 1, init );
    for( int i = 2; i <= it; i++ )
    {
    	unsigned long long iter = Evolve( init );

    	Print( i, iter );
    	
    	if( iter == init ) 
		{
			break;
		}

    	init = iter;
    }
    
    return 0;
}
