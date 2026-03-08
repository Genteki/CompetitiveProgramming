// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n, k;
    cin >> n >> k;
    auto calc = [&](auto&& self, i64 n, i64 k) -> pair<i64, i64> {
        if (n < k) {
            return {0LL, 0LL};
        }
        if ((n % 2) == 0) {
            auto [cntChild, sumChild] = self(self, n / 2, k);
            i64 cnt = 2LL * cntChild;
            i64 sum = 2LL * sumChild + (n / 2) * cntChild;
            return {cnt, sum};
        } else {
            auto [cntChild, sumChild] = self(self, (n - 1) / 2, k);
            i64 cnt = 1LL + 2LL * cntChild;
            i64 sum = ((n + 1) / 2) + 2LL * sumChild + ((n + 1) / 2) * cntChild;
            return {cnt, sum};
        }
    };

    auto [_, ans] = calc(calc, n, k);
    cout << ans << "\n";
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