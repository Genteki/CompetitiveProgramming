// a.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int r, g, b;
    cin >> r >> g >> b;
    string s;
    cin >> s;
    if (s == "Red") {
        cout << min(g, b);
    } else if (s == "Green") {
        cout << min(r, b);
    } else {
        cout << min(r, g);
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