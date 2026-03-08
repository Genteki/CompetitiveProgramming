#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;

    vector<vector<vector<i64>>> a(n, vector<vector<i64>>(n, vector<i64>(n, 0)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                cin >> a[i][j][k];
            }
        }
    }

    vector<vector<vector<i64>>> prefix_sum(n+1, vector<vector<i64>>(n+1, vector<i64>(n+1, 0)));
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         for (int k = 0; k < n; ++k) {
    //             prefix_sum[i + 1][j + 1][k + 1] =
    //                 prefix_sum[i + 1][j + 1][k] + a[i][j][k];
    //         }
    //     }
    // }
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         for (int k = 0; k <= n; ++k) {
    //             prefix_sum[i][j + 1][k] += prefix_sum[i][j][k];
    //         }
    //     }
    // }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         for (int k = 0; k <= n; ++k) {
    //             prefix_sum[i + 1][j][k] += prefix_sum[i][j][k];
    //         }
    //     }
    // }
    // for (int i = 0; i <= n; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         cout << prefix_sum[2][i][j] << " ";
    //     } cout << endl;
    // }

    // int q;
    // cin >> q;
    // for (; q--;) {
    //     int lx, rx, ly, ry, lz, rz;
    //     cin >> lx >> rx >> ly >> ry >> lz >> rz;
    //     cout << (prefix_sum[rx][ry][rz] - prefix_sum[lx - 1][ly - 1][lz - 1])
    //          << endl;
    // }
    // Build the 3D prefix sum array
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                prefix_sum[i][j][k] =
                    a[i - 1][j - 1][k - 1] + prefix_sum[i - 1][j][k] +
                    prefix_sum[i][j - 1][k] + prefix_sum[i][j][k - 1] -
                    prefix_sum[i - 1][j - 1][k] - prefix_sum[i - 1][j][k - 1] -
                    prefix_sum[i][j - 1][k - 1] +
                    prefix_sum[i - 1][j - 1][k - 1];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        i64 result =
            prefix_sum[rx][ry][rz] - prefix_sum[lx - 1][ry][rz] -
            prefix_sum[rx][ly - 1][rz] - prefix_sum[rx][ry][lz - 1] +
            prefix_sum[lx - 1][ly - 1][rz] + prefix_sum[lx - 1][ry][lz - 1] +
            prefix_sum[rx][ly - 1][lz - 1] - prefix_sum[lx - 1][ly - 1][lz - 1];

        cout << result << endl;
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}