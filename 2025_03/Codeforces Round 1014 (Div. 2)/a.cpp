#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &ai : a) cin >> ai;
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = a[j] - a[i];
            ans = max(ans, d);
        }
    }
    cout << ans << endl;
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