#include <iostream>
using namespace std;

int T[1010];
int A[100100], B[100100];

int main() {
    int n, m;
    while(cin >> n >> m) {
        for(int i=0; i<m; i++)
            cin >> A[i] >> B[i];
        for(int i=0; i<n; i++) {
            int temp; cin >> temp;        
            T[temp] = i;
        }
        bool ok = true;
        for(int i=0; i<m; i++)
            ok = ok & T[A[i]] < T[B[i]];
        cout << (ok?"YES":"NO") << endl;
        
        
    }
}