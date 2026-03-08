#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
constexpr int d = 'A' - 'a';
void solve() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    string t = a;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (c[i] != a[i] && c[i] != b[i]) {
                cout << "YES" << endl;
                return;
            }
        } else if (a[i] == b[i]) {
            if (c[i] != a[i]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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