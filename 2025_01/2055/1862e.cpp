// 1862e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 n, m, d;
    cin >> n >> m >> d;
    vector<i64> a(n);
    for (i64& ai : a) cin >> ai;
    priority_queue<i64, vector<i64>, std::greater<i64>> pq;
    i64 s = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, s + a[i] - (i+1)*d);
        if (a[i] > 0) {
            if (pq.size() < m-1) {
                pq.push(a[i]);
                s += a[i];
            } else if (!pq.empty() and pq.top() < a[i]) {
                s -= pq.top();
                s += a[i];
                pq.pop();
                pq.push(a[i]);
            }
        }
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