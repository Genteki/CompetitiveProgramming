// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    vector<set<int>> g(n);
    while(m--) {
        int u, v;
        cin >> u >> v;
        --u;--v;
        if (u > v) swap(u, v);
        if (u == v) {
            ++ans;
        } else if (g[u].find(v) == g[u].end()) {
            g[u].insert(v);
        } else {
            ++ans;
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