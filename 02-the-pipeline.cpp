#include <iostream>
#include <cstdio>
#define ull long long
using namespace std;

ull M[1010][1010];
ull U[1010], D[1010];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) 
                scanf("%lld", &M[i][j]);
                
        for(int j=1; j<n; j++) {
            for(int i=0; i<n; i++)
                U[i] = D[i] = M[i][j-1]+M[i][j];
         
            for(int i=1; i<n; i++)
                D[i] = min(D[i], D[i-1]+M[i][j]);

            for(int i=n-2; i>=0; i--)
                U[i] = min(U[i], U[i+1]+M[i][j]);

            for(int i=0; i<n; i++) 
                M[i][j] = min(D[i], U[i]);
        }
        
        ull minn = 1ll<<50;
        for(int i=0;i<n; i++) {
            minn = min(minn, M[i][n-1]);
        }
        printf("%lld\n", minn);
                
    }
}
