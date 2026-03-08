#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int ans = n - 1;
    int cur = 0;
    int mx = 0;
    for (int i = 0; i < n-1; ++i) {
        if (a[i] == a[i + 1]) {
            cur++;
            mx = max(cur, mx);
        } else {
            cur = 0;
        }
    }
    cout << (n - 1 - mx) << endl;

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