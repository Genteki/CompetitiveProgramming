// d2.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int m, n;
    cin >> n >> m;
    vector<int> a(n);
    input(a);
    vector<int> itll;
    vector<int> stg;

    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            itll.push_back(a[i]);
        } else if (a[i] < 0) {
            stg.push_back(-a[i]);
        }
    }

    // Sort the required levels
    sort(all(itll));
    sort(all(stg));

    int max_checks_passed = 0;

    for (int S = 0; S <= m; ++S) {
        int I = m - S;

        // Number of Intelligence checks passed with level I
        int itl_pass = upper_bound(all(itll), I) - itll.begin();

        // Number of Strength checks passed with level S
        int stg_pass = upper_bound(all(stg), S) - stg.begin();

        int total_passed = itl_pass + stg_pass;
        max_checks_passed = max(max_checks_passed, total_passed);
    }

    cout << max_checks_passed << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    //    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}