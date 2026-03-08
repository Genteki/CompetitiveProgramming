#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> edges;
    set<int> s;
    vector<int> viewed(n, false);
    viewed[0] = true;
    int i , j = 0;
    int k;

    while(edges.size() < n - 1) {
        for (int v = 0; v < n; ++v) {
            if (!viewed[v]) {
                i = v;
                break;
            }
        }
        flush;
        k = -1;
        j = 0;
        while(k != i) {
            if (k != -1) j = k;
            cout << "? " << (i+1) << " " << (j+1) << endl;
            flush;
            cin >> k;
            --k;
        }

        edges.emplace_back(j, i);
        viewed[i] = true;
        // for (auto ai : viewed) cout << ai; cout << endl;
    }
    cout << "! ";
    for (auto [i, j] : edges) cout << (i + 1) << " " << (j + 1) << " ";
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