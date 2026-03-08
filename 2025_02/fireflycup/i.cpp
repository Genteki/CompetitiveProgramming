// i.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string s, t;
    cin >> s >> t;
    i64 ns = s.size(), nt = t.size();
    i64 ans = (1+ns) * (1+nt) - 1;
    vector<i64> cnt(26, 0);
    for (auto c : t) {
        cnt[c - 'a'] += 1;
    }
    for (auto c : s) {
        ans -= cnt[c - 'a'];
    }
    cout << ans << endl;
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