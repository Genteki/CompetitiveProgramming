// g1.cpp
#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto &ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n), g_(n);
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        --j;
        g[i].push_back(j);
        g_[j].push_back(i);
    }
    vector<int> ord, viewed(n, 0);
    auto dfs1 = [&](auto &&self, int u) -> void {
        viewed[u] = 1;
        for (auto v : g[u]) {
            if (!viewed[v]) self(self, v);
        }
        ord.push_back(u);
    };
    for (int i = 0; i < n; ++i) {
        if (!viewed[i]) dfs1(dfs1, i);
    }
    fill(all(viewed), 0);
    vector<vector<int>> components;
    reverse(all(ord));
    auto dfs2 = [&](auto &&self, int u, vector<int> &c) -> void {
        c.push_back(u);
        viewed[u] = 1;
        for (auto v : g_[u]) {
            if (!viewed[v]) {
                self(self, v, c);
            }
        }
    };
    fill(all(viewed), 0);

    for (auto i : ord) {
        if (!viewed[i]) {
            vector<int> component;
            dfs2(dfs2, i, component);
            components.push_back(component);
        }
    }
    vector<int> s(n, 0);
    for (auto &ci : components) {
        for (auto cii : ci) {
            s[cii] = ci.size();
        }
    }
    fill(all(viewed), 0);
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        if (s[i] > 1) {
            q.emplace(i, 1);
            viewed[i] = 1;
        }
    }
    debug(components);
    fill(all(viewed), 0);
    auto dfs3 = [&](auto &&self, int u) -> int {
        if (viewed[u]) return 0;
        viewed[u] = 1;
        int cnt = 1;
        for (auto v : g_[u]) {
            if (s[v] == 1) {
                cnt += self(self, v);
            }
        }
        return cnt;
    };
    int ans = 0;

    for (const auto &c : components) {
        if (c.size() > 1) {
            int dep = 0;
            for (int u : c) {
                for (auto v : g_[u]) {
                    if (s[v] == 1) ans = max(ans, dfs3(dfs3, v));
                } 
            }
        }
    }

    cout << (ans + 2) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}