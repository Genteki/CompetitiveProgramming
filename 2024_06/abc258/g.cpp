#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<bitset<3000>> v(n, 0);
    for (int i = 0;i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char x;
            cin >> x;
            if (x == '1') {
                v[i][j] = 1;
            }
        }
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            if (v[i][j]) {
                auto tmp = v[i] & v[j];
                // cout << tmp.count() << endl;
                ans += (tmp.count());
            }
        }
    }

    cout << (ans/6) << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}