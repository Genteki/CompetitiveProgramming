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
    for (i64 i = 1; i < x; ++i) {
        i64 y = i ^ x;
        if (y <= m)
        if (x % i == 0 || y % i == 0) ++ ans;
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