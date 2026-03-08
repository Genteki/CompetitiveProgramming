// c.cpp
#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long i64;

int dist(int x, int y) {
    int xa = x / 3;
    int ya = y / 3;
    int ra = x % 3 - 1 + y % 3 - 1;
    int da = (xa + ya) * 3;
    if (ra == 1) {
        da++;
    } else if (ra == 2) {
        da+=4;
    }
    debug(x, y, da);
    return da;
}

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto &ci : c) cin >> ci;
    queue<pair<int,int>> q1;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> q2;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (cnt > n) break;
            q1.emplace(j*3+1,( i-j)*3+1);
            ++cnt;
        }
        if (cnt > n) break;
    }
    cnt = 0;
    for(int i = 0; i < n; ++i) {
        for (int x = 0; x <= i; ++x) {
            if (cnt > n) break;
            int y = i - x;
            q2.push({dist(x * 3 + 1, y * 3 + 1), x * 3 + 1, y * 3 + 1});
            q2.push({dist(x * 3 + 1, y * 3 + 2), x * 3 + 1, y * 3 + 2});
            q2.push({dist(x * 3 + 2, y * 3 + 1), x * 3 + 2, y * 3 + 1});
            q2.push({dist(x * 3 + 2, y * 3 + 2), x * 3 + 2, y * 3 + 2});
            cnt += 1;
        }
        if (cnt > n) break; 
    }
    set<pair<int,int>> st;
    auto check1 = [&](pair<int,int> x) -> bool{
        return st.contains(x);
    };
    auto check2 = [&](array<int, 3> x) -> bool { 
        return st.contains({x[1], x[2]}); 
    };
    for (auto ci : c) {
        if (ci == 0) {
            while(check1(q1.front())) q1.pop();
            auto [x, y] = q1.front();
            q1.pop();
            cout << x << " " << y << "\n";
            st.emplace(x, y);
        } else {
            while(check2(q2.top())) {q2.pop();}
            auto [_, x, y] = q2.top();
            q2.pop();
            cout << x << " " << y << "\n";
            st.emplace(x, y);
        }
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