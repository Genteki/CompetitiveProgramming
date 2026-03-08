// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

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
    vector<int> a(n);
    input(a);
    vector<int> b(n, 0), d(n);

    int x = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > x) {
            d[i] = 1;
        } else if (a[i] == x) {
            d[i] = 0;
        } else {
            d[i] = -1;
        }
        x += d[i];
        b[i] = x;
    }
    vector<int> c(n);
    c[0] = 0;
    int bm = 0;
    for (int i = 1; i < n; ++i) {
        bm = max(bm, b[i-1]);
        if (c[i-1] < a[i]) {
            c[i] = c[i-1] + 1;
        } else if (c[i-1] == a[i]) {
            c[i] = c[i-1];
        } else {
            c[i] = c[i-1] - 1;
        }
        c[i] = max(c[i], bm);
    }
    cout << c[n-1] << endl;
    debug(b);
    debug(c);
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