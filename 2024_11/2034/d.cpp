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
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    vector<pair<int,int>> ops;
    vector<int> ones;

    auto b = a;
    sort(all(b));
    if (a == b) {
        cout << 0 << endl;
        return;
    }
    debug(a, b);

    vector<set<int>> x(3);
    for (int i = 0; i < n ; ++i) {
        if (a[i] != b[i]) {
            x[a[i]].insert(i);
        }
        if (a[i] == 1) x[1].insert(i);
    }
    debug(x[0].size(), x[2].size());
    while(!x[0].empty() || !x[2].empty()) {
        debug(x[0].size(), x[2].size());
        if (x[0].empty() || *x[0].rbegin() < *x[1].begin()) {
            int u = *x[2].begin();
            int v = *x[1].rbegin();
            ops.emplace_back(u, v);
            x[2].erase(u);
            x[1].erase(v);
            if (b[u] != 1) x[1].insert(u);
            if (b[v] != 2) x[2].insert(v);
        } else if (x[2].empty() || *x[2].begin() > *x[1].rbegin()) {
            int u = *x[0].rbegin();
            int v = *x[1].begin();
            ops.emplace_back(u, v);
            x[0].erase(u);
            x[1].erase(v);
            if (b[u] != 1) x[1].insert(u);
            if (b[v] != 0) x[0].insert(v);
        } else if (abs(*x[1].rbegin() - *x[2].begin()) >
                   abs(*x[1].begin() - *x[0].rbegin())) {
            int u = *x[2].begin();
            int v = *x[1].rbegin();
            ops.emplace_back(u, v);
            x[2].erase(u);
            x[1].erase(v);
            if (b[u] != 1) x[1].insert(u);
            if (b[v] != 2) x[2].insert(v);
        } else {
            int u = *x[0].rbegin();
            int v = *x[1].begin();
            ops.emplace_back(u, v);
            x[0].erase(u);
            x[1].erase(v);
            if (b[u] != 1) x[1].insert(u);
            if (b[v] != 0) x[0].insert(v);
        }
    }
    cout << ops.size() << endl;
    for (auto& [u, v] : ops)
        cout <<(u+1) << " " << (v+1) << endl;
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