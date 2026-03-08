// g.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for (auto& ai : (x)) std::cin >> ai

using namespace std;
constexpr int inf = 1e9;


void solve() {
    int n, m;
    cin >> n;
    vector g(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(n);
    int ans = -1;

    for (int i = 0; i < n; ++i) dp[i] = g[i].size() - 2;
    auto dfs = [&](this auto&& self, int u, int p = -1) -> void {
        int x = dp[u];
        ans = max(ans, x);
        for (auto v : g[u]) {
            if (v == p) continue;
            self(v, u);
            ans = max(ans, dp[u] + dp[v]);
            dp[u] = max(dp[u], x + dp[v]);
        }
    }; 
    dfs(0);
    cout << max(1, ans + 2) << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}