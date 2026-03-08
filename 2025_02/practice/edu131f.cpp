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
        if (tl == tr) {
            t[v] = a[tl];
        } else {
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
        if (tl == tr) {
            t[v] = val;
        } else {
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
const i64 MOD = 0;
template <class T>
void matrix_multiply(const T A[], const T B[], T C[], const int& m,
                     const int& n, const int& q, const T& mod = MOD) {
    // C_mq = A_mn x B_nq
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < q; ++j) {
            T s = 0;
            for (int k = 0; k < n; ++k) {
                s += A[i * n + k] * B[k * q + j];
            }
            if (mod) s %= mod;
            C[i * q + j] = s;
        }
    }
}

template <class T>
void matrix_add(const T A[], const T B[], T C[], int m, int n, T mod = MOD) {
    // C = A + B
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i * n + j] = A[i * n + j] + B[i * n + j];
            if (mod) C[i * n + j] %= mod;
        }
    }
}
template <class T>
void matrix_add(T A[], const T B[], int m, int n, T mod = MOD) {
    // A += B
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i * n + j] += B[i * n + j];
            if (mod) A[i * n + j] %= mod;
        }
    }
}

const i64 A0[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
const i64 B0[3] = {0, 0, 0};

struct Info {
    i64 A[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
    i64 B[3]{0, 0, 0};

    Info() {};
    Info& operator=(const Info& other) {
        memcpy(A, other.A, 9 * sizeof(i64));
        memcpy(B, other.B, 3 * sizeof(i64));
        return *this;
    }
    Info(const Info& other) {
        memcpy(A, other.A, 9 * sizeof(i64));
        memcpy(B, other.B, 3 * sizeof(i64));
    };

    void adj(int delta = 0) {
        if (delta == 0) {
            A[3] = 0;
            B[0] = 0;
            B[1] = 0;
        } else if (delta == 1) {
            A[3] = 2;
            B[0] = 1;
            B[1] = 1;
        } else {
            A[3] = -2;
            B[0] = -1;
            B[1] = 1;
        }
    }
};

Info op(const Info& L, const Info& R) {
    Info ret;
    matrix_multiply(R.A, L.A, ret.A, 3, 3, 3);
    matrix_multiply(R.A, L.B, ret.B, 3, 3, 1);
    matrix_add(ret.B, R.B, 3, 1);
    return ret;
}

Info e() { return Info(); }

using LinearTree = SegmentTree<Info, op, e>;
const int N = 2e5;
void solve() {
    int q, d;
    cin >> q >> d;
    vector<Info> init(N + 1);
    LinearTree lt(init);
    vector<int> exist(N + 1, 0);
    for (; q--;) {
        int x;
        cin >> x;
        --x;
        if (!exist[x]) {
            exist[x] = 1;
            Info ni = lt.query(x, x);
            ni.A[6] = -1;
            ni.A[7] = 1;
            if (x >= d)
                ni.adj(-exist[x - d] + exist[x]);
            else
                ni.adj(exist[x]);
            lt.update(x, ni);
        } else {
            exist[x] = 0;
            Info ni = lt.query(x, x);
            ni.A[6] = 0;
            ni.A[7] = 0;
            if (x >= d)
                ni.adj(-exist[x - d] + exist[x]);
            else
                ni.adj(exist[x]);
            lt.update(x, ni);
        }
        if (x + d <= N) {
            Info ni = lt.query(x + d, x + d);
            ni.adj(-exist[x] + exist[x + d]);

            lt.update(x + d, ni);
        }

        Info ans = lt.query(0, N);
        for (int i = 0; i < 9; ++i) {
            auto tmp = lt.query(i, i);
        }
        cout << ans.B[2] / 2 << endl;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}