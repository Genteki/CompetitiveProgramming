// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void ouput(i64 x, i64 y) { cout << x << " " << y << "\n"; }

void solve() {
    i64 l, r, g;
    cin >> l >> r >> g;

    if (g > r) {
        cout << "-1 -1\n";
        return;
    }

    i64 dl = (l + g - 1) / g; 
    i64 dr = r / g;  
    if (dl > dr) {
        cout << "-1 -1\n";
        return;
    }
    if (dl == dr) {
        if (dl == 1)
            ouput(g, g);
        else
            cout << "-1 -1\n";
        return;
    }

    if (dl==1 or __gcd(dl, dr) == 1) {
        ouput(dl * g, dr * g);
        return;
    }
    i64 d = dr - dl;
    for (i64 i = 1; i < (dr - dl); ++i) {
        for (i64 j = 0; j <= i; ++j) {
            debug(dl+j, dr-i+j);
            if (__gcd(dl+j, dr-i+j) == 1) {
                ouput((dl+j)*g, (dr-i+j)*g);
                return;
            }
        }

    }

    cout << "-1 -1\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}