// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
const i64 inf = 1e16;
#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>
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

#endif
i64 op(i64 a, i64 b) {return min(a,b);}
i64 e() {return inf;}
typedef SegmentTree<i64, op, e> MinTree;
void solve() {
    i64 n;
    cin >> n;
    map<i64, i64> a;
    i64 c = 2;
    i64 ans = 2e9+1;
    for (i64 i = 0; i < n; ++i) {
        i64 x;
        cin >> x;
        a[x]++;
        if (a[x] == 2 and c > 0) {
            --c;
            a.erase(x);
        }
    }

    if (c == 0) {
        cout << 0 << endl;
    } else if (c == 1) {
        vector<pair<i64,i64>> r(a.begin(), a.end());
        i64 t = inf;
        for (i64 i = 0; i < r.size()-1; ++i) {
            t = min(t, r[i+1].first - r[i].first);
        }
        cout << t << endl;
    } else {
        vector<i64> r, d;
        for (auto [i,j] : a) r.push_back(i);
        for (int i = 0; i < n-1; ++i) {
            d.push_back(r[i+1] - r[i]);
        }
        MinTree mt(d);
        for (i64 i = 0; i < n-1; ++i) {
            i64 s = inf;
            if (i>=2) {
                s = min(s, mt.query(0,i-2));
            } 
            if (i<=n-4) {
                s = min(s, mt.query(i+2, n-2));
            }
            if (s < inf) {
                ans = min(ans, s + d[i]);
            }
        }
        cout << ans << endl;
    }

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