// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    string s;
    cin >> s;
    for (auto & si : s) {
        if (si == 'p') si = 'q';
        else if (si == 'q') si = 'p';
    }
    reverse(all(s));
    cout << s <<  endl;
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