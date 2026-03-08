// k.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

struct Info {
    int color;
    int t;
    Info() : Info(-1){}
    explicit Info(int x) {color=x; t=-1;}
    Info(int x, int y) : color(x), t(y) {}
    friend bool operator!=(const Info& lhs, const Info& rhs) {
        return lhs.t != rhs.t || lhs.color != rhs.color;
    }
};
Info op(const Info& lhs, const Info& rhs) {
    if (lhs.color==-1) return rhs;
    else if (rhs.color==-1) return lhs;
    if (lhs.t > rhs.t) {
        return lhs;
    } else {
        return rhs;
    }
}
Info e() { return Info(-1, -1); }
template <class T, auto op, auto e>
struct LazySegmentTree {
   public:
    LazySegmentTree() : LazySegmentTree(1) {}
    explicit LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n, e())) {}
    explicit LazySegmentTree(const std::vector<T>& a) : _n(int(a.size())) {
        t = std::vector<T>(_n * 4, e());
        lazy = std::vector<T>(_n * 4, e());
        build(a, 1, 0, _n - 1);
    }

    void build(const std::vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, (v << 1), tl, tm);
            build(a, (v << 1) | 1, tm + 1, tr);
            t[v] = op(t[(v << 1)], t[(v << 1) | 1]);
        }
    }

    void push(int v) {
        if (lazy[v] != e()) {
            t[(v << 1)] = op(lazy[v], t[(v << 1)]);
            lazy[(v << 1)] = op(lazy[v], lazy[(v << 1)]);
            t[(v << 1) | 1] = op(lazy[v], t[(v << 1) | 1]);
            lazy[(v << 1) | 1] = op(lazy[v], lazy[(v << 1) | 1]);
            lazy[v] = e();
        }
    }

    void update(int v, int tl, int tr, int l, int r, T delta) {
        if (l > r) return;
        if (l == tl && tr == r) {
            t[v] = op(delta, t[v]);
            lazy[v] = op(delta, lazy[v]);
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update((v << 1), tl, tm, l, std::min(r, tm), delta);
            update((v << 1) | 1, tm + 1, tr, std::max(tm + 1, l), r, delta);
            t[v] = op(t[(v << 1)], t[(v << 1) | 1]);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return e();
        if (l == tl && r == tr) return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return op(query((v << 1), tl, tm, l, std::min(r, tm)),
                  query((v << 1) | 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    T query(int l, int r) { return query(1, 0, _n - 1, l, r); }

    void update(int l, int r, T delta) { update(1, 0, _n - 1, l, r, delta); }

   private:
    int _n, log;
    std::vector<T> t;
    std::vector<T> lazy;
};
using LST = LazySegmentTree<Info, op, e>;
struct LCA {
    vector<int> height, euler, tin, tout, lca_tree;
    vector<bool> visited;
    vector<vector<int>> tins, touts;
    LST segtree;
    int n, m;

    int op_max(int lhs, int rhs) {return height[lhs]>height[rhs]?lhs:rhs;}
    static int e2() {return -1;}

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        tin.resize(n);
        tout.resize(n);
        tins.resize(n);
        touts.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        m = euler.size();
        segtree = LST(m);
        lca_tree.resize(m*4);
        build_lca(1,0,m-1);
    }
    int __lca_op(int lhs, int rhs) {
        return height[lhs] < height[rhs] ? lhs : rhs;
    }

    void build_lca(int v, int tl, int tr) {
        if (tl==tr) {
            lca_tree[v] = euler[tl];
            return;
        } else {
            int tm = (tl+tr) / 2;
            build_lca(v<<1, tl, tm);
            build_lca((v<<1)|1, tm+1, tr);
            lca_tree[v] = __lca_op(lca_tree[v<<1], lca_tree[(v<<1)|1]);
        }
    }

    int query(int v, int tl, int tr, int ql, int qr) {
        if (tl > qr or tr < ql) {return -1;}
        if (tl == ql and tr == qr) {
            return lca_tree[v];
        }
        int tm = (tl + tr) / 2;
        int left = query(v<<1, tl, tm, ql, min(tm, qr));
        int right = query(v<<1|1, tm+1, tr, max(tm+1,ql), qr);
        if (left==-1) return right;
        else if (right==-1) return left;
        else return __lca_op(left, right);
    }

    int lca(int u, int v) {
        int left = tin[u], right=tin[v];
        if (left > right) swap(left, right);
        return query(1, 0, m-1, left, right); 
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {

        visited[node] = true;
        height[node] = h;
        tin[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                tins[node].push_back(euler.size()-1);
                dfs(adj, to, h + 1);
                euler.push_back(node);
                touts[node].push_back(euler.size()-1);
            }
        }
        tout[node] = euler.size()-1;
    }

    int bs(int u, int v) {
        int low = 0, high = tins[u].size();
        while(high-low>1) {
            int mid = (low + high)/ 2;
            if (tins[u][mid]>tout[v]) high = mid;
            else low = mid;
        }
        return low;
    }

    void paint_path(int u, int v, Info tu) {
        if(u==v) {
            segtree.update(tin[u], tin[u], tu);
            segtree.update(tout[u], tout[u], tu);
            return;
        }
        if (tin[u] > tin[v]) swap(u, v);
        int w = bs(u, v);
        segtree.update(tins[u][w], tin[v], tu);
        segtree.update(tout[v], touts[u][w], tu);
    }

    void q1(int u, int v, int c, int stp) {
        Info tu{c, stp};
        int a = lca(u, v);
        paint_path(a, u, tu);
        paint_path(a, v, tu);
    }
    void q2(int u, int v, int c, int stp, vector<vector<int>>& g) {
        Info tu{c, stp};
        if (u == v) {
            segtree.update(0, m-1, tu);
        } else if (tin[v] < tin[u] or tin[v] > tout[u]) {
            segtree.update(tin[u], tout[u], tu);
        } else {
            int w = bs(u, v);
            if (tins[u].size()>0) {
                segtree.update(0, tins[u][w], tu);
                segtree.update(touts[u][w], m - 1, tu);
            } else {
                segtree.update(0, tin[u], tu);
                segtree.update(tout[u], m - 1, tu);
            }

        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    LST lst;
    vector<int> color(n);
    for (auto &c : color) cin >> c;
    vector<Info> ans(n);
    for (int i = 0; i < n; ++i) ans[i] = Info{color[i]};

    vector g(n, vector<int>());
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<array<int,4>> ops(m);
    for (int i = 0; i < m; ++i) {
        for(int j = 0; j < 4; ++j) {
            cin >> ops[i][j];
        }
        --ops[i][1]; --ops[i][2]; 
    }
    LCA lca(g);
    for (int i = 0; i < m; ++i) {
        debug(i, ops[i]);
        if (ops[i][0]==1) lca.q1(ops[i][1], ops[i][2], ops[i][3], i);
        else lca.q2(ops[i][1], ops[i][2], ops[i][3], i, g);
        for (int i = 0; i < lca.m; ++i) {
            auto info = lca.segtree.query(i, i);
            int vertex = lca.euler[i];
            ans[vertex] = op(ans[vertex], info);
        }

        for (auto info : ans) {
            cout << info.color << " ";
        }cout << endl;
    }

    for (int i = 0; i < lca.m; ++i) {
        auto info = lca.segtree.query(i,i);
        int vertex = lca.euler[i];
        ans[vertex] = op(ans[vertex], info);
    }

    for (auto info : ans) {
        cout << info.color << " ";
    }
    cout << endl;
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