// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    i64 s = 0;
    s = accumulate(all(a), 0LL);
    if (s % n) {
        cout << "NO\n";
        return;
    }
    i64 s1 = 0, s2 = 0, n1 = 0, n2 = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            s1 += a[i];
            ++n1;
        } else {
            s2 += a[i];
            ++n2;
        }
    }
    i64 avg = s / n;
    if (avg * n1 == s1 && avg * n2 == s2) {
        cout << "YES\n";
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