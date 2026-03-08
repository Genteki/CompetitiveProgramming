// e.cpp

#include <bits/stdc++.h>

#define ai64(x) (x).begin(), (x).end()
#define input(x) \
    for (auto &ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

long long mod = 998244353;
// 入力が必ず-mod<a<modの時.
struct mint {
    long long v = 0;
    mint() {}
    mint(int a) { v = a < 0 ? a + mod : a; }
    mint(long long a) { v = a < 0 ? a + mod : a; }
    mint(unsigned long long a) { v = a; }
    long long val() { return v; }
    void modu() { v %= mod; }

    mint repeat2mint(const long long a, long long b) {
        mint ret = 1, p = a;
        while (b) {
            if (b & 1) ret *= p;
            p *= p;
            b >>= 1;
        }
        return ret;
    };

    mint &operator=(const mint &b) = default;
    mint operator-() const { return mint(0) - (*this); }
    mint operator+(const mint b) { return mint(v) += b; }
    mint operator-(const mint b) { return mint(v) -= b; }
    mint operator*(const mint b) { return mint(v) *= b; }
    mint operator/(const mint b) { return mint(v) /= b; }

    mint operator+=(const mint b) {
        v += b.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    mint operator-=(const mint b) {
        v -= b.v;
        if (v < 0) v += mod;
        return *this;
    }
    mint operator*=(const mint b) {
        v = v * b.v % mod;
        return *this;
    }
    mint operator/=(mint b) {
        if (b == 0) assert(false);
        int left = mod - 2;
        while (left) {
            if (left & 1) *this *= b;
            b *= b;
            left >>= 1;
        }
        return *this;
    }

    mint operator++(int) {
        *this += 1;
        return *this;
    }
    mint operator--(int) {
        *this -= 1;
        return *this;
    }
    bool operator==(const mint b) { return v == b.v; }
    bool operator!=(const mint b) { return v != b.v; }
    bool operator>(const mint b) { return v > b.v; }
    bool operator>=(const mint b) { return v >= b.v; }
    bool operator<(const mint b) { return v < b.v; }
    bool operator<=(const mint b) { return v <= b.v; }
    friend ostream& operator<<(ostream& os, mint m) {os << m.v; return os;}
    friend istream& operator>>(istream& is, mint m) {is >> m.v; return is;}

    mint pow(const long long x) { return repeat2mint(v, x); }
    mint inv() { return mint(1) / v; }
};
using Z = mint;
void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Z> dp(m + 1);
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        std::vector<Z> ndp(m + 1);
        for (int j = i; j >= 0; j--) {
            ndp[j + 1] += dp[j];
            if (j) {
                ndp[j - 1] += dp[j];
            }
        }
        std::swap(dp, ndp);
    }

    std::vector<Z> f(m + 1);
    f[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        std::vector<Z> nf(m + 1);
        for (int x = 0; x <= m; x++) {
            for (int y = 0; x + y <= m; y++) {
                nf[x + y] += f[x] * dp[y];
            }
        }
        std::swap(f, nf);
    }

    Z ans = 0;
    for (int i = 0; i <= m; i++) {
        ans += dp[i] * f[i];
    }
    std::cout << ans << "\n";
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