#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
int N = (1 << 18) + 1;
vector<bool> prime(N, true);

void solve() {
    int n;
    cin >> n;
    vector<int> g(n);
    int l = -1;
    for (int i = 0; i <= 20; ++i) {
        if ((1 << i) > n) {
            l = i;
            break;
        }
    }
    vector<int> ps;
    for (int i = 2; i < (1 << l); ++i) {
        if (prime[i]) ps.push_back(i);
    }
    vector<i64> color(n+1, 0), mask(n+1, 0);

    vector<int> coprime((1<<l), 0);
    for (auto pi : ps) {
        if (pi == 2) continue;
        int pj = pi ^ 2;
        if (prime[pj]) {
            coprime[pi] = pj;
            coprime[pj] = pi;
        }
    }

    int ans = 1;
    // for (auto pi : ps) cout << pi << " "; cout << endl;
    // for (auto coi : coprime) {
    //     cout << coi << " ";
    // }cout << endl;

    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            color[i] = 1;
            for (auto pi : ps) {
                int x = i ^ pi;
                if (x != 0 && x <= n && color[x] == 0) {
                    color[x] = 2;
                    ans = max(ans, 2);
                    if (coprime[pi] != 0) {
                        // cout << i << "," << (i^pi) << "," << (i^coprime[pi]) << endl;
                        color[x] = 3;
                        ans = max(ans, 3);
                        if ((coprime[pi] ^ i) <= n) {
                            color[coprime[pi] ^ i] = 4;
                            ans = 4;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        cout << color[i] << " ";
    }
    cout << endl;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (i!=j && prime[i^j] && color[i] == color[j]) {
                cout << i << ',' << j << endl;
            }
        }
    }

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= N; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= N; i += p) {
                prime[i] = false;
            }
        }
    }
    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}