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

    int t, n; cin >> t >> n;
    int a[n + 1][n + 1], cnt[n + 1] = {0};
    set <pair <int, int>> edge;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if(a[i][j] <= 50 and j > i) {
                edge.insert({min(i, j), max(i, j)});
                ++cnt[i];
                ++cnt[j];
            }
        }
    }
    if(t == 1){
        for (int i = 1; i <= n; ++i) cout << cnt[i] << " ";
    } else {
        cout << n << " " << edge.size() << endl;
        for (auto &it : edge){
            cout << it.first << " " << it.second << " " << a[it.first][it.second] << endl;
        }
    }
}