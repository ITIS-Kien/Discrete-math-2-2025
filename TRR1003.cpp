#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast")

short n, matrixAdj[101][101];
short incidenceMatrix[101][101];
vector<pair<int, int>> edges;

inline void solve1() {
    for (int i = 1; i <= n; ++i) {
        int deg = 0;
        for (int j = 1; j <= n; ++j)
            deg += matrixAdj[i][j];
        cout << deg << ' ';
    }
}

inline void solve2() {
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {  
            if (matrixAdj[i][j]) {
                edges.emplace_back(i, j);
            }
        }
    }

    int m = edges.size();
    cout << n << ' ' << m << endl;

    
    for (int k = 0; k < m; ++k) {
        int u = edges[k].first, v = edges[k].second;
        incidenceMatrix[u][k] = 1;
        incidenceMatrix[v][k] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << incidenceMatrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    
    short t;
    cin >> t;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)    
            cin >> matrixAdj[i][j];

    (t == 1 ? solve1 : solve2)();
    return 0;
}