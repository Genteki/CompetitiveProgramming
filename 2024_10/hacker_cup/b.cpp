#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int N = 1e7;
vector<int> prime(1e7+1, true);
void solve(int t) {
    cout << "Case #" << t << ": ";
    set<int> ps;
    int n ;
    cin >> n;
    if (n <= 4) {
        cout << 0 << endl;
        return;
    }
    for (int i = 3; i <= n; ++i) {
        if(prime[i] && prime[i - 2]) ps.insert(i - 2);
    }
    cout << (ps.size() + 1) << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifdef INPUT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
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
    for (int t = 0; t < test_cases; ++t) {
        solve(t + 1);
    }
}