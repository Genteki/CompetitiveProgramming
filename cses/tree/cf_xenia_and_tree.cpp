// Xenia and Tree
// https://codeforces.com/problemset/problem/342/E
// Tree, Centroid Decomposition

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
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x>> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> subtree_size(n), min_dist(n, inf);
    vector<bool> is_removed(n, 0);
    vector<vector<pair<int, int>>> ancestors(n);

    auto cal_subtree_size = [&](auto &&self, int node, int parent = -1) -> int {
        int& res = subtree_size[node];
        res = 1;
        for (int & subi : adj[node]) {
            if (subi == parent) continue;
            res += self(self, subi, node);
        }
        return res;
    };
    
    auto get_centroid = [&](auto&& self, int node, int tree_size, int parent = -1) -> int {
        for (int& subi : adj[node]) {
            if (subi == parent) continue;
            if (subtree_size[subi] * 2 > tree_size) return self(self, subi, tree_size, node);
        }
        return node;
    };

    auto get_distance = [&](auto &&self, int node, int centroid, int parent=-1, int cur_dist=1) -> void {
        for (int subi : adj[node]) {
            if (subi == parent) continue;
            cur_dist++;
            self(self, subi, centroid, node, cur_dist);
            cur_dist--;
        }
        ancestors[node].push_back({centroid, cur_dist});
    };

    auto build_centroid_decompostion = [&](auto&& self, int node) -> void {
        int centroid = get_centroid(get_centroid, node, cal_subtree_size(cal_subtree_size, node));
        for (int subi : adj[centroid]) {
            if (!is_removed[subi]) get_distance(get_distance, subi, centroid, centroid);
        }
        is_removed[centroid] = true;
        for (int subi : adj[centroid]) {
            if (!is_removed[subi]) {
                self(self, subi);
            }
        }
    };

    build_centroid_decompostion(build_centroid_decompostion, 0);
    

    

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
