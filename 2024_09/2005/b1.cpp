// b1.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
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
        if (qi < t[1] && qi > t[0]) {
            cout << ((t[1] - t[0]) / 2);
        } else if (qi < t[0]) {
            cout << (t[0] - 1);
        } else {
            cout << (n - t[1]);
        }
    }
    cout << endl;
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