// b.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long i64;
void solve() {
    i64 x;
    cin >> x;
    i64 s = (x+1) * x / 2;
    if (i64(sqrt(s)) * i64(sqrt(s)) == s) {
        cout << -1 << endl;
        return;
    }
    queue<int> q;
    auto iss = [](i64 x) -> bool {
        i64 sx = sqrt(x);
        return (sx * sx == x);
    };
    s = 0;
    vector<int> v;
    for (int i = 2; i <= x; i += 2) v.push_back(i);
    for (int i = (x%2?x:(x-1)); i >=1; i -= 2) v.push_back(i);
    debug(v);
    for (int i = 0; i < x-1; ++i) {
        if (iss(s+v[i])) {
            swap(v[i], v[i+1]);
        }
        s += v[i];
    }
    for (auto vi : v) cout << vi << " "; cout << endl;
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