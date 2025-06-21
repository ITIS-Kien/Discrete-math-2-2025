#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

vector <int> adj[101];
vector <int> mark(101);
vector <int> component;
vector <vector <int>> res;

void dfs(int u) {
    mark[u] = 1;
    component.push_back(u);
    for (int it : adj[u]) {
        if (!mark[it]) dfs(it);
    }
}

inline void connected_components(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!mark[i]) {
            if(component.size()) {
                sort(component.begin(), component.end());
                res.push_back(component);
                component.clear();
            }
            dfs(i);
        }
    }
    if(component.size()) {
        sort(component.begin(), component.end());
        res.push_back(component);
    }
    cout << res.size() << endl;
    for (const auto& comp : res) {
        for (int v : comp) {
            cout << v << " ";
        }
        cout << endl;
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