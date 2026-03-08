// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    int ans = 0;
    vector<int> order(26);
    for (int i = 0; i < s.size(); ++i) {
        order[s[i] - 'A'] = i;
    }
    for (int i = 0; i < 25; ++i) {
        ans += abs(order[i] - order[i+1]);
    }
    cout << ans;
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