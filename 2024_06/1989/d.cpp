#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n, m;
    cin >> n >> m; // n : weapon, m : metal
    vector<i64> a(n), b(n), c(m); // a : metal->weapon, b: weapon -> metal, c: have metal
    input(a); input(b); input(c);
    i64 upper_bound = *max_element(all(a));
    vector<i64> cost(upper_bound+1, __LONG_LONG_MAX__);
    for (i64 i = 0; i < n; ++i) {
        i64 x = a[i] - b[i];
        cost[a[i]] = min(cost[a[i]], x);
    }
    for (i64 i = 1; i <= upper_bound; ++i) {
        cost[i] = min(cost[i-1], cost[i]);
    }
    
    vector<i64> dp(upper_bound + 1, 0);
    i64 up = 0;
    for (i64 i = 1; i <= upper_bound; ++i) {
        if (i >= cost[i] && cost[i] != LLONG_MAX) {
            dp[i] = dp[i-cost[i]] + 2;
            if (dp[i] > dp[up]) up = i;
        }
    }

    i64 ans = 0;
    for (i64 i = 0; i < m; ++i) {
        i64 thisans = 0;
        if (c[i] > up) {
            thisans = dp[up] + (c[i] - up) / cost[up] * 2;
        } else {
            thisans = dp[c[i]];
        }
        ans += thisans;
    }
    cout << ans << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}