// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef __int128_t i128;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    i64 m;
    cin >> m;
    // (y+d)3 - y3 = 3d2y + 3yd2 +d3
    //  d <= cbrt(n)
    // find d
    if (m == 1) {
        cout << -1;
        return;
    }
    i128 low = 1, high = 1e6+1;
    i128 n = m;
    while(high - low > 1) {
        i128 mid = (high + low) / 2;
        if (mid*mid*mid <= n) low = mid;
        else high = mid;
    }
    debug((i64)low);
    for (i128 d = 1; d <= low; ++d) {
        auto d2 = d*d, d3 = d2*d;
        if ((d3-n)%(3*d) != 0) continue;
        auto c =  (d3 - n) / d / 3;
        auto delta = d2 - 4*c;

        i128 y = (-d + sqrt((long double)(delta))) / 2;
        debug((i64)d, (i64)y);
        if ((y+d)*(y+d)*(y+d) - y*y*y == n) {
            cout << (i64)(y+d) << " " << i64(y);
            return;
        }
    }
    cout << -1;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}