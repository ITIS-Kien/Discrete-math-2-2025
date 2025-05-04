#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, used[1005];
vector <vector <int>> a(1005);
set <pair <int, int>> edge;

void dfs(int u){
    used[u] = 1;
    for (int it : a[u]) if(!used[it]) dfs(it);
}
void dfs2(int u, int s, int t){
    used[u] = 1;
    for (int it : a[u]) {
        if((u == s && it == t) || (u == t && it == s)) continue; 
        if(!used[it]) dfs2(it, s, t);
    }
}
void solve(){
    int cc = 0;
    vector <pair <int, int>> ans;
    for (int i = 1; i <= n; ++i){
        if(!used[i]){
            ++cc;
            dfs(i);
        }
    }
    for (auto it : edge){
        int x = it.first, y = it.second, cnt = 0;
        memset(used, 0, sizeof(used));
        for (int i = 1; i <= n; ++i){
            if(!used[i]){
                ++cnt;
                dfs2(i, x, y);
            }
        }
        if(cnt > cc) ans.push_back({x, y});
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans) cout << it.first << " " << it.second << endl;

}
int main(){
    fast;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x){
                a[i].push_back(j);
                edge.insert({min(i, j), max(i, j)});
            }
        }
    }
    solve();
}



