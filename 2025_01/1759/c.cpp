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
    i64 l,r,x;
    cin >> l >> r >> x;
    i64 a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
    }
    else if (abs(a-b) >= x) {
        cout << 1 << endl;
    } else if ((a-l) >=x and (b-l) >= x) {
        cout << 2 << endl;        
    } else if (r-b>= x and r-a>= x) {
        cout << 2 << endl;
    } else if (a - l >= x and r -b >= x) {
        cout << 3 << endl;
    } else if (r - a >= x and b - l >= x) {
        cout << 3 << endl;
    } else {
        cout << -1 << endl;
    }
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