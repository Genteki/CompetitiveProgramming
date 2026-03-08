#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void query(int i, int j, int &k) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    cin >> k;
}

void output(bool ans) {
    if (ans) cout << "! A\n";
    else cout << "! B\n";
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b = a;
    sort(a.begin(), a.end());
    fill(unique(a.begin(), a.end()), a.end(), -1);
    for (int i = 0; i < n; ++i) {
        if (i + 1 != a[i]) {
            int x;
            int j;
            if (i+1 == 1) j = 2;
            else j = 1;
            query(i+1, j, x);
            if (x == 0) {
                output(1);
                return;
            } else {
                output(0);
                return;
            }
        }
    }
    int i = 1, j = n;
    int x, y;
    for (int ii = 0; ii < n; ++ii) {
        if (b[ii] == 1) {
            i = ii+1;
        } else if (b[ii] == n) {
            j = ii+1;
        }
    }
    query(i, j, x);
    query(j, i, y);
    if (x == y and x >= (n-1)) {
        output(0);
    } else {
        output(1);
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