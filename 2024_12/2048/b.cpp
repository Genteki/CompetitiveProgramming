// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n, -1), used(n, 0);
    int j = 1;
    for (int i = k-1; i < n; i += k) {
        p[i] = j;
        ++j;
    }
    for (int i = n -1; i >= 0; --i) {
        if (p[i] == -1) {
            p[i] = j;
            ++j;
        }

    }
    for (auto ai : p) {
        cout << ai << " ";
    } cout << endl;
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