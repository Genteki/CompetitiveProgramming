#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> a(26, 0);
    for (auto & si : s) {
        a[si - 'a'] ++;
    }

    int m = *max_element(all(a));
    for (;m--;) {
        for (int i = 0; i < 26; ++i) {
            if (a[i]) {
                cout << char('a' + i);
                --a[i];
            }
        }
    }
    cout << endl;
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