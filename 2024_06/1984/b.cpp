#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (s[0] != '1') {
        cout << "NO" << endl;
        return;
    } else if (s.back()=='9') {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i < n - 1; ++i) {
        if (s[i] == '0') {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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