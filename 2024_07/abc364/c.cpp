// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n, x, y;
    cin >> n >> x >> y;
    vector<i64> a(n), b(n);
    input(a);
    input(b);
    sort(all(a), std::greater<i64>());
    sort(all(b), std::greater<i64>());

    vector<i64> sa(n+1, 0), sb(n+1, 0);
    for (int i = 0; i < n; ++i) {
        sa[i + 1] = sa[i] + a[i];
        sb[i + 1] = sb[i] + b[i];
        if (sa[i+1] > x || sb[i+1] > y) {
            cout << (i + 1);
            return;
        }
    }

    cout << n;


    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}