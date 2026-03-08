#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int l = -1, r = -1;
    int n;
    cin >> n;
    int ans = 0;
    for (;n--;) {
        int x; char c;
        cin >> x >> c;
        if (c == 'L') {
            if (l == -1) {
                l = x;
            } else {
                ans += abs(l - x);
                l = x;
            }
        } else {
            if (r == -1) {
                r = x;
            } else {
                ans += abs(r - x);
                r = x;
            } 
        }
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