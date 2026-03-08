#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    vector<i64> b(n, 1), c(n, 0);

    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == 1) continue;
        if (a[i] == 1) {
            cout << -1 << endl;
            return;
        }
        if (a[i] == a[i - 1]) {
            c[i] = c[i - 1];
        } else if (a[i] < a[i - 1]) {
            c[i] = c[i - 1];
            i64 x = a[i];
            i64 y = a[i - 1];
            while (x < y) {
                x *= x;
                c[i]++;
            }
        } else {
            c[i] = c[i - 1];
            i64 y = a[i];
            i64 x = a[i - 1];
            while (x <= y) {
                x *= x;
                c[i]--;
            }
            c[i]++;
        }
        c[i] = max(c[i], 0LL);
    }

    i64 ans = accumulate(all(c), 0LL);
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}