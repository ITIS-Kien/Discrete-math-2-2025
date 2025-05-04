#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast")

short t, n, m, matrix[108][108];
int main(){
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n >> m;
    for (int i = 0; i < m; ++i){
        short x, y; cin >> x >> y;
        matrix[x][y] = matrix[y][x] = 1;
    }
    if(t == 1) {
        for (int i = 1; i <= n; ++i) {
            int deg = 0;
            for (int j = 1; j <= n; ++j)
                deg += matrix[i][j];
            cout << deg << ' ';
        }
    }
    else {
        cout << n << endl;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j) cout << matrix[i][j] << " ";
            cout << endl;            
        }
        
    } 
}
