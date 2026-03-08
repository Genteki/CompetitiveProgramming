#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n ;
    cin >> n;
    vector<i64> a(n);
    input(a);
    for (i64 & ai : a) {
        if ((ai % 2)!= (a[0] % 2)) {
            cout << -1 << endl;
            return;
        }
    }
    i64 x = *max_element(all(a));
    i64 y;
    vector<i64> c;
    for (i64 i = 0; i < 32; ++i) {
        if ((1LL << i) >= x) {
            y = i;
            break;
        }
    }
    y -= 1;
    y = max(0LL, y);
    for (i64 i = 0; i <= y; ++i) {
        c.push_back((1LL << (y-i)));
        x = abs(x - (1LL << (y-i)));
    }
    if (x) c.push_back(1);
    cout << c.size() << endl;
    for (auto ci : c ) cout << ci << " "; cout << endl;
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}