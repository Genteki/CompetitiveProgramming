// e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n,x;
    cin >> n >> x;
    vector<i64> v(n), a(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i] >> a[i] >> c[i];
        --v[i];
    }

    vector dp(3, vector<i64>(x+2, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = x; j - c[i] >= 0; --j) {
            dp[v[i]][j] = max(dp[v[i]][j], dp[v[i]][j - c[i]] + a[i]);
        }
    }

    i64 low = 0, high = 1e14;
    while(high - low > 1) {
        i64 mid = (high + low) / 2;
        i64 y[3];
        for (int i = 0; i < 3; ++i) {
            y[i] = lower_bound(dp[i].begin(), dp[i].end(), mid) - dp[i].begin();
        }
        if (y[1] + y[2] + y[0] <= x) {
            low = mid;
        } else {
            high = mid;
        }
    }
    debug(dp);
    cout << low;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    for (; test_cases--;) {
        solve();
    }
}