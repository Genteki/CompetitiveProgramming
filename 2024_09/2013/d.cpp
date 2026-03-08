// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    
    stack<pair<i64, i64>> st; // (sum, count)
    
    for (int i = 0; i < n; ++i) {
        i64 cur_sum = a[i];
        i64 cur_count = 1;
        while (!st.empty() && (st.top().first / st.top().second) >= (cur_sum / cur_count)) {
            cur_sum += st.top().first;
            cur_count += st.top().second;
            st.pop();
        }
        st.emplace(cur_sum, cur_count);
    }

    auto [mx_sum, mx_count] = st.top();
    i64 mx_avg = (mx_sum + mx_count - 1) / mx_count;
    while (st.size() > 1) st.pop();
    auto [mi_sum, mi_count] = st.top();
    i64 mi_avg = mi_sum / mi_count; 
    cout << (mx_avg - mi_avg) << endl;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
   cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}