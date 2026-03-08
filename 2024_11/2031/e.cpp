// e.cpp
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
    vector<int> p(n, -1);
    vector<vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        int v;
        cin >> v;
        --v;
        g[v].push_back(i);
        g[i].push_back(v);
        p[i] = v;
    }
    vector<int> ans(n, 0);
    auto dfs = [&](auto && self, int u, int p = -1) -> int {
        if (g[u].size() == 1 && g[u][0] == p) {
            ans[u] = 1;
            return 1;
        }
        priority_queue<int, vector<int>, std::greater<>> pq;
        for (auto v : g[u]) {
            if (v==p) continue;
            pq.push(self(self, v, u));
        }
        while(pq.size() > 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int c = max(a, b) + 1;
            pq.push(c);
        }
        if (pq.size() == 2) pq.pop();
        ans[u] = pq.top() + 1;
        return pq.top() + 1;
    };
    cout << dfs(dfs, 0)-1 << endl;
    debug(ans);

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