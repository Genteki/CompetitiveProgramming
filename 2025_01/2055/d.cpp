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
    i64 n, k, l;
    cin >> n >> k >> l;
    vector<i64> a(n);
    for (auto& ai : a) {cin >> ai; ai *= 2;}
    i64 pos2 = k*2;
    i64 t2 = a[0];
    a[0] = 0;
    for (int i = 1; i < n; ++i) {
        debug(i, pos2, t2);
        if (pos2 >= (l*2)) {
            break;
        }
        if (a[i] - t2 <= pos2 and pos2 <= a[i] + t2) {
            a[i] = pos2;
            pos2 = pos2 + (k*2);
        } else if (a[i] - t2 > pos2) {
            a[i] = a[i] - t2;
            i64 delta = (a[i] - pos2)/2;
            t2 += delta;
            pos2 = pos2 + delta + (k*2);
        } else {
            pos2 = a[i] + t2 + 2 * k;
        }
    }
    t2 += max(0LL, (l*2-pos2));
    cout << t2 << endl;
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