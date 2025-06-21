#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

set <int> adj[101];
vector <int> mark(101, 0);
int deg[101] = {0};

inline void dfs(int u){
    mark[u] = 1;
    for (int v : adj[u]) {
        if (!mark[v]) {
            dfs(v);
        }
    }
}

inline int check(int n){
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0 && !adj[i].empty()) {
            return 0; // Not all nodes are reachable
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += deg[i] & 1;
    }
    if (cnt == 0) return 1; // Eulerian circuit
    if (cnt == 2) return 2; // Eulerian path
}

inline void euler(int n, int s){
    stack <int> st;
    st.push(s);
    vector <int> res;
    while (st.size()){
        int u = st.top();
        if(adj[u].empty()) {
            st.pop();
            res.push_back(u);
            continue;
        }
        int v = *adj[u].begin();
        adj[u].erase(v);
        adj[v].erase(u);
        st.push(v);
    }
    reverse(res.begin(), res.end());
    for (int i : res) cout << i << " ";
    cout << endl;
}
inline void solve(){
    int c, n, s; cin >> c >> n;
    if(c == 2) cin >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            if (x) {
                adj[i].insert(j);
                deg[i]++;
            }   
        }
    }
    if(c == 1) cout << check(n) << endl;
    else euler(n, s);
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    while (t--) solve();
}