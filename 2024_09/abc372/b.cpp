// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    vector<int> x(11, 1);
    for (int i = 1; i < 11; ++i) {
        x[i] = x[i-1] * 3;
    }
    int m;
    cin >> m;
    vector<int> ans;
    int k = 10;
    while(m > 0) {
        while(x[k] > m) k--;
        m -= x[k];
        ans.push_back(k);
    }
    cout << ans.size() << endl;
    for (auto ai : ans) cout << ai << " ";
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