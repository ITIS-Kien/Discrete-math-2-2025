#include <bits/stdc++.h>
using namespace std;
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

set <int> adj[101];
vector <int> mark(101, 0);
vector <int> tmp;
vector <vector <int>> res;

void hamilton(int n, int s, int c){
    if (tmp.size() == n){
        if(adj[c].find(s) != adj[c].end()){
            tmp.push_back(s);
            res.push_back(tmp);
            tmp.pop_back();
        }
        return;
    }
    for (int it : adj[c]){
        if(!mark[it]){
            mark[it] = 1;
            tmp.emplace_back(it);
            hamilton(n, s, it);
            tmp.pop_back();
            mark[it] = 0;
        }
    }
}

inline void solve(){
    int n, s; cin >> n >> s;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            if (x) adj[i].insert(j);
        }
    }
    mark[s] = 1;
    tmp.push_back(s);
    hamilton(n, s, s);
    if (res.empty()){
        cout << 0 << endl;
    } else {
        for (const auto& path : res){
            for (int it : path){
                cout << it << " ";
            }
            cout << endl;
        }
        cout << res.size() << endl;
    }

}

signed main(){
    nguyentukien
    int t = 1; //cin >> t;
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    while (t--) solve();
}