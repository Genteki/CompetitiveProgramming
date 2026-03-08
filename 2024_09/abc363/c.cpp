// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(all(s));

    int ans = 0;
    do {
        bool is = false;
        for (int i = 0; i < n - k + 1; ++i) {
            bool flag = true;
            for (int j = 0; j < k; ++j) {
                flag = flag && (s[i + j] == s[i + k - 1 - j]);
            }
            is = is || flag;
        }

        if (!is) ans++;
    } while(next_permutation(all(s)));
    cout << ans;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}