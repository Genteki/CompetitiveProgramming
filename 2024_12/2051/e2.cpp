// e2.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n), b(n);
    for (auto& ai : a) cin >> ai;
    for (auto& bi : b) cin >> bi;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    i64 last = -1, ans = -1;
    auto sm = [&](int price) -> i64 {
        i64 amount = distance(lower_bound(b.begin(), b.end(), price), b.end());
        i64 positive_review = distance(lower_bound(a.begin(), a.end(), price), a.end());
        if (amount - positive_review <= k) {
            return price * amount;
        } else {
            return -1;
        }
    };
    for (auto ai : a) {
        if (ai != last) {
            last =ai;
            ans = max(ans, sm(ai));
        }
    }
    for (auto ai : b) {
        if (ai != last) {
            last = ai;
            ans = max(ans, sm(ai));
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