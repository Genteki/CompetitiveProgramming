// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

const i64 BS_MAX = 1e9;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    i64 b[3] = {1, 1, 3};
    i64 ans = 0;
    i64 res = 0;
    for (auto& ai : a) {
        ans += (ai / 5LL * 3LL);
        ai = ai % 5;
        while (ai > 0) {
            ai -= b[res % 3];
            res++;
            ans++;
        }
    }

    cout << ans;
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