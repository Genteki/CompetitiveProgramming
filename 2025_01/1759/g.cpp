// g.cpp
#include <bits/stdc++.h>

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
int op(const int& a, const int & b) {return max(a,b); }
int e() {return -1;}
void solve() {
    int n;
    cin >> n;
    vector<int> b(n/2), a(n);
    for (auto &bi : b) {cin >> bi; --bi; }
    vector<int> ord(n, e());
    for (int i = 0; i < n/2; ++i) ord[b[i]] = i;
    auto c = b;
    sort(c.begin(), c.end(), std::greater<i64>());
    SegmentTree<int, op, e> segtree(ord);
    int last = n;
    for (int i = 0; i < n/2; ++i) {
        int idx = ord[c[i]];
        a[ord[c[i]]*2+1] = c[i];
        for (int k = last-1; k > c[i]; --k) {
            int p = segtree.query(k, n-1);
            if (p == -1) {
                cout << -1 << endl;
                return;
            } else {
                a[2 * p] = k;
                segtree.update(b[p], -1);
            }
        }
        last = c[i];
    }
    for (int k = last - 1; k >= 0; --k) {
        int p = segtree.query(k, n - 1);
        if (p == -1) {
            cout << -1 << endl;
            return;
        } else {
            a[2 * p] = k;
            segtree.update(b[p], -1);
        }
    }
    for (auto ai : a) cout << (ai+1) << " ";
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