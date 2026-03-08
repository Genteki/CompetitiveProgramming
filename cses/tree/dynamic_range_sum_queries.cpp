// Dynamic Range Sum Queries
// https://www.cses.fi/problemset/task/1648
// Segment tree

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))


struct SegmentTree {
    int n;
    vector<i64> a, t;
    
    SegmentTree(vector<i64> & arr) {
        n = arr.size();
        t.resize(n*4);
        a = arr;
        build(1, 0, n-1);
    }
    
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }

    i64 query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);

    }

    void update(int v, int tl, int tr, int pos, i64 new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(v*2, tl, tm, pos, new_val);
            else update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = t[v*2] + t[v*2 + 1];
        }
    }

};


void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> arr(n);
    input(arr);
    SegmentTree st(arr);
    cout << endl;
    for (;m--;) {
        int q, x, y;
        cin >> q >> x >> y;
        if (q == 1) {
            st.update(1, 0, n-1, x-1, y);
        } else {
            cout << st.query(1, 0, n-1, x-1, y-1) << endl;
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