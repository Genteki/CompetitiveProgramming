#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if (k == 0) {
        cout << 0 << endl;
        return;
    }

    ++ans;
    k -= n;
    for (int i = 0; i < n-1; ++i) {
        if (k <= 0) {
            break;
        }
        ++ans;
        k = k - (n - 1 - i);

        if (k <= 0) {
            break;
        }
        ++ans;
        k = k - (n - 1 - i);
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