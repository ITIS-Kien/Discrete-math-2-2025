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
    int t, n, m;
    int deg_in[101] = {0}, deg_out[101] = {0};
    int adj[101][101] = {0};
    cin >> t >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y; cin >> x >> y;
        ++deg_out[x];
        ++deg_in[y];
        adj[x][y] = 1;
    }
    

    if(t == 1){
        for (int i = 1; i <= n; ++i) cout << deg_in[i] << " " << deg_out[i] << endl;
    } else {
        cout << n << endl;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
}
