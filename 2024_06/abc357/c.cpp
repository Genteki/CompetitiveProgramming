#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> m(pow(3, n), vector<char>(pow(3, n), '.'));

    auto f = [&](auto &&self, int x, int y, int s) {
        if (s == 1) {
            m[x][y] = '#';
            return;
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!(i==1&&j==1)) self(self, x + i * s / 3, y + j * s / 3, s/ 3);
                // else {
                //     for (int k = x + s / 3 ; k < x + 2 * s / 3; ++k) {
                //         for (int l = y + s / 3 ; k < y + 2 * s / 3; ++l) {
                //             m[k][l] = '.';
                //         }
                //     }
                // }
            }
        }
    };

    f(f,0,0,pow(3,n));
    for (auto &mi : m) {
        for (auto &mii : mi) {
            cout << mii;
        } cout << endl;
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
