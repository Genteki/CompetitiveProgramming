// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n, -1);
    int cur;
    int zeros = -1;
    cout << "? 1 " << n << endl;
    cout.flush();
    cin >> cur;
    if (cur == 0) {
        cout << "! IMPOSSIBLE\n";
        cout.flush();
        return;
    }
    for (int i = n - 1; i > 1; --i) {
        cout << "? 1 " << i << endl;
        cout.flush();
        int x;
        cin >> x;
        if (x < cur) {
            ans[i] = 1;
            if (x == 0) {
                for (int j = 0; j < i - cur; ++j) ans[j] = 1;
                for (int j = i - cur; j < i; ++j) ans[j] = 0;
                cur = 0;
                break;
            }
            cur = x;

        } else if (x == cur) {
            ans[i] = 0;
        }

    }
    if (cur == 1) {
        ans[0] = 0;
        ans[1] = 1;
    }
    cout << "! ";
    for (auto ai : ans) cout << ai;
    cout << endl;
    cout.flush();

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