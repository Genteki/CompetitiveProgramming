// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 MOD = 1e9 + 7;
i64 pow(i64 base, i64 exp, i64 mod) {
    i64 result = 1;
    base = base % mod;  // Ensure base is modulo first

    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }

        // Now exp must be even, so we square the base
        base = (base * base) % mod;

        // Divide exp by 2
        exp = exp / 2;
    }

    return result;
}
void solve() {
    i64 t;
    cin >> t;
    vector<i64> a(t), b(t);
    input(a);
    input(b);
    for (int i = 0; i < t; ++i) {
        i64 ai = a[i], bi = b[i];
        if (bi == 0 || ai == bi) {
            cout << 1 << endl;
            continue;
        }
        cout << pow(2, bi, MOD) << endl;
    }
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}