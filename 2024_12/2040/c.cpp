// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;
void solve() {
    i64 n, k;
    cin >> n >> k;
    --k;
    deque<i64> ans = {n};
    i64 mod = 2;
    for (i64 i = n-1; i > 0; --i) {
        if (mod >= 1e13) {
            ans.push_front(i);
            continue;
        }

        i64 res = k % mod;
        if (res) {
            ans.push_back(i);
        } else {
            ans.push_front(i);
        }

        k -= res;
        mod *= 2;
    }
    if (k) {
        cout << -1 << endl;
    } else {
        for (auto ai : ans) {
            cout << ai << " ";
        }cout << endl;
    }

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