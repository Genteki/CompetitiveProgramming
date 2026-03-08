// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
constexpr i64 mod = 1e9+7;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& ai : a) cin >> ai;

    vector<i64> ps(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] ^ a[i - 1];
    }
    map<i64,i64> mp;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        mp[ps[i]] = mp[ps[i]] * 3 + mp[ps[i+1]] * 2;
        mp[ps[i]] %= mod;
    }
    i64 ans = 0;
    for (auto [_, x] : mp) ans += x;
    cout << ans << endl;
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