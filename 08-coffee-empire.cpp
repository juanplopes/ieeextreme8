#include <iostream>
#include <string>
using namespace std;

int C[1010][1010];
int D[7][1010][1010];
int E[7][1010][1010];
double F[7][1010][1010];
int n, m;

double R[1010][1010];


int bonus(int k, int x, int y) {
    if (x<0 or x>=n or y<0 or y>=m) return 0;
    if (C[x][y] == 3 and D[k][x][y] >= 5) return 1;
    return 0;
}

int main() {
    while(cin >> m >> n) {
        string temp; char temp3;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                R[i][j] = 0;
                if (j>0) cin >> temp3;
                cin >> temp3;
                C[i][j] = temp3 == '-' ? 0 :
                          temp3 == 'L' ? 1 :
                          temp3 == 'M' ? 2 :
                          temp3 == 'H' ? 3 : -1;
            }   
        }
        
        for(int k=0; k<7;k++) {
            cin >> temp;
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if (j>0) cin >> temp3;
                    int temp2;
                    cin >> temp2;
                    E[k][i][j] = D[k][i][j] = temp2;
                }   
            }
        }
        for(int k=0; k<7;k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    E[k][i][j] += bonus(k, i-1, j);
                    E[k][i][j] += bonus(k, i+1, j);
                    E[k][i][j] += bonus(k, i, j-1);
                    E[k][i][j] += bonus(k, i, j+1);
                    
                    F[k][i][j] = E[k][i][j] / (C[i][j]+1.0);
                   
                    if (C[i][j] < 3 and F[k][i][j] >= 20)
                        R[i][j] += F[k][i][j];
                }   
            }
        }

        double maxx = 0;
        int rx=-2, ry=-2;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if (R[i][j] > maxx) {
                    rx = i; ry = j; maxx = R[i][j];
                }
            }
        }
        cout << ry+1 << " " << rx+1 << endl;
        
    }    
}