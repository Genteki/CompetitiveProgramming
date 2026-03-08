#include<bits/stdc++.h>
#define MOD 998244353
template <class T>
void matrix_multiply(const T A[], const T B[], T C[], const int& m,
                     const int& n, const int& q, const T& mod = MOD) {
    // C_mq = A_mn x B_nq
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < q; ++j) {
            T s = 0;
            for (int k = 0; k < n; ++k) {
                s += A[i * n + k] * B[k * q + j];
            }
            if (mod) s %= mod;
            C[i * q + j] = s;
        }
    }
}

template <class T>
void matrix_add(const T A[], const T B[], T C[], int m, int n, T mod = MOD) {
    // C = A + B
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i * n + j] = A[i * n + j] + B[i * n + j];
            if (mod) C[i * n + j] %= mod;
        }
    }
}
template <class T>
void matrix_add(T A[], const T B[], int m, int n, T mod = MOD) {
    // A += B
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i * n + j] += B[i * n + j];
            if (mod) A[i * n + j] %= mod;
        }
    }
}