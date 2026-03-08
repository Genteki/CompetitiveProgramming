// f1.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
using namespace std;

typedef long long i64;

template <class S, auto op, auto e>
struct SegmentTree {
    int _n;
    std::vector<S> a, t;
    SegmentTree(vector<S>& arr) {
        _n = arr.size();
        a = arr;
        t = std::vector<S>(_n * 4, e());
        build(1, 0, _n - 1);
    }

    SegmentTree(int n) {
        _n = n;
        a = std::vector<S>(n);
        t = std::vector<S>(_n * 4, e());
        build(1, 0, _n - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            t[v] = op(t[v * 2], t[v * 2 + 1]);
        }
    }

    S __query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return e();
        if (ql == tl && qr == tr) return t[v];
        int tm = (tl + tr) / 2;
        S rl = __query(v * 2, tl, tm, ql, min(tm, qr));
        S rr = __query(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr);
        return op(rl, rr);
    }

    void __update(int v, int tl, int tr, int pos, S val) {
        if (tl == tr)
            t[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                __update(v * 2, tl, tm, pos, val);
            else
                __update(v * 2 + 1, tm + 1, tr, pos, val);
            t[v] = op(t[v * 2], t[v * 2 + 1]);
        }
    }

    S query(int ql, int qr) { return __query(1, 0, _n - 1, ql, qr); }

    void update(int pos, S val) { __update(1, 0, _n - 1, pos, val); }
};

template<typename T>
inline bool chmax(T& a, T b) {
    if (b > a) {
        a = b;
        return true;
    } else return false;
}

void solve() {
    int n;
    cin >> n;
    vector g(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int bob;
    cin >> bob >> bob;
    --bob;

    vector<int> depth(n, 0);
    vector<int> path;

    auto dfs = [&](auto&&self, int v, int p, int tgt) -> bool {
        bool on_way = false;
        if (v == tgt) on_way = true;
        for (auto u : g[v]) {
            if (u == p) continue;
            bool on_way_u = self(self, u, v, tgt);
            if (!on_way_u) chmax(depth[v], depth[u]+1);
            on_way |= on_way_u;
        }
        if (on_way) path.push_back(v);
        return on_way;
    };

    dfs(dfs, 0, -1, bob);
    debug(depth);
    auto f = []() { return -1; };
    auto op = [](int a, int b) { return max(a, b); };
    reverse(all(path));
    int m = path.size();
    vector<int> va(m), vb(m);
    for (int i = 0; i < m; ++i) {
        va[i] = i + depth[path[i]];
        vb[i] = i + depth[path[m - 1 - i]];
    }
    debug(va, vb);
    SegmentTree<int, op, f> sga(va), sgb(vb);
    debug(sga.query(1,1), sga.t);
    for (int i = 0; i < (m + 1) / 2; ++i) {
        debug(i);
        
        if (va[i] > sgb.query(i, m - 2 - i)) {cout << "Alice\n"; return; }
        if (vb[i] >= sga.query(i + 1, m - 2 - i)) {cout << "Bob\n"; return; }
    }

    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}