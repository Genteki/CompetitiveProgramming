// d.cpp
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

struct Info{
    int i;
    bool v;
    Info() : i(0), v(0) {}
    Info (int a, bool b) : i(a), v(b) {}
};
Info op(const Info& a, const Info& b) {
    Info c;
    c.v = a.v | b.v;
    if (b.v == true and a.v == true) {
        c.i = min(a.i, b.i);
    } else if (b.v == true) {
        c.i = b.i;
    } else if (a.v == true) {
        c.i = a.i;
    } else {
        c.i = min(a.i, b.i);
    }
    return c;
}
Info e() {return Info(1e6,0);}
bool chmin(int& a, int b){ return b < a ? a = b, true : false; }
bool chmax(int& a, int b){ return b > a ? a = b, true : false; }

const int D = 30;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto & ai : a) cin >> ai;
    reverse(a.begin(), a.end());
    vector<int> ps(n+1, 0);
    for(int i = 0;i < n;++i) ps[i+1] = ps[i] ^ a[i];
    vector<Info> init(n);
    vector<SegmentTree<Info, op, e>> vst;
    for (int d = 0; d < D; ++d) {
        for (int i = 0; i < n; ++i) {
            init[i].i = i;
            init[i].v = (a[i] >= (1 << d));
        }
        vst.push_back(SegmentTree<Info, op, e>(init));
    }

    while(q--) {
        int x;
        cin >> x;
        int z = x;
        int ans = 0, l = 0, r = n-1;
        for (int d=D-1; d>=0;--d) {
            if (l > r) break;
            if ((x^ps[l]) & (1<<d)) {
                auto y = vst[d].query(l, r);
                if (y.v) {
                    l = max(l, y.i);
                    if ((x^ps[y.i]) >= a[y.i]) {
                        l = y.i+1;
                        y = vst[d].query(l, r);
                        if (y.v == true) {
                            chmin(r, y.i - 1);
                        }
                    } else {
                        l = y.i;
                        r = y.i-1;
                    }
                } else {
                    l = r+1;
                }
            } else {
                auto y = vst[d].query(l, r);
                if (y.v == true) {
                    chmin(r, y.i-1);
                }
            }
        }
        cout << l << " ";
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