// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 l, r;
    cin >> l >> r;
    int ol = l;
    i64 a=0, b=0, c=0;
    int dl = -1, dr = 0, u = 1, d = 1;
    while((u<<1) <= r) {
        u = u << 1;
        ++dr;
    }
    if (l) ++dl;
    while((d<<1) <= l) {
        d = d << 1;
        ++dl;
    }
    debug(dl, dr);
    while (dl == dr) {
        a += (1 << dr);
        b += (1 << dr);
        c += (1 << dr);
        l -= (1 << dr);
        r -= (1 << dr);
        dl = -1, dr = 0, u = 1, d = 1;
        while ((u << 1) <= r) {
            u = u << 1;
            ++dr;
        }
        if (l) ++dl;
        while ((d << 1) <= l) {
            d = d << 1;
            ++dl;
        }
    }
    debug(dl, dr);

    dl = max(0, dl);
    if (dr > dl) {
        a += ((1 << dr));
        for (int i = 0; i < dr; ++i) {
            c += (1 << (i));
            b += (1 << i);
        }
        --c;
        if (c < ol) {
            c = a + 1;
        }
    }

    cout << a << " " << b << " " << c << endl;

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