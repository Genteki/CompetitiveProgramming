// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        b[i] = c - '0';
    }
    int a1 = 0, a2 = 0;
    for (int i = 0; i < n; ++i) {
        if (i%2==0) {
            a1 += (a[i] == 1);
            a2 += (b[i] == 1);
        } else {
            a2 += (a[i] == 1);
            a1 += (b[i] == 1);
        }
    }
    if (a1 <= n/2 and a2 <= (n+1)/2) {
        cout << "YES\n";
    } else cout << "NO\n";
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