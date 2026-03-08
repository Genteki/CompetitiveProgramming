// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    i64 ans = 0, r = 0;
    reverse(a.begin(), a.end());
    priority_queue<i64, vector<i64>, greater<i64>> pq;
    for (int i = 0; i < n; ++i) {
        i64 s = (i + 1) / (k + 1);
        if (pq.size() < s) {
            pq.push(a[i]);
        } else if (pq.size() == s) {
            pq.push(a[i]);
            pq.pop();
        }
    }
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
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