// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
constexpr i64 mod = 1e9+7;

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
    }
    mint& operator=(const mint& b) = default;
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
    friend std::ostream& operator<<(std::ostream& os, mint m) {
        os << m.v;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, mint m) {
        is >> m.v;
        return is;
    }
    mint pow(const long long x) { return repeat2mint(v, x); }
    mint inv() { return mint(1) / v; }
};
const int N = 11111;
vector<mint> f(N), fi(N);

void solve() {
    int n, c, m;
    cin >> n >> c >> m;
    vector<int> a(m);
    for (auto& ai : a) cin >> ai;
    int p = m - c, M = m + c + 1;

    auto g = [&](int r, int k) -> mint {
        return f[c] * f[r + c - k] * fi[c - k]
         * fi[k] * fi[r + c];
    };
    vector<mint> dp_next(p + 1, 0), dp(p + 1, 0);
    dp_next[0] = 1;
    for (int pos = n - 1; pos >= 1; pos--) {
        for (int r = 0; r <= p; r++) {
            mint sum = 0;
            int q = min(c, r);
            for (int k = 0; k <= q; k++) {
                sum = sum + g(r, k) * dp_next[r - k];
            }
            dp[r] = sum;
        }
        swap(dp, dp_next);
    }
    mint ans = f[m] * f[c].inv() * dp_next[p];
    cout << ans.v << "\n";
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    f[0] = 1, fi[0] = f[0].inv();
    for (int i = 1; i < N; ++i) {
        f[i] = f[i - 1] * i;
        fi[i] = f[i].inv();
    }
    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}