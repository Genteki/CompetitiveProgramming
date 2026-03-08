// e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto& ai : a) cin >> ai;
    i64 val = 0;
    i64 ans = 0;
    if (k > n/2) {
        k = n - k;
        for (auto ai : a) val ^= ai;
    }
    auto dfs = [&](auto&&self, int d, int digit) -> void {
        if (d == k) {
            ans = max(ans, val);
        } else {
            for (int i = digit; i < n-(k-d)+1; ++i) {
                val ^= a[i];
                self(self, d+1, i+1);
                val ^= a[i];
            }
        }
    };
    dfs(dfs, 0, 0);
    cout << ans;
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