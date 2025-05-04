#include<iostream> 
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector <vector <int>> a(1005);
int n, used[1005];
void dfs(int u){
    used[u] = 1;
    for (int it : a[u]) if(!used[it]) dfs(it);
}
void solve(){
    int cc = 0;
    for(int i = 1; i <= n; ++i){
        if(!used[i]){
            ++cc;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i){
        memset(used, 0, sizeof(used));
        used[i] = 1;
        int cnt = 0;
        for (int j = 1; j <= n; ++j){
            if(!used[j]){
                ++cnt;
                dfs(j);
            }
        }
        if(cnt > cc) cout << i << " ";
    }
}
int main(){
    fast;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x) a[i].emplace_back(j);
        }
    }
    solve();
}
