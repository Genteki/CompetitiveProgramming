#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const { return w < other.w; }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] > rank[ry])
            parent[ry] = rx;
        else if (rank[rx] < rank[ry])
            parent[rx] = ry;
        else
            parent[ry] = rx, rank[rx]++;
        return true;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        --edges[i].u, --edges[i].v;
    }
    DSU dsu(n);
    vector<int> cnt_a(n, 0), cnt_b(n, 0);
    for (int i = 0; i < k; ++i) {
        int ai;
        cin >> ai;
        cnt_a[ai - 1]++;
    }
    for (int i = 0; i < k; ++i) {
        int ai;
        cin >> ai;
        cnt_b[ai - 1]++;
    }
    sort(edges.begin(), edges.end());
    i64 ans = 0;
    for (auto & e : edges) {
        int u = e.u, v= e.v, w = e.w;
        if (dsu.find(u) == dsu.find(v)) continue;
        int ru = dsu.find(u);
        int rv = dsu.find(v);
        dsu.unite(u, v);
        int p = dsu.find(u);
        cnt_a[p] = cnt_a[ru] + cnt_a[rv];
        cnt_b[p] = cnt_b[ru] + cnt_b[rv];
        int x = min(cnt_a[p], cnt_b[p]);
        ans += 1LL * w * x;
        cnt_a[p] -= x;
        cnt_b[p] -= x;

    }
    cout << ans;
    return 0;
}