// c.cpp
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
    vector<vector<int>> a(n, vector<int>(n));
    for (auto & ai : a) for (auto & aii : ai) cin >> aii;
    vector<vector<int>> suf(n, vector<int>(n+1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            suf[i][j+1] = suf[i][j] + a[i][n-1-j];
        }
    }
    vector<int> x(n);
    for (int i = 0; i < n ; ++i) {
        for (int j = 0; j < n; ++j) {
            if (suf[i][j] == j) {
                x[i] = max(x[i], j);
            }
        }
    }
    sort(x.begin(), x.end());
    int y = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] >= y) {
            ++y;
        }
    }
    cout << y << endl;
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