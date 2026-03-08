#ifndef DSU_H
#define DSU_H

#include <vector>
#include <numeric>

struct DSU {
    std::vector<int> root, rank;
    DSU(int n) { init(n); }
    void init(int n) {
        root.resize(n);
        std::iota(root.begin(), root.end(), 0);
        rank.assign(n, 1);
    }
    int find(int x) {
        while(x != root[x]) {
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

#endif