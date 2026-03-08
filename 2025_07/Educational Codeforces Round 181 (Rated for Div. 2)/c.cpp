// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 l, r;
    cin >> l >> r;
    // 2, 3, 5, 7
    // 6, 10, 14, 15, 21, 35
    // 30, 42, 70, 105
    // 210
    vector<i64> p { 2, 3, 5, 7, 30, 42, 70, 105 };
    vector<i64> q { 6, 10, 14, 15, 21, 35, 210 };
    auto f = [&](i64 x) -> i64 {
        i64 r = 0;
        for (auto & pi : p) {
            r += x / pi;
        }
        for (auto & qi : q) {
            r -= x / qi;
        }
        return r;
    };
    i64 a = f(l-1), b = f(r);
    cout << (r - l + 1 - b + a) << endl;
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