// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n;
    cin >> n;
    deque<i64> odd, even;
    for (int i = 0; i < n; ++i) {
        i64 x;
        cin >> x;
        if (x%2) odd.push_back(x);
        else even.push_back(x);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    if (odd.empty()) {
        cout << even.back() << endl;
        return;
    }
    i64 ans = odd.back();
    odd.pop_back();
    while(!odd.empty() and !even.empty()) {
        i64 a = odd.back();
        odd.pop_back();
        even[0] += (a/2*2);
    }
    ans = accumulate(even.begin(), even.end(), ans);
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