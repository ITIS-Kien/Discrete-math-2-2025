#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

vector <int> adj[101];
vector <int> mark(101);
vector <int> component;

void dfs(int u) {
    mark[u] = 1;
    component.push_back(u);
    for (int it : adj[u]) {
        if (!mark[it]) dfs(it);
    }
}

inline void connected_components(int n) {
    int mcc = 0, scc = 1;
    for (int i = 1; i <= n; ++i) {
        mark.assign(n + 1, 0);
        dfs(i);
        if(component.size() != n) scc = 0;
        mcc = max(mcc, (int)component.size());
        component.clear();
    }
    if(scc) {
        cout << 1 << endl;
    } else if(mcc == n) {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
    }
}   
inline void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            if (x) adj[i].push_back(j);
        }
    }
    connected_components(n);
}

signed main(){
    nguyentukien
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int t = 1; //cin >> t;
    while (t--) solve();
}