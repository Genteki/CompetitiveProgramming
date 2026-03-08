// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 inf = 1e18;
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), b(n);
    input(a);
    for (auto & bi : b) {
        cin >> bi;
        --bi;
    }
    vector<i64> dp(n, inf);
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, std::greater<>> pq;
    pq.emplace(0, 0);
    while(!pq.empty()) {
        auto [dpi, i] = pq.top();
        pq.pop();
        if (dp[i] == inf) {
            dp[i] = dpi;
            if (b[i] > i) {
                pq.emplace(dpi + a[i], b[i]);
            }
            if (i > 0) {
                pq.emplace(dpi, i - 1);
            }
        }
    }
    i64 s = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        ans = max(ans, s - dp[i]);
    }
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