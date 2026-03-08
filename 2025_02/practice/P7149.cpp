//P7149.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    vector<int> xs{x}, ys{y};
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    for (int i = 0; i < n; ++i) {
        x[i] = lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
        y[i] = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin();
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int l, int r) {return x[l] < x[r];});
    vector dp(n + 1, vector<i64>(n + 1, 0));
    vector dp2(n + 1, vector<i64>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        int xi = x[ord[i]], yi = y[ord[i]];
        for (int j = 0; j < n; ++j) {
            if (j < yi) {
                dp[i+1][j+1] = dp[i][j+1];
            } else {
                // dp[i+1][j+1] = 1 + dp[i][j+1] + (dp[i][j+1]-dp[i][yi+1]);
                dp[i+1][j+1] = 1 + dp[i][j+1];
            }
        }
        for (int j = n-1; j>=0; --j) {
            if (j > yi) {
                dp2[i+1][j+1] = dp2[i][j+1];
            } else {
                // dp2[i+1][j+1] = 1 + dp2[i][j+1] + (dp2[i][j+1] - dp2[i][yi+1]);
                dp2[i+1][j+1] = 1 + dp2[i][j+1] ;
            }
        }
        // debug(dp[i+1 ]);
        // debug(dp2[i+1]);
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int yi = y[ord[i]];
        debug(dp[i][yi+1], dp2[i][yi+1]);
        ans = ans + (dp[i][yi+1]+1) * (dp2[i][yi+1] + 1);
        debug(ans);
    }
    cout << (ans+1) << endl;

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