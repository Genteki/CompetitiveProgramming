#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    input(a);
    input(b);

    vector<bool> viewed(n + 1, false);
    int j = 0;
    bool good = true;

    for (int i = 0; i < m; ++i) {
        if (viewed[b[i]]) continue;

        if (a[j] == b[i]) {
            viewed[a[j]] = true;
            ++j;
        } else {
            good = false;
            break;
        }
        if (j >= n) break;
    }

    if (good)
        cout << "YA\n";
    else
        cout << "TIDAK\n";
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}