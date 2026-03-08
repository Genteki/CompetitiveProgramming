// e.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
bool chmax(i64& a, i64 b){ return b > a ? a = b, true : false; }
void solve() {
    i64 n, h;
    cin >> n >> h;
    vector<i64> a(n);
    i64 cnt = 0;
    for (auto & ai : a) cin >> ai;
    sort(a.begin(), a.end());
    vector dp(6, vector<i64>(n+1, h));
    for (int i = 0; i < n; ++i) {
        for (int g = 2; g >= 0; --g) {
            for (int b = 1; b >= 0; --b) {
                if (g < 2) {
                    chmax(dp[b*3+g][i], dp[b*3+(g+1)][i] * 2);
                }
                if (b < 1) {
                    chmax(dp[b*3+g][i], dp[3 + g][i] * 3);
                }
                if (dp[b*3 + g][i] > a[i]) {
                    dp[b*3 + g][i+1] = dp[b*3 + g][i] + a[i]/2;
                } else {
                    dp[b*3 + g][i+1] = dp[b*3 + g][i];
                }
            }
        } 
    }
    debug(dp[0]);
    cout << lower_bound(a.begin(), a.end(), dp[0][n]) - a.begin() << endl;
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