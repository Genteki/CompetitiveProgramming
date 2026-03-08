// e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n,k;
    cin >> n >> k;
    int m = n*k;
    vector<vector<int>> g(m);
    for (int i = 0; i < m-1; ++i) {
        int u, v;
        cin >> u>> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(m, 0);
    auto dfs = [&](auto&& self, int u, int p=-1) -> bool {
        if (g[u].size() == 1 && g[u][0] == p) {
            dp[u] = 1;
            dp[u] %= k;
            return true;
        }
        bool r = true;
        vector<int> x;
        for (auto v : g[u]) {
            if (v== p) continue;
            r &= self(self, v, u);
            if (!r) return false;
            if(dp[v] != 0) x.push_back(dp[v]);
        }
        if (x.size() > 2) {
            return false;
        } else if (x.size() == 2) {
            if (x[0] + x[1] + 1 == k) {
                dp[u] = 0;
                return true;
            } else {
                return false;
            }
        } else if (x.size() == 1) {
            dp[u] = (x[0]+1)%k;
            return true;
        } else {
            dp[u] = 1%k;
            return true;
        }
        return r;
    };
    bool ans = dfs(dfs, 0);
    debug(dp);
    if (ans) cout << "Yes";
    else cout << "No";
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}