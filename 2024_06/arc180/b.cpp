#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), ind(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        ind[p[i]] = i;
    }
    int m = 0;
    vector<pair<int, int>> op;
    // for (int i = n-1; i >= 0; --i) {
    //     int indi = ind[i];
    //     while(indi+k<n) {
    //         int ad=0;
    //         while(ad < k && ad+indi < n && p[indi] < p[indi+ad]) {
    //             ++ad;
    //         }
    //         if (p[indi] > p[indi+k+ad]) {
    //             op.push_back({indi, indi+k+ad});
    //             swap(ind[i], ind[p[indi+k+ad]]);
    //             swap(p[indi], p[indi+k+ad]);
    //             indi = indi + k + ad;
    //         } else {
    //             break;
    //         }
    //     }
    // }
    // for (int d = 1; d < n; ++d) {
    //     for (int i = n; i > 0; --i) {
    //         int j = i - d;
    //         if (j >= 0 && j < n && ind[j] - ind[i] >= k) {
    //             op.push_back({ind[i], ind[j]});
    //             swap(ind[j], ind[i]);
    //         }
    //     }
    // }
    

    cout << op.size() << endl;
    for (auto &[l, r] : op) {
        cout << (l+1) << " " << (r+1) << endl;
    }
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