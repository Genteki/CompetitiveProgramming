// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n = 30;
    i64 a = 0, b= 0, pa=0,pb=0;
    int x = 0, y= 0;
    for (int i = 0; i < n; ++i)  {
        if(i%2==0){a += (1 << i);pa+=(2<<i);}
        else {b += (1<<i);pb+=(2<<i);}
    }
    cout << a << endl;
    cout.flush();
    i64 ra, rb;
    cin >> ra;
    ra -= pa;
    for (int i = 1; i < n; i+=2 ) {
        if (ra & (1<<i)) {
            x += (1 << i);
        } else if (ra & (1<<(i+1))) {
            x += (1 << i);
            y += (1 << i);
        }
    }
    cout << b << endl;
    cout.flush();
    cin >> rb;
    rb -= pb;
    for (int i = 0; i < n; i += 2) {
        if (rb & (1 << i)) {
            x += (1 << i);
        } else if (rb & (1 << (i + 1))) {
            x += (1 << i);
            y += (1 << i);
        }
    }
    cout << "!" << endl;
    debug(x, y);
    debug(ra, rb);
    cout.flush();
    int m;
    cin >> m;
    cout << ((x|m) + (y|m)) << endl;
    cout.flush();
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