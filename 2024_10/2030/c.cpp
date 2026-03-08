// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> w(n);
    for (int i = 0; i < n; ++i) w[i] = (s[i] == '1');
    bool ans = true;
    for (auto wi : w) {
        if (ans == wi) {
            break;
        }
        else ans = ! ans;
    }
    if (ans)
        cout << "YES" << endl;
    else cout << "NO" << endl;
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