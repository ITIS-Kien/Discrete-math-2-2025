#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#pragma GCC optimize("Ofast")

short t, n, a[108][108], edge;
void solve1(){
    for (short i = 1; i <= n; ++i){
        edge = 0;
        for (short j = 1; j <= n; ++j) edge += a[i][j];
        cout << edge << " ";
    }
}
void solve2(){
    cout << n << " " << (edge >> 1) << endl;
    for (short i = 1; i <= n; i++)
    {
        for (short j = i; j <= n; j++)
        {
            if (a[i][j] == 1) cout << i << " " << j << endl;
        }
    }
}

int main(){
    fast;
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t >> n;
    for (short i = 1; i <= n; ++i){
        for (short j = 1; j <= n; ++j){
            cin >> a[i][j];
            edge += a[i][j];
        }
    }
    if(t == 1) solve1();
    else solve2();
    
    
}