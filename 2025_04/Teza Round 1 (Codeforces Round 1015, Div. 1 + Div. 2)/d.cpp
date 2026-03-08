// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n, -1);
    if (n/(m+1) >= k) {
        int t = n / (m+1);
        for (int i = 0; i < m+1; ++i) {
            for (int j = 0; j < t; ++j) {
                a[j+t*i] = j;
            }
        }
        for (auto & ai : a) if (ai == -1) ai = 1e5;
    } else {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != -1) continue;
            for (int j = 0; j <= m; ++j) {
                int t = i + j * k;
                if (t < n) a[t] = cnt;
            }
            ++cnt;
        }
    }

    
    for (auto ai : a) cout << ai << " "; cout << endl;
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