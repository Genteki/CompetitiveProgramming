// f.cpp
// segment tree decomposition
// from #306767279 by jiangly
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
struct DSU {
    vector<int> rank, root;
    vector<pair<int&,int>> his;
    DSU(int n) : rank(n, 1), root(n) {iota(root.begin(), root.end(), 0); }
    int find(int x) { while(x != root[x]) x=find(root[x]); return x;}
    bool unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (rank[u] < rank[v] ) swap(u, v);
        his.emplace_back(rank[u], rank[u]);
        rank[u] += rank[v];
        his.emplace_back(root[v], root[v]);
        root[v] = u;
        return true;
    }
    int size(int x) {return rank[find(x)];}
    void undo(int x) {
        while(int(his.size()) > x) {
            his.back().first = his.back().second;
            his.pop_back();
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    map<array<int,2>, int> edges[2]; // u->v: query time
    vector<vector<array<int,3>>> f(4*q); // segtree
    auto addEdge = [&](this auto &&self, int v, int tl, int tr, int ql, int qr, array<int,3> info) -> void {
        if (tl >= qr or  tr <= ql) {
            return;
        }
        if (tl >= ql and tr <= qr) {
            f[v].push_back(info);
            return;
        }
        int tm = (tl + tr) / 2;
        self(v<<1, tl, tm, ql, qr, info);
        self(v<<1|1, tm, tr, ql, qr, info);
    };

    for (int i = 0; i < q; ++i) {
        char c;
        cin >> c;
        int u, v;
        cin>>u >> v;
        --u; --v;
        if (u > v) swap(u, v);
        int g = c - 'A';
        if (edges[g].contains({u, v})) {
            addEdge(1, 0, q, edges[g][{u,v}], i, {g,u,v});
            edges[g].erase({u,v});
        } else {
            edges[g][{u,v}] = i;
        }
    }

    for (int g = 0; g < 2; ++g) {
        for (auto [e, i] : edges[g]) {
            auto [u, v] = e;
            addEdge(1, 0, q, i, q, {g, u, v});
        }
    }
    DSU dsu[2] {n, n};
    auto work = [&](this auto&& self, int v, int tl, int tr, int A, int B) -> void{
        int his_size[2] = {dsu[0].his.size(), dsu[1].his.size()};
        for (auto [g, u, w] : f[v]) {
            A += dsu[0].unite(u, w);
            if (g == 0) {
                B += dsu[1].unite(u, w);
            }
        }
        if (tr - tl == 1) {
            cout << (A-B) << "\n";
        } else {
            int tm = (tl + tr) / 2;

            self(v<<1, tl, tm, A, B);
            self(v<<1|1, tm, tr, A, B);
        }
        for (int g = 0; g < 2; ++g) {
            dsu[g].undo(his_size[g]);
        }
    };

    work(1, 0,  q, 0, 0);

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

        solve();
}