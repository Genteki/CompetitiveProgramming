#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    int s = 0, t = 0;
    while(n--) {
        int ti, si;
        cin >> ti >> si;
        s = s - (ti - t);
        s = max(0, s);
        s += si;
        t = ti;
    }
    cout << s;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}