// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    input(a); input(b);

    sort(all(a));
    sort(all(b));

    int i = 0; int j = 0;
    i64 s = 0;
    while(i < n && j < m) {
        if (a[i] >= b[j]) {
            s += a[i];
            ++i; 
            ++j;
        } else {
            ++i;
        }
    }
    if (j == m) {
        cout << s<< endl;
    } else {
        cout << -1 << endl;
    }
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