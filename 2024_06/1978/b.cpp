// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    i64 n,a,b;
    cin >> n >> a >> b;
    i64 k = 0;
    if (b >= a) {
        k = (b + 1 - a);
        k = min({n, b, k});
    }
    i64 ans = ((2 * b + 1 - k) * k + 2 * a * (n - k)) / 2;
    ans = max(ans, a * n);
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