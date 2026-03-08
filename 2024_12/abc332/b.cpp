// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int k, g, m;
    cin >> k >> g >> m;
    int cg = 0, cm = 0;
    while(k--) {
        if (cg == g) {
            cg = 0;
        } else if (cm == 0) {
            cm = m;
        } else {
            int delta = min(cm, g-cg);
            cg += delta;
            cm -= delta;
        }
    }
    cout << cg << " " << cm;
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
