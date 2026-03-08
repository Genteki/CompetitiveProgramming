#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    input(r);
    vector<int> a(n, 1);
    auto gen = [&](auto && self, int j) -> void {
        if (j == n) {
            if (accumulate(all(a), 0) % k == 0) {
                for (auto& ai : a) cout << ai << " ";
                cout << endl;
            }
            return;
        }
        while(a[j] <= r[j]) {
            self(self, j+1);
            a[j]++;
        }
        a[j] = 1;
    };
    gen(gen, 0);
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}