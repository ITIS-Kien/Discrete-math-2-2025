#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

vector <int> adj[1001];
vector <int> mark(1001, 0);
vector <int> res;

ifstream fin("TK.INP");
ofstream fout("TK.OUT");

void dfs(int u){
    mark[u] = 1;
    for (int v : adj[u]){
        if (!mark[v]) dfs(v);
    }
}


void check (int n){
    mark.assign(1001, 0);
    int org = 0;
    for (int i = 1; i <= n; ++i){
        if (!mark[i]){
            dfs(i);
            ++org;
        }
    }
    for (int i = 1; i <= n; ++i){
        mark.assign(1001, 0);
        mark[i] = 1;
        int cnt = 0;
        for (int j = 1; j <= n; ++j){
            if (!mark[j]){
                dfs(j);
                ++cnt;      
            }
        }
        if (cnt > org){
            res.push_back(i);
        }
    }
}

inline void solve(){
    int n; fin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; fin >> x;
            if(x) adj[i].push_back(j);
        }
    }
    check(n);
    fout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i){
        fout << res[i] << " ";
    }
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
    fin.close();
    fout.close();
}