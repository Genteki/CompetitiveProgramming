// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    auto d = [](i64 x1, i64 y1, i64 x2, i64 y2) -> i64 {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };
    i64 d1 = d(xa, ya, xb, yb);
    i64 d2 = d(xa, ya, xc, yc);
    i64 d3 = d(xb, yb, xc, yc);

    i64 s = d1 + d2 + d3;
    i64 m = max({d1, d2, d3});
    if (m * 2LL == s) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}