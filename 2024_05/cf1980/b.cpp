#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n);
    input(a);

    if (k == n) {cout << "YES" <<endl;return;}
    int fav = a[f-1];
    int x, y, z;
    sort(all(a));
    reverse(all(a));
    if (a[k-1] > fav) {
        cout << "NO";
    } else if (a[k-1] < fav) {
        cout << "YES";
    } else {
        if (a[k]==fav) {
            cout << "MAYBE";
        } else {
            cout << "YES";
        }
    }
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