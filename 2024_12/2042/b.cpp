// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n+1, 0);
    input(a);
    for (auto ai : a) {
        c[ai]++;
    }
    sort(all(c));
    int score = 0, cnt= 0;
    for (auto ci : c) {
        if (ci == 1) cnt++;
        else if (ci > 1) score++;
    }
    score += ((cnt+1)/2 * 2);
    cout << score << endl;
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