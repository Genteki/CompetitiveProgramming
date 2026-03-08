// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifndef MINT_H
#define MINT_H
#include <cassert>
#include <istream>
#include <ostream>

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

#endif
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<mint> p2(n,1);
    for (int i = 0; i < n; ++i) {
        p2[i+1] = p2[i] * 2;
    }

    for (auto & ai : a) cin >> ai;
    vector<int> n2(n+1, 0);
    for (int i = 0; i < n; ++i) {
        n2[i+1] = n2[i];
        if (a[i] == 2) ++n2[1+i];
    }
    mint ad = 0, cnt = 0, ans = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            q.push(i);
            cnt += 1;
        } else if (a[i] == 3) {
            while(!q.empty()) {
                ad += (p2[n2[i+1]-n2[q.front()+1]]);
                q.pop();
            }
            ans = ans + ad - cnt;
            ans += mod;
        } else if (a[i] == 2) {
            ad *= 2;
        }
    }
    cout << ans << endl;

    return;
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