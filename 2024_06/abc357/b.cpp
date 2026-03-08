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
    int m = (n+1) / 2;
    int cnt = 0;
    for (char &si : s) {
        if (si >= 'a' && si <= 'z') {
            ++cnt;
            si = (si - 'a') + 'A';
        }
    }
    if (cnt >= m) {
        for (char & si : s) {
            si = (si -'A') + 'a';
        }
    }
    cout << s << endl;
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
