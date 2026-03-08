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
    vector<i64> a(2*n);
    for (auto& ai : a) cin >> ai;
    vector<i64> b(n*2+1);
    sort(a.begin(), a.end());
    i64 x = 0;
    for (int i = 0; i < n-1; ++i) {
        x -= a[i];
    }
    for (int i = n-1; i < 2*n; ++i) {
        x += a[i];
    }
    b[1] = x;
    for (int i = 0; i < n-1; i++) {
        b[3+i*2] = a[i];
    }
    for (int i = 0; i < n+1; ++i) {
        b[i*2] = a[i+n-1];
    }
    for (auto bi : b) cout << bi << " "; cout << endl;
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