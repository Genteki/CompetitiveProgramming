#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a, ans;
    for (i64 i = 0; i < 62; ++i) {
        if (n & (1LL << i) ) {
            a.push_back(i);
        }
    }
    ans.push_back(n);
    for (auto & ai : a) {
        i64 ansi = n;
        ansi = ansi ^ (1LL << ai);
        ans.push_back(ansi);
    }
    reverse(all(ans));
    if (a.size() == 1) {
        cout << 1 << endl;
        cout << n << endl;
        return;
    }
    cout << (a.size() + 1) << endl;

    for (auto ansi : ans) cout << ansi << " ";
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