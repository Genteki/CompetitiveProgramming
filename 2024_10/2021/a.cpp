#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    multiset<i64> ms;

    for (int i = 0; i < n; ++i) {
        i64 x;
        cin >> x;
        ms.insert(x);
    }

    for (int i = 0; i < n - 1; ++i) {
        auto it1 = ms.begin(); 
        i64 x = *it1;
        ms.erase(it1);  

        auto it2 = ms.begin();  
        i64 y = *it2;
        ms.erase(it2); 

        i64 z = (x + y) / 2;
        ms.insert(z); 
    }

    cout << *ms.begin() << endl;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}