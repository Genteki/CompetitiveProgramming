#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n ;
    cin >> n;
    vector<int> a(n-1);
    input(a);

    struct node {
        vector<int> sub;
        int n_sub = 0;
    };

    vector<node> b(n);
    for (int i = 0; i < n-1; ++i) {
        b[a[i]-1].sub.push_back(i+1);
    }

    auto bfs = [&](auto &&self, int x) -> void {
        if(b[x].sub.empty()) {
            b[x].n_sub = 0;
        } else {
            b[x].n_sub = b[x].sub.size();
            for (int y : b[x].sub) {
                self(self, y);
                b[x].n_sub += b[y].n_sub;
            }
        }
    };
    bfs(bfs, 0);
    for (auto bi : b) {
        cout << bi.n_sub << " ";
    }
    cout << endl;
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