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
    i64 n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    i64 ans = 0;
    map<i64, i64> gcdl, gcdm;
    for (i64 i = 0; i < n; ++i) {
        gcdl[a[i]]++;
    }
    while(!gcdl.empty()) {
        debug(gcdl);

        i64 mi = gcdl.begin()->first; i64 mn = gcdl.begin()->second;
        if (gcdl.size() == 1) {
            ans += (mi * mn);
            break;
        }
        ans += (mi);
        gcdl[mi]--;
        if(gcdl[mi] == 0) gcdl.erase(mi);
        for (auto [u, v] : gcdl) {
            auto newu = __gcd(u, mi);
            gcdm[newu] += v;
        }
        swap(gcdl, gcdm);
        gcdm.clear();
    }
    cout << ans << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}