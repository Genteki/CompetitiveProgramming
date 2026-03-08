#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    string a, b;
    cin >> a >> b;
    int sa = a.size(), sb = b.size();
    vector<int> x(sb);
    for (int i = 0; i < sb; ++i) {
        int &t = x[i];
        int j = i, k = 0;
        while(j < sb && k < sa) {
            if (a[k] == b[j]) {
                ++j; ++k;
            } else {
                ++k;
            }
        }
        t = j-i;
    }
    // for (int xi : x) cout << xi << " "; cout << endl;
    int ans = sa + sb - *max_element(all(x));
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