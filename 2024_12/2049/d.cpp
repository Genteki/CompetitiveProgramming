#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const i64 INF = 1e18;
bool chmin(i64& a, i64 b) { return b < a ? a = b, true : false; }
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, m;
    i64 k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& row : a) {
        for (auto& val : row) cin >> val;
    }

    vector dp(n + 1, vector<vector<i64>>(m + 1, vector<i64>(m + 1, INF)));

    for (int s = 0; s < m; ++s) {
        dp[1][1][s] = (i64)s * k + a[0][(0 + s) % m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int s = 0; s < m; ++s) {
                if (i == 0 and j == 0) continue;
                dp[i + 1][j + 1][s] =
                    min(dp[i][j + 1][m] + k * s, dp[i + 1][j][s]) + a[i][(j+s)%m];
            }
        }
        for (int j = 1; j <= m; ++j) {
            for (int s = 0; s < m; ++s) chmin(dp[i + 1][j][m], dp[i + 1][j][s]);
        }
    }

    i64 res = INF;
    for (int s = 0; s < m; ++s) {
        res = min(res, dp[n][m][s]);
    }
    debug(dp);
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}