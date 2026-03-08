#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, a;
    cin >> n >> a;
    vector<int> t(n);
    input(t);
    i64 s = 0;
    for (auto &ti : t) {
        if (s <= ti) {
            s = ti + a;
            cout << s << endl;
        } else {
            s = s + a;
            cout << s << endl;
        }
    }
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