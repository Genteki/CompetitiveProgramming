// d.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

typedef long long i64;
const i64 M = 61;
bool chmin(i64& a, i64 b){ return b < a ? a = b, true : false; }
vector dp(M+1, vector<i64>(M+1, LLONG_MAX));

void solve() {
    i64 x, y;
    cin >> x >> y;
    i64 ans = LLONG_MAX;
    for (i64 i = 0; i <= M; ++i) {
        for (i64 j = 0; j <= M; ++j) {
            if ((x>>i) == (y>>j)) {
                chmin(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    dp[0][0] = 0;
    for (i64 k = 1; k <= M; ++k) {
        for (i64 i = M; i >= 0; --i) {
            for (i64 j = M; j >= 0; --j) {
                if (dp[i][j] == LLONG_MAX) continue;
                chmin(dp[min(k + i, M)][j], dp[i][j] + (1LL << k));
                chmin(dp[i][min(k + j, M)], dp[i][j] + (1LL << k));
            }
        }
    }
    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}