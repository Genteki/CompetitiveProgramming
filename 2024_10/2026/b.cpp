// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    sort(all(a));
    
    auto canpaint = [&](i64 k) -> bool {
        int unmatched = n;
        vector<bool> matched(n, false);
        for (int i = 0; i < n; ++i) {
            if (!matched[i]) {
                int j = i + 1;
                while (j < n && matched[j]) ++j;
                if (j < n && !matched[j] && a[j] - a[i] <= k) {
                    matched[i] = matched[j] = true;
                    unmatched -= 2;
                }
            }
        }
        return unmatched <= 1;
    };

    i64 low = 0, high = 1e18 + 1;
    while (high - low > 1) {
        i64 mid = (low + high) / 2;
        if (canpaint(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << high << '\n';
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