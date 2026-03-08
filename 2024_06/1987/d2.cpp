#include <bits/stdc++.h>
 
#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
 
using namespace std;
 
typedef long long i64;
 
void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x] += 1;
    }
    vector<int> b(mp.size(), 0);
    int ib = 0;
    for (auto& [vi, ni] : mp) {
        b[ib] = ni;
        ++ib;
    }
 
    priority_queue<int, vector<int>, std::greater<int>> pq;
    vector<int> dp(b.size(), 0);
    vector<bool> upgrade(b.size(), false);
    int last;
    for (int i = 1; i < b.size(); ++i) {
        last++;
        if (i >= b[i]) {
            // dp[i] = max(dp[i-1], dp[i-b[i]-1] + 1);
            if (upgrade[i-b[i]]) dp[i] = dp[i-1];
            else dp[i] = max(dp[i-1], dp[i-b[i]-1] + 1);
            if (dp[i] - dp[i-1]) upgrade[i] = true;
        }
    }
    // cout << b.size() << " " << 
    // for (auto dpi : dp) cout << dpi << " ";
    // cout << endl;
    cout << (b.size() - dp[b.size()-1]) << endl;
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