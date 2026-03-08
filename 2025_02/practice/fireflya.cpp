// fireflya.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
typedef __int128_t i128;

bool check(i128 k) {
    int ecnt = 0;
    while(k >= 2) {
        if (k == 3) {
            ecnt += 5;
        } else {
            ecnt += 3;
            ecnt += (k % 2);
        }
        k/=2;
    }
    debug(ecnt);
    return ecnt <= 211;
}


void solve() {
    i64 k, p;
    cin >> k >> p;
    if (k == 0) {
        cout << "YES\n";
        cout << "2 0\n1 2\n";
        return;
    } else if (k == 1) {
        cout << "YES\n";
        cout << "2 1\n1 2\n1 2\n";
        return;
    }

    for (i128 x = 0; x * p + k <= (i128(1) << 70) + (i128(1) << 69); ++x) {
        debug(i64(x*p+k));
        if (check(x * p + k)) {
            i128 z = x * p + k;

            vector<pair<int, int>> edges;
            int vertices = 1;
            vector<int> r;
            int cnt = 0;
            while (z >= 2) {
                bool flag = (z % 2);
                z /= 2;
                edges.emplace_back(vertices, vertices + 1);
                edges.emplace_back(vertices, vertices + 2);
                edges.emplace_back(vertices + 1, vertices + 2);
                vertices += 2;
                if (flag) r.push_back(cnt);
                ++cnt;
            }
            int y = 0;
            for (int ri : r) {
                if (vertices - ri * 2 != 3) {
                    edges.emplace_back(1, vertices - ri * 2);
                } else {
                    edges.emplace_back(1, vertices + 1);
                    edges.emplace_back(vertices + 1, 3);
                    y = 1;
                }
            }
            cout << "YES" << endl;
            cout << (vertices + y) << " " << edges.size() << endl;
            cout << "1 " << vertices << endl;

            for (auto [u, v] : edges) cout << u << " " << v << endl;

            return;
        }
    }

    cout << "NO" << endl;

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