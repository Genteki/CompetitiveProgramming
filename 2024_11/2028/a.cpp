#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for (auto& ai : (x)) std::cin >> ai

using namespace std;

typedef long long i64;

void solve() {
    int n, targetX, targetY;
    cin >> n >> targetX >> targetY;

    string s;
    cin >> s;

    int a = 0, b = 0;

    for (char move : s) {
        switch (move) {
            case 'N':
                b++;
                break;
            case 'E':
                a++;
                break;
            case 'S':
                b--;
                break;
            case 'W':
                a--;
                break;
        }

        if (a == targetX && b == targetY) {
            cout << "YES" << endl;
            return;
        }
    }

    int da = a, db = b;

    a = 0, b = 0;

    for (char move : s) {
        switch (move) {
            case 'N':
                b++;
                break;
            case 'E':
                a++;
                break;
            case 'S':
                b--;
                break;
            case 'W':
                a--;
                break;
        }

        if (da == 0 && db != 0) { 
            if (a == targetX && (targetY - b) % db == 0 && (targetY - b) / db >= 0) {
                cout << "YES" << endl;
                return;
            }
        } else if (da != 0 && db == 0) {
            if (b == targetY && (targetX - a) % da == 0 &&
                (targetX - a) / da >= 0) {
                cout << "YES" << endl;
                return;
            }
        } else if (da != 0 && db != 0) {
            if ((targetX - a) % da == 0 && (targetY - b) % db == 0 && 
                (targetX - a) / da == (targetY - b) / db && (targetY - b) / db >= 0) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }
}