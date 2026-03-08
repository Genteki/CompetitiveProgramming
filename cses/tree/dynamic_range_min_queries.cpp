/**
 * Dynamic Range Minimum Queries
 * https://www.cses.fi/problemset/task/1649
 * Segment Tree, RMQ
 */
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

struct SegmentTree{
    int n;
    vector<int> a, t;
    SegmentTree(vector<int>& arr) {
        a = arr;
        n = arr.size();
        t.resize(n * 4);
        build(1, 0, n-1);
    }

    void build(int v, int l, int r) {
        if (l == r) {
            t[v] = a[l];
        } else {
            int m = (l + r) / 2;
            build(v*2, l, m);
            build(v*2+1, m+1, r);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int ql, int qr) {
        if (ql > qr) return INT_MAX;
        if (tl == ql && tr == qr) return t[v];
        int tm = (tl+tr) / 2;
        // return min(query(v * 2, tl, tm, ql, min(tm, qr)),
        //            query(v * 2 + 1, tm + 1, tr, max(tm + 1, ql), qr));
        return min(query(v * 2, tl, tm, ql, min(tm, qr)),
                   query(v * 2 + 1, tm + 1, tr, max(tm + 1, ql), qr));
    }

    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if(tm >= pos) update(v*2, tl, tm, pos, val);
            else update(v*2+1, tm+1, tr, pos, val);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
};





void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    input(a);
    SegmentTree st(a);
    // for (auto i : st.t) cout << i << " "; cout << endl;
    for (;m--;) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            --y;
            st.update(1, 0, n-1, y, z);
        } else {
            --y; --z;
            cout << st.query(1, 0, n - 1, y, z) << endl;
        }
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}