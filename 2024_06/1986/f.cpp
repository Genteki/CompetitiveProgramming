// f.cpp
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
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> cc;
    vector<i64> ccs;
    vector<bool> used(n, false);
    vector<int> root(n, -1);
    vector<i64> cc_size(n, -1);
    auto dfs = [&](auto && self, int node) -> void{
        used[node] = true;
        cc.push_back(node);
        for (auto subi : adj[node]) {
            if (!used[subi]) {
                self(self, subi);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(dfs, i);
            ccs.push_back(cc.size());
            for (auto cci : cc) root[cci] = cc[0];
            cc_size[cc[0]] = cc.size();
            cc.clear();
        }
    }

    i64 s = 0;

    for (int i = 0; i < ccs.size(); ++i) {
        s += (ccs[i]*(ccs[i]-1)/2);
    }


    vector<i64> subtree_size(n, 0);
    vector<int> tin(n, 0), low(n, 0);
    fill(all(used), false);
    int time = 0;
    i64 max_reduct = 0;
    
    auto find_bridge = [&](auto &&self, int node, int parent=-1) -> void {
        used[node] = true;
        tin[node] = low[node] = ++time;
        subtree_size[node] = 1;
        for (int subi : adj[node]) {
            if (subi == parent) continue;
            if (!used[subi]) {
                self(self, subi, node);
                low[node] = min(low[subi], low[node]);
                subtree_size[node]+=subtree_size[subi];
                if (low[subi] > tin[node]) {
                    // then node->subi is bridge
                    // cout << "bridge: " << node << subi << endl;
                    i64 ori_size = cc_size[root[subi]];
                    i64 new_size1 = subtree_size[subi];
                    i64 reduced_val = ori_size*(ori_size-1) - new_size1*(new_size1-1) - (ori_size-new_size1) * (ori_size-new_size1-1);
                    reduced_val /= 2;
                    max_reduct = max(reduced_val, max_reduct);
                    // cout << " " << ori_size << " " << new_size1 << endl;
                }
            } else {
                low[node] = min(tin[subi], low[node]);
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!used[i]) find_bridge(find_bridge, i);
    }
    // cout << "\ntin:\n";
    // for (auto tini : tin) cout << tini << " ";
    // cout << "\nlow:\n";
    // for (auto lowi : low) cout << lowi << " ";
    // cout << endl;
    i64 ans = s - max_reduct;
    // cout << max_reduct << endl;
    cout << ans << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}