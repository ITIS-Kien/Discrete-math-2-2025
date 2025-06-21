#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

ifstream fin("CT.inp");
ofstream fout("CT.out");

int degin[101], degout[101];
set <int> adj[101];

inline void solve1(){
    int n; fin >> n;
    for (int i = 1; i <= n; ++i){
        fin >> degout[i];
        for (int j = 0; j < degout[i]; ++j){
            int x; fin >> x;
            ++degin[x];
        }
    }
    int neu = 0, seu = 0;
    for (int i = 1; i <= n; ++i){
        int x = abs(degin[i] - degout[i]);
        if (x == 0) continue;
        if (x == 1) ++seu;
        else if (x == 2) ++neu;
    }
    if(neu) fout << 0;
    else if(seu) fout << 2;
    else fout << 1;
}

inline void solve2(){
    int n, u; fin >> n >> u;
    for (int i = 1; i <= n; ++i){
        int k; fin >> k;
        for (int j = 0; j < k; ++j){
            int x; fin >> x;
            adj[i].insert(x);
        }
    }
    stack <int> st;
    vector <int> res;
    st.push(u);
    while (!st.empty()){
        int v = st.top(); st.pop();
        res.push_back(v);
        if(adj[v].empty()) break;
        int x = *adj[v].begin();
        adj[v].erase(x);
        st.push(x);
    }
    for (int i = 0; i < res.size(); ++i){
        fout << res[i] << " ";
    }
}

inline void solve(){
    int t; fin >> t;
    if(t == 1) solve1();
    else solve2();
}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    while (t--) solve();
}