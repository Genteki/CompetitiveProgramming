// b.cpp
#include <bits/stdc++.h>

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
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    sort(a.begin(), a.end());
    map<int,int> mp;
    vector<int> b;
    for (auto ai : a) {
        mp[ai]++;
        if (mp[ai] == 2) {
            b.push_back(ai);
        }
    }
    debug(a);
    if (b.size() == 0) {
        cout << -1 << endl;
        return;
    }
    if (b.size()>=2) {
        cout << b[0] << " " << b[0] << " " << b[1] << " " << b[1] << endl; return;
    } else {
        mp[b[0]] -= 2;
        if (mp[b[0]] == 0) {
            mp.erase(b[0]);
        }
        vector<int> c;
        for (auto [x,_] : mp) {
            c.push_back(x);
        }
        for (int i = 0; i < c.size()-1; ++i) {
            if (c[i+1] - c[i] < 2 * b[0]) {
                cout << b[0] << " " << b[0] << " " << c[i] << " " << c[i+1] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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