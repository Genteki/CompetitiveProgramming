// e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    i64 n, x;
    cin >> n >> x;
    vector<i64> a(n), b(n);
    for (auto & ai : a) cin >> ai;
    for (auto & bi : b) cin >> bi;
    i64 ans = 1;
    for (i64 i = 0; i < n; ++i) {
        i64 t = min(a[i], b[i]);
        a[i] -= t;
        b[i] -= t;
    }
    vector<i64> r(n, 0);
    deque<pair<i64,i64>> dq;
    i64 s = 0;
    for (i64 i = 0; i < n*2; ++i) {
        debug(i, a, b);
        debug(dq);
        if (a[i%n]) {
            dq.emplace_back(i, a[i%n]);
        } else if (!dq.empty()) {
            i64 p = b[i%n];
            while(p && !dq.empty()) {
                auto& [k, d] = dq.back();
                ans = max<i64>(ans, i-k+1);
                if (d <= p) {
                    p -= d;
                    dq.pop_back();
                    a[k%n] = 0;
                } else {
                    dq.back().second -= p;
                    a[k%n] = d;
                    p = 0;
                }
            }
            b[i%n] = p;
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}