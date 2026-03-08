// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n, 0);
    input(a);
    vector<i64> ps(n+1, 0), ps2(n + 2, 0);
    for (int i = 0; i < n; ++i) {
        ps[i + 1] = (ps[i] + a[i]) % m;
    }
    for (int i = 0; i <= n; ++i) {
        ps2[i + 1] = ps[i] % m + ps2[i];
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += ((ps2[n+1] - ps2[i+1]) - (n - i) * (ps[i]%m));
    }
    debug(ps);
    debug(ans);
    i64 cnt = 0;
    set<i64> s;
    for (int i = 1; i <= n; ++i) {
        auto it = s.upper_bound(ps[i]);
        cnt += distance(it, s.end());
        s.insert(ps[i]);
    }
    debug(cnt);
    ans += cnt * m;
    cout << ans ;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}
