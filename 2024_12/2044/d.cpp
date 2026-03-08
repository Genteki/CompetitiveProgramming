// d.cpp
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
    vector<int> viewed(n+1, 0), vieweda(n + 1, 0);
    for (auto ai : a) vieweda[ai] = 1;
    vector<int> b(n);
    int j = 1;
    for (int i = 0; i < n; ++i) {
        if (!viewed[a[i]]) {
            b[i] = a[i];
            viewed[b[i]] = 1;
        } else {
            while((viewed[j]) || (vieweda[j])) {
                ++j;
            }
            b[i] = j;
            viewed[j] = 1;
        }
    }
    for (auto bi : b) cout << bi << " ";
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