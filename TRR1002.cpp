#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast")

short t, n, a[108][108];
vector <short> edge[108];


int main(){
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n;
    for (short i = 1; i <= n; ++i){
        for (short j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    if(t == 1) {
        for (int i = 1; i <= n; ++i) {
            int deg = 0;
            for (int j = 1; j <= n; ++j)
                deg += a[i][j];
            cout << deg << ' ';
        }
    }
    else {
        cout << n << endl;

        for (int i = 1; i <= n; ++i) {
            vector<int> adjVer;
            for (int j = 1; j <= n; ++j)
                if (a[i][j])
                    adjVer.push_back(j);
            
            cout << adjVer.size() << ' ';
            for (auto v : adjVer)
                cout << v << ' ';
            cout << endl;
        }
    }    
}
