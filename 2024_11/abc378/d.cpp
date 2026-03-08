#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    vector<i64> ans(n), c(n);

    // Compute differences
    vector<i64> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] - a[(i + 1) % n];
    }

    // Compute c for even indices
    c[0] = 0;
    for (int i = 0; i < n; i += 2) {
        c[(i + 2) % n] = c[i] + b[(i + 1) % n];
    }

    // Compute c for odd indices with unknown t
    // Set up the equation to solve for t
    i64 lhs = c[0];
    i64 rhs = c[n - 2] + b[n - 1];
    i64 t = lhs - rhs;

    // Update c[1] with the solved t
    c[1] = t;

    // Recompute c for odd indices with the correct t
    for (int i = 1; i < n; i += 2) {
        c[(i + 2) % n] = c[i] + b[(i + 1) % n];
    }

    // Now, check consistency
    if (c[0] != c[n - 2] + b[n - 1]) {
        cout << -1 << endl;
        return;
    }

    // At this point, c[i] = ans[i] + ans[i+1]
    // We can now solve for ans[i]
    ans[0] = 0;  // Arbitrary starting point
    for (int i = 0; i < n; ++i) {
        ans[(i + 1) % n] = c[i] - ans[i];
    }

    // Output the result
    for (const auto& val : ans) {
        cout << val << " ";
    }
    cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}