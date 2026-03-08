#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 x, y, k;
    cin >> x >> y >> k;
    i64 sx = x * k, sy = y * k;
    vector<i64> a(k, x), b(k, y);
    for (int i = 0; i < k / 2; ++i) {
        a[i] += (i + 1);
        a[k-1-i] -= (i+1);
        b[i] += (i+1);
        b[k-1-i] -= (i+1);
    }
    for (int i = 0; i < k; ++i) {
        cout << a[i] << " " << b[i] << endl;
    }
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