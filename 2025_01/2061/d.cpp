// d.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n), b(m);
    for (auto & ai : a) cin >> ai;
    for (auto & bi : b) cin >> bi;
    map<i64,i64> mpa, mpb;
    for (auto ai : a) {
        mpa[ai]++;
    }
    for (auto bi : b) {
        if (mpa[bi]) {
            mpa[bi]--;
            if (mpa[bi] == 0) {
                mpa.erase(bi);
            }
        } else {
            mpb[bi]++;
        }
    }
    debug(vector<pair<i64, i64>>(mpa.begin(), mpa.end()));

    auto dfs = [&](this auto && self, i64 x) -> bool {
        bool ans = true;
        if (x == 0) return false;
        if (x == 1 and mpa[x] == 0) return false;
        if (mpa[x]) {
            mpa[x]--;
            if (mpa[x] == 0) mpa.erase(x);
            return true;
        }  else {
            ans &= self(x/2);
            if (!ans) return ans;
            ans &= self(x - x/2);
            if (!ans) return ans;
        }

        return ans;
    };
    debug(a);
    for (auto [bi, k] : mpb) {
        while(k--) {
            debug(bi);
            bool q = dfs(bi);
            if (!q) {
                cout << "No" << endl;
                return;
            }
        }
    }
    i64 s = 0;
    for (auto [_, z] : mpa) s += z;

    if (s == 0)
    cout << "Yes" << endl;
    else cout << "No\n";
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