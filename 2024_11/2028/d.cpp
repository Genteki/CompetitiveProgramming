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
    vector<vector<int>> a(3, vector<int>(n)), b(3, vector<int>(n));
    for (int l = 0; l < 3; ++l) {
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            --x;
            a[l][i] = x;
            b[l][x] = i;
        }
    }
    vector<int> viewed(n, 0);
    vector<pair<int,int>> p(n);
    // vector<vector<pair<int, int>>> g(n);
    // for (int l = 0; l < 3; ++l) {
    //     for (int i = 0; i < n-1; ++i) {
    //          g[b[l][i]].emplace_back(b[l][i + 1], l);
    //     }
    // }

    // auto dfs = [&](auto && self, int u, int pi = -1, int pl = -1) -> void {
    //     viewed[u] = true;
    //     p[u] = {pi, pl};
    //     for (auto &[v, vl] : g[u]) {
    //         if (!viewed[v]) {
    //             self(self, v, u, vl);
    //         }
    //     }
    // };
    vector<int> pointers(3 , 0);
    queue<tuple<int,int,int>> q;
    q.emplace(0, -1, -1);
    auto dfs = [&](auto && self, int u, int pi = -1, int pl = -1) -> void {
        viewed[u] = true;
        int pref = a[pl][u];
        for (int i = pointers[pl]; i < pref; ++i) {
            if (!viewed[b[pl][i]]) {

            }
        }
    };
    while (!q.empty()) {
        auto [u, pi, pl] = q.front();
        q.pop();
        viewed[u] = true;
        p[u] = {pi, pl};
        for (int l = 0; l < 3; ++l) {
            int pref = a[l][u];
            debug(u, pref);
            for (int i = pointers[l]; i < pref; ++i) {
                if (!viewed[b[l][i]] && b[l][i] > u) {
                    q.emplace(b[l][i], u, l);
                }
            }
            pointers[l] = max(pointers[l], pref);
        }
    }
    debug(viewed);
    debug(p);
    vector<string> player = {"q", "k", "j"};
    if (!viewed[n-1]) {
        cout << "NO" << endl;
        return;
    }
    vector<pair<int,int>> order;
    int cur = n-1;
    while(cur != 0) {
        auto [pi, pl] = p[cur];
        order.emplace_back(cur, pl);
        cur = pi;
    }
    debug(order);
    reverse(all(order));
    cout << "YES" << endl << order.size() << endl;
    for (auto [i, l] : order) {
        cout << player[l] << " " << (i + 1) << endl;
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