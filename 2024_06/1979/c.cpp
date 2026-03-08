// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve(i64 lcm20 ) {
    int n;
    cin >> n;
    vector<int> a(n), b(n, 0);
    input(a);
    i64 x = 0;
    for (int i = 0; i < n; ++i) {
        x += (lcm20 / a[i]);
        b[i] = lcm20 / a[i];
    }
    if (x >= lcm20) {
        cout <<-1<< endl;
        return;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << (b[i]+1) << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 lcm20 = 1;
    for (int i = 2; i <=20; ++i) {
        lcm20 = lcm(lcm20, i);
    }
    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve(lcm20);
    }
}