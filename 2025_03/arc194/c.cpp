// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>
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
            build((v << 1), tl, tm);
            build((v << 1) | 1, tm + 1, tr);
            t[v] = op(t[(v << 1)], t[(v << 1) | 1]);
        }
    }

    S __query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return e();
        if (ql == tl && qr == tr) return t[v];
        int tm = (tl + tr) / 2;
        S rl = __query((v << 1), tl, tm, ql, min(tm, qr));
        S rr = __query((v << 1) | 1, tm + 1, tr, max(ql, tm + 1), qr);
        return op(rl, rr);
    }

    void __update(int v, int tl, int tr, int pos, S val) {
        if (tl == tr)
            t[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                __update((v << 1), tl, tm, pos, val);
            else
                __update((v << 1) | 1, tm + 1, tr, pos, val);
            t[v] = op(t[(v << 1)], t[(v << 1) | 1]);
        }
    }

    S query(int ql, int qr) { return __query(1, 0, _n - 1, ql, qr); }

    void update(int pos, S val) { __update(1, 0, _n - 1, pos, val); }
};

#endif
auto op_sum = [](i64 a, i64 b) { return a + b; };
i64 e() { return 0; }
using Segtree = SegmentTree<i64, op_sum, e>;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), b(n), c(n);
    for (auto& ai : a) cin >> ai;
    for (auto& ai : b) cin >> ai;
    for (auto& ai : c) cin >> ai;
    vector<int> init(n, 0);
    for (int i = 0; i < n; ++i) {if (a[i] != b[i]) init[i] = 1;}
    for (int i = n-1; i >= 0; --i) {
        if ()
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}