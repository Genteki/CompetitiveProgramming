// g.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
typedef long long i64;
const int MOD = 998244353;
const int N = 1e6 + 5;
void solve(vector<int>& prime) {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    int m = prime.size();
    debug(m);
    vector<int> sum(m, 0);
    for (int i = 0; i < n; ++i) {
        int ways = 0;
        if (i == 0) {
            ways = 1;
        } else {
            for (int j = 0; j < m; ++j) {
                if (a[i] % prime[j] == 0) {
                    ways = (ways + sum[j]) % MOD;
                }
            }
        }
        for (int j = 0; j < m; ++j) {
            sum[j] = (sum[j] + ways) % MOD;
        }
        debug(ways);
        if (i == n - 1) {
            cout << ways << endl;
        }
    }

    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<int> p(N+1, 1);
    vector<int> nums;
    p[1] = 0;

    for (int i = 2; i <= 1e3; ++i) {
        if (p[i] == 1) {
            nums.push_back(i);
            for (int j = 2; j <= N / i; ++j) {
                p[j * i] = 0;
            }
        }
    }
    // debug(nums);
    int test_cases = 1;
    // cin >> test_cases;
    for (; test_cases--;) {
        solve(nums);
    }
}