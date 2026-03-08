#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[i] = c - 'a';
    }
    bool same = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[0]) {
            same = false;
        }
    }
    if (same) {
        cout << "NO" << endl;
        return;
    }
    if (k >= 1) {
        cout << "YES" << endl;
        return;
    }
    bool ans = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] > a[n-i-1]) {
            cout << "NO" << endl;
            return;
        } else if (a[i] < a[n-i-1]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

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