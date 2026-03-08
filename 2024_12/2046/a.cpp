#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    int ans = 0, cnt = 1, sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        while(cnt * cnt < sum) {
            cnt+=2;
        }
        if (cnt * cnt == sum) ++ans;
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