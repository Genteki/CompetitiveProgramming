// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int x, y;
    int a, b;
    cin >> x >> y;
    a = max(x,y); b = min(x,y);
    int p = a ^ b;
    int c = 0;
    for (int i = 0; i < 31; ++i) {
        if (p & (1 << i)) {
            c = i;
            break;
        }
    }

    // c = i;
    cout << (1 << c) << endl;
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