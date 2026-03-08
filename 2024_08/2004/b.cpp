#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int al, ar, bl, br;
    int ans = 0;
    cin >> al >> ar >> bl >> br;
    if (ar < bl || br < al) {
        ans = 1;
    } else if ((al <= bl && ar >= br)) {
        ans = br - bl + !(al == bl) + !(ar == br);
    } else if (al >= bl && ar <= br) {
        ans = ar - al + !(al == bl) + !(ar == br);
    } else {
        ans = min(ar, br) - max(al, bl) + !(al == bl) + !(ar == br);
    }
    cout << ans << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}