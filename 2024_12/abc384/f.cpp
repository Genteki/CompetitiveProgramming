// f.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    i64 s = accumulate(all(a), 0LL);
    i64 ans = s * (n + 1);
    map<i64, pair<int, i64> > mp;
    int k = 1;
    for (auto ai : a) {
        mp[ai].first += 1;
        mp[ai].second += ai; 
    }
    while ((1 << k) <= 2e7) {
        ++k;
    }
    while (k) {
        i64 cur = 0;
        for (auto it = mp.lower_bound((1 << k)); it != mp.end(); ++it) {
            i64 val = it -> first;
            auto [itn, su] = it -> second;
            auto &np = mp[val & ((1 << k) - 1)];
            np.first += itn;
            np.second += su;
        }
        mp.erase(mp.lower_bound((1 << k)), mp.end());

        for (auto &[val, p] : mp) {

            i64 delta = 0;
            if (val == 0 || val == (1 << (k-1))) {
                delta = (p.first + 1) * p.second;
                // debug(val, p, 1);
            } else if (mp.find((1<<k)-val) != mp.end()) {
                delta = (p.second) * mp[(1 << k) - val].first;
                // debug(val, p, 2);
            }
            cur += delta;
        }
        ans -= (cur >> k);
        --k;
        debug(k, ans, cur);
    }
    cout << ans;
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