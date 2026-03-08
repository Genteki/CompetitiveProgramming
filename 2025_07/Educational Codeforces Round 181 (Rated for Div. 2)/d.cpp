
#include <bits/stdc++.h>

#ifndef MODINT_H
#define MODINT_H
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

template <class T>
constexpr T power(T a, u64 b, T res = 1) {
    for (; b != 0; b /= 2, a *= a) {
        if (b & 1) {
            res *= a;
        }
    }
    return res;
}

template <u32 P>
constexpr u32 mulMod(u32 a, u32 b) {
    return u64(a) * b % P;
}

template <u64 P>
constexpr u64 mulMod(u64 a, u64 b) {
    u64 res = a * b - u64(1.L * a * b / P - 0.5L) * P;
    res %= P;
    return res;
}

constexpr i64 safeMod(i64 x, i64 m) {
    x %= m;
    if (x < 0) {
        x += m;
    }
    return x;
}

constexpr std::pair<i64, i64> invGcd(i64 a, i64 b) {
    a = safeMod(a, b);
    if (a == 0) {
        return {b, 0};
    }

    i64 s = b, t = a;
    i64 m0 = 0, m1 = 1;

    while (t) {
        i64 u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        std::swap(s, t);
        std::swap(m0, m1);
    }

    if (m0 < 0) {
        m0 += b / s;
    }

    return {s, m0};
}

template <std::unsigned_integral U, U P>
struct ModIntBase {
   public:
    constexpr ModIntBase() : x(0) {}
    template <std::unsigned_integral T>
    constexpr ModIntBase(T x_) : x(x_ % mod()) {}
    template <std::signed_integral T>
    constexpr ModIntBase(T x_) {
        using S = std::make_signed_t<U>;
        S v = x_ % S(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }

    constexpr static U mod() { return P; }

    constexpr U val() const { return x; }

    constexpr ModIntBase operator-() const {
        ModIntBase res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }

    constexpr ModIntBase inv() const { return power(*this, mod() - 2); }

    constexpr ModIntBase &operator*=(const ModIntBase &rhs) & {
        x = mulMod<mod()>(x, rhs.val());
        return *this;
    }
    constexpr ModIntBase &operator+=(const ModIntBase &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr ModIntBase &operator-=(const ModIntBase &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr ModIntBase &operator/=(const ModIntBase &rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr ModIntBase operator*(ModIntBase lhs,
                                          const ModIntBase &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator+(ModIntBase lhs,
                                          const ModIntBase &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator-(ModIntBase lhs,
                                          const ModIntBase &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr ModIntBase operator/(ModIntBase lhs,
                                          const ModIntBase &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::istream &operator>>(std::istream &is, ModIntBase &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os,
                                              const ModIntBase &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(const ModIntBase &lhs,
                                     const ModIntBase &rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr std::strong_ordering operator<=>(const ModIntBase &lhs,
                                                      const ModIntBase &rhs) {
        return lhs.val() <=> rhs.val();
    }

   private:
    U x;
};

template <u32 P>
using ModInt = ModIntBase<u32, P>;
template <u64 P>
using ModInt64 = ModIntBase<u64, P>;

struct Barrett {
   public:
    Barrett(u32 m_) : m(m_), im((u64)(-1) / m_ + 1) {}

    constexpr u32 mod() const { return m; }

    constexpr u32 mul(u32 a, u32 b) const {
        u64 z = a;
        z *= b;

        u64 x = u64((u128(z) * im) >> 64);

        u32 v = u32(z - x * m);
        if (m <= v) {
            v += m;
        }
        return v;
    }

   private:
    u32 m;
    u64 im;
};

template <u32 Id>
struct DynModInt {
   public:
    constexpr DynModInt() : x(0) {}
    template <std::unsigned_integral T>
    constexpr DynModInt(T x_) : x(x_ % mod()) {}
    template <std::signed_integral T>
    constexpr DynModInt(T x_) {
        int v = x_ % int(mod());
        if (v < 0) {
            v += mod();
        }
        x = v;
    }

    constexpr static void setMod(u32 m) { bt = m; }

    static u32 mod() { return bt.mod(); }

    constexpr u32 val() const { return x; }

    constexpr DynModInt operator-() const {
        DynModInt res;
        res.x = (x == 0 ? 0 : mod() - x);
        return res;
    }

    constexpr DynModInt inv() const {
        auto v = invGcd(x, mod());
        assert(v.first == 1);
        return v.second;
    }

    constexpr DynModInt &operator*=(const DynModInt &rhs) & {
        x = bt.mul(x, rhs.val());
        return *this;
    }
    constexpr DynModInt &operator+=(const DynModInt &rhs) & {
        x += rhs.val();
        if (x >= mod()) {
            x -= mod();
        }
        return *this;
    }
    constexpr DynModInt &operator-=(const DynModInt &rhs) & {
        x -= rhs.val();
        if (x >= mod()) {
            x += mod();
        }
        return *this;
    }
    constexpr DynModInt &operator/=(const DynModInt &rhs) & {
        return *this *= rhs.inv();
    }

    friend constexpr DynModInt operator*(DynModInt lhs, const DynModInt &rhs) {
        lhs *= rhs;
        return lhs;
    }
    friend constexpr DynModInt operator+(DynModInt lhs, const DynModInt &rhs) {
        lhs += rhs;
        return lhs;
    }
    friend constexpr DynModInt operator-(DynModInt lhs, const DynModInt &rhs) {
        lhs -= rhs;
        return lhs;
    }
    friend constexpr DynModInt operator/(DynModInt lhs, const DynModInt &rhs) {
        lhs /= rhs;
        return lhs;
    }

    friend constexpr std::istream &operator>>(std::istream &is, DynModInt &a) {
        i64 i;
        is >> i;
        a = i;
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os,
                                              const DynModInt &a) {
        return os << a.val();
    }

    friend constexpr bool operator==(const DynModInt &lhs,
                                     const DynModInt &rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr std::strong_ordering operator<=>(const DynModInt &lhs,
                                                      const DynModInt &rhs) {
        return lhs.val() <=> rhs.val();
    }

   private:
    u32 x;
    static Barrett bt;
};

const int MOD = 998244353;
template <u32 Id>
Barrett DynModInt<Id>::bt = MOD;
using mint = ModInt<MOD>;

#endif
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
    explicit LazySegmentTree(const std::vector<T> &a) : _n(int(a.size())) {
        t = std::vector<T>(_n * 4, e());
        lazy = std::vector<F>(_n * 4, id());
        build(a, 1, 0, _n - 1);
    }

    void build(const std::vector<T> &a, int v, int tl, int tr) {
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
using namespace std;

typedef long long i64;

struct Data {
    mint p0, p1;
    Data () : p0(1), p1(0) {}
    Data(mint p, mint q) {
        p0 = 1 - p / q;
        p1 = p / q;
    }
    bool operator != (const Data& other) {return p0!=other.p0 or p1 != other.p1;}
};

Data op(Data l, Data r) {
    Data ret;
    ret.p0 = l.p0 * r.p0;
    ret.p1 = l.p1 * r.p0 + l.p0 * r.p1;
    return ret;
}

Data e () {return Data();}

typedef LazySegmentTree<Data, op, e, Data, op, op, e> LZT;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    i64 n,m ;
    cin >> n >> m;
    vector<mint> dp(m+1, 0);
    dp[0] = 1;
    vector<vector<pair<int, mint>>> p(m+1);
    vector<mint> p_start(m+1, 1);
    for (int i : std::views::iota(0, n)) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        p[r].emplace_back(l, mint(x)/mint(y));
        p_start[l] = p_start[l] * (y-x) / y;
    }
    for (auto i : std::views::iota(1, m+1)) p_start[i] = p_start[i-1] * p_start[i];
    debug(p_start[3].val(), (1 - mint(8) / 9).val());

    for (auto r : std::views::iota(1, m+1)) {
        mint z = 0;
        for (auto [l, pi] : p[r]) {
            // last state p[l-1]
            // all p from l to r except pi, p_start[r] / p_start[l-1] / pi
            z = z + dp[l-1] * p_start[r] / p_start[l-1] / (1-pi) * pi;
        }
        dp[r] = z;
    }
    cout << dp[m] << endl;;
    return;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}