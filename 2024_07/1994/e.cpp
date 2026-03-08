// e.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

struct comp { 
    bool operator()(int a, int b) const { return a > b; } 
} greatc;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> trees(n);
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        s[i] = m;
        trees[i].resize(m-1);
        input(trees[i]);
    }

    sort(all(s));
    int ans = s.back();
    s.pop_back();
    reverse(all(s));
    int h = 0;
    for (int i = 0; i < 22; ++i) {
        if (ans & (1 << i)) {
            h = i;
        }
    }
    for (auto ansi : s) {
        int hi = 0;
        for (int i = 0; i < 22; ++i) {
            if (ans & (1 << i)) {
                hi = i;
            }
        }
        for (int j = hi; j >= 0; --j) {
            if ((ans & (1 << j)) && (ansi & (1 << j))) {
                for (int k = j-1; k >= 0; --k) {
                    ans |= (1 << k);
                }
                break;
            } else if (!(ans & (1 << j)) && (ansi & (1 << j))) {
                ans |= (1 << j);
            }
        }
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