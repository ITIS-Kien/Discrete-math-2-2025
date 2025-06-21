#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

ifstream fin("TK.INP");
ofstream fout("TK.OUT");

vector <int> adj[101];
vector <int> mark(101);
vector <int> path;
int cnt = 0, found = 0;

inline void dfs(int u, int v) {
    mark[u] = 1;
    path.push_back(u);
    if (u == v) {
        found = true;
        return;
    }
    for (int it : adj[u]) {
        if (!mark[it] && !found) {
            dfs(it, v);
        }
    }
    if (!found) path.pop_back();
}

inline void solve(){
    int c, n, x, y, mat[101][101]; 
    fin >> c >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> mat[i][j];
            if(mat[i][j]) adj[i].emplace_back(j);
        }
    }
    if(c == 1) {
        for (int i = 1; i <= n; ++i) cnt += mat[x][i] and mat[i][y];
        fout << cnt;
    }
    else {
        dfs(x, y);
        if (!found) cout << 0 << endl;
        else {
            for (int i = 0; i < path.size(); ++i)
                fout << path[i] << " ";
        }
    }
       
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}