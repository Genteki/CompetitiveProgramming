#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n), cc(n);
    for(int i =0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        a[x].push_back(y);
        a[y].push_back(x);
    }
    

    vector<int> viewed(n, 0), cc_start_pt;
    for (int i = 0; i < n; ++i) {
        if (!viewed[i]) {
            stack<int> s;
            s.push(i);
            viewed[i] = 1;
            cc_start_pt.push_back(i);
            while(!s.empty()) {
                int node = s.top();
                cc[i].push_back(node);
                s.pop();
                for (int son : a[node]) {
                    if (!viewed[son]) {
                        s.push(son);
                        viewed[son] = 1;
                    }
                }
            }
        }
    }
    // for (auto cci : cc) {
    //     if(cci.size() > 0) {for (auto ccii : cci) {
    //         cout << ccii << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    cout << (cc_start_pt.size() - 1) << endl;
    for (int i = 1; i < cc_start_pt.size(); ++i) {
        cout << (cc_start_pt[0]+1) << " " << (cc_start_pt[i]+1) << endl;
    }
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