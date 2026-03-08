// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;
    auto func = [](int x1, int x2, int y1, int y2) -> bool {
        if (x1 > y1) {
            swap(x1, y1);
            swap(x2, y2);
        }
        return x2 > y1;
    };

    if (func(a, d, g, j) && func(b, e, h, k) && func(c, f, i, l)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
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