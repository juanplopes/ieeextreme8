#include <iostream>
#include <algorithm>
#define ull long long
using namespace std;

struct Gas {
    ull i, p;
    inline bool operator <(const Gas& other) const {
        return i<other.i;
    }
};

struct Result {
    ull cost, fuel;
    Result(ull cost, ull fuel) : cost(cost), fuel(fuel) {}
    
    Result add(Result other, ull cost) {
        return Result(this->cost+other.cost+cost, other.fuel);
    }
};

Gas G[50100];
ull tank;

Result solve(ull a, ull b, int ga, int gb, ull fuel) {
    if (b-a<=fuel) return Result(0, fuel-(b-a));
    if (ga >= gb) return Result(-(1ll<<62), 0);

    int x = ga;
    for(int i=ga; i<gb; i++)
        if (G[i].p < G[x].p) 
            x = i;

    Result first = solve(a, G[x].i, ga, x, fuel);
    ull buy = min(b-G[x].i, tank);
          
    return first.add(solve(G[x].i, b, x+1, gb, buy), (buy-first.fuel)*G[x].p);
}

int main() {
    int cases; cin >> cases;
    int n, t, L;

    while(cin >> n >> tank >> t >> L) {
        for(int i=0; i<n; i++)
            cin >> G[i].i >> G[i].p;   
        sort(G, G+n);
        cout << max(solve(0, L, 0, n, t).cost, -1ll) << endl;
    }
}