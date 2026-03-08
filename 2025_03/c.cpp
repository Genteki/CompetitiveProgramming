// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    int m = *max_element(a.begin(), a.end());
    vector<int> b(m+1, -1);
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        if (b[a[i]] == -1) {
            b[a[i]] = i;
        } else {
            ans = min(1 + i - b[a[i]], ans);
            b[a[i]] = i;
                }
    }
    if (ans == 1e9) {
        cout << -1;
    } else cout << ans;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}