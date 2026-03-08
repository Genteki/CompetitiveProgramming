// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef long double f64;

void solve() {
    i64 r;
    cin >> r;
    i64 cnt = 0;
    f64 x = 0.5;
    while(x < r) {
        f64 h = sqrt(r*r-x*x);
        i64 d = 0;
        if (h > 0.5) {
            h -= 0.5;
            d++;
        }
        d += (i64(h) * 2);
        if (x > 1) {
            cnt += (2 * d);
        } else {
            cnt += d;
        }
        x += 1.0;
    }
    cout << cnt;
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