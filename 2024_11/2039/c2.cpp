// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    i64 x, m;
    cin >> x >> m;
    i64 ans = 0;
    i64 p = 1;
    if (x == 1) {
        cout << m << endl;
        return;
    }
    while (p <= x) p *= 2;
    // O(x)
    for (i64 i = 1; i < p; ++i) {
        i64 y = i ^ x;
        if (y <= m && y > 0) {
            if (i % x != 0 && i % y == 0) {
                ++ans;
            }
        }
    }
    // O(x)
    for (i64 i = max(0LL, m-x); i <= m + x; ++i) {
        i64 y = i ^ x;
        if (y <= m && i % x == 0 && y > 0) {
            ++ans;
        }
    } 
    if (m - x - 1 >= 0) {
        ans += max(1LL, (m - x - 1) / x);
    }
    cout << ans << endl;
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