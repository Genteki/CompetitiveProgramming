#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;  --v;
        g[u].push_back(v);
        g[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    int ans = n;
    for (int u = 0; u < n; ++u) {
        sort(g[u].begin(), g[u].end(), [&](int lhs, int rhs)->bool{
            return deg[lhs] > deg[rhs];
        });
        int x = 0, y = 0;
        for (int v : g[u]) {
            x += 1;
            y = deg[v] - 1;
            ans = min(ans, n - (1 + x + x * y));
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}