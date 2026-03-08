#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
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
struct DSU {
    std::vector<int> root, rank;
    int find_root(int node) {
        return root[node] == node ? node : (root[node] = find_root(root[node]));
    }
    void make_union(int node) {
        root[node] = node;
        rank[node] = 1;
    }
    void init() {
        for (int i = 0; i < root.size(); ++i) make_union(i);
    }
    void unite(int a, int b) {
        a = find_root(a);
        b = find_root(b);
        if (a == b) return;
        if (b < a) std::swap(a, b);
        root[b] = a;
        rank[a] += rank[b];
    }
    DSU(int n) {
        root.assign(n, 0);
        rank.assign(n, 0);
        init();
    }
    DSU(const DSU& other) {
        root = other.root;
        rank = other.rank;
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (auto &pi : p) {
        cin >> pi;
        --pi;
    }
    string s;
    cin >> s;
    s = " " + s;  // 1-based indexing
    auto f = []() -> int { return -1; };
    auto mx = [](int a, int b) -> i64 { return max(a, b); };
    auto mi = [](int a, int b) -> i64 { return min(a, b); };
    SegmentTree<int, mx, f> st_max(p);
    SegmentTree<int, mi, f> st_min(p);
    DSU dsu(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            dsu.unite(i, i - 1);
        } else {
            dsu.unite(i, i + 1);
        }
    }
    set<int> start;
    start.insert(n);
    for (auto di : dsu.root) start.insert(di);
    auto check = [&](int from, int to) -> bool{
        int ma = st_max.query(from, to-1);
        int mi = st_min.query(from, to-1);
        if (ma < to && mi >= from) return true;
        else return false;
    };
    int good = 0;
    for (auto it = start.begin(); next(it) != start.end(); ++it) {
        int from = *it;
        int to = *next(it);
        good += check(from, to);
    }
    debug(vector<int>(all(start)));
    debug(good);
    if (good == start.size()) cout << "YES\n";
    else cout << "NO\n";
    for (; q--;) {
        int pos;
        cin >> pos;
        --pos;
        if (s[pos]=='L') {
            if (s[pos - 1] != 'R') {
                start.insert(pos);
            }
        } else {
            if ()
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}