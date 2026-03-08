// e.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

const i64 N = 101 * 101 + 1;
void solve() {
    i64 n, x;
    cin >> n >> x;
    vector<i64> a(n), ca(n), b(n), cb(n);
    for (i64 i = 0; i < n; ++i) {
        cin >> a[i] >> ca[i] >> b[i] >> cb[i];
    }
    vector dp(n, vector<i64>(N, LONG_MAX));
    for (i64 i = 0; i < n; ++i) {
        dp[i][0] = 0;
    }
    for (i64 i = 0; i < n; ++i) {
        i64 c = a[i], cc = ca[i];
        for (i64 j = 0; j <= c; ++j) {
            dp[i][j] = min<i64>(dp[i][j], cc);
        }
        for (i64 j = 0; j <= N - c; ++j) {
            dp[i][j + c] = min(dp[i][j + c], dp[i][j] + cc);
        }
        c = b[i]; cc = cb[i];
        for (i64 j = 0; j <= c; ++j) {
            dp[i][j] = min<i64>(dp[i][j], cc);
        }
        for (i64 j = 0; j <= N - c; ++j) {
            dp[i][j + c] = min(dp[i][j + c], dp[i][j] + cc);
        }
        debug(dp[i][a[i] * b[i]]);
    }
    i64 low = 0, high = 2e9;
    while(high - low > 1) {
        i64 mid = (high + low ) / 2;
        i64 s = 0;
        i64 cur = LONG_MAX;

        for (i64 i = 0; i < n; ++i) {
            double cp = (double) a[i] * cb[i] / b[i] / ca[i];
            i64 c = cp > 1 ? a[i] : b[i];
            i64 cc = cp > 1 ? ca[i] : cb[i];
            i64 d = cp > 1 ? b[i] : a[i];
            i64 dd = cp > 1 ? cb[i] : ca[i];
            i64 local_s = (mid / c * cc) + dp[i][mid % c];
            for (int j = 0; j <= min(d, mid / c); ++j) {
                local_s = min<i64>(
                    local_s, ((mid / c - j) * cc) + dp[i][mid % c + j * c]);
            }
            s += local_s;
        }

        if (s > x) {
            high = mid;
        } else {
            low = mid;
        }
        debug(mid, s, x);
    }
    cout << low;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}