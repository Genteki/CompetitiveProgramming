// e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
struct DSU {
    std::vector<int> root, rank;
    DSU(int n) { init(n); }
    void init(int n) {
        root.resize(n);
        std::iota(root.begin(), root.end(), 0);
        rank.assign(n, 1);
    }
    int find(int x) {
        while (x != root[x]) {
            x = root[x] = root[root[x]];
        }
        return x;
    }
    bool same(int a, int b) { return find(a) == find(b); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) std::swap(a, b);
        root[b] = a;
        rank[a] += rank[b];
        return true;
    }
    DSU(const DSU& other) {
        root = other.root;
        rank = other.rank;
    }
};
void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int,int>> fedg;
    for (int i = 0; i < m1; ++i) {
        int u,v;
        cin >> u>> v;
        --u; --v;
        fedg.emplace_back(u,v);
    }
    DSU dsu(n);
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        dsu.unite(u,v);
    }
    auto& root = dsu.root;
    int ans = 0;
    DSU dsuf(n);
    for (auto [u,v] : fedg) {
        if (dsu.find(u) == dsu.find(v)) {
            dsuf.unite(u, v);
        } else {
            ++ans;
        }
    }
    
    for (int idx=0; auto x : dsu.root) {
        if (x == idx) {
            ans--;
        }
        ++idx;
    }
    for (int idx = 0; auto x : dsuf.root) {
        if (x == idx) {
            ans++;
        }
        ++idx;
    }
    cout << ans << endl;
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