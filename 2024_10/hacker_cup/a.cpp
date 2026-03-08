#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#define debug(...) 42
void solve(int t) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    double delta = 1e-10;
    double low = 0, high = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        if (b[i]) low = max(low, (i + 1) / double(b[i]));
        if (a[i]) high = min(high, (i + 1) / double(a[i]));
        debug(high, low);
    }
    if (abs(high - low) <= delta) {
        cout << "Case #" << t << ": " << setprecision(8) << low << endl;
    } else if (high < low) {
        cout << "Case #" << t << ": " << setprecision(8) << -1 << endl;
    } else {
        cout << "Case #" << t << ": " << setprecision(8) << low << endl;
    }
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test_cases = 1;
    cin >> test_cases;
    for (int t = 0; t < test_cases; ++t) {
        solve(t+1 );
    }
}