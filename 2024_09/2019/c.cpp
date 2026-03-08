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
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    input(a);
    sort(all(a), std::greater<i64>());
    i64 s = accumulate(all(a), 0LL);
    i64 max_ans = min({(s+k) / a[0], n});
    debug(s, a[0], max_ans);

    for (i64 i = max_ans; i >= 1; --i) {
        i64 x1 = s / i;
        i64 x2 = (s+k) / i;
        if (x2 > x1 || (s) % i == 0) {
            cout << i << endl;
            return;
        }
    } 
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