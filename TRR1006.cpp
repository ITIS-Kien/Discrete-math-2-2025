#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast")

short t, n, m, incidenceMatrix[108][108];
vector <short> adj[108];

int main(){
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n >> m;
    for (int i = 1; i <= m; ++i){
        short x, y; cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        incidenceMatrix[x][i] = 1;
        incidenceMatrix[y][i] = 1;
    }
    if (t == 1){
        for (int i = 1; i <= n; ++i) cout << adj[i].size() << " ";
    }
    else {
        cout << n <<  " " << m << endl;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j) cout << incidenceMatrix[i][j] << " ";
            cout << endl;
        }
    }
    
}
