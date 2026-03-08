// f.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
bool chmin(int& a, int b){ return b < a ? a = b, true : false; }
void solve() {
    int k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    int ns = s.size(), nt = t.size();
    if (ns > nt)  {
        swap(s,t);
        swap(ns, nt);
    }
    dp[0][k] = 0;
    vector<vector<int>> dp(ns+1, vector<int>(2*k+1, 1e5));
    for (int i = 0; i < ns; ++i) {
        for (int j = 0; j < 2 * k + 1; ++j) {
            int idxt = i - k + j;
            if (j < 0 or idxt >= nt) continue;
            
        }
    }

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}