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
    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(m));
    for (auto & ai : a) for (auto & aii : ai) cin >> aii;
    for (auto & ai : a) sort(ai.begin(), ai.end());
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](const int& lhs, const int& rhs) -> bool {
        return a[lhs][0] < a[rhs][0];
    });
    int last = -1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[ord[j]][i] > last) {
                last = a[ord[j]][i];
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (auto i: ord) cout << (i+1) << " ";
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