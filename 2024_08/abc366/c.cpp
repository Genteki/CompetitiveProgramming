#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int q;
    cin >> q;
    map<int,int> mp;
    for (;q--;) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            mp[x]++;
        } else if (q == 2) {
            int x;
            cin >> x;
            mp[x]--;
            if (mp[x] == 0) {
                mp.erase(x);
            }
        } else {
            cout << mp.size() << endl;
        }
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