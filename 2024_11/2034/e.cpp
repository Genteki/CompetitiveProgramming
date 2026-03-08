// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

const i64 M = 15;
i64 factorial(const i64 n) {
    i64 f = 1;
    for (i64 i=1; i<=n; ++i)
        f *= i;
    return f;
}
void solve() {
    i64 n, k;
    cin >> n >> k;
    if (k == 1 && n == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return;
    }
    if (k == 1) {
        cout << "NO" << endl;
        return;
    }
    i64 s = (n + 1) * k;
    if (s % 2) {
        cout << "NO" << endl;
        return;
    }
    vector<vector<i64>> ans(k, vector<i64>(n));
    if (n < M) {
        if (k % 2 == 0) {
            vector<i64> per(n);
            for (i64 i = 0; i < n; ++i) {
                per[i] = i + 1;
            }
            if (n < 12 && factorial(n) < k) {
                cout << "NO" << endl;
                return;
            }
            for (i64 i = 0; i < k / 2; ++i) {
                for (i64 j = 0; j < n; ++j) {
                    ans[i * 2][j] = per[j];
                    ans[i * 2 + 1][j] = n + 1 - per[j];
                }
                next_permutation(all(per));
            }
        } else {
            vector<i64> per(n), x(n), y(n), z(n), y_(n), z_(n);
            if (n < 11 && factorial(n) - 3 < k) {
                cout << "NO" << endl;
                return;
            }
            for (i64 i = 0; i < n; ++i) {
                per[i] = i + 1;
                x[i] = i + 1;
                y[i] = ((n + 3) / 2 + i) % n;
                if (y[i] == 0) y[i] = n;
                z[i] = (n + 1) * 3 / 2 - x[i] - y[i];
                y_[i] = n + 1 - y[i];
                z_[i] = n + 1 - z[i];
            }
            ans[0] = x;
            ans[1] = y;
            ans[2] = z;
            next_permutation(all(per));

            for (i64 i = 0; i < (k - 3) / 2; ++i) {
                while (per == y_ || per == z_ || per == z || per == y) {
                    next_permutation(all(per));
                }
                for (i64 j = 0; j < n; ++j) {
                    ans[i * 2 + 3][j] = per[j];
                    ans[i * 2 + 4][j] = n + 1 - per[j];
                }
                next_permutation(all(per));
            }
        }
    } else {
        if (k % 2 == 0) {
            vector<i64> per(M);
            for (i64 i = 0; i < M; ++i) {
                per[i] = i + 1;
            }
            for (i64 i = 0; i < k / 2; ++i) {
                for (i64 j = 0; j < n; ++j) {
                    if(j < M) ans[i * 2][j] = per[j];
                    else ans[i * 2][j] = j + 1;
                    ans[i * 2 + 1][j] = n + 1 - ans[i*2][j];
                }
                next_permutation(all(per));
            }
        } else {
            vector<i64> per(M), x(n), y(n), z(n), y_(M), z_(M), y__(M), z__(M);
            for (i64 i = 0; i < n; ++i) {
                if(i < M) per[i] = i + 1;
                x[i] = i + 1;
                y[i] = ((n + 3) / 2 + i) % n;
                if (y[i] == 0) y[i] = n;
                z[i] = (n + 1) * 3 / 2 - x[i] - y[i];
            }
            ans[0] = x;
            ans[1] = y;
            ans[2] = z;
            for (int i = 0; i < M; ++i) {
                y_[i] = y[i];
                y__[i] = n+1- y[i];
                z_[i] = z[i];
                z__[i] = n + 1 - z[i];
            }
            next_permutation(all(per));

            for (i64 i = 0; i < (k - 3) / 2; ++i) {
                while (per == y_ || per == z_ || per == z__ || per == y__) {
                    next_permutation(all(per));
                }
                for (i64 j = 0; j < n; ++j) {
                    if(j < M) ans[i * 2 + 3][j] = per[j];
                    else ans[i * 2 + 3][j] = j + 1;
                    ans[i * 2 + 4][j] = n + 1 - ans[i * 2 + 3][j];
                }
                next_permutation(all(per));
            }
        }
    }


    cout << "YES" << endl;
    for (auto &ai : ans) {
        for (auto &aii : ai) {
            cout << aii << " ";
        }
        cout << endl;
    }
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