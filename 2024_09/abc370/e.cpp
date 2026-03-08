// e.cpp
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 MOD = 998244353;

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    input(a);
    vector<i64> dp(n+1, 0);

    dp[0] = 1;  // There's one way to split an empty array

    // prefix_sum[i] stores the sum of the first i elements of the array
    vector<i64> prefix_sum(n + 1, 0), p2(n + 1);
    vector<vector<i64>> rng(n);
    map<i64, i64> mp;
    debug(rng);
    // This set will track the last valid partition point
    i64 acc = 1;
    for (int i = 1; i <= n; ++i) {
        mp[prefix_sum[i] - k] += a[k];
        for (int j = i - 1; j >= 0; --j) {
            i64 sum_subsequence = prefix_sum[i] - prefix_sum[j];
            if (sum_subsequence != k) {
                dp[i] += dp[j];
                dp[i] = (dp[i]) % MOD;
            }
        }
        acc = acc + dp[i];
    }
    debug(dp);
    // The result is the total number of ways to split N elements
    cout << dp[n] << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}