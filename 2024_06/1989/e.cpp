#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    i64 ans = 0;
    vector<i64> dp1(n+1, 0);
    for (int i = 2; i <= n; ++i) {
        dp1[i] = i - 1;
    }
    vector<i64> dp2(n+1, 1);
    i64 s = 0;
    for (int i = 1; i <= n; ++i) {
        dp2[i] = dp2[i-1] + s;
        dp2[i] %= mod;
        if (i - 2 >= 0)
            s += dp2[i-2];
        s %= mod;
        cout << i << ": " << dp2[i] << endl;
    }
    vector<i64> dp3(k, 0);
    for (int i = 0; i < k; ++i) {
        
    }

    for (int i = 2; i <= n; ++i) {
        i64 p = dp1[i] * dp2[n-i];
        p %= mod;
        ans += p;
        ans %= mod;
    }
    cout << ans << endl;

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}