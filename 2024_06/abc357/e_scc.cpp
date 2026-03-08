#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;

    vector<int> adj(n);
    vector<vector<int>> adj_(n);
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        --y;
        adj[i] = y;
        adj_[y].push_back(i);
    }

    vector<int> component;
    vector<bool> used(n, false);
    stack<int> order;
    vector<int> root(n), scc_n(n, 0);
    vector<vector<int>> adj_scc(n);

    auto dfs1 = [&](auto && self, int node) -> void {
        used[node] = true;
        int sub = adj[node];
        if (!used[sub]) {
            self(self, sub);
        }
        order.push(node);
    };
    auto dfs2 = [&](auto &&self, int node) -> void {
        used[node] = true;
        component.push_back(node);
        for (int subi : adj_[node]) {
            if (!used[subi]) {
                self(self, subi);
            }
        }
    };
    vector<int> root_node;

    for (int i = 0; i < n; ++i) {
        if(!used[i]) dfs1(dfs1, i);
    }

    fill(all(used), false) ;

    while(!order.empty()) {
        int t = order.top();
        order.pop();
        if (!used[t]) {
            dfs2(dfs2, t);
        }
        root_node.push_back(t);
        for (int ci : component) {
            root[ci] = t;
        }
        scc_n[t] = component.size();
        component.clear();
    }

    for (int i = 0; i < n; ++i) {
        int from = i, to = adj[i];
        if (root[from] != root[to]) {
            adj_scc[root[from]].push_back(root[to]);
        }
    }

    vector<int> sub_n(n, 0);
    auto dfs3 = [&](auto && self, int node) -> void {
        used[node] = true;
        for (int subi : adj_scc[node]) {
            if (!used[subi]) {
                self(self, subi);
            }
        }
        for (int subi : adj_scc[node]) {
            sub_n[node] += (sub_n[subi] + scc_n[subi]);
        }
    };

    fill(all(used), false);
    for (int i : root_node) {
        if (!used[i]) dfs3(dfs3, i);
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        if (scc_n[i] > 0) {
            ans = ans + (i64)scc_n[i] * (i64)scc_n[i] +
                  (i64)scc_n[i] * (i64)sub_n[i];
        }
    }

    cout << ans << endl;
    // for (auto )
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