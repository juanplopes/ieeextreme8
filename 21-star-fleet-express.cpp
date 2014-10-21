#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#define ERR (1ll<<63-1)   
#define ull unsigned long long
using namespace std;

struct Flight {
    int dest;
    ull start, end;
    Flight(int dest, ull start, ull end) : dest(dest), start(start), end(end) {}
};

map<string, int> M;
vector<Flight> G[1010];
ull best[1010];

ull dfs(int path, int from, int dest, ull now) {
    if (now>=best[from]) return ERR;
    best[from] = now;
        
    if (from==dest) return now;
    ull minn = ERR;
    for(int i=0; i<G[from].size(); i++) {
        if (G[from][i].start >= now+(path>0?60:0))
            minn = min(minn, dfs(path+1, G[from][i].dest, dest, G[from][i].end));
    }
    return minn;
}

int main() {
    int n, m, q;
    while(cin >> n >> m >> q) {
        string s;
        for(int i=0; i<n; i++) {
            cin >> s;
            M[s] = i;
        }
        for(int i=0; i<m; i++) {
            string a, b; ull a1, a2, b1, b2;
            cin >> a >> a1 >> a2 >> b >> b1 >> b2;
            G[M[a]].push_back(Flight(M[b], a1*1440+a2, b1*1440+b2));
        }
        
        for(int i=0; i<q; i++) {
            string a, b; ull a1, a2;
            cin >> a >> a1 >> a2 >> b;
            memset(best, 0x3f, sizeof best);
            ull answer = dfs(0, M[a], M[b], a1*1440+a2);
            if (answer == ERR) {
                cout << "No trip on XSL" << endl;
            } else {
                cout << answer/1440 << " " << answer%1440 << endl;
            }
        }
    }
}
