// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n,x ,y;
    cin >> n >> x >> y;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai ;
    i64 s = accumulate(a.begin(), a.end(), 0LL);
    x = s - x;
    y = s - y;
    swap(x, y);
    sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        i64 dx = x - a[i];
        i64 dy = y - a[i];
        auto itx = lower_bound(a.begin() + i + 1, a.end(), dx);
        auto ity = upper_bound(a.begin() + i + 1, a.end(), dy);
        ans += distance(itx, ity);
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