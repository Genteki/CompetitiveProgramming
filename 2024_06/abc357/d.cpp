#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))
const int mod = 998244353;
i64 remain(i64 a,i64 x) {
    a = a % mod;
    if(x == 1) {
        return a % mod;
    }
    if (x % 2 == 0) {

        return remain((a*a)%mod, x /2 );
    } else {
        return (a * remain((a * a) % mod, x / 2)) % mod;
    }
}

void solve() {
    i64 n;
    cin >> n;
    i64 tmp = n;
    int m = 0;
    while (tmp > 0) {
        tmp /= 10;
        m++;
    }

    i64 t = remain(10, m);
    // cout << m << endl;

    auto f = [&](auto&& self, i64 x, i64 p) -> i64 {
        x = x % mod;
        if (p == 1) {
            return x % mod;
        }
        
        i64 r = self(self, x, p/2);
        i64 new_p = p / 2;
        i64 ans = (r % mod + (r * remain(t, new_p))) % mod;
        if (p % 2 == 0) {
            return ans;
        } else {
            return (((ans * t) % mod) + (x % mod)) % mod;
        }
    };

    i64 q = f(f, n, n);
    cout << q << endl;
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