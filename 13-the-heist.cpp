#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Type {
    string name;
    int w, v;
    Type(string name, int w, int v) : name(name), w(w), v(v) {}
    
    inline bool operator<(const Type& other) const {
        return name<other.name;
    }
};

struct Node {
    int v, p, right;
    void set(int v, int p, int right) {
        this->v = v;
        this->p = p;
        this->right = right;
    }
};

vector<Type> V;
int N[1000];
Node T[40000000];

int main() {
    int n, m;
    string line, s;
    char temp;
    while(cin >> n >> m) {
        int size=0;
        m*=n;
        getline(cin, line);
    
        while(getline(cin, line)) {
            stringstream sin(line);
            if (!getline(sin, s, ',')) break;
            int weight, value; sin >> weight >> temp >> value;
            if (s[0]=='E'&&s[1]=='N'&&s[2]=='D') break;
            V.push_back(Type(s, weight, value));
        }
        sort(V.begin(), V.end());


        T[0].set(0, 0, -1);
        int maxx = 0;
        for(int k=0; k<V.size(); k++) {
            int it=0, up=0;
            
            while(it != -1) {
                int cand = T[it].v+V[k].v;
                int where = it+V[k].w;
                if (where > m) break;
                
                while(T[up].right != -1 && T[up].right <= where)
                    up = T[up].right;

                if (up == where) {
                    if (cand > T[up].v) {
                        T[up].v = cand;
                        T[up].p = k;
                        if (T[up].v > T[maxx].v)
                            maxx = up;
                    }
                } else {
                    T[where].set(cand, k, T[up].right);
                    T[up].right = where;
                    size++;
                    if (cand > T[maxx].v)
                        maxx = where;
                }
                
                it = T[it].right;
            }
        }
        
        while(maxx != 0) {
            N[T[maxx].p]++;
            maxx -= V[T[maxx].p].w;
        }
        
        int total = 0, totw=0;
        for(int i=0; i<V.size(); i++) {
            if (not N[i]) continue;
            cout << V[i].name << "," << N[i] << "," << V[i].w*N[i] << "," << V[i].v*N[i] << endl;
            totw += V[i].w*N[i];
            total += V[i].v*N[i];
        }
        cout << totw << "," << total << endl;
        
        printf("Each robber gets: %.2f\n", total/(double)n);
    }
}