#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto &ai : a) cin >> ai;
    i64 s = accumulate(a.begin(), a.end(), 0LL);

    vector dp(d + 1, vector<i64>(1 << n, 0));
    for (i64 m = 0; m < (1 << n); ++m) {
        for (i64 i = 0; i < n; ++i) {
            if ((m >> i) & 1) {
                dp[1][m] += a[i];
            }
        }
        dp[1][m] *= dp[1][m];

        for (i64 j = 2; j <= d; ++j) {
            dp[j][m] = dp[j - 1][m] + dp[1][0];
            i64 x = (m);
            while (x > 0) {
                dp[j][m] = min(dp[j][m], dp[1][x] + dp[j - 1][x ^ m]);
                x = (x - 1) & m;
            }
        }
    }
    i64 d3 = d * d * d;
    long double ans = (long double)(dp[d][(1 << n) - 1] * d - (s * s)) / (d*d);
    cout << fixed << setprecision(16) << ans;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    //    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}