// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    int d = n - k;
    int ans = k / 2 + 1;
    int cnt = 1;
    int idx = 0;
    for (int i = 1; i <= k/2; ++i) {
        debug(i, idx);
        ++idx;
        bool flag = true;
        for (int x = 0; x <= d; ++x) {
            if (a[x + idx] != i) flag = false;
        }
        if (!flag) {
            cout << i << endl;
            return;
        } else {
            if (d) {
                cout << (i + 1) << endl;
                return;
            }
            idx++;
        }
    }
    cout << (k/2+1) << endl;
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