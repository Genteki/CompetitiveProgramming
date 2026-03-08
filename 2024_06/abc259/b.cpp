// b.cpp
#include <bits/stdc++.h>
#include <cmath>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto& ai : (x)) std::cin >> ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;

void solve() {
    double a, b, d;
    cin >> a >> b >> d;
    double theta1 = 0;
    if ((int)a == 0 &&(int) b == 0) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    if ((int)a!= 0) 
        theta1 = atan(b/a) + ((a > 0) ? 0 : M_PI);
    else
        theta1 = b > 0 ? M_PI / 2 : -M_PI / 2;
    double theta2 = M_PI * d / 180LL;
    double theta = theta1 + theta2;
    // if (theta >= 2*M_PI) theta = theta - M_PI * 2 * (int)(theta/M_PI/2);
    // else if(theta < 0) theta = theta + M_PI * 2;
    double ansx = sqrt(a*a + b*b) * cos(theta);
    double ansy = sqrt(a*a + b*b) * sin(theta);
    // cout << theta / M_PI * 180LL << " ";
    cout << setprecision(8) << ansx << " " << ansy << endl;
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