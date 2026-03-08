// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
constexpr long long mod = 998244353;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
template <class S, auto op, auto e>
struct SegmentTree {
    i64 _n;
    std::vector<S> a, t;
    SegmentTree(vector<S>& arr) {
        _n = arr.size();
        a = arr;
        t = std::vector<S>(_n * 4, e());
        build(1, 0, _n - 1);
    }

    SegmentTree(i64 n) {
        _n = n;
        a = std::vector<S>(n);
        t = std::vector<S>(_n * 4, e());
        build(1, 0, _n - 1);
    }

    void build(i64 v, i64 tl, i64 tr) {
        if (tl == tr)
            t[v] = a[tl];
        else {
            i64 tm = (tl + tr) / 2;
            build((v << 1), tl, tm);
            build((v << 1) | 1, tm + 1, tr);
            t[v] = op(t[(v << 1)], t[(v << 1) | 1]);
        }
    }

    S __query(i64 v, i64 tl, i64 tr, i64 ql, i64 qr) {
        if (ql > qr) return e();
        if (ql == tl && qr == tr) return t[v];
        i64 tm = (tl + tr) / 2;
        S rl = __query((v << 1), tl, tm, ql, min(tm, qr));
        S rr = __query((v << 1) | 1, tm + 1, tr, max(ql, tm + 1), qr);
        return op(rl, rr);
    }

    void __update(i64 v, i64 tl, i64 tr, i64 pos, S val) {
        if (tl == tr)
            t[v] = val;
        else {
            i64 tm = (tl + tr) / 2;
            if (pos <= tm)
                __update((v << 1), tl, tm, pos, val);
            else
                __update((v << 1) | 1, tm + 1, tr, pos, val);
            t[v] = op(t[(v << 1)], t[(v << 1) | 1]);
        }
    }

    S query(i64 ql, i64 qr) { return __query(1, 0, _n - 1, ql, qr); }

    void update(i64 pos, S val) { __update(1, 0, _n - 1, pos, val); }
};
void solve() {
    i64 n,q;
    cin >> n >> q;
    vector<i64> a(n), b(n);
    for (auto& ai : a) cin >> ai;
    for (auto& ai : b) cin >> ai;
    auto op = [](i64 &lhs, i64 &rhs) -> i64 {
        return (lhs * rhs) % mod;
    };
    auto e = []() -> i64 {return 1LL;};
    vector<i64> sa = a, sb = b;
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    vector<i64> sc = sa;
    for (i64 i = 0; i < n; ++i) sc[i] = min(sa[i], sb[i]);
    int x = 1;
    for (auto ai : sc) {x = ( x * ai) %mod;}
    SegmentTree<i64, op, e> segtree(sc);
    cout << segtree.query(0, n - 1) << " ";
    while(q--) {
        i64 o, x;
        cin >> o >> x;
        --x;

        if (o == 1) {
            auto it = upper_bound(sa.begin(), sa.end(), a[x]);
            a[x]++;
            i64 idx = it - sa.begin() - 1;
            sa[idx]++;
            debug(sa);
            debug(idx, min(sa[idx], sb[idx]));
            segtree.update(idx, min(sa[idx], sb[idx]));
        } else {
            auto it = upper_bound(sb.begin(), sb.end(), b[x]);
            b[x]++;
            i64 idx = it - sb.begin() - 1;
            sb[idx]++;
            debug(sb);
            debug(idx,x);
            segtree.update(idx, min(sa[idx], sb[idx]));
        }
        cout << segtree.query(0,n-1)<< " ";
    }
    cout << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}