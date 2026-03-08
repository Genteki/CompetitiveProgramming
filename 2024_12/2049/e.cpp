// e.cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int query(int l, int r) {
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    int response;
    cin >> response;
    if (response == -1) {
        exit(0);
    }
    return response;
}

void solve() {
    i64 n;
    cin >> n;
    int r1, r2, r3,r4=0;
    r1=query(1, n/4);
    r2=query(n/4+1, n/2);
    r3=query(n/2+1, 3 * n / 4);
    // r4=query(3*n/4+1, n);
    int x = r1 + r2 + r3 + r4;
    if ( x > 1) {
        i64 low = 1;
        i64 high = n/4;
        int l;
        if (r1 + r2 == 2) {
            l = 1;
        } else {
            l = n/2+1;
        }
        while (high - low > 1) {
            i64 mid = (high + low) / 2;
            int r = query(l, l + mid - 1);
            if (r) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << "! " << high << endl;
        cout.flush();
        return;
    } else {
        i64 low = n/4;
        i64 high = n-1;
        i64 l = n/2 + 1;
        if (r1) {
            l = 1;
        } else if (r2) {
            l = n/4+1;
        } else if(r3) {
            l = n/2 + 1;
        } else {
            l = 3*n/4 +1;
        }
        while(high - low > 1) {
            int mid = (high + low ) /2;
            int res;
            if (l + mid - 1 <= n) {
                res = query(l, l+mid-1);
            } else {
                res = query(n-mid+1, n);
            }
            if (res) {
                low = mid;
            } else {
                high = mid;
            }
        }
        cout << "! " << high << endl;
        cout.flush();
        return;
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}