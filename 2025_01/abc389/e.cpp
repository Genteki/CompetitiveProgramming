// e.cpp
#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> p(n);
    for (i64& pi : p) cin >> pi;
    __int128_t low = 0, high = m;
    while(high - low > 1) {
        i64 mid = (high + low) / 2;
        __int128_t cost = 0;
        for (auto pi : p) {
            __int128_t k = (mid / pi + 1) / 2;
            __int128_t tmp = k * k * pi;
            cost += k * k * pi;
        }
        if (cost > m) high = mid;
        else low = mid;
    }
    i64 ans = 0;
    for (auto pi : p) {
        __int128_t k = (low / pi + 1) / 2;
        ans += k;
        m -= (k*k*pi);
    }
    ans += (m/(low+1));
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