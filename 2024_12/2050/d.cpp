// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; auto si : s) {
        a[i] = si - '0';
        i++;
    }
    debug(a);
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && a[j-1] < a[i] - (i - j + 1)) {
            --j;
        }
        if (j < i) {
            char tmp = a[i] - (i - j);
            for (int k = i; k > j; --k) {
                a[k] = a[k - 1];
            }
            a[j] = tmp;
        }
        
        debug(a);
    }
    for (auto ai : a) cout << ai;
    cout << endl;
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