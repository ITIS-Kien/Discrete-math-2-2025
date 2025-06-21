#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

set <int> adj[101];
set <pair<int, int>> edge;
vector <int> mark(101, 0);
vector <pair<int, int>> ans;

inline void bfs(int u) {
    mark[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int it : adj[v]) {
            if (!mark[it]) {
                mark[it] = 1;
                q.push(it);
            }
        }
    }
}

inline void cut_edge(int n) {
    int connected_components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!mark[i]) {
            bfs (i);
            connected_components++;
        }
    }
    for (auto it : edge){
        int u = it.first;
        int v = it.second;
        adj[u].erase(v);
        adj[v].erase(u);
        mark.assign(101, 0);
        int temp_components = 0;
        for (int j = 1; j <= n; ++j) {
            if (!mark[j]) {
                bfs(j);
                temp_components++;
            }
        }
        if (temp_components > connected_components) {
            ans.push_back({u, v});
        }
        adj[u].insert(v);
        adj[v].insert(u);

    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first << " " << it.second << endl;
    }
}   

inline void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            if (x) {
                adj[i].insert(j);
                edge.insert({min(i, j), max(i, j)});
            }
        }
    }
    cut_edge(n);
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    while (t--) solve();
}