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
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    int m = *max_element(all(a));
    int k = 30;
    while(!((1 << k) & m)) {
        --k;
    }
    debug(k);
    ++k;
    i64 ans = 0;
    for (int i = 0; i < k; ++i) {
        int z = 0;
        i64 cnt = 0;
        for (int j = 0; j < n; ++j) {
            bool tmp = bool(a[j] & (1 << i));
            if (tmp == false) {
                cnt += (j - z);
                z += 1;
            } else {
                cnt += z;
                z = (j - z);
            }
            debug(i, j, tmp, z, cnt);
        }
        ans = ans + (1LL << i) * cnt;
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