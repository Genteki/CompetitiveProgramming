// d.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

int query(int i, int j) {
    cout << "? " << (i+1) << " " << (j+1) << endl;
    flush;
    int res;
    cin >> res;
    flush;
    if (res == -1) exit(0);
    return res;
}

void solve() {
    int n;
    cin >> n;
    int pos = -1 ,imposter = -1;
    if (n % 2 == 1) {
        for (int i = 0; i + 1 < n; i += 2) {
            if (i + 3 == n) {
                    int a1 = query(i, i+1);
                    int a2 = query(i, i+2);
                    int a3 = query(i + 1, i + 2);
                    if (a1 == a2) {
                        
                    }
                    // Output the result
                    cout << "! " << (imposter + 1)
                         << endl;  // Adjusted to 1-based indexing
                    flush;
                    return;
            }
            int a1 = query(i, i+1);
            int a2 = query(i + 1, i);
            if (a1 != a2) {pos = i;break;}
        } 
        if (pos == -1) {
            imposter = n;
            cout << "! " << (imposter) << endl;
            flush;
            return;
        }
    } else {
        for (int i = 0; i + 2 < n; i += 2) {
            int a1 = query(i, i+1);
            int a2 = query(i + 1, i);
            if (a1 != a2) {pos = i; break;}
        } 
        if (pos == -1) pos = (n - 2);
    }
    
    
    int pos_ = (pos - 1 + n) % n;
    int a1 = query(pos, pos_);
    int a2 = query(pos_, pos);
    if (a1 == a2) {
        imposter = pos + 1;
    } else imposter = pos;
    cout << "! " << (imposter+1) << endl;
    return;
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_cases = 1;
    cin >> test_cases;
    for (; test_cases--;) {
        solve();
    }
}