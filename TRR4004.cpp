#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

struct edge {
    int u, v, w;
    edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
    bool operator < (const edge& other) const {
        if (w != other.w) return w < other.w;
        if (u != other.u) return u < other.u;
        return v < other.v;
    }
};

set <edge> edges;
vector <int> mark(101, 0);

inline void prim(int n, int s){
    vector<edge> mst;
    int d = 0;
    mark[s] = 1;
    while (mst.size() < n - 1){
        auto it = edges.begin();
        while (it != edges.end() && (mark[it->u] + mark[it->v] != 1)) ++it;
        if (it == edges.end()) {
            cout << 0 << endl;
            return;
        }
        mark[it->u] = mark[it->v] = 1;
        mst.push_back(*it);
        d += it->w;
        edges.erase(it);
    }
    if (mst.size() != n - 1) {
        cout << 0 << endl;
        return;
    }
    cout << d << endl;
    for (auto it : mst) {
        cout << min(it.u, it.v) << " " << max(it.u, it.v) << " " << it.w << endl;
    }
}
inline void solve(){
    int n, s, w; cin >> n >> s;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> w;
            if (w) {
                edges.insert(edge(min(i, j), max(i, j), w));
            }
        }
    }
    prim(n, s);
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    while (t--) solve();
}