// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    vector<int> dp(n+1, 0);
    bool flag = false;
    int ct;
    for (int i = 0; i < n; ++i) {
        dp[i+1] = dp[i];
        if (a[i] == 0) {
            flag=false;
        } else if (a[i] <= 2) {
            if (flag && ct % 2 == 0) {
                flag = false;
            } else {
                flag=true;
                ct = 0;
                dp[i+1] = dp[i]+1;
            }
        } else if (a[i] <= 4) {
            dp[i+1] = dp[i]+1;
            ++ct;
        } else {
            dp[i+1] = dp[i]+1;
            flag = false;
        }
    }
    // for (int dpi : dp) cout << dpi << " ";
    cout << dp[n] << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}