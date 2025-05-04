#include <iostream>
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
int used[1000];
queue <int> q;
void BFS(vector <vector <int>> f, int i){
    q.push(i);
    used[i] = 1;
    while (q.size()){
        int j = q.front(); q.pop();
        cout << j << " ";
        for (int it : f[j]) 
            if(!used[it]) {
                q.push(it);
                used[it] = 1;
            }
    }
}
int main(){
    int n; cin >> n;
    vector <vector <int>> f(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x) f[i].push_back(j);
        }
    }
    BFS(f, 1);
}
