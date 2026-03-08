// d.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    vector<pair<int,int>> ans;
    vector<bool> used(n, false);
    for (int mod = n-1; mod >= 1; --mod) {
        vector<int> p(n, -1);
        for (int i = 0; i < n; ++i) {
            if (used[i] == false) {
                int t = a[i] % mod;
                if (p[t] == -1) {
                    p[t] = i;
                } else {
                    ans.emplace_back(i + 1, p[t] + 1);
                    used[i] = true;
                    break;
                }
            }
        }
    }
    cout << "YES" << endl;;
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        cout << it -> first << " " << it -> second << endl;
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