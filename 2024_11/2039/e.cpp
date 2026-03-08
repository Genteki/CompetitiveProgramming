// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
constexpr int MOD = 998244353;
constexpr int N = 1e6 + 5;
void solve() {
    int n;
    cin >> n;
    int sum = 0;
    int ans = n - 1;
    for (int i = n; i >= 4; i--) {
        int x = (1 + 1LL * sum * i) % MOD;
        sum = (sum + x) % MOD;
        ans = (ans + 1LL * x * (1LL * (i - 3) * i / 2 % MOD)) % MOD;
    }
    cout << ans << '\n';
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