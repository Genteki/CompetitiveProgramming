// c.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n , q;
    cin >> n >> q;
    string s;
    cin >> s;
    int st = 0;
    for (;q--;){
        int x,y ;
        cin >> x >> y;
        if (x == 1) {
            st -= y;
            st = st % n;
            // cout << st << endl;
            if (st < 0) st += n;
        } else {
            y = y + st - 1;
            y = y % n;
            cout << s[y] << endl;
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