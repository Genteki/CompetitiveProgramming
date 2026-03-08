#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        --u; --v;
        g[u].emplace_back(v, d);
        g[v].emplace_back(u, d);
    }
    vector<i64> d(n, -1);
    auto dfs = [&](auto && self, int u, int p) -> int {
        int mxv = u;
        i64 mxd = 0;
        if (g[u].size() == 1 && g[u][0].first == p) {
            d[u] = 0;
            return u;
        }
        for (auto & [v, l] : g[u]) {
            if (v == p) continue;
            int tmp_mxv = self(self, v, u);
            d[tmp_mxv] += (l * 2);
            debug(u, tmp_mxv, d);

            if (d[tmp_mxv] > mxd) {
                mxd = d[tmp_mxv];
                mxv = tmp_mxv;
            }
        }
        return mxv;
    };
    dfs(dfs, 0, -1);
    debug(d);

    sort(all(d), std::greater<i64>());
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] > 0) {
            ans += d[i];
        }
        cout << ans << endl;
    }
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}