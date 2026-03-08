#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    if (s[0] == '1') {
        ++ans;
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) ++ans;
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