// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >>l2 >> r2;
    i64 ans = max(0LL, min(r2, r1) - max(l1, l2) + 1);
    i64 k0 = k;
    while(k * l1 <= r2) {
        i64 l = max(l1, (l2 + k - 1) / k);
        i64 r = min(r1, (r2) / k);
        i64 cur = max(0LL, (r - l + 1));
        ans += cur;
        k *= k0;
        debug(l, r, cur);
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