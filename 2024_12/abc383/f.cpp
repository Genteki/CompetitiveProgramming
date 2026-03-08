#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, x, k;
    cin >> n >> x >> k;
    vector<i64> p(n), u(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> u[i] >> c[i];
    }
    vector<i64> cs = c;
    sort(all(cs));
    cs.erase(unique(all(cs)), cs.end());

    for (i64& ci : c) {
        ci = distance(cs.begin(), lower_bound(all(cs), ci)) + 1;
        debug(ci);
    }
    i64 nc = cs.size();
    vector<vector<i64>> dp(nc+1, vector<i64>(x+1, 0));
    vector<i64> s(n, 0);
    iota(all(s), 0);
    sort(all(s), [&](int a, int b) -> bool{ return c[a] < c[b]; });
    for (auto i : s) {
        for (int j = p[i]; j >= 0; --j) {
            dp[c[i]][j] = max(dp[c[i]-1][j], dp[c[i]][j]);
        }
        for (int j = x; j >= p[i]; --j) {
            dp[c[i]][j] = max({dp[c[i]][j], dp[c[i]][j-p[i]] + u[i], dp[c[i]-1][j-p[i]] + u[i] + k, dp[c[i]-1][j]});
        }
        debug(dp);
    }
    debug(dp);
    cout << dp.back().back();
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