// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
using namespace std;
typedef long long i64;

const i64 N = 2e5 + 5;
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
    S total() {return t[1]; }
};

i64 op(i64 a, i64 b) {return a+b;}
i64 e() {return 0;}

void solve() {
    i64 n;
    cin >> n;
    vector<i64> x(n), y(n);
    for (i64 i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    auto xs = x, ys = y;
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    for (int i = 0; i < n; ++i) {
        x[i] = (lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin());
        y[i] = (lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin());
    }
    vector<i64> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](i64 i, i64 j) {
        return x[i] < x[j];
    });
    i64 nx = xs.size(), ny = ys.size();

    SegmentTree<i64, op, e> fl(ny), fr(ny);
    for (i64 i = 0; i < n; i++) {
        i64 val = fr.query(y[i], y[i]);
        fr.update(y[i], val + 1);
    }
    i64 ans = 0, ax = 0, ay = 0;
    for (int i = 0, j = 0; i <= nx; ++i) {
        i64 low = -1, high = ny;
        while (high - low > 1) {
            i64 mid = (low + high) / 2;
            i64 sl = fl.query(0, mid-1);
            i64 sr = fr.query(0, mid-1);
            i64 s0 = min(sl, sr);
            i64 sn = min(fl.total() - sl, fr.total() - sr);
            if (s0 <= sn) {
                low = mid;
            } else {
                high = mid;
            }
            if (min(s0, sn) > ans) {
                ax = i;
                ay = mid;
                ans = min(s0, sn);
            }
        }
        while (j < n && i < nx && x[p[j]] == i) {
            i64 yj = y[p[j]];
            i64 val = fl.query(yj, yj);
            fl.update(yj, val + 1);
            val = fr.query(yj, yj);
            fr.update(yj, val - 1);
            j++;
        }
    }
    cout << ans << endl;
    cout << (xs[ax]) << " " << (ys[ay]) << endl;
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