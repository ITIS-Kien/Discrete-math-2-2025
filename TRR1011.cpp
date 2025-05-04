#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007
#define BOOST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast")


int main(){
    BOOST;
    fstream cin("DT.INP", ios::in);
    fstream cout("DT.OUT", ios::out);

    int t, n, m, cnt[101] = {0}; 
    cin >> t >> n >> m;
    int adj[n + 1][n + 1] = {0};
    for (int i = 0; i < m; ++i){
        int a, b, c; 
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
        ++cnt[a]; ++cnt[b];
    }
    if(t == 1){
        for (int i = 1; i <= n; ++i) cout << cnt[i] << " ";
    } else {
        cout << n << endl;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if(!adj[i][j] and i != j) cout << 10000 << " ";
                else cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
        
}
