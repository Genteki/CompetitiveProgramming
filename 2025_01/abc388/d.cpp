// d.cpp
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
    vector<i64> a(n),b(n);
    for (i64& ai : a) cin >> ai;
    priority_queue<i64, vector<i64>, std::greater<i64>> pq;
    for (int i = 0; i < n; ++i) {
        while(!pq.empty() and pq.top() < i) {
            pq.pop();
        }
        b[i] = pq.size() + a[i];

        pq.push(b[i] + i);
    }
    for (int i = 0; i < n; ++i) {
        cout << max(0LL, b[i] - (n-1) + i) << " ";
    }
    debug(b);
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