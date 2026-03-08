// f.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<pair<i64, i64>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    double ans = -10;
    for (int i = 0; i < n - 1; ++i) {
        i64 x1 = a[i].first, y1 = a[i].second;
        i64 x2 = a[i + 1].first, y2 = a[i + 1].second;
        i64 tmp = y2 * (x2-x1) -x2 * (y2-y1);
        double tmp2 = double(tmp) / (x2-x1);

        ans = max(ans, tmp2);
    }
    if (ans < 0) {
        cout << -1;
    } else {
        cout << fixed << setprecision(18) << ans;
    }
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