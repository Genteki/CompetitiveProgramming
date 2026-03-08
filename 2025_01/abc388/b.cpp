#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> l(n), t(n);
    for (int i = 0; i < n; ++i) cin >> t[i] >> l[i];
    for (int i = 1; i <= k; ++i) {
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = max(ans, (l[j]+i) * t[j]);
        }
        cout << ans << endl;
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