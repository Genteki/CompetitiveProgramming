// d.cpp
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i ) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int root = -1;
    vector<int> v(n, false);
    for (; k--;) {
        int a;
        cin >> a;
        a--;
        v[a] = true;
        root = a;
    }

    debug(v);
    vector<int> num(n, 0);
    int ans = 0;

    auto dfs = [&](auto&& self, int node, int parent = -1) -> void {
        if (v[node]) num[node]++;
        if (g[node].size() == 1 && g[node][0] == parent) return;
        for (auto & u : g[node]) {
            if (u == parent) continue;
            self(self, u, node);
            num[node] += num[u];
        }
    };

    debug(num);
    dfs(dfs, root);

    for (auto& ni : num) {
        if (ni) ans++;
    }

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