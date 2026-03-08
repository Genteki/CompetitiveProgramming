// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> pigeon(n);
    vector<int> nest(n), idx(n);
    for (int i = 0; i < n; ++i) {
        pigeon[i] = i;
        nest[i] = i;
        idx[i] = i;
    }
    while(q--) {
        int qi;
        cin >> qi;
        if (qi == 1) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            pigeon[x] = idx[y];
        } else if (qi == 2) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            swap(nest[idx[x]], nest[idx[y]]);
            swap(idx[x], idx[y]);
        } else {
            int x;
            cin >> x; --x;
            cout << (nest[pigeon[x]]+1) << endl;
        }
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}