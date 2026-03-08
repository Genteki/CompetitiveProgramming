// e.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const i64 mod = 998244353;

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
int op (int l, int r) {return max(l, r);}
int e() {return 0;}
int sum(int l, int r) {return l + r;}

using MaxTree = SegmentTree<int, op, e>;
using SumTree = SegmentTree<int, sum, e>;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (auto & ai : a) cin >> ai,--ai;
    for (auto & ci : c) cin >> ci,--ci;
    MaxTree st(a);
    vector<vector<int>> g(n);
    i64 ans = 1;
    for (int i = 0; i < n; ++i) {
        g[c[i]].push_back(i);
    }
    for (auto&gi : g) {

        if(gi.size() <= 1) continue;

        for (auto gii : gi) st.update(gii, 0);
        auto ord = gi;
        sort(ord.begin(), ord.end(), [&a](int l, int r) {return a[l] < a[r];});
        int ni = gi.size();
        vector<int> init(ni, 0);
        SumTree t(init);

        for (auto i : ord) {
            int idx = lower_bound(gi.begin(), gi.end(), i) - gi.begin();
            auto l = partition_point(gi.begin(), gi.begin()+idx, [&](int x) ->bool{
                int y = gi[idx];
                int len = st.query(x, y);

                if (len <= a[i]) return false;
                else return true;
            });
            auto r = partition_point(gi.begin()+idx, gi.end(), [&](int x) ->bool{
                int y = gi[idx];
                int len = st.query(y, x);
                if (len > a[i]) return false;
                else return true;
            });
            int dl = distance(gi.begin(), l), dr = distance(gi.begin(), r);
            int z = t.query(dl, dr-1);
            ans = ans * (dr-dl-z) % mod;
            t.update(idx, 1);
        }

        for (auto gii : gi) st.update(gii, a[gii]);
    }

    cout << ans<< endl;
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