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

const int INF = INT_MIN;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    input(r);

    vector<int> dp(m + 1, INF);
    dp[0] = 0;
    int pts = 0;
    int idx = 0;

    while (idx < n) {
        vector<int> stg;
        vector<int> itl;
        while (idx < n && r[idx] != 0) {
            if (r[idx] > 0) {
                itl.push_back(r[idx]);
            } else {
                stg.push_back(-r[idx]);
            }
            idx++;
        }
        auto filter_checks = [&](vector<int>& checks) {
            vector<int> filtered;
            for (int req : checks) {
                if (req <= pts) {
                    filtered.push_back(req);
                }
            }
            return filtered;
        };

        auto strength_filtered = filter_checks(stg);
        auto intelligence_filtered = filter_checks(itl);

        vector<int> stg_cnt(pts + 1, 0);
        vector<int> int_cnt(pts + 1, 0);

        for (int req : strength_filtered) {
            stg_cnt[req]++;
        }
        for (int req : intelligence_filtered) {
            int_cnt[req]++;
        }

        for (int i = 1; i <= pts; ++i) {
            stg_cnt[i] += stg_cnt[i - 1];
            int_cnt[i] += int_cnt[i - 1];
        }

        for (int s = 0; s <= pts; ++s) {
            int S = s;
            int I = pts - s;
            int stg_pass = (S >= 0) ? stg_cnt[S] : 0;
            int itl_pass = (I >= 0) ? int_cnt[I] : 0;
            dp[s] += stg_pass + itl_pass;
        }

        if (idx < n && r[idx] == 0) {
            pts++;
            vector<int> dp_new(m + 1, INF);
            for (int s = 0; s <= pts - 1; ++s) {
                dp_new[s + 1] = max(dp_new[s + 1], dp[s]);
                dp_new[s] = max(dp_new[s], dp[s]);
            }
            dp = dp_new;
            idx++;
        }
    }

    int max_checks_passed = *max_element(dp.begin(), dp.end());
    cout << max_checks_passed << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}