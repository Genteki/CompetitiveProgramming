// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
const int M = 33;
void solve() {
    i64 x, y, k=0;
    cin >> x >> y;
    i64 ox = x, oy = y;
    debug(x, y);
    if ((x & y) == 0) {
        cout << 0 << endl;
        return;
    }
    auto dfs = [](this auto&& self, i64 x, i64 y, i64 k, i64 d = 0) -> bool {
        if (d == M) {
            if ((x & y) == 0) {
                cout << k << endl;
                return true;
            } 
            else return false;
        }
        i64 mask = (1LL << d);
        if ((x & mask) and (y & mask)) {
            if (self(x+mask, y+mask, k+mask, d+1)) return true;
        } else if ((x & mask) ^ (y & mask)) {
            if (self(x, y, k, d+1)) return true;
            if (self(x + mask, y + mask, k + mask, d + 1)) return true;
        } else {
            if (self(x, y, k, d + 1)) return true;
        }
        return false;
    };
    if (!dfs(x,y,k,0)) cout << -1 << endl;

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