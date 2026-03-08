#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    input(a);
    sort(all(a));
    int s = 0;
    for (int i = n-1; i >=0; --i) {
        if (s + a[i] <= k) {
            s += a[i];
        } else {
            break;
        }
    }
    cout << (k-s) << endl;
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