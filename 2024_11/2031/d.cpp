// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

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
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            t[v] = op(t[v * 2], t[v * 2 + 1]);
        }
    }

    S __query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return e();
        if (ql == tl && qr == tr) return t[v];
        int tm = (tl + tr) / 2;
        S rl = __query(v * 2, tl, tm, ql, min(tm, qr));
        S rr = __query(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr);
        return op(rl, rr);
    }

    void __update(int v, int tl, int tr, int pos, S val) {
        if (tl == tr)
            t[v] = val;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                __update(v * 2, tl, tm, pos, val);
            else
                __update(v * 2 + 1, tm + 1, tr, pos, val);
            t[v] = op(t[v * 2], t[v * 2 + 1]);
        }
    }

    S query(int ql, int qr) { return __query(1, 0, _n - 1, ql, qr); }

    void update(int pos, S val) { __update(1, 0, _n - 1, pos, val); }
};
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> g(n+1);
    input(a);
    for (int i = 0; i < n; ++i) {
        g[a[i]].push_back(i);
    }
    auto opmax = [](int a, int b) -> int {return max(a, b);};
    auto opmin = [](int a, int b) -> int {return min(a, b);};
    auto emax = []() -> int {return 1e9; };
    auto emin = []() -> int {return -1;};
    SegmentTree<int, opmax, emin> sg_max(a);
    SegmentTree<int, opmin, emax> sg_min(a);
    SegmentTree<int, opmax, emin> sg_ans(n);
    vector<int> ans(n, 0);
    int pt = n;
    int last = 1e9;
    for (int i = n; i >= 1; --i) {
        for (int j : g[i]) {
            if (ans[j]) continue;
            int xmax = sg_max.query(pt, n-1);
            int xmin = sg_min.query(pt, n-1);
            if (xmin >= i) {
                int k = j;
                pt = min(pt, j);
                while (k < n && ans[k] == 0) {
                    ans[k] = i;
                    k++;
                }
            } else {
                int k = j;
                while (k < n && ans[k] == 0) {
                    ans[k] = ans[pt];
                    k++;
                }
                pt = j;
            }
        }
        debug(ans);
    }
    debug(ans);
    for (auto ansi  : ans) cout << ansi << " ";
    cout << endl;
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