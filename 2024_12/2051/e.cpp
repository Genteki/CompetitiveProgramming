#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(n), b(n);
    for (auto& ai : a) cin >> ai;
    for (auto& bi : b) cin >> bi;

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int lhs, int rhs) -> bool {
        if (a[lhs] == a[rhs]) return b[lhs] < b[rhs];
        return a[lhs] < a[rhs];
    });

    i64 ans = a[ord[0]] * n;
    priority_queue<i64, vector<i64>, std::greater<>> pqb;
    i64 t = n;

    for (int i : ord) {
        while (!pqb.empty() && pqb.top() < a[i]) {
            i64 price = pqb.top();
            if (pqb.size() <= k) ans = max(ans, price * t);
            while(!pqb.empty() and pqb.top() == price) {
                pqb.pop();
                t--;
            }
        }
        if (pqb.size() <= k) {
            // pqb.emplace(b[i]);
            ans = max(ans, t * a[i]);
        }
        debug(a[i], t);
        pqb.emplace(b[i]);
    }

    while (!pqb.empty()) {
        i64 price = pqb.top();
        debug(price, t);

        if(pqb.size()<=k) ans = max(ans, price * t);
        while (!pqb.empty() && pqb.top() == price) {
            pqb.pop();
            t--;
        }
    }

    cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}