#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int>a(n), b(n);
    for (auto&ai : a) cin >> ai;
    for (auto& ai : b) cin >> ai;
    int ans = a[n-1];
    for (int i = 0; i < n-1;++i) {
        ans += max(0, a[i] - b[i+1]);
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