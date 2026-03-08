// h.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const i64 MOD = 1000000007;

void solve() {
    i64 l, r, y,;
    cin >> l >> r >> y >> k;
    long long ans = (F(r, k, y) - F(l - 1, k, y)) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
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