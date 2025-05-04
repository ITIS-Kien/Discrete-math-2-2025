#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fixs(x, n) fixed << setprecision(n) << x
#define setf(x, n, c) setw(n) << setfill(c) << x
//ITIS LA NHA

int used[10000];
void DFS (int u, vector <vector <int>> a){
    used[u] = 1;
    for (int it : a[u])
        if(!used[it]) DFS(it, a);
}
int main(){
    int n, cnt = 0; cin >> n;
    vector <vector <int>> a(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x) a[i].push_back(j);
        }
    }
    // for (int i = 1; i <= n; i++){
    //     for (int it : a[i]) cout << it << " ";
    //     cout << endl;
    // }
    for (int i = 1; i <= n; i++){
        if(!used[i]){
            cnt++;
            DFS(i, a);
        }
    }
    cout << cnt;
    
}
