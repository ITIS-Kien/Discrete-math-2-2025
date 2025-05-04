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
    int t, n, deg_in[101] = {0}, deg_out[101] = {0};
    vector <int> adj[101];
    cin >> t >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x){
                ++deg_in[j];
                ++deg_out[i];
                adj[i].emplace_back(j);
            }
        }
    }
    if(t == 1){
        for (int i = 1; i <= n; ++i) cout << deg_in[i] << " " << deg_out[i] << endl;
    } else {
        cout << n << endl;
        for (int i = 1; i <= n; ++i){
            cout << adj[i].size() << " ";
            for (int it : adj[i]) cout << it << " ";
            cout << endl;
        }
    }
}
