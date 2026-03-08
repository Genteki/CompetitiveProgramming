// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;
typedef long long i64;
const int M = 100;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int x = 0;
    vector<int> cnt(10);
    for (auto c : s) {
        cnt[c - '0']++;
        x += (c - '0');
    }
    int md = x % 9;
    if (md == 0) {
        cout << "YES" << endl;
        return;
    }
    vector<int> dp(M, 0);
    dp[0] = 1;
    for (int i = 0; i < cnt[2]; ++i) {
        for (int j = M-1; j >= 0; --j) {
            if (dp[j] && j + 2 < M) {
                dp[j + 2] = 1;
            }
        }
    }
    for (int i = 0; i < cnt[3]; ++i) {
        for (int j = M - 1; j >= 0; --j) {
            if (dp[j] && j + 6 < M) {
                dp[j + 6] = 1;
            }
        }
    }
    int y = 0;
    while (y * 9 + 9 - md < M) {
        if (dp[y * 9 + 9 - md]) {
            cout << "YES" << endl;
            return;
        }
        y++;
    }
    cout << "NO\n";
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