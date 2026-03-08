// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    int p = n - 2;
    map<int, int> mp;
    for (auto ai : a) {
        if (p % ai == 0 && mp[p/ai]) {
            cout << p/ai << " " << ai << endl;
            return;
        }
        mp[ai]++;
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}