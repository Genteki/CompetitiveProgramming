#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

// using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;

#ifndef LAZY_SEGTREE_H
#define LAZY_SEGTREE_H

#include <functional>
#include <type_traits>
#include <vector>

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
    explicit LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n, e())) {}
    explicit LazySegmentTree(const std::vector<T>& a) : _n(int(a.size())) {
        t = std::vector<T>(_n * 4, e());
        lazy = std::vector<F>(_n * 4, id());
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
        if (lazy[v] != id()) {
            t[(v << 1)] = mapping(lazy[v], t[(v << 1)]);
            lazy[(v << 1)] = composition(lazy[v], lazy[(v << 1)]);
            t[(v << 1) | 1] = mapping(lazy[v], t[(v << 1) | 1]);
            lazy[(v << 1) | 1] = composition(lazy[v], lazy[(v << 1) | 1]);
            lazy[v] = id();
        }
    }

    void update(int v, int tl, int tr, int l, int r, F delta) {
        if (l > r) return;
        if (l == tl && tr == r) {
            t[v] = mapping(delta, t[v]);
            lazy[v] = composition(delta, lazy[v]);
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

    void update(int l, int r, F delta) { update(1, 0, _n - 1, l, r, delta); }

   private:
    int _n, log;
    std::vector<T> t;
    std::vector<F> lazy;
};

#endif
void solve() {
    int n , q;
    std::cin >> n >> q;
    std::vector<i64> a(n);
    input(a);
    auto op = [](const i64& a, const i64& b) -> i64 {return a + b;};
    auto e = []() -> i64 {return 0;};
    auto mapping = [](const i64 & a, const i64 & b) -> i64 {return a + b; };
    LazySegmentTree<i64, op, e, i64, op, op, e> lst(a);
    while(q--) {
        int p;
        std::cin >> p;
        if (p == 1) {
            int l, r;
            i64 d;
            std::cin >> l >> r >> d;
            --l; --r;
            lst.update(l, r, d);
            debug(lst.t);
        } else {
            int pos;
            std::cin >> pos;
            --pos;
            std::cout << lst.query(0, pos) << std::endl;
        }
    }

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    for (; test_cases--;) {
        solve();
    }
}