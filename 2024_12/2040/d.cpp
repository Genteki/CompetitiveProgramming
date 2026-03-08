// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
const int N = 4e5 + 5;
vector<int> prime(N+1, true);
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u,v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> a(n, -1), used(2 * n + 1, 0);
    a[0] = 1;
    int odd = 1, even = 2;
    used[1] = true;
    auto dfs = [&] (auto &&self, int u, int p = -1) -> void {
        for (auto v : g[u]) {
            if (v == p) continue;
            debug(v, a[u]);
            if (!used[a[u] + 1]) {
                a[v] = a[u] + 1;
                if (a[v] % 2) odd = max(odd, a[v]);
                else even = max(even, a[v]);
            } else {
                if (a[u] % 2) {
                    a[v] = max(a[u] + 4, odd + 2);
                    odd = max(odd, a[v]);
                } else {
                    a[v] = max(a[u] + 4, even + 2);
                    even = max(even, a[v]);
                }
            }
            used[a[v]] = true;
            self(self, v, u);
        }
    };
    dfs(dfs, 0);
    for (auto ai : a) cout << (ai) << " ";
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