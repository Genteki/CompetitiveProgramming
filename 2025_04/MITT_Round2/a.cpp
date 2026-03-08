#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &ai : a) cin >> ai;
    for (auto &ai : b) cin >> ai;
    for (int i = 0; i < n; ++i) c[i] = b[i] - a[i];
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int l, int r) -> bool { return c[l] < c[r]; });
    i64 s = 0;
    for (auto &i : ord) {
        if (c[i] <= 0) {
            s += a[i];
        } else {
            if (s < c[i]) {
                cout << "NO\n";
                return;
            }
            s += a[i];
        }
    }
    cout << "YES" << endl;
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