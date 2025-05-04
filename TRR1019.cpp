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
    int deg_in[n + 1] = {0}, 
        deg_out[n + 1] = {0};
    vector <pair <int, int>> edge;
    for (int i = 1; i <= n; ++i){
        int k; cin >> k;
        while (k--)
        {
            int x; cin >> x;
            ++deg_out[i];
            ++deg_in[x];
            edge.push_back({i, x});
        }
    }
    if(t == 1) {
        for (int i = 1; i <= n; ++i) cout << deg_in[i] << " " << deg_out[i] << endl;
    } else {
        cout << n << " " << edge.size() << endl;
        for (auto it : edge) cout << it.first << " " << it.second << endl;
    }
    
    
}
