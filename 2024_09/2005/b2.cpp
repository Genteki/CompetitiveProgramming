// b2.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 m = 2, q = 1, n;
    cin >> n >> m >> q;
    vector<i64> t(m);
    input(t);
    vector<i64> query(q);
    input(query);

    sort(all(t));
    
    for (auto qi : query) {
        if (qi > t.back()) {
            cout << (n - t.back());
        } else if (qi < t.front()) {
            cout << (t.front() - 1);
        } else {
            // auto itl = lower_bound(all(t), qi);
            auto itr = upper_bound(all(t), qi);
            cout << (*itr - *prev(itr)) / 2 ;
        }
        cout << endl;
    }
    return;
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