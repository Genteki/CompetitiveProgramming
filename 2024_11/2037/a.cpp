#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    vector<int> a(22);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] += 1;
        if (a[x] == 2) {
            a[x] = 0;
            ans++;
        }
    }
    cout << ans << endl;
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