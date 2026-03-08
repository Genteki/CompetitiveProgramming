// e1.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 INF = LONG_MAX;
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
typedef array<i64, 3> Edge;
void solve() {
    i64 n, m, p;
    cin >> n >> m >> p;
    vector<i64> r(p);
    for (int i = 0; i < p; ++i) {
        cin >> r[i];
        --r[i];
    }
    vector edges(m, array<int,3>());
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        edges[i] = {w, u, v};
    }
    sort(all(edges));

    DSU dsu(2 * n - 1);
    int cnt = n;
    vector<int> weight(2 * n - 1, 0);
    vector krt(2 * n - 1, vector<int>());

    for (auto [w, u, v] : edges) {
        if (!dsu.same(u, v)) {
            int x = cnt++;
            weight[x] = w;
            krt[x].push_back(v);
            krt[x].push_back(u);
            dsu.unite(x, u);
            dsu.unite(x, v);
        }
    }

    vector<int> siz(2 * n - 1, 1);
    for (auto ri : r) {
        siz[ri] ++;
    }


    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}