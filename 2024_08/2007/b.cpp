#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<i64> a(n);
    input(a);
    int p = *max_element(all(a));
    for (;m--;) {
        int l, r;
        char c;
        cin >> c >> l >> r;
        if (l <= p && r >= p) {
            if (c == '+') {
                ++p;
            } else {
                --p;
            }
        }
        cout << p << " ";
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