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
        a.push_back(ps[(n) / 2]);
        ps.push_back(ps[n] ^ a[n]);
        ++n;
    }

    auto getv = [&](i64 idx, int p=0) -> i64 {
        i64 ans = 0;
        if (p%2) p = ps.back();
        if (idx - 1 < n) {
            return a[idx - 1];
        }
        while (idx / 2 > n) {
            idx /= 2;
            ans ^= ps.back();
            if (idx % 2 == 1) {
                return ans;
            }
        }
        return ans ^ ps[idx / 2];
    };
    vector<array<int,2>> pss(n+1, array<int,2>({0,0}));
    for (int i = 0; i <n;++i) {pss[i+1][0] = pss[i][0] + ps[i+1];}
    for (int i = 0; i <n;++i) {pss[i+1][1] = pss[i][1] + (ps.back()^ps[i+1]);}

    vector<int> psx(n+1, 0);
    for (int i = 0; i < n; ++i) psx[i+1] = psx[i] + a[i];
    auto cs = [&](i64 x) -> i64 {
        int p = 0;
        i64 z = 1;
        i64 s = 0;
        if (x <= n) {
            debug(x);
            return psx[x];
        }
        s += psx[n];
        while(x > n) {
            debug(x, s);
            if (x % 2== 0) {
                s += (z * getv(x, p));
            }
            x /= 2;
            p = !p;
            z *= 2;
            if (x <= n) {
                s += (z * (pss[x][p] - pss[n/2][p]));
                return s;
            }
            s += (z * (pss[n][p] - pss[n / 2][p]));
        }
        return s;
    };
    i64 sl = cs(l-1), sr = cs(r);
    debug(psx);
    debug(pss);
    debug(sl, sr);
    // cout << sr-sl << endl
    std::println("{}",sr-sl);
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