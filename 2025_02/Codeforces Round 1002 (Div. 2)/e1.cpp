// e1.cpp
#include <bits/stdc++.h>

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
    vector<i64> a(n*m), b(n*m);
    for (auto & ai : a)  cin >> ai;
    for (auto & bi : b)  cin >> bi;
    int idx = 0;
    i64 ans = 0;
    
    for (int k = 0; k < n; ++k) {
        // kmp
        vector<i64> tmp(2 * m + 1, -1);
        for (int j = 0; j < m; ++j) {
            if(k*m+j < idx + m) tmp[j] = a[k*m + j];
            tmp[m + 1 + j] = b[k*m+j];
        }
        int ts = tmp.size();
        vector<int> pi(ts);
        for (int i = 1; i < ts; ++i) {
            int j = pi[i-1];
            while(j > 0 and tmp[i] != tmp[j]) {
                j = pi[j-1];
            }
            if (tmp[i] == tmp[j]) {
                ++j;
            }
            pi[i] = j;
        }
        // subseq and impose
        int remain = pi.back();
        deque<int> subseq;
        for (int i = 0; i < m; ++i) {
            if (idx + i < k * m) subseq.push_back(a[idx+i]);
        }
        debug(tmp);
        debug(subseq, remain);
        int x = subseq.size();
        for (int i = 0; i < m-remain; ++i) {
            if ((!subseq.empty()) and b[i + k * m] == subseq.front()) subseq.pop_front();
        }
        if (subseq.empty()) {
            ans += (m - remain - x);
            idx += (remain + x);
        } else {
            ans += (m - (x - subseq.size()));
            idx += (x - subseq.size());
        }
        debug(subseq, ans);

    }
    cout << ans << endl;
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