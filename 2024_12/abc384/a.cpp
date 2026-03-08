#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    char c1, c2;
    string s;
    cin >> n >> c1 >> c2;
    cin >> s;
    for (auto & si : s) {
        if ( si != c1) {
            si = c2;
        }
    }
    cout << s;
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