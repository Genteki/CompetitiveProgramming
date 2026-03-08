// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    input(a);
    vector<int> b(n, -1), c(n, -1);
    int d = -1, e = INT_MAX;
    int t = k * 2;
    int x = *max_element(all(a));
    for (auto & ai : a) {
        int l = (x - ai) / t;
        int s = ai + t * l;
        if (s + k > x) {
            d = max(d, x);
            e = min(e, s + k);
        } else {
            d = max(d, s + 2 * k);
            e = min(e, x + k);
        }
    }
    if (d < e) {
        cout << d << endl;
    } else {
        cout << -1 << endl;
    }

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