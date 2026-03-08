// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, r;
    cin >> n >> r;
    while (n--) {
        int div, delta;
        cin >> div >> delta;
        if (div == 1) {
            if (r >= 1600 && r <= 2799) {
                r += delta;
            }
        } else {
            if (r >= 1200 && r <= 2399) {
                r += delta;
            }
        }
    }
    cout << r;
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