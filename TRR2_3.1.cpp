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
int used[1000];
void DFS(vector <vector <int>> f, int i){
    cout << i << " ";
    used[i] = 1;
    for (int it : f[i]) if(!used[it]) DFS(f, it);
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
    DFS(f, 1);
}
