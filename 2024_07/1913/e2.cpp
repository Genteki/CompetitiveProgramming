#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
constexpr int inf = 0x3f3f3f3f;
typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (auto& ai : g) input(ai);
    vector<int> a(n), b(m);
    input(a);
    input(b);

    int sa = accumulate(all(a), 0);
    int sb = accumulate(all(b), 0);
    if (sa != sb) {
        cout << -1 << endl;
        return;
    }

    int N = n + m + 2;
    int i_row = 0, i_col = n, source = N - 2, sink = N - 1;
    vector<vector<int>> adj(N);
    vector<vector<int>> capacity(N, vector<int>(N, 0));
    int all1 = 0;
    for (int i = 0; i < n; ++i) {
        adj[source].push_back(i_row+i);
        adj[i_row+i].push_back(source);
        capacity[source][i_row] = a[i];
    }
    for (int j = 0; j < m; ++j) {
        adj[i_col+j].push_back(sink);
        adj[sink].push_back(i_col + j);
        capacity[i_col+j][sink] = b[j];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            adj[i_row + i].push_back(i_col + j);
            adj[i_col + j].push_back(i_row + i);
            if (g[i][j] == 0) {
                capacity[i_row + i][i_col + j] = 1;
            } else {
                capacity[i_col + j][i_row + i] = 1;
                if (capacity[source][i_row+i]) {
                    capacity[source][i_row + i]--;
                } else {
                    capacity[i_row + i][source]++;
                }
                if (capacity[sink][i_col + j]) {
                    capacity[source][i_row + i]--;
                } else {
                    capacity[i_row + i][source]++;
                }
            }
        }
    }
   
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
    return 0;
}