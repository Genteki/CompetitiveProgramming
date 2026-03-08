// b.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);
    input(a);
    // odd
    i64 odd_max = -1;
    i64 even_max = -1;
    i64 cnt = 0;
    vector<int> b;
    for (auto & ai : a) {
        if (ai % 2) {
            odd_max = max(ai, odd_max);
        } else {
            even_max = max(even_max, ai);
            b.push_back(ai);
            ++cnt;
        }
    }
    sort(all(b));
    if (odd_max == -1 || even_max == -1) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] > odd_max) {
            cout << (cnt + 1) << endl;
            return;
        } else {
            odd_max += b[i];
        }
    }
    if (odd_max > even_max ) {
        cout << cnt << endl;
    } else {
        cout << (cnt+1) << endl;
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