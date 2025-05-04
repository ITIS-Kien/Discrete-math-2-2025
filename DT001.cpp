#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007
#define BOOST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast")


int main(){
    BOOST;
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    int t, n, cnt[101] = {0};
    set <pair <int, int>> edge; 
    cin >> t >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x) {
                edge.insert({min(i, j), max(i, j)});
                ++cnt[i];
            }
        }
    }
    if(t == 1){
        for (int i = 1; i <= n; ++i) cout << cnt[i] << " ";
    } else {
        cout << n << " " << edge.size() << endl;
        for (auto it : edge) cout << it.first << " " << it.second << endl;
    }
    
}
