// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, m, v;
    cin >> n >> m >> v;
    vector<i64> a(n);
    input(a);
    vector<i64> b(n, 0);
    vector<i64> c(n, 0);
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        x += a[i];
        if (x >= v) {
            x = 0;
            y++;
        }
        b[i] = y;
    }
    x = y = 0;
    for (int i = n - 1; i >= 0; --i) {
        x += a[i];
        if (x >= v) {
            x = 0;
            y++;
        }
        c[i] = y;
    }
    vector<i64> ps(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        ps[i + 1] = ps[i] + a[i];
    }
    reverse(all(c));
    i64 ans = -1;
    for (int i = 0; i < n; ++i) {
        int nl = b[i];
        i64 curs = -1;
        if (nl >= m) {
            curs = ps[n] - ps[i + 1];
        } else {
            i64 nr = m - nl;
            auto it = lower_bound(all(c), nr);
            i64 ir = distance(c.begin(), it);
            if (n - ir - 1 >= 0) curs = ps[n - ir - 1] - ps[i + 1];
        }
        ans = max(ans, curs);
    }
    for (int i = 0; i < n; ++i) {
        int nr = c[i];
        if (nr >= m) {
            i64 curs = ps[n - 1 - i];
            ans = max(ans, curs);
        }
    }
    cout << ans << endl;
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