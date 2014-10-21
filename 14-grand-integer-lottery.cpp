#include <iostream>
#define ull unsigned long long
using namespace std;

int DEZ[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

ull T[20];
int D[20], n;

bool contains(ull x) {
    while(x) {
        for(int i=0; i<n; i++) 
            if (x%DEZ[D[i]] == T[i]) 
                return true;
        x/=10;                
    }

    return false;
}

int digits(ull x) {
    int sum = 0;
    while(x) {
        sum+=1;
        x/=10;
    }
    return sum;
}

int main() {
    int s, e, p;
    while(cin >> s >> e >> p >> n) {
        for(int i=0; i<n; i++) {
            cin >> T[i];
            if (T[i]>1000000) {
                i--;
                n--;
            } else {
                D[i] = digits(T[i]);
            }
        }
        
        int count = 0;
        for(int i=s; i<=e; i++) {
            if (contains(i))
                count++;
                
            if (count == p) {
                cout << i << endl;
                break;
            }
        }
        if (count < p) {
            cout << "DOES NOT EXIST" << endl;
        }
    }
}