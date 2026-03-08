#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n,m,h;
    cin >> n >> m >> h;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    vector g(n, vector<int>());
    vector<pair<int,int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int u,v ;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = {u, v};
    }
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    vector<int> p(n, -1);
    
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    for (; test_cases--;) {
        solve();
    }
}