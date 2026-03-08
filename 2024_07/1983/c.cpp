#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n), b(n), c(n);
    input(a);
    input(b);
    input(c);
    i64 tot = accumulate(all(a), 0LL);
    i64 target = (tot + 2) / 3;

    vector<i64> psa(n+1,0), psb(n+1, 0), psc(n+1,0);
    for (int i = 0; i < n; ++i) {
        psa[i+1] = psa[i] + a[i];
        psb[i+1] = psb[i] + b[i];
        psc[i+1] = psc[i] + c[i];
    }

    auto bs = [&target, &n](vector<i64>& ps, int start) -> int {
        int low = start, high = n;
        if (ps[n] - ps[start] < target) return 5;
        while(high - low > 1) {
            int mid = (high + low) / 2;
            if (ps[mid] - ps[start] == target) {
                return mid;
            } else if (ps[mid] - ps[start] > target) {
                high = mid;
            } else {
                low = mid;
            }
        } 
        return high;
    };

    auto find = [&target, &n, &bs] (vector<i64>& psa, vector<i64>& psb, vector<i64>& psc) -> vector<int> {
        vector<int> result(3, 0);
        int la = 0;
        int ra = bs(psa, 0);
        int rb = bs(psb, ra);
        int rc = n;
        if (psc[n] - psc[rb] >= target) {
            result[0] = 1;
            result[1] = ra;
            result[2] = rb;
        }
        // cout << ra << " " << rb << endl;
        return result;
    };

    vector<int> result;
    int la, lb, lc, ra, rb, rc;

    result = find(psa, psb, psc);
    if (result[0]) {
        la = 1;
        ra = result[1];
        lb = result[1] + 1;
        rb = result[2];
        lc = result[2] + 1;
        rc = n;
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl; 
        return;
    }

    result = find(psa, psc, psb);
    if (result[0]) {
        la = 1;
        ra = result[1];
        lc = result[1] + 1;
        rc = result[2];
        lb = result[2] + 1;
        rb = n;
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl; 
        return;
    }

    result = find(psb, psa, psc);
    if (result[0]) {
        lb = 1;
        rb = result[1];
        la = result[1] + 1;
        ra = result[2];
        lc = result[2] + 1;
        rc = n;
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl; 
        return;
    }

    result = find(psb, psc, psa);
    if (result[0]) {
        lb = 1;
        rb = result[1];
        lc = result[1] + 1;
        rc = result[2];
        la = result[2] + 1;
        ra = n;
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " "
             << rc << endl;
        return;
    }

    result = find(psc, psb, psa);
    if (result[0]) {
        lc = 1;
        rc = result[1];
        lb = result[1] + 1;
        rb = result[2];
        la = result[2] + 1;
        ra = n;
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " "
             << rc << endl;
        return;
    }
    result = find(psc, psa, psb);
    if (result[0]) {
        lc = 1;
        rc = result[1];
        la = result[1] + 1;
        ra = result[2];
        lb = result[2] + 1;
        rb = n;
        cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " "
             << rc << endl;
        return;
    }

    cout << -1 << endl;
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