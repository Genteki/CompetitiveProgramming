#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
void solve() {
    int n;
    cin >> n;
    vector a(n, vector<i64>(n));
    for (auto & ai : a) for (auto &aii : ai) cin >> aii;

    vector dp((n), vector<i64>(1 << n, 0));
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j  <n ;++j) {
            for (int k = j + 1; k < n; ++k) {
                if (((i>>j)&1) and ((i>>k) & 1)) {
                    dp[0][i] += a[j][k];
                }
            }
        }
        for (int j = 1; j < n; ++j) {
            int x = i;
            while(x > 0) {
                dp[j][i] = max(dp[j][i], dp[j-1][i^x] + dp[0][x]);
                x = (x-1) & i;
            }
        }
    }
    cout << dp[n-1][(1<<n)-1];
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