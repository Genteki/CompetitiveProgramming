// c.cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
const i64 mod = 998244353;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) cin >> ai;
    vector<i64> dp(n + 1, 0);
    dp[0] = 1;
    if (a[0] == 0) {
        dp[1] = 1;
    } else {
        dp[1] = 0;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            dp[i + 1] += dp[i];
        }
        if (i >= 2 and a[i] == a[i - 2] + 1) {
            dp[i + 1] += dp[i - 1];
        } else if (i == 1) {
            if (a[i] == 1) {
                dp[i + 1] += 1;
            }
        }
        dp[i + 1] %= mod;
    }
    cout << ((dp[n] + dp[n - 1]) % mod) << endl;
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