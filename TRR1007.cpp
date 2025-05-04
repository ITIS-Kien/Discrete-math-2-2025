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
    int k, V; cin >> k >> V;
    vector<vector<int>> a(V + 1, vector<int>(V + 1, 0));
    vector<int> cnt(V + 1, 0);
    
    for(int i = 1; i <= V; i++) {
        int sz; cin >> sz;
        while(sz--) {
            int j; cin >> j;
            a[i][j] = 1;
            cnt[i]++;
        }
    }
    if(k == 1) {
        for(int i = 1; i <= V; i++) cout << cnt[i] << " ";
    }
    else {
        cout << V << endl;
        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}