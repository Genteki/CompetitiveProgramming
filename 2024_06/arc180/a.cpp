#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;
typedef long long i64;
constexpr i64 mod = 1e9 + 7;

void solve() {
    string s;
    int n;
    cin >> n;
    cin >> s;
    vector<i64> a;
    int i = 0;
    int count = 1;
    while (i < n - 1) {
        if (s[i] != s[i + 1]) {
            ++count;
        } else {
            a.push_back(count);
            count = 1;
        }
        ++i;
    }
    a.push_back(count);
    // for (auto ai : a) cout << ai << " ";
    i64 ans = 1;
    for (auto ai : a) {
        ans = ((ai + 1) / 2) * ans;
        ans %= mod;
    }
    cout << ans;
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