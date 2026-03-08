// d.cpp
#include <bits/stdc++.h>

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
    string s;
    cin >> s;
    vector<i64> ps(n+1, 0), ps2(n+1, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ps[i+1] = ps[i] + i;
            ps2[i+1] = ps2[i] + 1;
        } else {
            ps[i + 1] = ps[i] ;
            ps2[i + 1] = ps2[i] ;
        }
    }
    debug(ps);
    debug(ps2);
    i64 ans = LONG_MAX;
    for (i64 i = 0; i < n; ++i) {
        i64 cur = ps2[i+1] * i - ps[i+1] - (0 + ps2[i+1]-1)*ps2[i+1]/2;
        debug(cur);
        if (i < n-1) {
            cur = cur + ps[n] - ps[i + 2];
            cur -= (1 + ps2[n] - ps2[i+2]) * (ps2[n]-ps2[i+1]) / 2;
            cur -= (ps2[n] - ps2[i+2]) * i;
        }
        debug(cur);
        ans = min(ans, cur);
    }
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