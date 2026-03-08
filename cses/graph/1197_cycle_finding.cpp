#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
struct Edge {
    int u, v;
    i64 c;
};
const i64 inf = 1e18;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    vector<vector<int>> g(n);
    for (auto & e : edges) {
        int u, v, c;
        cin >> u >> v >> c;
        e.u = --u;
        e.v = --v ;
        e.c = c;
        g[u].push_back(v);
    }
    vector<int> viewed(n, 0), v2(n, 0);
    vector<i64> d(n, inf);
    vector<int> p(n, -1);
    int x;
    auto dfs = [&](auto &&self, int v, int& cnt) -> void {
        viewed[v] = true;
        ++cnt;
        for (auto u : g[v]) {
            if (!viewed[u]) {
                self(self, u, cnt);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (viewed[i] == 0) {
            fill(all(d), inf);
            d[i] = 0;
            int cnt = 0;
            dfs(dfs, i, cnt);
            for (int i = 0; i < cnt; ++i) {
                x = -1;
                for (auto e : edges) {
                    if (d[e.u] != inf && d[e.u] + e.c < d[e.v] && !v2[e.u] && !v2[e.v]) {
                        d[e.v] = max(-inf, d[e.u] + e.c);
                        p[e.v] = p[e.u];
                        x = e.v;
                        p[e.v] = e.u;
                    }
                }
            }
            v2 = viewed;
            if (x != -1) {
                cout << "YES\n";
                vector<int> path;
                int start = x;
                for (int i = 0; i < n; ++i) {
                    start = p[start];
                }
                x = start;
                path.push_back(x);
                while (p[x] != start) {
                    path.push_back(p[x]);
                    x = p[x];
                }
                reverse(all(path));
                for (auto pi : path) cout << (pi + 1) << " ";
                cout << (x + 1) << endl;
                return;
            }
        }
    }
    
    
        cout << "NO\n";
    
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