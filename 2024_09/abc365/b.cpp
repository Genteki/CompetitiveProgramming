// b.cpp
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
    int ia = 0, ib = 1, va = a[0], vb = a[1];
    if (va < vb) {
        swap(ia, ib);
        swap(va, vb);
    }
    for (int i = 2; i < n; ++i) {
        if (a[i] > va) {
            vb = va;
            ib = ia;
            ia = i;
            va = a[i];
        } else if (a[i] > vb) {
            ib = i;
            vb = a[i];
        }
    }
    cout << (ib + 1);
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}