// e.cpp
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
    int n,m;
    i64 x1;
    cin >> n >> m >> x1;
    vector<i64> a(m), b(m), s(m), t(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i] >> s[i] >> t[i];
        --a[i]; --b[i];
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