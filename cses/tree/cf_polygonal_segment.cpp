// solution: https://codeforces.com/blog/entry/131716
// problem: https://codeforces.com/contest/1990/problem/F
// Segment Tree
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

template <typename T>
struct functor {
    bool operator()(T a, T b) const { return a > b; }
};

template <typename T, typename Comp>
struct SegTree {
    int n;
    vector<T> a, t;
    Comp comp;
    SegTree(vector<T> &arr) {
        // comp = Comp();
        n = arr.size();
        t.resize(n * 4);
        a = arr;
        build(1, 0, n - 1);
    }
    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = l;
        } else {
            int m = (l + r) / 2;
            build(v * 2, l, m);
            build(v * 2 + 1, m + 1, r);
            t[v] = comp(a[t[v * 2]], a[t[v * 2 + 1]]) ? t[v * 2] : t[v * 2 + 1];
        }
    }

    T query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return -1;  // replace it when comp changes
        if (ql == qr && tl == tr) return t[v];
        int tm = (tl + tr) / 2;
        int vl = query(v * 2, tl, tm, ql, min(tm, qr));
        int vr = query(v * 2 + 1, tm + 1, tr, max(tm + 1, ql), qr);
        if (vl == -1) return qr;
        if (vl == -1) return ql;
        return comp(a[vl], a[vr]) ? vl : vr;
    }

    T query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
    void update(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            a[pos] = val;
            t[v] = tl;
            return;
        }
        int tm = (tl + tr) / 2;
        if (tm >= pos) {
            update(v * 2, tl, tm, pos, val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, val);
        }
        t[v] = comp(a[t[v * 2]], a[t[v * 2 + 1]]) ? t[v * 2] : t[v * 2 + 1];
    }

    void update(int pos, T val) {
        a[pos] = val;
        update(1, 0, n - 1, pos, val);
    }
};

template <typename T>
struct SumTree {
    int n;
    vector<T> a, s;
    void build(int v, int l, int r) {
        if (l == r)
            s[v] = a[l];
        else {
            int m = (l + r) / 2;
            build(v * 2, l, m);
            build(v * 2 + 1, m + 1, r);
            s[v] = s[v * 2] + s[v * 2 + 1];
        }
    }
    SumTree(vector<T> &arr) {
        a = arr;
        n = a.size();
        s.resize(n * 4, 0);
        build(1, 0, n - 1);
    }
    T query(int v, int sl, int sr, int ql, int qr) {
        if (ql > qr) return 0;
        if (sl == sr && ql == qr) return s[v];
        int sm = (sl + sr) / 2;
        T al = query(v * 2, sl, sm, ql, min(qr, sm));
        T ar = query(v * 2 + 1, sm + 1, sr, max(sm + 1, ql), qr);
        return (al + ar);
    }
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int v, int sl, int sr, int pos, T val) {
        if (sl == sr && pos == sl) {
            s[v] = val;
            a[pos] = val;
        } else {
            int sm = (sl + sr) / 2;
            if (pos <= sm)
                update(v * 2, sl, sm, pos, val);
            else
                update(v * 2 + 1, sm + 1, sr, pos, val);
            s[v] = s[v * 2] + s[v * 2 + 1];
        }
    }
    void update(int pos, T val) { update(1, 0, n - 1, pos, val); }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n);
    input(a);
    SegTree<i64, functor<i64>> st(a);
    SumTree<i64> sum_tree(a);
    vector<i64> ps(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        ps[i + 1] = ps[i] + a[i];
    }
    auto f = [&](auto &&self, int l, int r) -> i64 {
        if (r - l + 1 < 3) return -1;
        i64 s = sum_tree.query(l, r);
        i64 imx = st.query(l, r);
        i64 mx = st.a[imx];
        if (mx * 2 < s) {
            return (r - l + 1);
        } else {
            i64 al = self(self, l, imx - 1);
            i64 ar = self(self, imx + 1, r);
            i64 ans = max(al, ar);
            return max(al, ar);
        }
    };
    for (; m--;) {
        int x, y;
        i64 z;
        cin >> x >> y >> z;
        --y;
        --z;
        if (x == 1) {
            i64 ans = f(f, y, z);
            cout << ans << endl;
        } else {
            st.update(y, z + 1);
            sum_tree.update(y, z + 1);
        }
    }

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}