#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Tri {
    int a, b;
    Tri(int a, int b) : a(a), b(b) {}
};

vector<Tri> T[1010];

int main() {
    for(int i=-1000; i<=1000; i++) {
        for(int j=-1000; j<=1000; j++) {
            if (i==0 or j==0) continue;
            double k = sqrt(i*i+j*j);
            int kk = (int)floor(k);
            if (kk == k && kk<1010)
                T[kk].push_back(Tri(i, j));   
        }
    }
    
    int n, a, b;
    cin >> n;
    while(cin >> a >> b) {
        bool any = false;
        for(int i=0; i<T[a].size(); i++) {
            for(int j=0; j<T[b].size(); j++) {
                int x1 = T[a][i].a, y1 = T[a][i].b;
                int x2 = x1+T[b][j].a, y2 = y1-T[b][j].b;

                double hyp = sqrt(x2*x2+y2*y2);

                any = any || abs((a*a+b*b)-(hyp*hyp)) < 1e-7;
            }
        }
    
        cout << (any ? "TRUE" : "FALSE") << endl;
    }
}