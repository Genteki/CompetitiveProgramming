#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n ;
    cin >> n;
    string s, t;
    cin >> s >> t;
    bool has1 = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            has1 = true;
        }
        if (s[i] == '0' && t[i] == '1') {
            if (!has1) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}