#include <bits/stdc++.h>
using namespace std;
#define BOOST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    BOOST;
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    int t, n;
    fin >> t >> n;
    vector<int> deg_in(n + 1, 0), deg_out(n + 1, 0);
    vector<pair<int, int>> edges; // lưu các cạnh theo thứ tự từ điển

    // Đọc danh sách kề và lưu cạnh
    for (int i = 1; i <= n; ++i) {
        int k; fin >> k;
        for (int j = 0; j < k; ++j) {
            int x; fin >> x;
            deg_out[i]++;
            deg_in[x]++;
            edges.push_back({i, x});
        }
    }
    int m = edges.size();

    if (t == 1) {
        for (int i = 1; i <= n; ++i)
            fout << deg_in[i] << " " << deg_out[i] << "\n";
    } else {
        fout << n << " " << m << "\n";
        // Tạo ma trận liên thuộc
        vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j < m; ++j) {
            int u = edges[j].first;
            int v = edges[j].second;
            matrix[u][j + 1] = 1;
            matrix[v][j + 1] = -1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                fout << matrix[i][j] << " ";
            fout << "\n";
        }
    }
}
