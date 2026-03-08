#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    input(a);
    int s = accumulate(all(a), 0);
    int t = r * 2 - s;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = ans + (a[i] / 2) * 2;
        if (a[i] % 2) {
            if (t) {
                t--;
                ans++;
            }
        } 
    }
    cout << ans << endl;
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