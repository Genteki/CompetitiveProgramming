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


auto op = [](const int&a, const int& b) -> int {
    return __gcd(a, b);
};

auto e = []() -> int {return 0;};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& ai : a) cin >> ai;

    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = abs(a[i + 1] - a[i]);
    }
    if (d.size() == 0) {
        while(q--) {
            int l, r;
            cin >> l >> r;
            cout << 0 << endl;
        }
        return;
    }
    SegmentTree<int, op, e> segtree(d);

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cerr <<l << r << endl;
        if (l == r) {
            cout << "0 ";
        } else {
            int ans = segtree.query(l, r - 1);
            cout << ans << " ";
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
    return 0;
}