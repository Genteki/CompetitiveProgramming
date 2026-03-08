// d.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif  
typedef long long i64;
void solve() {
    int h, w;
    cin >> h >> w;
    int sx=-1, sy=-1, gx=-1, gy=-1;
    vector<vector<char>> m(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j){
            cin >> m[i][j];
            if (m[i][j] =='S') {
                sx = i;
                sy = j;
            } else if (m[i][j] == 'G') {
                gx = i;
                gy = j;
            }
        }
    }
    vector dis(2, vector(h, vector<int>(w, -1)));
    dis[0][sx][sy] = 0;
    dis[1][sx][sy] = 0;
    queue<tuple<int,int,int>> q;
    q.emplace(sx,sy,0); q.emplace(sx,sy,1);
    while(!q.empty()) {
        auto [x,y,d] = q.front();
        q.pop();

        if (x==gx and y==gy) {
            cout << dis[d][x][y];
            return;
        }
        int next_d = !d;
        int d0 = dis[d][x][y];
        if (d) {
            if (y+1 < w and m[x][y+1]!='#' and dis[next_d][x][y+1] == -1) {
                dis[next_d][x][y + 1] = d0 + 1;
                q.emplace(x, y + 1, next_d);
            }
            if (y-1 >= 0 and m[x][y-1]!='#' and dis[next_d][x][y-1] == -1) {
                dis[next_d][x][y - 1] = d0 + 1;
                q.emplace(x, y - 1, next_d);
            }
        } else {
            if (x+1 < h and m[x+1][y]!='#' and dis[next_d][x+1][y] == -1) {
                dis[next_d][x + 1][y] = d0 + 1;
                q.emplace(x + 1, y, next_d);
            }
            if (x-1 >= 0 and m[x-1][y]!='#' and dis[next_d][x-1][y] == -1) {
                dis[next_d][x - 1][y] = d0 + 1;
                q.emplace(x - 1, y, next_d);
            }
        }
    }
    cout << -1;
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    for (; test_cases--;) {
        solve();
    }
}