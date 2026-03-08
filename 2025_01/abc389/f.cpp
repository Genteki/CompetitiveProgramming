// f.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
i64 op(const i64& a, const i64& b) {
    return a + b;
}
i64 e () {
    return 0;
}
const i64 N = 5e5 + 5;

template <class T, auto op, auto e, class F, auto mapping, auto composition,
          auto id>
struct LazySegmentTree {
    static_assert(std::is_convertible_v<decltype(op), std::function<T(T, T)>>,
                  "op must work as T(T, T)");
    static_assert(std::is_convertible_v<decltype(e), std::function<T()>>,
                  "e must work as T()");
    static_assert(
        std::is_convertible_v<decltype(mapping), std::function<T(F, T)>>,
        "mapping must work as T(F, T)");
    static_assert(
        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,
        "compostiion must work as F(F, F)");
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>,
                  "id must work as F()");

   public:
    LazySegmentTree() : LazySegmentTree(0) {}
    explicit LazySegmentTree(i64 n) : LazySegmentTree(std::vector<T>(n, e())) {}
    explicit LazySegmentTree(const std::vector<T>& a) : _n(i64(a.size())) {
        t = std::vector<T>(_n * 4, e());
        lazy = std::vector<F>(_n * 4, id());
        build(a, 1, 0, _n - 1);
    }

    void build(const std::vector<T>& a, i64 v, i64 tl, i64 tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            i64 tm = (tl + tr) / 2;
            build(a, (v << 1), tl, tm);
            build(a, (v << 1) | 1, tm + 1, tr);
            t[v] = op(t[(v << 1)], t[(v << 1) | 1]);
        }
    }

    void push(i64 v) {
        if (lazy[v] != id()) {
            t[(v << 1)] = mapping(lazy[v], t[(v << 1)]);
            lazy[(v << 1)] = composition(lazy[v], lazy[(v << 1)]);
            t[(v << 1) | 1] = mapping(lazy[v], t[(v << 1) | 1]);
            lazy[(v << 1) | 1] = composition(lazy[v], lazy[(v << 1) | 1]);
            lazy[v] = id();
        }
    }

    void update(i64 v, i64 tl, i64 tr, i64 l, i64 r, F delta) {
        if (l > r) return;
        if (l == tl && tr == r) {
            t[v] = mapping(delta, t[v]);
            lazy[v] = composition(delta, lazy[v]);
        } else {
            push(v);
            i64 tm = (tl + tr) / 2;
            update((v << 1), tl, tm, l, std::min(r, tm), delta);
            update((v << 1) | 1, tm + 1, tr, std::max(tm + 1, l), r, delta);
            t[v] = op(t[(v << 1)], t[(v << 1) | 1]);
        }
    }

    T query(i64 v, i64 tl, i64 tr, i64 l, i64 r) {
        if (l > r) return e();
        if (l == tl && r == tr) return t[v];
        push(v);
        i64 tm = (tl + tr) / 2;
        return op(query((v << 1), tl, tm, l, std::min(r, tm)),
                  query((v << 1) | 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    T query(i64 l, i64 r) { return query(1, 0, _n - 1, l, r); }

    void update(i64 l, i64 r, F delta) { update(1, 0, _n - 1, l, r, delta); }

   private:
    i64 _n, log;
    std::vector<T> t;
    std::vector<F> lazy;
};

void solve() {
    i64 n;
    cin >> n;
    vector<i64> l(n), r(n);
    for (i64 i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    LazySegmentTree<i64, op, e, i64, op, op, e> segtree(N);
    for (i64 i = 0; i < n; ++i) {
        i64 li, ri;
        i64 low = 0, high = l[i];
        while(high - low > 1) {
            i64 mid = (high + low) / 2;
            if (segtree.query(mid, mid) + mid >= l[i]) {
                high = mid;
            } else {
                low = mid;
            }
        }
        li = high;
        low = 0, high = r[i]+1;
        while(high - low > 1) {
            i64 mid = (high + low) / 2;
            if (segtree.query(mid, mid) + mid > r[i]) {
                high = mid;
            } else {
                low = mid;
            }
        }
        ri = low;
        debug(i, li, ri);
        if(ri >= li) segtree.update(li, ri, 1);
    }
    i64 q;
    cin >> q;
    while(q--) {
        i64 x ;
        cin >> x;
        cout << (x + segtree.query(x,x)) << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    for (; test_cases--;) {
        solve();
    }
}