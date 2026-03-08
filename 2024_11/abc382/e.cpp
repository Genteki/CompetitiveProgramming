#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<double> p(n);
    for (auto &pi : p) {
        int px;
        cin >> px;
        pi = (double) px / 100.0;
    }

    vector<vector<double>> dp(n+1, vector<double>(n+1, 0.0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = dp[i-1][j] * (1 - p[i-1]);
        }
        for (int j = 1; j <= i; ++j) {
            dp[i][j] += dp[i-1][j-1] * p[i-1];
        }
    }
    debug(dp[n]);
    vector<double> e(k + n,0);
    e[0] = 0;
    auto &c = dp[n];
    for (int i = k - 1; i >= 0; --i) {
        for (int j = 1; j <= n; ++j) {
            e[i] += c[j] * e[i + j];
        }
        e[i] = (e[i] + 1) / (1 - c[0]);
    }
    cout << fixed << setprecision(16) << e[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}