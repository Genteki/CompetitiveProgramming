#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
bool chmin(i64& a, i64 b){ return b < a ? a = b, true : false; }
void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<i64> a(n), b(m);
    for (auto & ai : a) cin >> ai;
    for (auto & bi : b) cin >> bi;
    vector dp(n, vector<i64>(m+1, 2e9)), sub(n, vector<i64>(m));
    vector<pair<int,int>> mask(1 << m);
    for (int i = 0; i < (1 << m); ++i) {
        int val = (1<<30)-1;
        for (i64 d = 0; d < m; ++d) {
            if ((1 << d) & i) {
                val &= b[d];
            }
        }
        mask[i] = {val, __builtin_popcount(i)};
    }
    for (i64 i = 0; i < n; ++i) {
        dp[i][0] = a[i];
        for (auto&[m, j] : mask) {
            chmin(dp[i][j], a[i]&m);
        }
        for (i64 j = 0; j < m; ++j) {
            sub[i][j] = dp[i][j] - dp[i][j+1];
        }
    }
    i64 ans = 0;
    priority_queue<tuple<i64,i64,i64>> pq;
    for (i64 i = 0; i < n; ++i) {
        pq.emplace(sub[i][0], i, 0);
    }
    debug(dp);
    debug(sub);
    while(k--) {
        auto [delta, i, j] = pq.top();
        pq.pop();
        ans -= delta;
        if (j < m-1) pq.emplace(sub[i][j+1], i, j + 1);
    }
    ans += (accumulate(a.begin(), a.end(), 0LL));
    cout << ans << endl;
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