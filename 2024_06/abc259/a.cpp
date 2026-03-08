#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    int t0;
    if (n >= x) t0 = t;
    else t0 = t + (x-n) * d;
    // cout << t0 << " ";
    if (m >= x) {
        cout << t0 << endl;
    } else {
        cout << (t0 - d * (x-m)) << endl;
    }
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