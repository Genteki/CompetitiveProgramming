// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), ab(n), ia(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        ia[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    for (int i = 0; i < n; ++i) {
        ab[a[i]] = b[i];
    }
    int p = n%2;
    vector<pair<int,int>> ans;
    int m = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            if (p) {
                --p;
                m = i;
                
            } else {
                cout << -1 << endl;
                return;
            }
        } 
    }

    if (n/2 != m and m != -1) {
        ans.emplace_back(n/2, m);
        swap(a[n/2], a[m]);
        swap(b[n/2], b[m]);
        swap(ia[a[n/2]], ia[a[m]]);
    }
    debug(p);
    if (p) {
        cout << -1 << endl;
        return;
    }
    for (int ai = 0; ai < n; ++ai) {
        int i = ia[ai];
        if (a[i]==b[i]) continue;
        int bi = b[i];
        int j = ia[bi];
        if (a[i] != b[j] or a[j] != b[i]) {
            cout << -1 << endl;
            return;
        }
        if (i+j!=n-1) {
            int ni = n-1-j;
            ans.emplace_back(i, ni);
            swap(a[i], a[ni]);
            swap(b[i], b[ni]);
            swap(ia[a[i]], ia[a[ni]]);
        }
    }
    cout << ans.size() << endl;
    for (auto [i, j] : ans) {
        cout << i+1 << " " << j+1 << "\n";
    }
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