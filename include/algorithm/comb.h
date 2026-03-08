#ifndef COMB_H
#define COMB_H
#include "modint.h"

struct Comb {
    int n;
    std::vector<mint> _fac;
    std::vector<mint> _invfac;
    std::vector<mint> _inv;

    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() { init(n); }

    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }

    mint fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    mint invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    mint inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    mint binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

#endif