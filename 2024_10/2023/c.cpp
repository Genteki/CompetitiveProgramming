// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        if (min(a.first, a.second) < min(b.first, b.second)) return true;
        else if (min(a.first, a.second) == min(b.first, b.second)) {
            if (max(a.first, a.second) < max(b.first, b.second)) return true;
        }

            return false;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto & ai : a) {
        cin >> ai.first >> ai.second;
    }
    sort(all(a), comp());
    for (auto & ai : a) {
        cout << ai.first << " " << ai.second << " ";
    }
    cout << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}