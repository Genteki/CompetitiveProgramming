#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai : a) {
        cin >> ai;
        --ai;  // Adjust for zero-based indexing
    }

    vector<vector<int>> g(n);  // Array to store the indices of each number
    for (int i = 0; i < n; ++i) {
        g[a[i]].push_back(i);
    }

    debug(g);

    i64 ans = 0;

    // Iterate through each distinct element
    for (int i = 0; i < n; ++i) {
        i64 s = -1, t;
        for (int j = 0; j < g[i].size(); ++j) {
            t = g[i][j];
            // Calculate subarray sums between s+1 and t
            ans += (t - s) *
                   (n - t);  // Contribution of element `i` between `s` and `t`
            debug(s, t, ans);
            s = t;
        }
    }

    cout << ans << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}