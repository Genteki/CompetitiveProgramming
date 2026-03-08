// e.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
int N = 1.2e6;
void solve() {
    vector<int> cnt(N+1, 0);
    vector<vector<int>> g(N+1);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j * i <= N; ++j) {
            g[i*j].push_back(j);
        }
    }
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (auto b : g[a[i]]) {
            cnt[b]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        debug(a[i], g[a[i]]);
        for (auto b : g[a[i]]) {
            if (cnt[b] >= m)ans = max(ans, b);
        }
        cout << ans << "\n";
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}