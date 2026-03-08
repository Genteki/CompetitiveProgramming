// g.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) b[i] = distance(a.begin(), 
        upper_bound(a.begin(), a.end(), a[i]/2)) - i;
    for (int i = 0; i < n; ++i) c[i] = distance(a.begin(), 
        lower_bound(a.begin(), a.end(), 2 * a[i]));
    auto op = [](const int &lhs, const int &rhs) -> int {return min(lhs, rhs);};
    auto e = []() -> int {return 1e8;};
    SegmentTree<int, op, e> segtree(b);
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l;
        int ql = c[l];
        if (ql > r) {
            cout << 0 << endl;
            continue;
        }
        ql = max(ql, r-(r-l)/2);
        int x = segtree.query(ql, r-1);

        cout << max(0, min(r-ql, x + r - l - 1 )) << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}