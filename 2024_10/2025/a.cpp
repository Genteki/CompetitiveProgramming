#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    string s, t;
    cin >> s >> t;
    int ls = s.size(), lt = t.size();
    int x = min(ls, lt);
    for (int i = 0; i < min(ls, lt); ++i) {
        if (s[i] != t[i]) {
            x = i;
            break;
        }
    }
    int ans = 0;
    if (x == 0) {
        ans = ls + lt;
    } else {
        ans = x + 1 + (ls - x) + (lt - x);
    }
    cout << ans << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}