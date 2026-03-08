// 1083e.cpp
// [CHT] [Convex Hull]
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

bool chmax(i64& a, i64 b) { return b >= a ? a = b, true : false; }
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    i64 n;
    cin >> n;
    vector<i64> x(n + 1), y(n + 1), a(n + 1);
    for (i64 i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> a[i];
    }
    vector<i64> ord(n + 1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(),
         [&](i64 l, i64 r) -> bool { return x[l] < x[r]; });
    vector<i64> dp(n + 1, 0);
    dp[0] = 0;
    /*
        dp[i]
            = max{dp[j] + (x[i] - x[j]) * y[i]} - a[i], for j < i
            = max{dp[j] + x[i]y[i] - x[j]y[i]} - a[i], for j < i
            = x[i]y[i] - a[i] + max{dp[j] - x[j]y[i]}, for j < i
    */
    auto f = [&](i64 j, i64 y) -> i64 { return dp[j] - x[j] * y; };
    auto g = [&](i64 i, i64 j) -> i64 {
        i64 r = x[i] * y[i] + dp[j] - x[j] * y[i] - a[i];
        return r;
    };
    auto h = [&](i64 i, i64 j) -> long double {
        i64 db = dp[i] - dp[j];
        i64 dk = x[i] - x[j];
        return (long double)(db) / (double)dk;
    };
    deque<i64> dq;
    dq.push_back(ord[0]);
    debug(x);
    for (i64 pi = 1; pi <= n; ++pi) {
        i64 i = ord[pi];
        while (dq.size() > 1 and g(i, dq[0]) <= g(i, dq[1])) {
            dq.pop_front();
        }
        dp[i] = dp[ord[pi - 1]];
        if (chmax(dp[i], g(i, dq.front()))) {
            while (dq.size() > 1 and h(i, dq.back()) >= h(i, dq.rbegin()[1])) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

    }
    cout << dp[ord[n]];
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}