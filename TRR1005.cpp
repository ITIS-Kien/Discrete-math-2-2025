#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast")

short t, n, m;
vector <short> adj[108];
int main(){
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n >> m;
    for (int i = 0; i < m; ++i){
        short x, y; cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    if (t == 1){
        for (int i = 1; i <= n; ++i) cout << adj[i].size() << " ";
    }
    else {
        cout << n << endl;
        for (int i = 1; i <= n; ++i){
            cout << adj[i].size() << " ";
            for (short it : adj[i]) cout << it << " ";
            cout << endl;
        }
    }
    
}
