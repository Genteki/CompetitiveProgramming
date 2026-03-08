#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    i64 x, y, k;
    cin >> x >> y >> k;
    while(x != 1) {
        int mod = x % y;
        int step = y - mod;
        if (k < step) {
            cout << (x + k) << endl;
            return;
        } else if (k >= step) {
            x += step;
            k -= step;
            while (x % y == 0) x /= y;
            if (k == 0) {
                cout << x << endl;
                return;
            }
        }
    }

    k = k % (y-1);
    x = x + k;
    cout << x << endl;
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