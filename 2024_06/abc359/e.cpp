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
    vector<i64> a(n);
    input(a);
    vector<i64> ans(n, 0);
    stack<pair<i64, int>> q;
    q.push({inf, -1});
    for (int i = 0; i < n; ++i) {
        while (q.top().first < a[i]) {
            q.pop();
        }
        if (q.top().second == -1) {
            ans[i] = (i + 1LL) * a[i];
            q.push({a[i], i});
        } else {
            int prev = q.top().second;
            ans[i] = ans[prev] + a[i] * (i - prev);
            q.push({a[i], i});
        }
    }
    for (i64& ansi : ans) cout << (ansi+1LL) << " ";
    cout << endl;
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