#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fixs(x, n) fixed << setprecision(n) << x
#define setf(x, n, c) setw(n) << setfill(c) << x
//ITIS LA NHA

int used[10000], pre[10000];
void DFS(int u, vector<vector<int>> a) {
    used[u] = 1;
    for (int it : a[u]){
        if (!used[it]){
            cout << min(it, u) << " " << max(it, u) << endl;
            DFS(it, a);
        }
    }
}

void BFS(int u, vector <vector <int>> a){
    queue <int> q;  q.push(u);
    used[u] = 1;
    while (q.size())
    {
        int i = q.front(); q.pop();
        for (int it : a[i])
        {
            if(!used[it]){
                cout << min(it, i) << " " << max(it, i) << endl;
                used[it] = 1;
                q.push(it);
            }
        }
    }
}

int main() {
    fast;
    int n, k; cin >> n >> k;
    vector <vector <int>> a(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x) a[i].push_back(j);
        }
    }
    memset(used, 0, sizeof(used));
    cout << "DFS tree\n";
    DFS(k, a);
    memset(used, 0, sizeof(used));
    cout << "BFS tree\n";
    BFS(k, a);

}
