#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long i64;
const i64 MOD = 998244353;
void solve() {
    int n, k;
    cin >> n >> k;
    k = abs(k);
    vector dp(n+1, vector<i64>(n+1, 0));
    // brute force
    dp[1][0] = 1; dp[1][1] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i+1][i] = 1;
        for (int j = i-1; j > 0; --j) {
            dp[i+1][j] = dp[i][j] * (i-1) + dp[i][j+1] + dp[i][j-1];
            dp[i+1][j] %= MOD;
        }
        dp[i+1][0] = dp[i][0] * (i-1) + 2 * dp[i][0+1];
        dp[i+1][0] %= MOD;
    }
    cout << dp[n][k]; 
    if(n<100)debug(dp);
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