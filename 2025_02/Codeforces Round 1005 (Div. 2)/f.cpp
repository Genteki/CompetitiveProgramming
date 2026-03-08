// f.cpp
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
constexpr int inf = 1e9;
int opmin(const int& a, const int& b) { return min(a, b); }
int opmax(const int& a, const int& b) { return max(a, b); }
int emin() {return inf;}
int emax() {return 0;}
using MaxTree = SegmentTree<int, opmax, emax>;
using MinTree = SegmentTree<int, opmin, emin>;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<vector<int>> b(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }
    MaxTree max_tree(a);
    MinTree min_tree(a);
    vector<int> minl(n), minr(n), maxl(n), maxr(n);
    for (int i = 0; i < n; ++i) {
        int low = 0, high = i;
        while(high-low>0) {
            int mid = (high+low)/2;
            if (min_tree.query(mid, i) == a[i]) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        minl[i] = high;
        low = i, high = n;
        while(high - low > 1) {
            int mid = (high + low) / 2;
            if (min_tree.query(i, mid) == a[i]) {
                low = mid;
            } else high = mid;
        }
        minr[i] = high;

        low=0, high=i;
        while(high-low>0) {
            int mid = (high+low)/2;
            if (max_tree.query(mid, i) == a[i]) high = mid;
            else low = mid + 1;
        }
        maxl[i] = high;
        high = n-1, low = i;
        while(high-low>0) {
            int mid = (high+low+1)/2;
            if (max_tree.query(i, mid)==a[i]) low=mid;
            else high = mid-1;
        }
        maxr[i] = low;
    }
    i64 ans = 0;


    for (int x = 0; x <= n; ++x) {

        int y = k - x;
        if (b[x].empty()) continue;
        if (y < 0 or y> n or b[y].empty()) continue;

        for (int i = 0; i < b[y].size()-1; ++i) {
            maxr[b[y][i]] = min(maxr[b[y][i]], b[y][i+1]-1);
        }
        deque<int> q;
        int idy = 0; i64 ly = 0;

        for (int idx = 0; idx < b[x].size(); ++idx) {
            if(idx){
                minl[b[x][idx]] = max(minl[b[x][idx]], b[x][idx - 1]+1);
            }

            while(idy < b[y].size()) {
                if (maxl[b[y][idy]] <= minr[b[x][idx]]) {
                    q.push_back(b[y][idy]);
                    ly += (maxr[b[y][idy]] - b[y][idy] + 1);
                    ++idy;
                } else {
                    break;
                }
            }

            while (!q.empty()) {
                int i = q.front();
                if (maxl[i] <= minr[b[x][idx]]  and i > b[x][idx]) {
                    break;
                } else {
                    q.pop_front();
                    ly -= (maxr[i] - i + 1);
                }
            }
            int lx = b[x][idx] - minl[b[x][idx]] + 1;
            ans += lx * ly;
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}