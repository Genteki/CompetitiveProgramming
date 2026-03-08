#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(4, n);
    int ans = 0;
    for (int i = 0; i < n * 4; ++i) {
        if (s[i] == '?') {
            continue;
        } else {
            int j = s[i] - 'A';
            if (a[j]) {
                a[j]--;
                ans++;
            }
        }
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