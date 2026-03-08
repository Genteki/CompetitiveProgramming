// e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n), b(n), c(n);
    i64 ans = LLONG_MAX;
    for (i64 i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        c[i] = b[i] - a[i];
    }
    i64 sa = accumulate(a.begin(), a.end(), 0LL);
    i64 sb = accumulate(b.begin(), b.end(), 0LL);
    i64 min_b = *min_element(b.begin(), b.end());
    if (sa > (sb - min_b)) {
        cout << -1 << endl;
        return;
    }
    vector<i64> orda(n);
    iota(orda.begin(), orda.end(), 0);
    sort(orda.begin(), orda.end(), [&](i64 lhs, i64 rhs) {
        if (a[lhs] != a[rhs]) {
            return a[lhs] < a[rhs];
        } else {
            return b[lhs] > b[rhs];
        }
    });
    i64 blocki = -1;
    for (auto i : orda) {
        if (a[i] >= b[i] and b[i] <= sb - sa) {
            blocki = i;
        }
    }

    debug(blocki);
    if (blocki != -1) {
        i64 cost = 0, vac = 0;

        for (auto i : orda) {
            if (a[i] <= b[i] and i != blocki) {
                if (vac < a[i]) {
                    cost += (a[i] - vac);
                    vac = b[i];
                } else {
                    vac += (b[i] - a[i]);
                }
            }
        }
        reverse(orda.begin(), orda.end());
        for (auto i : orda) {
            if (a[i] > b[i] and i != blocki) {
                if (vac >= a[i]) {
                    vac -= (a[i] - b[i]);
                } else {
                    cost += (a[i] - vac);
                    vac = b[i];
                }
            }
        }
        reverse(orda.begin(), orda.end());
        ans = min(ans, cost + sa);
    }
    for (auto i : orda) {
        if (b[i] <= sb - sa) {
            blocki = i;
        }
    }
    if (blocki != -1) {
        i64 cost = 0, vac = 0;

        for (auto i : orda) {
            if (a[i] <= b[i] and i != blocki) {
                if (vac < a[i]) {
                    cost += (a[i] - vac);
                    vac = b[i];
                } else {
                    vac += (b[i] - a[i]);
                }
            }
        }
        reverse(orda.begin(), orda.end());
        for (auto i : orda) {
            if (a[i] > b[i] and i != blocki) {
                if (vac >= a[i]) {
                    vac -= (a[i] - b[i]);
                } else {
                    cost += (a[i] - vac);
                    vac = b[i];
                }
            }
        }
        reverse(orda.begin(), orda.end());
        ans = min(ans, cost + sa);
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