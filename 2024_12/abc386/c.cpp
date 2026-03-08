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
    string s, t;
    int k;
    cin >> k;
    cin >> s >> t;
    int ns = s.size(), nt = t.size();
    if (ns > nt) {
        swap(ns, nt);
        swap(s, t);
    }
    if (nt - ns > 1) {
        cout << "No"; return;
    }
    int x = 0;
    while(x < ns && s[x] == t[x]) {
        ++x;
    } 
    int y = 0;
    while (y < (ns-x) and s[ns-y-1] == t[nt-1-y]) {
        ++y;
    }
    debug(x, y);
    if (ns == nt && x + y >= ns - 1) {
        cout << "Yes";
    } else if (ns < nt && x + y >= ns) {
        cout << "Yes";
    } else {
        cout << "No";
    }
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