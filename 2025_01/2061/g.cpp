// g.cpp
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

int query(int x, int y) {
    cout << "? " << (x+1) <<  " " << (y+1) << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}
void outp(vector<int> &v, int k) {
    cout << "! ";
    for (int i = 0; i < k*2; ++i) cout << (v[i]+1) << " ";
    cout << endl;
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << 1 << endl;
        cout.flush();
        cout << "! 1 2\n";
        cout.flush();

    }
    else if (n % 4 == 0) {
        cout << (n/4) << endl;
        cout.flush();

        vector<vector<int>> a(2, vector<int>());
        for (int i = 0; i < n / 2; ++i) {
            int h = query(2 * i, 2 * i + 1);
            a[h].push_back(2 * i);
            a[h].push_back(2 * i + 1);
        }
        // for (auto ai : a[0]) cout << ai  << " ";cout << endl;cout.flush();
        if (a[0].size() < a[1].size()) swap(a[0], a[1]);
        outp(a[0], n/4);
    } else {
        int k = n/4+1;
        cout << k << endl;
        cout.flush();

        vector<vector<int>> a(2, vector<int>());
        for (int i = 0; i < n / 4 * 2; ++i) {
            int h = query(2 * i, 2 * i + 1);
            a[h].push_back(2 * i);
            a[h].push_back(2 * i + 1);
        }
        if (a[0].size() >= k * 2) {outp(a[0], k);return;}
        if (a[1].size() >= k * 2) {outp(a[1], k);return;}
        int q = n-1;
        int a1 = query(q, a[0][0]);
        int a2 = query(q, a[1][0]);
        int a3 = query(a[0][1], a[1][1]);
        if (a1 == 1) {
            a[1].push_back(q);
            a[1].push_back(a[0][0]);
            outp(a[1], k);
            return;
        } else if (a2 == 0) {
            a[0].push_back(q);
            a[0].push_back(a[1][0]);
            outp(a[0], k);
            return;
        } else  {
            a[a3].push_back(a[a3][1]);
            a[a3].push_back(a[1-a3][1]);
            a[a3][1] = q;
            outp(a[a3], k);
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