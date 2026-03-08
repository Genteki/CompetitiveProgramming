#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    map<char,char> mp = {{'S', 'N'}, {'N', 'S'}, {'W', 'E'}, {'E', 'W'}};
    for (auto si : s) cout << mp[si];
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}