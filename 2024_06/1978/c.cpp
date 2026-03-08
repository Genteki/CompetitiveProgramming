#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    i64 n, k;
    cin >> n >> k;
    if (k % 2 == 1) {
        cout << "no" << endl;
        return;
    }

    // i64 max_val = ((n+1)/2 + n) * (n - (n+1)/2 + 1);
    // if (k > max_val) {
    //     cout << "no" << endl;
    //     return;
    // }
    i64 p = k / 2;
    i64 q = 0;
    while (p > ((n-q) - (1+q))) {
        if (((n-q) - (1+q)) <= 0) {
            cout << "no" << endl;
            return;
        }
        p -= ((n - q) - (1 + q));
        ++q;
    }
    cout << "yes" << endl;

    // cout << " " << q << endl;
    for (i64 i = 0; i < q; ++i) {
        cout << (n - i) << " ";
    }
    if (p > 0) {
        cout << (q + 1 + p) << " ";
        i64 y = q + 2;
        for (i64 i = 0; i < n - 2 * q - 1; ++i) {
            if (y == (q + 1 + p)) {
                ++y;
                cout << (q + 1) << " ";
            }
            else {
                cout << y << " ";
                ++y;
            }
        }
        // cout << (q + 1) << " ";
    } else {
        for (i64 i = 0; i < n - 2 * q; ++i) {
            cout << (q + 1 + i) << " ";
        }
    }
    for (i64 i = 0; i < q; ++i) {
        cout << (1+i) << " ";
    }
    cout << endl;

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