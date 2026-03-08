// e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const i64 MOD = 998244353;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto & ai : a) {
        cin >> ai;
    }
    i64 ans = 0;
    vector<i64> dp(n+1, 0);
    for (int i = 0; i < n; ++i) {
        i64 even = 0, odd = 0, mi = 1e9;
        dp[i] = 0;
        for (int j = i; j < n; ++j) {
            mi = min(mi, a[j]);
            if (j % 2 == 0) {
                dp[j+1] = max(dp[j], dp[j] + (a[j]-odd));
                ans += dp[j+1];
                even = max(even, a[j]);
            } else {
                dp[j + 1] = max(dp[j], dp[j] + (a[j] - even));
                ans += dp[j+1];
                odd = max(odd, a[j]);
            }
        }
        debug(dp);
    }
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}