#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))
const int mod = 1e9+7;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+6);
    a[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            a[i+j] += a[i];
            a[i+j] %= mod;
        }
    }
    cout << a[n] << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}