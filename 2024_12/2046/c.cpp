// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n), b(n);
    input(a);
    input(b);
    vector<i64> c(n), d(n);
    i64 x=0, y=-1e9;
    for (int i = 0; i < n; ++i) {
        c[i] = max(a[i], b[i]);
        d[i] = min(a[i], b[i]);
        x += c[i];
        y = max(y, d[i]);
    }
    cout << (x + y) << endl;
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