// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    i64 n, c;
    cin >> n >> c;
    vector<i64> a(n);
    input(a);
    
    auto max_ele = max_element(all(a));
    int max_i = max_ele - a.begin();
    int max_val = *max_ele;
    vector<int> ans(n, n);
    if (max_val > (a[0] + c)) ans[max_i] = 0;
    i64 s = c;
    vector<i64> max_list(n+1);
    max_list[n] = -1;
    for(int i = n - 1; i >= 0; --i) {
        max_list[i] = max(max_list[i+1], a[i]);
    }
    for (int i = 0; i < n; ++i) {
        // if (i == )
        a[i] = s + a[i];
        if (a[i] >= max_list[i+1]) {
            ans[i] = min(ans[i], i);
        } else {
            ans[i] = min(ans[i], i+1);
        }
        s = a[i];
    }

    for (auto ansi : ans) {
        cout << ansi << " ";
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