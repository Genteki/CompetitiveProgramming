// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first < b.first)
            return true;
        else if (a.first == b.first && a.second < b.second)
            return true;
        else
            return false;
    }
};

int e() { return 1e9; }

template <class S, auto op, auto e> struct SegmentTree{
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
        if (tl == tr) t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2+1, tm + 1, tr);
            t[v] = op(t[v*2], t[v*2+1]);
        }
    }

    S __query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return e();
        if (ql == tl && qr == tr) return t[v];
        int tm = (tl + tr) / 2;
        S rl = __query(v * 2, tl, tm, ql, min(tm, qr));
        S rr = __query(v * 2 + 1, tm + 1, tr, max(ql, tm+1), qr);
        return op(rl, rr);
    }

    void __update(int v, int tl, int tr, int pos, S val) {
        if (tl == tr) t[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) __update(v * 2, tl, tm, pos, val);
            else __update(v * 2 + 1, tm + 1, tr, pos, val);
            t[v] = op(t[v*2], t[v*2 + 1]);
        }
    }

    S query(int ql, int qr) { return __query(1, 0, _n - 1, ql, qr); }

    void update(int pos, S val) {__update(1, 0, _n - 1, pos, val);}
};
void solve() {
    int n, m;
    cin >> m >> n;
    i64 ans = 0;
    vector<pair<int,int>> interval(m);
    for (auto& [f, s] : interval) {
        cin >> f >> s;
    }
    sort(all(interval), comp());
    vector<int> p(m), q(m);
    for (int i = 0; auto [f, s] : interval) {
        p[i] = s;
        ++i;
    }
    auto min_op = [](int a, int b) -> int {return min(a, b);};
    SegmentTree<int, min_op, e> segtree(p);
    for (int l = 1; l <= n; ++l) {
        auto x = make_pair(l, 0);
        auto it = lower_bound(all(interval), x, comp());
        int i = it - interval.begin();
        int r = segtree.query(i, m-1);
        ans = ans + (min(r-1, n) - (l - 1));
    }
    cout << ans;
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