#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    input(a);
    input(b);
    int ra = 0, rb =0, minus = 0, plus = 0;
    for(int i = 0; i < n; ++i) {
        if (a[i] == 1 && b[i] <= 0) {
            ra++;
        } else if (b[i] == 1 && a[i] <= 0) {
            rb++;
        } else if (a[i] == 1 && b[i] == 1) {
            plus++;
        } else if (a[i] == -1 && b[i] == -1) {
            minus++;
        }
    }
    if (ra < rb) {
        swap(ra, rb);
    }
    // cout << (-3/2) << endl;
    int diff = ra - rb;
    int ans;
    if (plus + minus >= diff) {
        ans = (ra + rb - minus + plus);
        if (ans >=0) ans /= 2;
        else ans = (ans-1)/2;
    } else {
        ans = rb + plus;
    }
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