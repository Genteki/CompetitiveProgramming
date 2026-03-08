// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n; i64 x;
    cin >> n >> x;
    vector<i64> a(n), b(n);
    for(int i = 0; i< n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<i64> c(n);
    i64 min_game_time = INT_MAX;
    i64 ans = __LONG_LONG_MAX__;
    i64 t = 0;
    for(int i = 0; i < n; ++i) {
        min_game_time = min(min_game_time, b[i]);
        x--;
        t = t + a[i] + b[i];
        ans = min(ans, min_game_time * x + t);
    }
    cout << ans << endl;
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