// g.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

// https://cp-algorithms.com/algebra/fft.html#inverse-fft
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    i64 n = a.size();

    for (i64 i = 1, j = 0; i < n; i++) {
        i64 bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;

        if (i < j) swap(a[i], a[j]);
    }

    for (i64 len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (i64 i = 0; i < n; i += len) {
            cd w(1);
            for (i64 j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd& x : a) x /= n;
    }
}
vector<i64> multiply(vector<i64> const& a, vector<i64> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    i64 n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (i64 i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<i64> result(n);
    for (i64 i = 0; i < n; i++) result[i] = round(fa[i].real());
    return result;
}

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto & ai : a) cin >> ai;
    i64 N = (*max_element(a.begin(), a.end()))+1;
    vector<i64> b(N, 0);
    for (i64 ai : a) b[ai] = 1;
    vector<i64> c = multiply(b, b);
    i64 ans = 0;
    for (i64 ai : a) {
        i64 idx = 2 * ai;
        if (idx < c.size()) {
            ans += (c[idx] - 1) / 2;
        }
    }
    cout << ans << "\n";

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}