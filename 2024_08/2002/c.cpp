#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    i64 xs, xt, ys, yt;
    cin >> xs >> ys >> xt >> yt;
    i64 t = (xs- xt) * (xs - xt) + (ys-yt) * (ys - yt);
    vector<i64> ds2(n), dt2(n);
    bool good = true;
    for (int i = 0; i < n; ++i) {
        ds2[i] = (x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys);
        dt2[i] = (x[i] - xt) * (x[i] - xt) + (y[i] - yt) * (y[i] - yt);
    }
    // for (auto di : dt2) cout << di << " "; cout << endl;
    i64 md1 = *min_element(all(ds2));
    i64 md2 = *min_element(all(dt2));
    if (md1 > 0) {

        // cout << "YES";
        if (md2 > t) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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