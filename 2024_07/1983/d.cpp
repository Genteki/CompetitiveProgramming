#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), ia(200001, -1), ib(200001, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ia[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ib[b[i]] = i;
    }
    i64 cnt = 0;
    // cout << ia[7] << endl; 
    for (int i = 0; i < n; ++i) {
        int iat = ia[b[i]];
        if (iat == -1) {
            cout << "NO" << endl;
            return;
        }
        if (iat != i) cnt = cnt + 1;
        // cnt = cnt + 1;
        swap(a[i], a[iat]);
        ia[a[iat]] = iat;
        ia[a[i]] = i;
        // cout << cnt << " ";
    }
    if (cnt % 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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