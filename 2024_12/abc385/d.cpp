// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const i64 inf = 1e9 + 7;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, m, x, y;
    cin >> n >> m >> x >> y;
    map<i64, set<i64>> mpx, mpy;
    for (i64 i = 0; i < n; ++i) {
        i64 u, v;
        cin >> u >> v;
        mpx[u].insert(v);
        mpy[v].insert(u);
    }
    i64 cnt = 0;
    for (i64 _ = 0; _ < m; ++_) {
        char c;
        i64 d;
        cin >> c >> d;
        if (c == 'L' or c == 'R') {
            if (c == 'L') d=-d;
            i64 l = x, r = x + d;
            if (l > r) swap(l, r);
            for (auto it = mpy[y].lower_bound(l); it != mpy[y].upper_bound(r); ++it) {
                i64 xi = *it;
                mpx[xi].erase(y);
                ++cnt;
            }
            mpy[y].erase(mpy[y].lower_bound(l), mpy[y].upper_bound(r));
            x = x + d;
        } else {
            if (c == 'D') d =- d;
            i64 u = y, down = y + d;
            if (u < down) swap(u, down);
            for (auto it = mpx[x].lower_bound(down); it != mpx[x].upper_bound(u); ++it) {
                i64 yi = *it;
                mpy[yi].erase(x);
                ++cnt;
            }
            mpx[x].erase(mpx[x].lower_bound(down), mpx[x].upper_bound(u));
            y += d;
        }
        debug(x, y);
    }
    cout << x << " " << y << " " << cnt << endl; 
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}