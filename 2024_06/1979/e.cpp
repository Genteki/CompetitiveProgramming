// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, d;
    cin >> n >> d;
    vector<pair<int,int>> points(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    vector<unordered_set<int>> v(n);
    for (int i = 0; i < n; ++i) {
        int px = points[i].first;
        int py = points[i].second;
        for (int j = i + 1; j < n; ++j) {
            if (abs(points[j].first - px) + abs(points[j].second - py) == d) {
                v[i].insert(j);
                v[j].insert(i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (v[i].size()>=2) {
            for (int j : v[i]) {
                if (v[j].size() >= 2) {
                    for (int k : v[j]) {
                        if (v[k].find(i) != v[k].end()) {
                            cout << (i+1) << " " << (j+1) << " " << (k+1) << endl;
                            return;
                        }
                    }
                }
                v[i].erase(j);
                v[j].erase(i);
            }
        }
    }
    cout << "0 0 0\n";
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