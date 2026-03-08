// d.cpp
#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
using namespace std;

typedef long long i64;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool chmin(int& a, int b){ return b < a ? a = b, true : false; }
const int inf = 1e9;
void solve() {
    int h, w;
    cin >> h >> w;
    vector m(h, vector<char>(w));
    for (auto & mi : m) for (auto& mii : mi) cin >> mii;
    vector d(h, vector(w, inf));
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    --ax; --ay; --bx; --by;
    priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
    d[ax][ay] = 0;
    pq.push({0, ax, ay});
    while(!pq.empty()) {
        auto [d0, x, y] = pq.top();
        pq.pop();
        debug(x, y, d0);
        if (x==bx and y == by) {
            cout << d0;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and nx < h and ny >= 0 and ny < w) {
                if (m[nx][ny] == '#') {
                    if(chmin(d[nx][ny], d0+1)) {
                        pq.push({d0+1, nx, ny});
                    }
                    nx  += dx[i];
                    ny += dy[i];
                    if (nx >= 0 and nx < h and ny >= 0 and ny < w) {
                        if (chmin(d[nx][ny], d0+1)) {
                            pq.push({d0+1, nx, ny});
                        }
                    }
                } else {
                    if (chmin(d[nx][ny], d0)) {
                        pq.push({d0, nx, ny});
                    }
                }
            }
        }
    }
    cout << d[bx][by];
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}