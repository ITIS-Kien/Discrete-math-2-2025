#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;


signed main(){
    nguyentukien
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t, n, m; cin >> t >> n >> m;
    int matrix[n + 1][n + 1];
    int degin[n + 1], degout[n + 1];
    memset(matrix, 0, sizeof(matrix));
    memset(degin, 0, sizeof(degin));
    memset(degout, 0, sizeof(degout));
    while (m--)
    {
        int x, y, z; cin >> x >> y >> z;
        matrix[x][y] = z;
        ++degout[x];
        ++degin[y];
    }
    if(t == 1){
        for (int i = 1; i <= n; ++i){
            cout << degin[i] << " " << degout[i] << endl;
        }
    } else {
        cout << n << endl;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if(!matrix[i][j] and i != j) cout << 10000 << " ";
                else cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
}