#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define BOOST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

int t, n, m, u;
set <int> adj[10005];
vector <bool> mark(10005, false);

void DFS(int u){
    mark[u] = 1;
    for (int v : adj[u])
        if (!mark[v]) DFS(v);
}

void EulerCycle(int u)
{
    stack <int> st;
    st.push(u);
    vector <int> ans;
    while (!st.empty())
    {
        int x = st.top();
        if (adj[x].size() != 0)
        {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else
        {
            st.pop();
            ans.push_back(x);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int check1()
{
    for (int i = 1; i <= n; i++)
        if (adj[i].size() & 1) check = 1;
    return 1;
}

int check2()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() & 1) cnt++;
    }
    if (cnt == 2) return 1;
    else if (cnt == 1) return 1;
    return 0;
}

int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!mark[i])
        {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

int main()
{
    BOOST;
    cin >> t >> n >> m; 
    if (t == 2) cin >> u;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    if(t == 1){
        if (tplt() > 1) cout << 0;
        else
        {
            if (check1()) cout << 1;
            else if (check2()) cout << 2;
            else cout << 0;
        }
    }
    else EulerCycle(u);
    return 0;
}