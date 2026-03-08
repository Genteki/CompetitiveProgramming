// d.cpp
#include <bits/stdc++.h>

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n,w;
    std::cin >> n >> w;
    std::vector a(w, std::vector<int>());
    std::vector<int> x(n), y(n), ord(n), row(n);
    for (int i = 0; i < n; ++i) {
        int a,b;
        std::cin >> a >> b;
        --a; --b;
        x[i] = a; y[i] = b;

    }
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](const int& lhs, const int & rhs) {
        return y[lhs] < y[rhs];
    });
    for (auto i : ord) {
        a[x[i]].push_back(y[i]);
        row[i] = a[x[i]].size();
    }
    int rmx = 1e9;
    for (auto & ai : a) {
        rmx = std::min<int>(rmx, ai.size());
    }
    std::vector<int> ans(rmx, 0);
    for (int i = 0; i < rmx; ++i) {
        for (int j = 0; j < w; ++j) {
            ans[i] = std::max(ans[i], a[j][i]);
        }
    }
    int q;
    debug(a);
    debug(ans);
    std::cin >> q;
    while(q--) {
        int t, idx;
        std::cin >> t >> idx;
        --idx;
        if (row[idx] > rmx) {
            std::cout << "Yes\n";
        }  else {
            int tmax = ans[row[idx]-1];
            debug(row[idx], tmax);
            if (t > tmax) {
                std::cout << "No\n";
            } else {
                std::cout << "Yes\n";
            }
        }
    }
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
