// e.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
const int inf = 1e9;
void solve() {
    int n;
    cin >> n;
    vector<int> s(n+1, 1);
    for (int i = 0; i < n; ++i) s[i+1] = s[i] * 3;
    vector<int> a(s[n]);
    for (auto & ai : a) {char x; cin >> x; ai = x - '0';}
    vector b(n+1, vector<int>(s[n], -1));
    auto dfs = [&]( auto && self, int idx, int depth) -> int {
        if (depth == 0) {
            b[depth][idx] = a[idx];
            return a[idx];
        }
        int cnt[2] = {0};
        for (int i = 0; i < 3; ++i) {
            cnt[self(self, idx + i * s[depth-1], depth-1)]++; 
        }
        if (cnt[0] > cnt[1]) {
            b[depth][idx] = 0;
        } else {
            b[depth][idx] = 1;
        }
        return b[depth][idx];
    };

    dfs(dfs, 0, n);
    int tgt = b[n][0];
    auto dfs2 = [&]( auto && self, int idx, int depth) -> int {
        if (depth == 0) {
            if (a[idx] == tgt) return 1;
            else return 0;
        }
        vector<int> cnt(3);
            for (int i = 0; i < 3; ++i) {
                cnt[i] = self(self, idx + i * s[depth-1], depth-1);
            }
            sort(cnt.begin(), cnt.end());
            return cnt[0] + cnt[1];
    };
    cout << dfs2(dfs2, 0, n) ;
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