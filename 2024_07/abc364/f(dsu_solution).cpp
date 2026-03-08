#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
struct DSU {
    std::vector<int> root, rank;
    int find_root(int node) {
        return root[node] == node ? node : (root[node] = find_root(root[node]));
    }
    void make_union(int node) {
        root[node] = node;
    }
    void init() {
        for (int i = 0; i < root.size(); ++i)
            make_union(i);
    }
    void unite(int a, int b) {
        a = find_root(a);
        b = find_root(b);
        if (a == b) return;
        if (a > b) std::swap(a, b);
        root[a] = b;
    }
    DSU(int n) {
        root.assign(n, 0);
        init();
    }
    DSU(const DSU& other) {
        root = other.root;
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, pair<int,int>>> queries(q);
    for (auto &[c, r] : queries) {
        cin >> r.first >> r.second >> c;
        --r.first; --r.second;
    }
    sort(all(queries));
    DSU dsu(n);
    i64 ans = 0;
    for (auto &[c, range] : queries) {
        int l = range.first, r = range.second;
        for (int i = l; i <= r; ++i) {
            i = dsu.find_root(i);
            dsu.unite(r, i);
            ans += c;
        }
        debug(dsu.root);
    }
    int cnt = 0;
    for (int i = 0; auto& pi : dsu.root) {
        if (i == pi) cnt++;
        ++i;
    }
    if (cnt == 1) cout << ans;
    else cout << -1;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}