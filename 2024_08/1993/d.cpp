// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    vector<int> v(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        a[i] = {v[i], i};
    }
    sort(all(a));
    for (int i = 0; i < n; ++i) {
        b[a[i].second] = i;
    }
    int m = (n - 1) % k + 1;
    

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