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
    vector<int> a(n);
    input(a);
    vector<int> b(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   std::greater<pair<int, int>>>
        pq;
    for (int i = n - 1; i >= 0; --i) {
        pq.emplace(a[i], i);
        while(!pq.empty() && pq.top().first < a[i]) {
            b[pq.top().second] = i + 1;
            pq.pop();
        }
    }
    priority_queue<int, vector<int>,
                        std::greater<int>> pq2;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; ++i) {
        v.emplace_back(b[i]-1, i);
    }
    sort(all(v));
    debug(v);
    vector<int> c(n, 0);
    int j = 0, k = 0;
    for (int i = 0; i < n; ++i) {
        while(j < n && v[j].first <= i) {
            pq2.push(v[j].second);
            ++j;
        }
        while(!pq2.empty() && pq2.top() <= i) pq2.pop();
        debug(pq2.top(), i);

        cout << pq2.size() << " ";
    }

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