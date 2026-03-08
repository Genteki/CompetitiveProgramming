#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

bool jd(vector<int> &b, int i, int ci, int n) {
    auto c = b;
    if (i == 0) {
        if (ci <= b[2]) {
            return true;
        } else {
            return false;
        }
    } else if (i == n-3) {
        if (b[i-1] <= ci) {
            return true;
        } else {
            return false;
        }
    }  
    else {
        if (ci <= b[i+2] && b[i-1] <= ci) {
            return true;
        } else {
            return false;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    input(a);
    if (n==3) {
        cout << "YES\n";
        return;
    }
    vector<int> b(n-1);
    for (int i = 0; i < n-1; ++i) {
        b[i] = std::gcd(a[i], a[i+1]);
    }

    vector<int> c(n-2);
    for (int i = 0; i < n-2; ++i) {
        c[i] = std::gcd(a[i], a[i+2]);
    }

    vector<int> w;
    for (int i = 0; i < n - 2; ++i) {
        if (b[i] > b[i+1]) {
            w.push_back(i);
        }
    }

    if (w.size() > 3) {
        cout << "NO";
    } else if (w.size() == 0 ) {
        cout << "YES";
    } else if (w.size() == 1) {
        // cout << "Case1: " << w[0] << "|" << c[w[0]] << "|";
        if (w[0] == n-3 || w[0] == 0) {
            cout << "YES";
        } else if (jd(b, w[0]-1, c[w[0]-1], n)) {
            cout << "YES";
        } else if (jd(b, w[0] + 1, c[w[0] + 1], n)) {
            cout << "YES";
        } else if (jd(b, w[0], c[w[0]], n)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else if (w.size() == 2) {
        if (w[1] - w[0] == 2) {
            if (jd(b, w[0]+1, c[w[0]+1], n)) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else if (w[1]-w[0]==1) {
            if(jd(b, w[0], c[w[0]], n) || jd(b, w[0]+1, c[w[0]=1], n)) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else {
            cout << "NO";
        }
    } else if (w.size() == 3) {
        if (jd(b, w[1], c[w[1]], n)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    cout << endl;
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