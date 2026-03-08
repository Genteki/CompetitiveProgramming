// e.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<i64> a(n);
    input(a);

    vector<pair<i64, i64>> b(n);
    for (i64 i = 0; i < n; ++i) {
        b[i] = {a[i], i};
    }
    sort(all(b), std::greater());

    vector<i64> ans(n, -2), prefix_sum(n + 1, 0);
    i64 prev = -1, prev_i = -10;
    if (m == n) {
        for (auto& ai : ans) cout << 0 << " ";
        return;
    }
    for (i64 i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + b[i].first;
    }
    k -= prefix_sum[n];
    i64 sm = prefix_sum[m], sm1 = prefix_sum[m + 1];
    for (i64 r = -1; auto [ai, i] : b) {
        r++;
        if (prev == ai) {
            ans[i] = ans[prev_i];
            continue;
        } else {
            prev = ai;
            prev_i = i;
        }
        i64 s = (r < m) ? (sm1 - ai) : sm;
        i64 high = k, low = 0;
        debug(r, ai, i);
        if (r < m) {
            if (prefix_sum[m + 1] - prefix_sum[r + 1] + k >=
                (ai + 1) * (m - r)) {
                low = 0;
            } else {
                ans[i] = 0;
                continue;
            }
        } else {
            if (ai + high < b[m - 1].first) {
                ans[i] = -1;
                continue;
            }
        }

        while (high - low > 1) {
            i64 mid = (high + low) / 2;
            i64 newai = ai + mid;
            auto it = lower_bound(all(b), make_pair(newai, 0LL),
                                  [](const pair<i64, i64>& a, const pair<i64, i64>& b) {
                return a.first > b.first;});
            i64 newr = it - b.begin();
            if (newr >= m) {
                low = mid;
            } else {
                i64 remain_votes = k - mid;
                i64 remain_sum = s - prefix_sum[newr];
                if (remain_sum + remain_votes >= (newai + 1) * (m - newr)) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
        }

        ans[i] = high;
    }

    for (auto ansi : ans) cout << ansi << " ";
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    //    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}
