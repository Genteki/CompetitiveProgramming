// c.cpp
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
    i64 n; i64 m;
    cin >> n >> m;
    vector<i64> a(n);
    input(a);
    sort(all(a));
    i64 s = accumulate(all(a), 0LL);
    if (s <= m) {
        cout << "infinite";
        return;
    }
    s = 0;
    int i = 0;
    while(i < n) {
        s = s + a[i];
        i64 sl = s + a[i] * (n - 1 - i);
        if (sl > m) break;
        ++i;
    }
    s -= a[i];
    --i;
    debug(i, s);
    i64 ans = (m - s) / (n - 1 - i);
    cout << ans;
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