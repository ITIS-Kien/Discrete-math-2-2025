#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define nguyentukien ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;

struct edge{
    int x, y, val;
    edge (int x, int y, int val){
        this->x = x;
        this->y = y;
        this->val = val;
    }
    bool operator < (const edge& other){
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
};


signed main(){
    nguyentukien
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n; fin >> t >> n;
    vector <int> degin(109, 0), degout(109, 0);
    vector <edge> adj;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int x; fin >> x;
            if(x != 0 and x != 10000){
                ++degout[i];
                ++degin[j];
                adj.push_back(edge(i, j, x));
            }
        }
    }
    if(t == 1){
        for (int i = 1; i <= n; ++i) fout << degin[i] << " " << degout[i] << endl;
    } else {
        fout << n << " " << adj.size() << endl;
        // sort(adj.begin(), adj.end());
        for (edge it : adj){
            fout << it.x << " " << it.y << " " << it.val << endl;
        }
    }
    
}