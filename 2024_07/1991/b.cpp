#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n-1);
    input(b);
    vector<int> a(n);

    a[0] = b[0];
    a[n-1] = b[n-2]; 
    for (int i = 1; i < n-1; ++i) {
        a[i] = b[i-1] | b[i];
        if ((a[i] & a[i-1]) != b[i-1]) {
            
            cout << -1 << endl;
            // cout << i << "," <<( a[i] & a[i - 1]) << endl;
            return;
        }
    }
    for (auto ai : a) cout << ai << " ";
    cout << endl;
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