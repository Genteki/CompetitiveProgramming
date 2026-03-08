// b.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

void solve() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<vector<char>> a(h, vector<char>(w));
    for (auto & ai : a) for (auto & c : ai) cin >> c;
    string s;
    cin >> s;
    --x; --y;
    vector viewed(h, vector<int>(w, 0));
    int cnt = 0;
    auto mov = [&](int dx, int dy) -> void {
        int nx = x + dx;
        int ny = y + dy;
        if (nx < h && ny < w && nx >= 0 && ny >= 0 && a[nx][ny] != '#') {
            x = nx;
            y = ny;
            if (a[nx][ny] == '@' and !viewed[nx][ny]) ++cnt;
            viewed[nx][ny] = 1;
        }
        cerr << x << y << endl;
    };
    mov(0, 0);

    for (char si : s) {
        if (si == 'L') { mov(0, -1);} 
        else if (si == 'R') mov(0, 1);
        else if (si == 'U') mov(-1, 0);
        else mov(1, 0);
    }
    cout << (x+1) << " " << (y+1) << " " << cnt;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
//    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}