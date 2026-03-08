#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
void solve() {
    int r, b;
    cin >> r >> b;
    debug(r,b);
    if (r % 2 == 1) {
        cout << "No" << endl;
        return;
    }
    if (r == 0 and b % 2 == 1) {
        cout << "No" << endl;
        return;
    }

    int s = r/2 + b;
    auto go = [](int x0, int y0, int x, int y, int& t) -> void {
        debug(t);
        if (t == 0) {
            cout << "R " << x0 << " " << y0 << "\n";
            int dx = x-x0, dy = y-y0;
            if (dx==1 and dy==1) {
                cout << "R " << x0+1 << " " << y0 << "\n";
            } else if (dx==-1 and dy==1) {
                cout << "R " << x0 << " " << y0+1 << "\n";
            } else if (dx==-1 and dy==-1) {
                cout << "R " << x0-1 << " " << y0 << "\n";
            } else if (dx ==1 and dy==-1) {
                cout << "R " << x0 << " " << y0-1 << "\n";
            }
        } else {
            t--;
            cout << "B " << x0 << " " << y0 << "\n";
        }
    };
    cout << "Yes\n";
    if (b == 0 and r == 2) {
        cout << "R 1 1\n";
        cout << "R 2 1\n";
        return;
    }
    if (s==2) {
        go(1, 1, 2, 2, b);
        go(2, 2, 1, 1, b);
        return;
    }
    if (s%2 == 0) {
        int l = (s-2)/2;
        int px = 1+l, py = l;
        int qx = l, qy = l+1;
        int x=2, y=1;
        for (int i = 0; i < l; ++i) {
            go(x, y, x+1, y+1, b);
            x++;
            y++;
        }
        go(x, y, x-1, y+1, b);
        x--; y++;
        for(int i = 0; i < l;++i) {
            go(x, y, x-1,y-1, b);
            x--; y--;
        }
        go(1,2,2,1,b);
    } else {
        int l = (s-1)/2;
        int px = 1+l, py = l;
        int qx = l, qy = l+1;
        int x=2, y=1;
        for (int i = 0; i < l; ++i) {
            go(x, y, x+1, y+1, b);
            x++;
            y++;
        }
        go(x, y, x-1, y+1, b);
        x--; y++;
        for(int i = 0; i < l-1;++i) {
            go(x, y, x-1,y-1, b);
            x--; y--;
        }
        cout << "R 2 3\nR 2 2\n";
    }
    return;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}