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
    vector <int> a[n + 1];
    set <pair <int, int>> s;
    for (int i = 1; i <= n; ++i){
        int k; cin >> k;
        while (k--)
        {
            int x; cin >> x;
            a[i].emplace_back(x);
            s.insert({min(i, x), max(i, x)});
        }
    }
    if(t == 1) {
        for (int i = 1; i <= n; ++i) cout << a[i].size() << " ";
    } else {
        cout << n << " " << s.size() << endl;
        for (auto &it : s) cout << it.first << " " << it.second << endl;
    }
    
}
