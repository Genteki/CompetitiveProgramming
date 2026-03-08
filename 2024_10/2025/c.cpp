// c.cpp

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
    int n, k;
    cin >> n >> k;
    map<int,i64> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<pair<int, i64>> seq(mp.begin(), mp.end());
    vector<i64> s(n+1, 0);
    int l = 0, prev = -10, m = seq.size();
    for (int i = 0; i < m; ++i) {
        auto [ai, p] = seq[i];
        if (ai - prev != 1) {
            l = 1;
            s[i + 1] = p;
        }else if (l < k) {
            l++;
            s[i+1] = s[i] + p;
        } else {
            s[i+1] = s[i] + p - seq[i - k].second;
        }
        prev = ai;
    }
    i64 ans = *max_element(all(s));
    debug(seq);
    debug(s);
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