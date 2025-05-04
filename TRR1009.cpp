#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define MOD 1000000007
#define BOOST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast")


int main(){
    BOOST;
    // fstream cin("DT.INP", ios::in);
    // fstream cout("DT.OUT", ios::out);
    int t, n, cnt[101] = {0}; cin >> t >> n;
    set <pair <int, int>> s;
    for (int i = 1; i <= n; ++i){
        int k; cin >> k;
        while (k--)
        {
            int x; cin >> x;
            ++cnt[i];
            s.insert({min(i, x), max(i, x)});
        }
    }
    if(t == 1) {
        for (int i = 1; i <= n; ++i) cout << cnt[i] << " ";
    } else {
        cout << n << " " << s.size() << endl;
        for (int i = 1; i <= n; ++i){
            for (auto it : s){
                if(it.first == i || it.second == i) cout << "1 ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
    
}