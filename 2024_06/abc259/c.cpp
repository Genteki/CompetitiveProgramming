// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    vector<pair<char, int>> v1, v2;
    string s, t;
    cin >> s >> t;
    for (auto & si : s) {
        if (v1.empty() || v1.back().first != si) {
            v1.push_back({si, 1});
        } else {
            v1.back().second++;
        }
    }
    for (auto& ti : t) {
        if (v2.empty() || v2.back().first != ti) {
            v2.push_back({ti, 1});
        } else {
            v2.back().second++;
        }
    }

    if (v1.size() != v2.size()) {
        cout << "No";
        return;
    }

    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i].first == v2[i].first) {
            if (v1[i].second == v2[i].second) {
                continue;
            } else {
                if (v1[i].second >= 2 && v2[i].second >= v1[i].second) {
                    continue;
                }
            }
        }
        // cout << i << endl;
        cout << "No";
        return;
    }
    cout <<"Yes";
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