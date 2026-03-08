#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return;
    }
    i64 p = 0, l = 1, ans = 0;
    while (l < n) {
        l *= k;
        ++p;
    }
    while(l > 0) {
        ans += (n / l);
        n = n % l;
        l /= k;
    }
    cout << ans << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}