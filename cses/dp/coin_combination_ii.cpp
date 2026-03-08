// coin_combination_ii.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))
const int mod = 1e9 + 7;
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    input(a);
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    sort(all(a));
    for (int& ai : a) {
        for  (int i = 0; i < x; ++i) {
                if (i + ai <= x) {
                    dp[i + ai] += dp[i];
                    dp[i + ai] %= mod;
                }
            }
    }
    cout << dp[x] << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}