// labyrith.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, m;
    cin >> n >> m;
    int dx[4] = {1, -1, 0,0}, dy[4] = {0, 0, 1, -1};
    string dir = "DURL", rdir="UDLR";
    vector<vector<char>> laby(n, vector<char>(m));
    int sx, sy, tx, ty;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char &x = laby[i][j];
            cin >> x;
            if (x == 'A') {
                sx = i;
                sy = j;
            }
            if (x == 'B') {
                tx = i; ty = j;
            }
        }
    }
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> viewed(n, vector<bool>(m, false));
    distance[sx][sy] = 0;
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while(!q.empty()) {
        auto& [x, y] = q.front();
        if(x == tx && y == ty) break;
        q.pop();
        viewed[x][y] = true;
        for (int d = 0; d < 4; ++d) {
            int newx = x + dx[d];
            int newy = y + dy[d];
            if (newx >= 0 && newy >= 0 && newx < n && newy < m && laby[newx][newy] != '#')  {
                distance[newx][newy] = min(distance[newx][newy], distance[x][y]+1);
                if (!viewed[newx][newy]) q.push({newx, newy});
                // viewed[newx][newy] = true;
            }
        }
    }

    if (distance[tx][ty] == INT_MAX) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        cout << distance[tx][ty] << endl;
    }
    int x = tx, y = ty;
    vector<int> steps;
    while(x != sx || y != sy) {
        for (int d = 0; d < 4; ++d) {
            int newx = x + dx[d];
            int newy = y + dy[d];
            if (newx >= 0 && newy >= 0 && newx < n && newy < m &&
                distance[newx][newy] == distance[x][y]-1) {
                    steps.push_back(d);
                    x = newx;
                    y = newy;
                }   
        }
    }
    reverse(all(steps));
    for (auto si : steps) cout << rdir[si]; cout << endl;
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