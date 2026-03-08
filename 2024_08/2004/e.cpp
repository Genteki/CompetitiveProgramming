// e.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)
using namespace std;

const int N = 1e7 + 1;
vector<int> isPrime(N, true);


typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    
    int x = 0, y = 0;
    for (auto ai : a) {
        if (!isPrime[ai]) x++;
        else y++;
    }
    bool winner = y % 2;
    // if (x % 2 ) winner = !winner;
    if (!winner) cout << "Bob";
    else cout << "Alice";
    cout << endl;

    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not primes

    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;  // Mark multiples of i as non-prime
            }
        }
    }
    isPrime[1] = true;
    

    // for (int i = 0; i < 100; ++i) {
    //     if (isPrime[i]) {
    //         cout << i << ' ';
    //     }
    // }

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}