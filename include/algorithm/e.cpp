// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

typedef long long i64;
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
const int inf = 1e8;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dr(n+1, inf), dl(n+1, inf);
    dr[0] = -1;
    auto dfs = [&](auto &&self, int u, int p = 0) -> void {
        dr[u] = dr[p] + 1;
        if (g[u].size() == 1 && u != 1) dl[u] = 0;
        for (auto v : g[u]) {
            if (v == p) continue;
            self(self, v, u);
            dl[u] = min(dl[u], dl[v] + 1);
        }
    };

    dfs(dfs, 1);
    debug(dl);
    debug(dr);
    vector<mint> ans(n + 1, mint(0));
    auto dfs2 = [&](auto &&self, int u, int p = 0) ->void {
        if (u == 1) ans[u] = 1;
        else ans[u] = ans[p] * dl[u] / (dl[u]  + 1);
        for (auto v : g[u]) {
            if (v == p) continue;
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}