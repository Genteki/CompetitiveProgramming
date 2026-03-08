#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
map<char, int> g = {
    {'B', 0},
    {'G', 1},
    {'R', 2},
    {'Y', 3}
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> color(4);
    vector<vector<int>> dual(16);
    vector<vector<int>> a(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        char c1 = g[s[0]], c2 = g[s[1]];
        // color[c1].push_back(i);
        // color[c2].push_back(i);
        a[i][0] = c1;
        a[i][1] = c2;
        dual[c1 * 4 + c2].push_back(i);
        dual[c2 * 4 + c1].push_back(i);
    }

    // for (auto ai : dual) {
    //     for (auto aii : ai) {
    //         cout << aii << " ";
    //     }cout << endl;
    // }

    auto find = [&](int i, int from, int to) -> int {
        auto& vec = dual[from * 4 + to];
        auto it = std::lower_bound(all(vec), i);
        if (it == vec.end()) {
            return (vec.size()-1);  // Return last element if 'i' is beyond the range
        } else if (it == vec.begin()) {
            return 0; // Return first element if 'i' is smaller
        } else {
            int idx1 = *it;
            int idx2 = *(it - 1);
            return (it - 1 - vec.begin());
        }
    };
        // for (auto aii : dual[1 * 4 + 2]) {
        //     cout << aii << " ";
        // }cout << endl;

    while(q--) {
        int src, dst;
        cin >> src >> dst;
        --src; --dst;
        int from1 = a[src][0], from2 = a[src][1];
        int to1 = a[dst][0], to2 = a[dst][1];
        i64 ans = INT64_MAX;
        // cout << from1 << from2 << to1 << to2 << endl;
        if (from1 != to1 && from1 != to2 && from2 != to2 && from2 != to1) {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    int from = a[src][i], to = a[dst][j];
                    if (dual[from * 4 + to].empty()) continue;
                    int idx = find(src, from, to);
                    ans =
                        min<i64>(ans, abs(dst - dual[from * 4 + to][idx]) +
                                          abs(src - dual[from * 4 + to][idx]));
                    if (idx + 1 < dual[from * 4 + to].size()) {
                        ++idx;
                        ans = min<i64>(ans,
                                       abs(dst - dual[from * 4 + to][idx]) +
                                           abs(src - dual[from * 4 + to][idx]));
                    }
                    idx = find(dst, from, to);
                    ans = min<i64>(ans, abs(dst - dual[from * 4 + to][idx]) + abs(src - dual[from * 4 + to][idx]));
                    if (idx+1 < dual[from * 4 + to].size()) {
                        ++idx;
                        ans = min<i64>(ans,
                                       abs(dst - dual[from * 4 + to][idx]) +
                                           abs(src - dual[from * 4 + to][idx]));
                    }
                    // cout << from << " " << to << " " << dual[from * 4 + to][idx] << " " << ans << "\n";
                }
            }
            if (ans == INT64_MAX) {
                cout << -1 << endl;
            } else {
                cout << ans << endl;
            }
        } else {
            cout << abs(src - dst) << endl;
        }
    }

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