// coin_collector.cpp
// strongly connected component, map reduce
// https://cses.fi/problemset/task/1686/
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    input(a);
    vector<vector<int>> g(n), g_(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g_[y].push_back(x);
    }   

    vector<int> roots(n), component, root_nodes;
    stack<int> order;
    vector<bool> visited(n, false);
    vector<i64> scc_coin(n, 0);

    auto dfs1 = [&](auto &&self, int node) -> void {
        visited[node] = true;
        for (int & subi : g[node]) {
            if (!visited[subi]) {
                self(self, subi);
            }
        }
        order.push(node);
    };

    auto dfs2 = [&](auto &&self, int node) -> void {
        visited[node] = true;
        component.push_back(node);
        for (int & subi : g_[node]) {
            if (!visited[subi]) {
                self(self, subi);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(dfs1, i);
        }
    }
    fill(all(visited), false);
    while(!order.empty()) {
        int t = order.top();
        order.pop();
        component.clear();
        if (!visited[t]) dfs2(dfs2, t);
        root_nodes.push_back(t);
        for (int ci : component) {
            roots[ci] = t;
            scc_coin[t] += a[ci];
        }
    }

    vector<vector<int>> adj_scc(n), adj_scc_(n);
    for (int i = 0; i < n; ++i) {
        for (auto & gi : g[i]) {
            if (roots[i] != roots[gi]) {
                adj_scc[roots[i]].push_back(roots[gi]);
                adj_scc_[roots[gi]].push_back(roots[i]);
            }
        }
    }
    fill(all(visited), false);
    vector<int> start_point;
    vector<i64> ans(n, -1);
    auto bfs= [&](auto && self, int node) -> void{
        visited[node] = true;
        if (scc_coin[node] > 0) {
            if (adj_scc[node].empty()) {
                ans[node] = scc_coin[node];
            } else {
                for (int subi : adj_scc[node]) {
                    if (!visited[subi]) self(self, subi);
                }
                for (int subi : adj_scc[node]) {
                    // cout << subi << " ";
                    // cout << (ans[subi]) << " " << scc_coin[node] << endl;
                    ans[node] = max(ans[node], ans[subi]+scc_coin[node]);
                }
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) bfs(bfs, i);
    }
    // cout << "roots: " << endl;
    // for (auto ri : roots) cout << ri << " ";
    // cout << endl << "scc coin: " << endl;
    // for (auto ansi : scc_coin) cout << ansi << " ";
    // cout << endl << "ans: " << endl;
    // for (auto ansi : ans ) cout << ansi << " ";
    // cout << endl;
    cout << (*max_element(all(ans))) << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}