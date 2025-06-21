#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

vector <int> adj[101];
vector <int> mark(101, 0);
vector <int> ans;

inline void dfs(int u) {
    mark[u] = 1;
    for (int it : adj[u]) {
        if (!mark[it]) dfs(it);
    }
}

inline void articulation_points(int n) {
    int connected_components = 0;
    for (int i = 1; i <= n; ++i) {
        if (!mark[i]) {
            dfs(i);
            connected_components++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        mark.assign(101, 0);
        mark[i] = 1; // Temporarily mark the current node as visited
        int temp_components = 0;
        for (int j = 1; j <= n; ++j) {
            if (!mark[j]) {
                dfs(j);
                temp_components++;
            }
        }
        if (temp_components > connected_components) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int v : ans) {
        cout << v << " ";
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
    articulation_points(n);
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    while (t--) solve();
}