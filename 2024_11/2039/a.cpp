#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    a[0] = 2;
    for (int i = 1; i < n; ++i) {
        a[i] = (a[i-1] + i) / (i + 1) * (i + 1) + i;
        if (a[i] - (i + 1) > a[i-1]) a[i] -= (i + 1);
    }
    for (auto ai : a) cout << ai << " ";
    cout << endl;
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