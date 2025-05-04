#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fixs(x, n) fixed << setprecision(n) << x
#define setf(x, n, c) setw(n) << setfill(c) << x
//ITIS LA NHA
int used[1000];
stack <int> st;
void DFS(vector <vector <int>> f, int i){
    st.push(i);
    used[i] = 1;
    while (st.size())
    {
        int i = st.top(); st.pop();
        cout << i << " ";
        for (int j = f[i].size() - 1; j >= 0; j--){
            if(!used[f[i][j]]){
                st.push(f[i][j]);
                used[f[i][j]] = 1;
            }
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
    DFS(f, 1);
}
