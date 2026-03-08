#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; i += 2) {
        ans1 = max(ans1, a[i]);
    }
    ans1 += ((n+1)/2);
    for (int i = 1; i < n; i+=2) {
        ans2 = max(ans2, a[i]);
    }
    ans2 += (n / 2);
    cout << max(ans1, ans2) << endl;
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