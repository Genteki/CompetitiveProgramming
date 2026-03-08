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
    i64 n, a, b;
    cin >> n >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    vector<i64> c(n);
    input(c);
    for (auto & ci : c) {
        ci = ci % a;
    }
    set<i64> s(all(c));
    vector<i64> v(all(s));
    c = v;
    i64 d = b;
    d = d % a;
    debug(c);
    debug(d);
    i64 ans = INT_MAX;
    n = c.size();
    vector<i64> u(n);
    for (size_t i = 0; i < n-1; ++i) {
        u[i] = c[i+1] - c[i];
        u[i] %= d;                                                                          
    }
    u[n-1] = (c[0] + a - c[n-1]) % d;

    i64 su = accumulate(all(u), 0LL);

    for (i64 vi : u) {
        i64 ansi = su - vi;
        ans = min<i64>(ans, ansi);
    }

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