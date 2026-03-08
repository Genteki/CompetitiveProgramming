#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
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
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = op(t[v * 2], t[v * 2 + 1]);
        }
    }

    void push(int v) {
        if (lazy[v] != id()) {
            t[v * 2] = mapping(lazy[v], t[v * 2]);
            lazy[v * 2] = composition(lazy[v], lazy[v * 2]);
            t[v * 2 + 1] = mapping(lazy[v], t[v * 2 + 1]);
            lazy[v * 2 + 1] = composition(lazy[v], lazy[v * 2 + 1]);
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
            update(v * 2, tl, tm, l, std::min(r, tm), delta);
            update(v * 2 + 1, tm + 1, tr, std::max(tm + 1, l), r, delta);
            t[v] = op(t[v * 2], t[v * 2 + 1]);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return e();
        if (l == tl && r == tr) return t[v];
        push(v);
        int tm = (tl + tr) / 2;
        return op(query(v * 2, tl, tm, l, std::min(r, tm)),
                  query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    T query(int l, int r) { return query(1, 0, _n - 1, l, r); }

    void update(int l, int r, F delta) { update(1, 0, _n - 1, l, r, delta); }

   private:
    int _n, log;
    std::vector<T> t;
    std::vector<F> lazy;
};
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> r(n), c(n), l(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i] >> c[i] >> l[i];
        --r[i];
        --c[i];
        --l[i];
    }
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int& lhs, const int& rhs) -> bool {
        return r[lhs] > r[rhs];
    });
    auto op = [](const int& lhs, const int& rhs) -> int {
        return min(lhs, rhs);
    };
    constexpr auto e = []() -> int { return 1e9; };
    vector<int> ans(n);

    LazySegmentTree<int, op, e, int, op, op, e> segtree(w);
    for (int i : ord) {
        int x = segtree.query(c[i], c[i] + l[i]);
        ans[i] = min(h - 1, x - 1);
        segtree.update(1, 0, w - 1, c[i], c[i] + l[i], min(h - 1, x - 1));
        debug(i, ans[i]);
    }
    for (auto ai : ans) cout << (ai + 1) << endl;
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