// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    i64 ans = 0;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') for (int j = i + 1; j < n; ++j) {
            if (j * 2 - i < n and s[j] == 'B' and s[j*2-i] == 'C') ++ans;
        }
    }
    cout << ans;
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