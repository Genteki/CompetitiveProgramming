// removing_digits.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;
    vector<bool> x(10, false);
    for (int i = n; i >= 1; --i) {
        if(dp[i]!=INT_MAX){fill(all(x), false);
        int l  = i;
        while(l > 0) {
            x[l%10] = true;
            l /= 10;
        }
        for (int j = 1; j <= 9; ++j) {
            if ((x[j]) && i - j >= 0) {
                dp[i-j] = min(dp[i]+1, dp[i-j]);
            }
        }}
    }
    cout << dp[0] << endl;
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