#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
bool chmax(i64& a, i64 b){ return b > a ? a = b, true : false; }
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    i64 even_max = -1e18, odd_max = -1e18;
    vector<i64> dp(1+n, -1e18);
    dp[0] = 0;
    odd_max = 0;
    for (int i = 0; i < n; ++i) {
        dp[i+1] = dp[i] + a[i];
        if (i >= 1) {
            if (i % 2 == 1) {
                chmax(dp[i+1], odd_max);
            } else {
                chmax(dp[i+1], even_max);
            }
        }
        if (i % 2 == 1) {
            chmax(odd_max, dp[i+1]);
        } else {
            chmax(even_max, dp[i+1]);
        }
    }
    cout << dp[n];
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}