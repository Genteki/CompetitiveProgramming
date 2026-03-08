// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;

void solve() {
    int n, t, p;
    cin >> n >> t >> p;
    vector<int> a(n);
    input(a);
    sort(all(a), std::greater<int>());
debug(a);
    if (a[p-1] >= t) cout << 0;
    else {
        cout << (t - a[p-1]);
    }
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