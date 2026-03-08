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
    int n;
    cin >> n;
    vector<i64> a(n), b(n-1);
    input(a);
    for (i64 i = 0; i < n - 1; ++i) {
        b[i] = a[i+1] - a[i];
    }

    i64 ans = 0;
    vector<i64> seq;
    i64 cur = 0;
    for (i64 i = 0; i < n - 1; ++i) {
        if (cur == 0) {
            cur++;
            seq.push_back(1);
        } else {
            if (b[i] == b[i-1]) {
                seq.back()++;
            } else {
                seq.push_back(1);
            }
        }
    }
    ans = n + n - 1;
    debug(b,seq);
    for(auto & seqi : seq) {
        if (seqi >= 2) ans += ((seqi - 1) * (seqi) / 2);
    }
    cout << ans << endl;
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