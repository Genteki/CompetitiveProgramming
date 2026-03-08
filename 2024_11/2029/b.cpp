// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    string s, r;
    cin >> n ;
    cin >> s >> r;
    int zero = 0, one = 0;
    for (auto si : s) {
        if (si == '0') {
            zero++;
        } else {
            one++;
        }
    }
    for (auto ri : r) {
        if (zero <= 0 || one <= 0) {
            cout << "NO" << endl;
            return;
        } else {
            if (ri == '0') {
                one--;
            } else {
                zero--;
            }
        }
    }
    cout << "YES" << endl;
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