// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n), b(m);
    input(a);
    input(b);
    int z = *max_element(all(a));
    for (auto& bi : b) {
        if (bi > z) bi = 0;
    }
    int hard=0, eazy=0;
    for (i64 bi : b) {
        if (bi > a[0]) {
            hard++;
        } else {
            eazy++;
        }
    }
    i64 rk = 1;
    for (auto ai : a) {
        if (ai > a[0]) {
            rk++;
        }
    }

    int a0 = a[0];
    sort(all(a));
    sort(all(b), std::greater<i64>());
    vector<i64> diff_rank(m, 0);
    int q = b[hard-1];
    
    for (int i = 0; i < m; ++i) {
        diff_rank[i] = distance(lower_bound(all(a), b[i]), a.end()) + 1;
        if (b[i] <= a0) {
            diff_rank[i] = 1;
        }
    }
    debug(diff_rank);
    debug(m, hard);
    for (int k = 1; k <= m; ++k) {
        i64 constest = m / k;
        i64 ez_c = (m-hard)/k;

        i64 hard_c = constest  - ez_c;
        i64 rank = ez_c;
        int remain = m - hard - ez_c * k;
        int hardi = k-1-remain;
        debug(k, hard_c, remain);
        for (int i = 0; i < hard_c; ++i) {
            if (hardi >= hard) {
                hardi -= remain;
            }
            rank += diff_rank[max(0, hardi)];
            hardi += k;
        }
        cout << rank << " ";
    }cout << endl;
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