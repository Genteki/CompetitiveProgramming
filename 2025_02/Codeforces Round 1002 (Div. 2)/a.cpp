#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    map<int,int> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] += 1;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b[x] += 1;
    }
    if (a.size() + b.size() >= 4) {
        cout << "YES" << endl;
    } else {
        cout << "NO\n";
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