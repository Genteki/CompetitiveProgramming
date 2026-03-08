#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
#define int long long
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
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

struct da {
    int x, y;
    int d;
    da(){x=1e9;y=-1e9;d=-1e9;};
    da(int a, int b) : x(a), y(b){
        d = 0;
    }
};
struct da2 {
    int x, y;
    int d;
    da2(){y=1e9;x=-1e9;d=-1e9;};
    da2(int a, int b) : x(a), y(b){
        d = 0;
    }
    friend ostream& operator << (ostream& os, da2& c) {os << c.d; return os;}
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<da> b(n);
    vector<da2> c(n);
    for (int i = 0; i < n; ++i) {
        b[i] = da(a[i]-i, a[i]-i);
        c[i] = da2(a[i]+i, a[i]+i);
    }
    auto merge = [](da lhs, da rhs) -> da {
        da nda(0, 0);
        nda.d = max({lhs.d, rhs.d, rhs.y - lhs.x});
        nda.x = min(lhs.x, rhs.x);
        nda.y = max(lhs.y, rhs.y);
        return nda;
    };
    auto merge2 = [](da2 lhs, da2 rhs) -> da2 {
        da2 nda(0, 0);
        nda.d = max({lhs.d, rhs.d, lhs.x - rhs.y});
        nda.x = max(lhs.x, rhs.x);
        nda.y = min(lhs.y, rhs.y);
        return nda;
    };
    auto e =[]->da{return da();};
    auto e2 = [] -> da2 { return da2(); };
    cerr << c[0];
    SegmentTree<da, merge, e> seg_tree(b);
    SegmentTree<da2, merge2, e2> seg_tree2(c);
    debug(seg_tree.query(0, n - 1).d);
    debug(seg_tree2.query(0, 1).d);
    auto qu = [&]() ->int {return max(seg_tree2.query(0,n-1).d, seg_tree.query(0,n-1).d);};
    cout << qu() << endl;
    while(q--) {
        int p,x;
        cin >> p >> x;
        --p;
        a[p] = x;
        debug(p, x);
        seg_tree.update(p, da(x-p,x-p));
        seg_tree2.update(p, da2(x + p, x + p));
        cout << qu() << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) solve();
}