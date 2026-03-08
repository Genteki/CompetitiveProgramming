// f.cpp
// [greedy] [prioriy_queue]
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;


void solve() {
    i64 n, x;
    cin >> n >> x;
    i64 s = 0;
    vector<i64> u(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i] >> d[i];
        s += (u[i] + d[i]);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> viewed(n, 0);
    for (int i = 0; i < n; ++i) {
        pq.emplace(u[i], i);
    }
    while(!pq.empty()) {
        auto [l, i]  =pq.top();
        pq.pop();
        if (viewed[i]) continue;
        viewed[i] = true;
        if (i > 0 and u[i-1] - u[i] > x) {
            u[i-1] = l + x;
            pq.emplace(l+x, i-1);
        }
        if (i < n-1 and u[i+1] - l > x) {
            u[i+1] = l + x;
            pq.emplace(l + x, i + 1);
        }
    }
    i64 y = 2e9;
    for (int i = 0; i < n; ++i) {
        y = min(y, u[i]+d[i]);
    }
    i64 ans = s - y * n;
    cout << ans;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}