#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n, 1);
    for (int i = n; i >= 2; --i) {
        int t = i;
        while(t <= n) {
            if (a[t-1] % t != 0) {
                a[t-1] *= t;
            }
            t += i;
        }
    }
    for (auto ai : a) cout << ai << " ";
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