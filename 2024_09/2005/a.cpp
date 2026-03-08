#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    int k = n / 5;
    for (int i = 0; i < 5; ++i) {
        if (k * 5 + i < n) {
            cout << string(k + 1, v[i]);
        } else {
            cout << string(k, v[i]);
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