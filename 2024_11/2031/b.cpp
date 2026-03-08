// b.cpp
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
    for (int i = 0; i < n-1; ++i) {
        if (a[i] == a[i + 1] + 1) {
            swap(a[i], a[i + 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != i + 1) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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