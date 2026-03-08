// {[ddp]} {[dp_optimization]}
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const i64 MOD = 998244353;
i64 A0[9]{2, 0, 1, 0, 2, 1, 0, 0, 1};
i64 B0[3]{1, 1, 0};
i64 A1[9]{2, 1, 0, 0, 1, 0, 0, 1, 2};
i64 B1[3]{1, 0, 1};
struct Info {
    i64 A[9]{0}, B[3]{0};
    Info() {
        for (int i = 0; i < 3; i++) {
            A[i * 3 + i] = 1;
        }
    }
    Info(const i64 pa[], const i64 pb[]) {
        memcpy(A, pa, sizeof(i64) * 9);
        memcpy(B, pb, sizeof(i64) * 3);
    }
};

template <class T>
void matrix_multiply(const T A[], const T B[], T C[], const int& m,
                     const int& n, const int& q, const T& mod = MOD) {
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
void matrix_add(const T A[], const T B[], T C[], int m, int n,
                T mod = MOD) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i * n + j] = A[i * n + j] + B[i * n + j];
            if (mod) C[i * n + j] %= mod;
        }
    }
}
template <class T>
void matrix_add(T A[], const T B[], int m, int n,
                T mod = MOD) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i * n + j] += B[i * n + j];
            if (mod) A[i * n + j] %= mod;
        }
    }
}

Info e() { return Info(); }

Info op(const Info& L, const Info& R) {
    Info ret;
    matrix_multiply<i64>(L.A, R.A, ret.A, 3, 3, 3);
    matrix_multiply<i64>(L.A, R.B, ret.B, 3, 3, 1);
    matrix_add<i64>(ret.B, L.B, 3, 1);
    return ret;
}

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

using ST = SegmentTree<Info, op, e>;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }

    Info F0(A0, B0), F1(A1, B1);
    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        init[i] = (a[i] == 0 ? F0 : F1);
    }
    ST seg(init);

    int q;
    cin >> q;
    while (q--) {
        int qi;
        cin >> qi;
        qi--;
        a[qi] = 1 - a[qi];
        Info upd = (a[qi] == 0 ? F0 : F1);
        seg.update(qi, upd);
        Info ans = seg.query(0, n - 1);
        cout << ans.B[0] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}