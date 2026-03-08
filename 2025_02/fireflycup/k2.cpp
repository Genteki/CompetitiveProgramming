// k2.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
struct Info {
    int color;
    int t;
    explicit Info(int x) {
        color = x;
        t = -1;
    }
    Info(int x, int y) : color(x), t(y) {}
    friend bool operator!=(const Info& lhs, const Info& rhs) {
        return lhs.t != rhs.t;
    }
};
Info op(const Info& lhs, const Info& rhs) {
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
            t[(v << 1)] = op(lazy[v], t[(v << 1)]);
            lazy[(v << 1)] = op(lazy[v], lazy[(v << 1)]);
            t[(v << 1) | 1] = op(lazy[v], t[(v << 1) | 1]);
            lazy[(v << 1) | 1] = op(lazy[v], lazy[(v << 1) | 1]);
            lazy[v] = e();
        }
    }

    void update(int v, int tl, int tr, int l, int r, F delta) {
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

    void update(int l, int r, F delta) { update(1, 0, _n - 1, l, r, delta); }

   private:
    int _n, log;
    std::vector<T> t;
    std::vector<F> lazy;
};
void solve() {
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