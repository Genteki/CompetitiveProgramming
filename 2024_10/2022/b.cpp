// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, x;
    cin >> n >> x;
    vector<i64> a(n);
    input(a);
    sort(all(a), std::greater<i64>());
    debug(a);
    i64 s = accumulate(all(a), 0LL);
    int i = 0;
    x = min(n , x);
        i64 ans = max(a[0], (s + x - 1) / x);
    cout << ans << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}