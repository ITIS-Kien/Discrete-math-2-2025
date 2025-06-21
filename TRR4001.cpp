#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

vector <int> adj[101];
vector <int> mark(101, 0);
vector <pair <int, int>> tree;

inline void dfs(int u){
    mark[u] = 1;
    for (int v : adj[u]){
        if (!mark[v]) {
            tree.emplace_back(make_pair(u, v));
            dfs(v);
        }
    }
}

inline void bfs(int u){
    queue <int> q;
    q.push(u);
    mark[u] = 1;
    while (q.size()){
        int v = q.front(); q.pop();
        for (int x : adj[v]){
            if (!mark[x]){
                tree.emplace_back(make_pair(v, x));
                mark[x] = 1;
                q.push(x);
            }
        }
    }
}

inline void solve(){
    int n, c, s; cin >> c >> n >> s;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            if (x) adj[i].emplace_back(j);
        }
    }
    if(c == 1) dfs(s);
    else bfs(s);
    if(tree.size() != n - 1) cout << 0, 0 << endl;
    else {
        cout << tree.size() << endl;
        for (auto it : tree){
            cout << min(it.first, it.second) << " " << max(it.first, it.second) << endl;
        }
    }
    
}

signed main(){
    nguyentukien
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);
    int t = 1; //cin >> t;
    while (t--) solve();
}