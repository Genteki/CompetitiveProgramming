// cf527.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <vector>
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

#endif
bool chmax(int& a, int b){ return b > a ? a = b, true : false; }
struct Info {
    bool rcut {false};
    bool lcut {false};
    bool mcut {false};
    int left{1};
    int right{1};
    int mid{1};
    Info() {};
    Info(int x) :left(x), right(x), mid(x) {}
    Info(const Info& other) = default;
    friend ostream& operator<<(ostream& os, const Info& info) {
        return os << "[" << info.left << ", " << info.right << ", " << info.mid
                  << "] ";
    }
};

Info op(const Info& L, const Info& R) {
    Info ret;
    ret.right = R.right;
    ret.left = L.left;
    ret.mid = max(L.mid, R.mid);
    ret.rcut = R.rcut;
    ret.lcut = L.lcut;
    ret.mcut = L.mcut | R.mcut | L.rcut | R.lcut;
    if (!L.rcut) {
        chmax(ret.mid, L.right + R.left);
    }
    if (!L.rcut and !R.rcut and !R.mcut) {
        chmax(ret.right, R.right + L.right);
    }
    if (!L.lcut and !L.rcut and !L.mcut) {
        chmax(ret.left, L.left + R.left);
    }
    if (L.lcut) ret.left = 0;
    if (R.rcut) ret.right = 0;
    chmax(ret.mid, ret.left);
    chmax(ret.mid, ret.right);
    return ret;
}

Info e() {return Info(0);}

void solve() {
    int m, n, q;
    cin >> m >> n >> q;
    SegmentTree<Info, op, e> stv(m), sth(n);
    while(q--) {
        char x;
        cin >> x;
        int j;
        cin >> j;
        if (x=='H') {
            if (j < n) {
                Info i{sth.query(j, j)};
                i.lcut = true;
                sth.update(j,i);
            }
            if (j > 0) {
                Info i {sth.query(j-1, j-1)};
                i.rcut = true;
                sth.update(j-1, i);
            }
        } else {
            if (j < m) {
                Info i{stv.query(j, j)};
                i.lcut = true;
                stv.update(j, i);
            }
            if (j > 0) {
                Info i{stv.query(j - 1, j - 1)};
                i.rcut = true;
                stv.update(j - 1, i);
            }
        }
        i64 hmax = sth.query(0, n - 1).mid;
        i64 vmax = stv.query(0, m - 1).mid;
        cout << (hmax * vmax) << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}