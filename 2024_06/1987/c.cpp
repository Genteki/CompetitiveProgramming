#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), b;
    input(a);

    i64 x = a[0];
    i64 ans = 0;
    for (int i = 1; i < n; ++i) {
        // cout << x << ' ';
        if (a[i] < x) {
            b.push_back(x - a[i]);
        } else {
            x = a[i];
        }
    }
    i64 y = b.size();
    x = 0;
    sort(all(b));
    for (int i = 0; i < b.size(); ++i) {
        // cout << ans << " ";
        if (b[i] > x) {
            ans += ((b[i] - x) * (y - i + 1));
        }
        x = b[i];
    }

    cout << ans << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}