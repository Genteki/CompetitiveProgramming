// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
template <int MOD>
class ModInt {
   public:
    int value;

    // Constructors
    ModInt() : value(0) {}
    ModInt(int64_t x) { value = normalize(x); }

    // Helper to normalize the value to [0, MOD)
    static int normalize(int64_t x) {
        int v = int(x % MOD);
        if (v < 0) v += MOD;
        return v;
    }

    // Addition
    ModInt& operator+=(const ModInt& other) {
        value += other.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }

    // Subtraction
    ModInt& operator-=(const ModInt& other) {
        value -= other.value;
        if (value < 0) value += MOD;
        return *this;
    }

    // Multiplication
    ModInt& operator*=(const ModInt& other) {
        value = int64_t(value) * other.value % MOD;
        return *this;
    }

    // Exponentiation
    ModInt pow(int64_t exp) const {
        ModInt base = *this, result = 1;
        while (exp > 0) {
            if (exp & 1) result *= base;
            base *= base;
            exp >>= 1;
        }
        return result;
    }

    // Modular inverse using Fermat's Little Theorem
    ModInt inv() const {
        return pow(MOD - 2);  // Only works if MOD is prime
    }

    // Division
    ModInt& operator/=(const ModInt& other) { return *this *= other.inv(); }

    // Operator overloading for binary operators
    friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
    friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
    friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
    friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }

    // Comparison operators
    bool operator==(const ModInt& other) const { return value == other.value; }
    bool operator!=(const ModInt& other) const { return value != other.value; }

    // Output
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) {
        return os << x.value;
    }
};
using mint = ModInt<998244353>;
void solve() {
    i64 w, g, l;
    mint mw = w, mg = g, ml = l;

    cout << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef INPUT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test_cases = 1;
    cin >> test_cases;
    for (int t = 0; t < test_cases; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        solve();
    }
}