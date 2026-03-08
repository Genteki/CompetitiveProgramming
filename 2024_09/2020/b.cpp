// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
const i64 inf = 1.5e18;
void solve() {
    i64 k;
    cin >> k;
    i64 low = 1, high = 1.2e9;
    while(high - low > 1) {
        i64 mid = (low + high) / 2;
        if ((mid - 1) * mid >= k) {
            high = mid;
        } else {
            low = mid;
        }
    }
    if (high * (high - 1) == k) {
        cout << (high * high - 1) << endl;
    } else {
        i64 delta = k - low * (low - 1);
        i64 ans = low * low + delta;
        cout << ans << endl;
    }
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}