#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    input(a);
    input(b);
    bool all = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            all = false;
        }
    }
    bool allv = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[n-1-i]) {
            allv = false;
        }
    }
    if (all || allv) {cout << "Bob" << endl;}
    else cout << "Alice" << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}