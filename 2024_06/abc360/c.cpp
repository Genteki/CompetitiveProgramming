#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), w(n);
    input(a); 
    input(w);

    vector<i64> box(n, 0);
    vector<i64> boxs(n, 0);
    for (int i = 0; i < n; ++i) {
        int boxi = a[i] - 1;
        box[boxi] = max(w[i], box[boxi]);
        boxs[boxi] += w[i];
        // cout << boxs[boxi] << endl;
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = ans + boxs[i] - box[i];
    }
    cout << ans;
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