// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    vector<i64> ps(n + 1, 0), ps2(n + 1, 0);
    for (int i = 0; i < n; ++i) ps[i + 1] = ps[i] + a[i];
    for (int i = 0; i < n; ++i) ps2[i + 1] = ps2[i] + ps[i + 1];
    debug(ps2);
    int q;
    cin >> q;
    auto bi_sect = [&](i64 x) -> i64 {
        i64 low = 0, high = n;
        i64 z;
        while(high - low > 1) {
            i64 mid = (low + high) / 2;
            i64 y = (n + n - mid) * (mid) / 2;
            if (y <= x) low = mid;
            else high = mid;
            z = x - y;
        }
        return low;
    };
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    for (; test_cases--;) {
        solve();
    }
}