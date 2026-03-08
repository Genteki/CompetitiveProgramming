// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const i64 INF = 1e9;

template <const int &MOD>
struct _m_int {
    int val;

    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }

    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}

    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }

    _m_int &operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    _m_int &operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in
        // an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a"(quot), "=d"(rem)
            : "d"(x_high), "a"(x_low), "r"(m));
        return rem;
    }

    _m_int &operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    _m_int &operator/=(const _m_int &other) { return *this *= other.inv(); }

    friend _m_int operator+(const _m_int &a, const _m_int &b) {
        return _m_int(a) += b;
    }
    friend _m_int operator-(const _m_int &a, const _m_int &b) {
        return _m_int(a) -= b;
    }
    friend _m_int operator*(const _m_int &a, const _m_int &b) {
        return _m_int(a) *= b;
    }
    friend _m_int operator/(const _m_int &a, const _m_int &b) {
        return _m_int(a) /= b;
    }

    _m_int &operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    _m_int &operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    _m_int operator++(int) {
        _m_int before = *this;
        ++*this;
        return before;
    }
    _m_int operator--(int) {
        _m_int before = *this;
        --*this;
        return before;
    }

    _m_int operator-() const { return val == 0 ? 0 : MOD - val; }

    friend bool operator==(const _m_int &a, const _m_int &b) {
        return a.val == b.val;
    }
    friend bool operator!=(const _m_int &a, const _m_int &b) {
        return a.val != b.val;
    }
    friend bool operator<(const _m_int &a, const _m_int &b) {
        return a.val < b.val;
    }
    friend bool operator>(const _m_int &a, const _m_int &b) {
        return a.val > b.val;
    }
    friend bool operator<=(const _m_int &a, const _m_int &b) {
        return a.val <= b.val;
    }
    friend bool operator>=(const _m_int &a, const _m_int &b) {
        return a.val >= b.val;
    }

    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];

    static void prepare_inv() {
        // Ensures that MOD is prime, which is necessary for the inverse
        // algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1) assert(MOD % p != 0);

        save_inv[0] = 0;
        save_inv[1] = 1;

        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }

    _m_int inv() const {
        if (save_inv[1] == 0) prepare_inv();

        if (val < SAVE_INV) return save_inv[val];

        _m_int product = 1;
        int v = val;

        do {
            product *= MOD - MOD / v;
            v = MOD % v;
        } while (v >= SAVE_INV);

        return product * save_inv[v];
    }

    _m_int pow(int64_t p) const {
        if (p < 0) return inv().pow(-p);

        _m_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1) result *= a;

            p >>= 1;

            if (p > 0) a *= a;
        }

        return result;
    }

    friend ostream &operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};

template <const int &MOD>
_m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];

const int MOD = int(1e9) + 7;
using Z = _m_int<MOD>;

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n), b(m);
    input(a);
    input(b);
    vector<vector<i64>> dp(n + 1, vector<i64>(m, INF));

    vector<i64> ps(n + 1, 0);
    for (int i = 0; i < n; ++i) ps[i + 1] = ps[i] + a[i];
    dp[0][0] = 0;
    for (i64 i = 0; i <= n; ++i) {
        for (i64 j = 0; j < m; ++j) {
            if (j > 0) dp[i][j] = min(dp[i][j - 1] , dp[i][j]);
            i64 s = ps[i] - b[j];
            auto it = lower_bound(all(ps), s);
            i64 l = distance(ps.begin() , it);
            if (l < i) dp[i][j] = min(dp[i][j], dp[l][j] + (m - j - 1));
        }
    }
    i64 ans = *min_element(all(dp[n]));
    if (ans == INF)
        {cout << -1 << endl;return;}
    vector<vector<Z>> dp2(n + 1, vector<Z>(m, 0));
    dp2[0][0] = 1;

    vector<vector<Z>> ps2d(n + 2, vector<Z>(m, 0));
    for (int j  = 0; j < m; ++j) {
        map<i64, i64> point;
        for (int i = 0; i <= n; ++i) {
            point[dp[i][j]] = i;
            if (i == 0 && j == 0) { ps2d[1][0] = 1; continue;}
            if (dp[i][j] == dp[i][j - 1]) {
                dp2[i][j] += dp2[i][j - 1];
            }
            if (i > 0) {
                i64 s = ps[i] - b[j];
                auto it = lower_bound(all(ps), s);
                i64 l = std::distance(ps.begin(), it);
                if (l < i && dp[l][j] + (m - j - 1) == dp[i][j]) {
                    if (j == m - 1) dp2[i][j] += (ps2d[i][j] - ps2d[l][j]);
                    else dp2[i][j] += (ps2d[point[dp[l][j]] + 1][j] - ps2d[l][j]);
                }
            }
            ps2d[i+1][j] = ps2d[i][j] + dp2[i][j];
        }
    }

    cout << ans << " ";
    cout << dp2[n][m-1] << endl;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}