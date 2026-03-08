// b.cpp

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
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    vector<int> b(all(a));
    sort(all(b), std::greater<>());
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.find(b[i]) == mp.end()) {
            mp[b[i]] = i;
        }
    }
    
    int ans = 1e9 + 1;
    for (int i = 0; i < n; ++i) {
        debug(i, mp[a[i]]);
        int cur_ans = i + mp[a[i]];
        ans = min(ans, cur_ans);
    }
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}