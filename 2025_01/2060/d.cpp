// d.cpp
#include <bits/stdc++.h>

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
    vector<i64> a(n);
    for (i64 & ai : a) cin >> ai;
    for (int i = 0; i < n-1; ++i) {
        i64 sub = min(a[i], a[i+1]);
        a[i] -= sub;
        a[i+1] -= sub;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i+1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    debug(a);
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