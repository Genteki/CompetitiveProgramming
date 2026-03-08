#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto &ai : (x)) std::cin >> ai
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;
const i64 neg_inf = INT_MIN;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<string> a(n);
    input(a);

    vector<vector<i64>> dp(n + 1, vector<i64>(5, neg_inf));
    string b = "narek";
    set<char> mp = {'n', 'a', 'r', 'e', 'k'};

    dp[0][0] = 0; 
    for (i64 i = 0; i < n; ++i) {
        for (i64 j = 0; j < 5; ++j) {
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
        }

        for (i64 j = 0; j < 5; ++j) {
            string &s = a[i];
            i64 cur = j;           
            i64 score = dp[i][j]; 

            if (score <= neg_inf) continue; 
            for (char &si : s) {
                if (si == b[cur]) {
                    cur = (cur + 1) % 5; 
                    if (si == 'k') score += 10;  
                }
                if (mp.find(si) != mp.end()) score -= 1;
            }

            dp[i + 1][cur] = max(dp[i + 1][cur], score);
        }
    }
    i64 max_score = neg_inf;
    for (i64 j = 0; j < 5; ++j) {
        max_score = max(max_score, dp[n][j]);
    }

    cout << max(0LL, max_score) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}