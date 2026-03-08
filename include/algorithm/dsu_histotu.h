#ifndef DSU_HIST
#define DSU_HIST
#include <vector>
#include <numeric>
struct DSU {
    std::vector<int> rank, root;
    std::vector<std::pair<int&, int>> his;
    DSU(int n) : rank(n, 1), root(n) { iota(root.begin(), root.end(), 0); }
    int find(int x) {
        while (x != root[x]) x = find(root[x]);
        return x;
    }
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (rank[u] < rank[v]) std::swap(u, v);
        his.emplace_back(rank[u], rank[u]);
        rank[u] += rank[v];
        his.emplace_back(root[v], root[v]);
        root[v] = u;
        return true;
    }
    int size(int x) { return rank[find(x)]; }
    void undo(int x) {
        while (int(his.size()) > x) {
            his.back().first = his.back().second;
            his.pop_back();
        }
    }
};
#endif