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
vector <int> par(101, 0);
int cnt = 0, found = 0;

inline void bfs(int u) {
    queue <int> q;
    q.push(u);
    mark[u] = 1;
    while (q.size())
    {
        int i = q.front(); q.pop();
        for (int it : adj[i]){
            if(!mark[it]){
                mark[it] = 1;
                par[it] = i;
                q.push(it);
            }
        }
    }
}

inline void solve(){
    int c, n, x, y, mat[101][101]; 
    fin >> c >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
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
        bfs(x);
        if(par[y] == 0) fout << 0;
        else {
            vector <int> res;
            int cur = y;
            while (cur != x) {
                res.push_back(cur);
                cur = par[cur];
            }
            res.push_back(x);
            reverse(res.begin(), res.end());
            for (int i = 0; i < res.size(); ++i) {
                fout << res[i] << " ";
            }
        }
    }
       
}

signed main(){
    nguyentukien
    int t = 1; //fin >> t;
    while (t--) solve();
}