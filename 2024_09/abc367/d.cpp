// d.cpp
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
    int n, m;
    cin >> n >> m;
    vector<i64> a(n), b(m, 0);
    input(a);
    i64 s=0, ans = 0;
    for (int i = 0; i < n - 1; i++) {
        s = (s + a[i]) % m;
        b[s]++;
    }
    debug(b);
    i64 bias = 0;

    for (int i = 0; i < n; ++i) {
        ans += b[(m + bias) % m];
        bias = (bias + a[i]) % m;
        s = (s + a[(n - 1 + i) % n]) % m;
        b[bias]--;
        b[s]++;
    }
    
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