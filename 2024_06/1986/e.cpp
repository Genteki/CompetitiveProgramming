#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    vector<i64> a(n);
    input(a);

    sort(all(a));
    map<i64, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        int mod = a[i] % k;
        mp[mod].push_back(i);
    }
    int tor = 0;
    if (n % 2 == 1) tor = 1;
    int ans = 0;
    for (auto &[mod, mpi] : mp) {
        if (mpi.size() % 2 == 1) {
            --tor;
            if (tor < 0) {
                cout << -1 << endl;
                return;
            }
            int l = mpi.size() / 2;
            vector<int> s1(l+1, 0), s2(l+1, 0);
            for (int i = 1; i <= l; ++i) {
                s1[i] = s1[i - 1] + (a[mpi[2 * (i-1) + 1]] - a[mpi[2 * (i-1)]]) / k;
            }
            for (int i = l-1; i >= 0; --i) {
                s2[i] = s2[i+1] + (a[mpi[(i+1)*2]] - a[mpi[(i+1)*2-1]]) / k;
            }
            int all_m = inf;
            for (int i = 0; i < mpi.size(); i+=2) {
                int j = i / 2;
                int cur_m = s1[j] + s2[j];
                all_m = min(cur_m, all_m);
                // cout << " " << s1[j] << " " << s2[j] << endl;
                // cout << " " << a[mpi[(l)*2]] << " " << a[mpi[l*2-1]] << endl;
            }
            ans += all_m;
        } else {
            for (int i = 0; i < mpi.size(); i+=2) {
                ans += ((a[mpi[i+1]] - a[mpi[i]]) / k);
            }
        }
    }
    cout << ans << endl;

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}