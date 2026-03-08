#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    i64 ans = 0;
    vector<vector<i64>> dp(n - 1, vector<i64>(k - 1, 0));
    vector<i64> s(k, 0);
    dp[0][0] = 1; s[0] = 1;
    for (int i = 1; i <= n-2; ++i) {
        for (int j = 0; j <= k-2; ++j) {
            // dp[i][j] = dp[i-1][j-1] + dp[i-3][j-1] + dp[i-4][j-1] + ...
            dp[i][j] = 0;

            if (j > 0) {
                dp[i][j] += s[j-1];
                if (i >= 2) dp[i][j] -= dp[i - 2][j - 1];
            }
            if (j == k-2) {
                dp[i][j] += s[j];
                if (i >= 2) dp[i][j] -= dp[i-2][j];
            }
            dp[i][j] %=mod;
        }
        for (int j = 0; j <= k-2; ++j) {
            s[j] += dp[i][j];
            s[j] %= mod;
        }
    }

    for (i64 i = 2; i <= n; ++i) {
        i64 increment = (i-1) * dp[n-i][k-2];
        increment %= mod;
        ans = (ans + increment) % mod;
    }
    cout << ans;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}