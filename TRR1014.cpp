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
    int t, n, m = 0;
    int deg_in[101] = {0}, deg_out[101] = {0};
    int adj[101][101] = {0};
    cin >> t >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x){
                ++m;
                ++deg_in[j];
                ++deg_out[i];
                adj[i][m] = 1;
                adj[j][m] = -1;
            }
        }
    }
    if(t == 1){
        for (int i = 1; i <= n; ++i) cout << deg_in[i] << " " << deg_out[i] << endl;
    } else {
        cout << n << " " << m <<  endl;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
}
