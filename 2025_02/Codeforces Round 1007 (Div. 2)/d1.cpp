// d1.cpp
// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    i64 n, l, r;
    cin >> n >> l >> r;
    // --l; --r;
    vector<i64> a(n);
    for (auto& ai : a) cin >> ai;
    vector<i64> ps(n + 1, 0);
    for (int i = 0; i < n; ++i) ps[i + 1] = ps[i] ^ a[i];
    if (n % 2 == 0) {
        // n++;
        a.push_back(ps[(n) / 2]);
        ps.push_back(ps[n] ^ a[n]);
        ++n;
    }

    auto getv = [&](i64 idx) -> i64 {
        i64 ans = 0;
        if (idx - 1 < n) {
            return a[idx-1];
        }
        while (idx / 2 > n) {
            idx /= 2;
            ans ^= ps.back();
            if (idx % 2 == 1) {
                return ans;
            }
        }
        return ans^ps[idx/2];
    };
    cout << getv(l) << endl;
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