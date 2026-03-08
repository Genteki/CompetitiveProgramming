#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) \
    for (auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    cin >> n;

    vector<int> a(n * n);
    int mx;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char r;
            cin >> r;
            int s = r - '0';
            a[i + j * n] = s;
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int d = 0; d < 8; ++d) {
                int x = i;
                int y = j;
                vector<int> s = {a[x + y * n]};
                for (int k = 0; k < n - 1; ++k) {
                    x += dx[d];
                    y += dy[d];
                    if (x >= n)
                        x -= n;
                    else if (x < 0)
                        x += n;
                    if (y >= n)
                        y -= n;
                    else if (y < 0)
                        y += n;

                    s.push_back(a[x + y * n]);
                }
                i64 this_ans = 0;
                for (auto it = s.rbegin(); it != s.rend(); ++it) {
                    this_ans = this_ans * (i64)10 + *it;
                }
                ans = max(ans, this_ans);
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
    //    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}