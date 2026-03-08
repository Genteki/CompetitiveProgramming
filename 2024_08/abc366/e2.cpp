#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n, d;
    cin >> n >> d;

    vector<i64> x(n), y(n);
    for (i64 i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    sort(all(x));
    sort(all(y));

    // Prefix sums
    vector<i64> px(n + 1, 0), py(n + 1, 0);
    for (i64 i = 0; i < n; ++i) {
        px[i + 1] = px[i] + x[i];
        py[i + 1] = py[i] + y[i];
    }

    // Range count arrays
    vector<i64> nx(2e6 + 1, 0), ny(2e6 + 1, 0);
    for (i64 i = 1; i <= 2e6; ++i) {
        nx[i] = nx[i - 1];
        ny[i] = ny[i - 1];

        while (nx[i] < n && x[nx[i]] <= i - 1e6) {
            ++nx[i];
        }
        while (ny[i] < n && y[ny[i]] <= i - 1e6) {
            ++ny[i];
        }
    }

    vector<i64> dx(d + 1, 0), dy(d + 1, 0);

    for (i64 i = -1e6; i <= 1e6; ++i) {
        i64 nxi = nx[i + 1e6];
        i64 left_x = px[nxi] - px[0];
        i64 right_x = px[n] - px[nxi];
        i64 q_x = nxi - (n - nxi);
        i64 r_x = q_x * i - left_x + right_x;
        if (r_x <= d && r_x >= 0) {
            dx[r_x]++;
        }

        i64 nyi = ny[i + 1e6];
        i64 left_y = py[nyi] - py[0];
        i64 right_y = py[n] - py[nyi];
        i64 q_y = nyi - (n - nyi);
        i64 r_y = q_y * i - left_y + right_y;
        if (r_y <= d && r_y >= 0) {
            dy[r_y]++;
        }
    }

    // Accumulate counts for easier final calculation
    for (i64 i = 1; i <= d; ++i) {
        // dx[i] += dx[i - 1];
        dy[i] += dy[i - 1];
    }

    // Compute final answer
    i64 ans = 0;
    for (i64 i = 0; i <= d; ++i) {
        ans += dx[i] * dy[d - i];
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 test_cases = 1;
    // cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}