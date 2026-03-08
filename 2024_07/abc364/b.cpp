// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int h, w;
    cin >> h >> w;
    int sx, sy;
    cin >> sx >> sy;
    --sx; --sy;
    vector<vector<char>> m(h, vector<char>(w));
    for (auto &mi : m) {
        for (auto && mii : mi) {
            cin >> mii;
        }
    }

    string op;
    cin >> op;
    for (auto opi : op) {
        int dx = 0, dy = 0;
        switch (opi) {
        case 'R':
            dy = 1;
            break;
        case 'L':
            dy = -1;
            break;
        case 'D':
            dx = 1;
            break;
        case 'U':
            dx = -1;
            break;
        default:
            break;
        }
        int newx = sx + dx, newy = sy + dy;
        if (newx >= 0 && newy >= 0 && newx < h && newy < w) {
            if (m[newx][newy] == '.') {
                sx = newx;
                sy = newy;
            }
        }
    }
    cout << (sx+1) << " " << (sy + 1);
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