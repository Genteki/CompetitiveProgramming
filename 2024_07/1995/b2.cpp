// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<pair<i64,i64>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
    }
    // Count frequencies of each number in the array
    sort(all(a));
    i64 ans = 0;

    // Iterate through the map to calculate the maximum sum under the conditions
    for (auto it = a.begin(); it != a.end(); ++it) {
        i64 x = it->first, nx = it->second;
        auto next_it = next(it);
        i64 y = -1, ny = -1;
        if (next_it != a.end()) {
            y = next_it->first;
            ny = next_it->second;
        }

        if (y == x + 1) {
            // Check if we can include both x and y in the sum
            if (nx * x + ny * y <= m) {
                ans = max(ans, nx * x + ny * y);
            } else {
                i64 tmp = 0;
                i64 ix = min(nx, m / x);
                tmp = min(nx, m / x) * x;
                i64 iy = 0;
                if (tmp < m) {
                    iy = (m - tmp) / y;
                    tmp = tmp + iy * y;
                }
                tmp += min({ix, (ny - iy), m - tmp});
                ans = max(ans, tmp);
            }
        }
        if (nx * x <= m) {
            ans = max(ans, nx * x);
        } else {
            i64 tmp = (m / x) * x;
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}