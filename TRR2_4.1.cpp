#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, deg[1001];
set <int> a[1001];

void euler(int u){
    stack <int> st;
    vector <int> ec;
    st.push(u);
    while (st.size())
    {
        int x = st.top();
        if(a[x].size()){
            int y = *a[x].begin();
            st.push(y);
            a[x].erase(y);
            a[y].erase(x);
        }
        else {
            st.pop();
            ec.push_back(x);
        }
    }
    reverse(ec.begin(), ec.end());
    for(int it : ec) cout << it << " ";
}
int main(){
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x) a[i].insert(j);
        }
    }
    euler(m);
}
