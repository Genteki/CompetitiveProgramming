// d.cpp
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
void solve() {
    i64 n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return;
    }
    n -= 2;
    vector<i64> a(35, 0);
    a[0] = 9;
    a[1] = 9;
    for (i64 i = 2; i < 35; ++i) {
        if (i % 2 == 0) {
            a[i] = a[i-1] * 10;
        } else {
            a[i] = a[i - 1];
        }
    }
    i64 p = n, q = 0;
    while (p > a[q]) {
        p -= a[q];
        ++q;
    }

    vector<i64> ans(q+1);
    i64 k = 0;
    while(q > 1) {
        debug(p, q);
        q -= 2;

        a[q] = a[q] / 9 * 10;
        ans[k] = (p / a[q]);
        ++k;
        p = p % a[q];
    }
    ans[k] = p;
    ans[0]++;
    debug(a);
    i64 m = ans.size();
    for (i64 i = 0; i < m / 2; ++i) {
        ans[m - 1 - i] = ans[i];
    }
    for (auto ai : ans) {
        cout << ai;
    }
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}