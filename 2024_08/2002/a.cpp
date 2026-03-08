#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (m > n) swap(m, n);
    int c1 = (n >= k) ? k : n;
    int c2 = (m >= k) ? k : m;
    int c = c1 * c2;
    // int c = ((n + k - 1) / k) * ((m + k - 1) / k);
    cout << c << endl;
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