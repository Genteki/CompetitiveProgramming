// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(m);
    for (auto & ai : a) cin >> ai;
    sort(a.begin(), a.end());
    vector<i64> b(n+1, 0);
    i64 s = 0, l = 0;
    for (int i = 0; i < m; ++i) {
        b[a[i]] = i+1;
    }
    for (int i = 1; i <= n; ++i) {
        if(b[i] == 0) b[i] = b[i-1];
    }
    for (int i = 0; i <= n; ++i) b[i] = m - b[i];
    for (int i = 1; i < n; ++i) {
        if (n-i > i) {
            s = s + (b[i - 1]-1) * (b[n - i - 1]) * 2;
        } else if (n - i == i) {
            s = s + (b[i - 1] - 1) * (b[n - i - 1]);
        }
    }
    cout << s << endl;
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