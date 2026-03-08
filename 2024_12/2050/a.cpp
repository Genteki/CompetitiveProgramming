#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    int x = 0, y = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i] = s.size();
    }

    for (auto ai : a) {
        if (ai + x <= m) {
            x += ai;
            y++;
        } else break;
    }
    cout << y << endl;
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