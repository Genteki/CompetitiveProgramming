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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto & ai :a ) {
        cin >> ai ;
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    map<int,int> mp;
    for (auto ai : a) {
        mp[ai] ++ ;
    }
    vector<int> v;
    for (auto [val, cnt] : mp) {
        v.push_back(cnt);
    }
    sort(v.begin(), v.end());
    bool flag = true;
    int ans = 0;
    for (int cnt: v) {
        if ( k >= cnt and flag) {
            k -= cnt;
            ++ans;
        } else {
            flag = false;
            break;
        }
    }
    cout << max(1, int(v.size()-ans)) << endl;
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