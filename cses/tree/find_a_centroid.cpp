// finding a centroid
// https://cses.fi/problemset/task/2079

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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> subtree_size(n, 0);
    auto get_res = [&](auto &&self, int node, int parent=-1) -> int {
        int &res = subtree_size[node];
        res = 1;
        for (int subi : adj[node]) {
            if (subi == parent) continue;
            res += self(self, subi, node);
        }
        return res;
    };

    get_res(get_res, 0);

    auto get_centroid = [&](auto &&self, int node, int parent=-1) ->int {
        for (auto subi : adj[node]) {
            if (subi == parent) continue;
            if (2 * subtree_size[subi] > n) {
                return self(self, subi, node);
            }
        }
        return node;
    };

    cout << (get_centroid(get_centroid, 0) + 1) << endl;

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