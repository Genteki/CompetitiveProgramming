// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
struct SegmentTree {
    int n;
    vector<long long> a, t;

    SegmentTree(vector<long long>& arr) {
        n = arr.size();
        t.resize(n * 4);
        a = arr;
        build(1, 0, n - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    
    void update(int v, int tl, int tr, int pos, long long new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<i64> loc(n, 0), pop(n, 0);
    input(loc);
    input(pop);
    SegmentTree sgt(pop);
    int m;
    cin >> m;
    for(;m--;) {
        int l, r;
        cin >> l >> r;
        auto itl = lower_bound(all(loc), l);
        auto itr = upper_bound(all(loc), r);
        int il = distance(loc.begin(), itl);
        int ir = distance(loc.begin(), itr);
        i64 ans = sgt.query(1, 0, n-1, il, ir-1);
        cout << ans << endl;
    }   
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}