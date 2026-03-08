// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].insert(v);
        g[v].insert(u);
        edges.emplace_back(u, v);
    }
    vector<tuple<int, int, int>> ops;
    vector<bool> a(n, 0);
    for (auto v : g[0]) {
        a[v] = 1;
    }
    for (auto &[u, v] : edges) {
        if (u != 0 && v != 0) {
            g[u].erase(v);
            g[v].erase(u);
            a[u] = !a[u];
            a[v] = !a[v];
            ops.emplace_back(0 , u, v);
        }
    }
    int b = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i]) {
            b = i;
            break;
        }
    }
    if (b > 0) {
        for (int i = 1; i < n; ++i) {
            if (a[i] == 0) {
                ops.emplace_back(0, b, i);
                b = i;
            }
        }
    }
    cout << ops.size() << endl;
    for (auto [u, v, w] : ops) {
        ++u; ++v; ++w;
        cout << u << " " << v << " " << w << endl;
    }
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