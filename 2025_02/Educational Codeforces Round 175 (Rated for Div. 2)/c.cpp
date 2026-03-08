// c.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    vector<i64> p(n);
    for (auto & pi : p) cin >> pi;
    i64 x = accumulate(p.begin(), p.end(), 0LL);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') p[i] = -p[i];
    }
    vector<i64> b;
    b.push_back(p[0]);
    for (int i = 1; i < n; ++i) {
        if (p[i] * p[i-1] < 0) {
            b.push_back(p[i]);
        } else {
            b.back() += p[i];
        }
    }
    if (b.back() < 0) b.pop_back();
    if(!b.empty() and b[0] < 0) b = vector<i64>(b.begin()+1, b.end());
    n = b.size();
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    debug(b);
    // priority_queue<array<int,2> ,vector<array<int,2>>, std::greater<>> pq, pqm;
    // vector<int> used(n,0);
    // for (int i = 0; i < n;++i) {
    //     if (b[i] > 0) pq.emplace(b[i],i);
    // }
    // while(true) {
    //     if (k and !pq.empty()) {
    //         --k;
    //         auto [v, i] = pq.top();
    //         used[i] = true;

    //     }
    // }
    priority_queue<int, vector<int>, std::greater<>> pq;
    for (int i = 0; i < n; ++i) {if (b[i] < 0) pq.emplace(-b[i]);
    }
    int x = (n+1)/2 - k;
    while(x > 0) 
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