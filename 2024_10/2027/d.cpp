// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 INF  = 1e9;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n), b(m);
    input(a);
    input(b);
    vector<vector<i64>> dp(n + 1, vector<i64>(m, INF));
    vector<i64> ps(n + 1, 0);
    for (int i = 0; i < n; ++i) ps[i+1] = ps[i] + a[i];
    dp[0][0] = 0;
    for (i64 i = 0; i <= n; ++i) {
        for (i64 j = 0; j < m; ++j) {
            if (j > 0) dp[i][j] = min(dp[i][j-1], dp[i][j]);
            i64 s = ps[i] - b[j];
            auto it = lower_bound(all(ps), s);
            i64 l = it - ps.begin();
            if (l < i) dp[i][j] = min(dp[i][j], dp[l][j] + (m - j - 1));
        }
    }
    debug(dp);
    i64 ans = *min_element(all(dp[n]));
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
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