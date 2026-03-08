// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), b(n);
    input(a);
    if (n == 1) {
        cout << "0" << endl;
        return;
    }
    vector<i64> ans(n), c(n, -1);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] - a[(i + 1) % n];
    }
    // c[i] = ans[i] + ans[i + 1]
    c[0] = 0;
    for (int i = 0, j =0; j < n-1; ++j) {
        c[(i+2) % n] = c[i] + b[(i + 1) % n];
        i = (i + 2) % n;
    }

    // check
    if (c[0] != c[n-2] + b[n-1]) {
        cout << -1 << endl;
        return;
    }
    i64 p = *min_element(all(c));
    for (auto & ci : c) ci -= p;
    debug(c);

    i64 s = accumulate(all(c), 0LL);
    if (s % 2 == 1) {
        for (auto & ci : c) {
            ci ++;
        }
        s += n;
    }
    i64 s_ = 0;
    for (i64 i = 1; i < n; i += 2) {
        s_ += c[i];
    }
    debug(s , s_);
    ans[0] = s / 2 - s_;
    for (int i = 0; i < n-1; ++i) {
        ans[i + 1] = c[i] - ans[i];
    }
    p = *min_element(all(ans));
    for (auto & ai : ans) {
        cout << (ai - p) << " ";
    }
    cout << endl;
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