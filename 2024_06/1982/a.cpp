#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    i64 x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if (x1 > y1) {
        swap(x1, y1);
        swap(x2, y2);
    }
    
    // if (x2 > y1) {
    //     cout << "NO\n";
    // } else if (x2 < y1) {
    //     cout << "YES\n";
    // } else {
    //     if (y2 > y1) {
    //         cout << "NO\n";
    //     } else {
    //         cout << "YES\n";
    //     }
    // }
    if (y2 > x2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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