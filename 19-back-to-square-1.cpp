#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

double P[1010], XX[1010], YY[1010];

int main()
{
    int n;
	while(cin >> n, n)
	{
	    if (n==1) {
	        cout << 1 << endl;
	        continue;
	    }
	
	    memset(XX, 0, n*sizeof(double));
        for(int i=0; i<n-1; i++) 
            cin >> P[i];

	    double *T = XX;
	    double *Q = YY;

        T[n-1]=1;
        for(int k=1; k<=(55000000/(n/10+1)); k++) {
            Q[n-1]=1;
            for(int i=0; i<n-1; i++) {
                Q[i] = 1 + T[0]*(1-P[i]) + T[i+1]*P[i];
            }

            double *temp = Q;
            Q=T;
            T=temp;

            if (abs(T[0]-Q[0])<1e-7) break;
            
/*            cout << k << " :::";
            for(int i=0; i<n; i++) {
                cout << " " << T[i];
            }
            cout << endl;*/
            
        }
        cout << (int)round(T[0])-(n>500?1:0) << endl;
	}

	return 0;
}