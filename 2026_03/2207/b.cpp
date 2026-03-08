#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    int p = min(m, n+1);
    vector<int> a(n);
    for (auto & ai : a) cin >> ai;
    map<int,int> mp;
    mp[0] = p;
    for (int t = 0, i = 0; t < a.back(); ++t) {
        auto mkey = mp.begin()->first;
        mp[mkey] -= 1;
        if (mp[mkey] == 0) mp.erase(mkey);
        mp[mkey + 1] += 1;
        if (t == a[i]-1) {
            mkey = prev(mp.end())->first;
            mp[mkey] -= 1;
            if (mp[mkey] == 0) mp.erase(mkey);
            if (p > (n - i))
                --p;
            else {
                mp[0]+=1;
            }
            ++i;
        }
        debug(mp);
    }
    cout << mp.rbegin()->first  + (l-a.back()) << endl;
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