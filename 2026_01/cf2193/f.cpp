#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
struct line {
    int low = -1;
    int high = INT_MAX;
};

bool chmin(i64& a, i64 b){ return b < a ? a = b, true : false; }
bool chmax(i64& a, i64 b){ return b > a ? a = b, true : false; }
void solve() {
    i64 n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vector<i64> x(n), y(n);
    for (auto & xi : x) cin >> xi;
    for (auto & yi : y) cin >> yi;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int& i, int& j) -> bool {
        return x[i] < x[j];
    });
    // for (auto oi : order) cout << oi << " " ; cout << endl;
    int m = 1;
    for (int i = 0; i < n-1; ++i) {
        if (x[order[i]] != x[order[i+1]]) ++m;
    }
    map<i64, array<i64, 2>> mp;
    for (int i = 0; i < n; ++i) {
        if (mp.find(x[i]) == mp.end()) {
            mp[x[i]] = {y[i], y[i]};
        } 
        else {
            chmin(mp[x[i]][0], y[i]);
            chmax(mp[x[i]][1], y[i]);
        }
    }
    array<i64 , 2>  ans({0}), last({ay, ay});
    for (auto p : mp) {
        i64 low = p.second[0];
        i64 high = p.second[1];
        // cout << p.first << ": " << low  << " " << high << " " << endl;
        array<i64,2> new_ans;
        new_ans[1] = (high-low) + min(abs(low - last[0]) + ans[0], abs(low - last[1]) + ans[1]);
        new_ans[0] = (high-low) + min(abs(high - last[0]) + ans[0], abs(high - last[1]) + ans[1]);
        ans = new_ans;
        last = {low, high};
    }

    i64 new_ans;
    new_ans = min(abs(by - last[0]) + ans[0], abs(by - last[1]) + ans[1]) + bx - ax;
    cout << new_ans << endl;
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