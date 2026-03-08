#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    if (n == 2) {
        cout << (a[0]*10 + a[1]) << endl;
        return;
    } else if (n == 3) {
        int ans = min({
            a[0] * 10 + a[1] + a[2],
            a[0] + a[1] * 10 + a[2],
            (a[0] * 10 + a[1]) * a[2],
            a[0] * (a[1] * 10 + a[2])
        });
        cout << ans << endl;
        return;
    }
    i64 ans = -1;
    for (int i = 0; i < n-1; ++i) {
        vector<int> b;
        for (int j = 0; j < n; ++j) {
            int x;
            if (j == i) {
                x = a[j] * 10 + a[j+1];
            } else if (j == i + 1) {
                continue;
            } else {
                x = a[j];
            }
            if (x == 0) {
                cout << 0 << endl;
                return;
            } else if (x == 1) {
                continue;
            } else {
                b.push_back(x);
            }
        }
        i64 product = accumulate(all(b), 0);
        
        if (ans == -1) ans = product;
        else ans = min(product, ans);
    }
    cout << ans << endl;

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