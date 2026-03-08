// e2.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

 i64 mod = 1e9+7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<i64> v(n);
    input(v);

    i64 s = accumulate(all(v), 0LL);
    // s %= mod;
    cout << s<< endl;

    i64 r1 = (n-k);
    i64 r2 = (n-k+1);
    if (r1 == 0) {
        cout << (s%mod) << " " << 0 << endl;
        return;
    }
    double pr1 = double(n-k) / n;
    double pr2 = double(k) / n;

    double av1 = double(n) / double(r1);
    double av2 = double(n) / double(r2);

    i64 ra1 = (n - k + 1) / 2;
    i64 ra2 = (n - k + 2) / 2;

    double e = av1 * ra1 * pr1 + av2 * ra2 * pr2;
    // cout << e << endl;
    i64 r = i64(e / n * s);
    i64 u = s - r;

    cout << (r%mod) << " " << (u % mod) << endl;
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