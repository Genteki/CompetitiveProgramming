// e.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
long long mod = 998244353;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, q;
    cin >> n >> q;
    vector<i64> p(n, -1);
    vector<vector<i64>> g(n);
    for (i64 i = 0; i < n - 1; ++i) {
        i64 u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto &&self, i64 u, i64 parent = -1) -> void {
        p[u] = parent;
        for (i64 v : g[u]) {
            if (v == parent) continue;
            self(self, v, u);
        }
    };
    dfs(dfs, 0);
    vector<array<i64, 2>> dp(n);
    dp[0][0] = 0; dp[0][1] = 0;
    auto dfs2 = [&](auto&&self, i64 u, i64 p = -1) -> void {
        for (auto v : g[u]) {
            if (v == p) continue;
            dp[v][0] = dp[u][1] + 1;
            dp[v][1] = (2 * (i64)g[v].size()) - 1 + dp[u][0];
            self(self, v, u);
        }
    };
    vector<vector<array<i64, 2>>> dp2(n + 1, vector<array<i64, 2>>(n));
    for (auto &dp2i : dp2) {dp2i[0][0] = 0; dp2i[0][1] = 0;}
    auto dfs3 = [&](auto&&self, i64 u, i64 c, i64 p = -1) -> void {
        for (auto v : g[u]) {
            if (v== p) continue;
            dp2[c][v][0] = dp2[c][u][1] + 1;
            dp2[c][v][1] = min(
                dp2[c-1][u][0] + 1,
                2 * (i64)g[v].size() - 1 + dp2[c][u][0]
            );
            self(self, v, c, u);
        }
    };
    dfs2(dfs2, 0);
    dp2[0] = dp;

    for (i64 c = 1; c <= n; ++c) dfs3(dfs3, 0, c);

    debug(dp2);
    debug(dp2[1][9][1]);
    debug(dp2[1][7][0], dp2[0][7][0]);
    debug(dp2[1][5][1], dp2[0][7][0]);
    while (q--) {
        i64 v, c;
        cin >> v >> c;
        --v;
        cout << (dp2[min(n, c)][v][0] % mod) << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}