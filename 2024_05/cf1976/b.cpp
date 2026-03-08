// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
	int n ;
	cin >> n;
	vector<i64> a(n);
	input(a);
	vector<i64> b(n+1);
	input(b);

	i64 ans = 1; i64 diff = 1e9 + 1; i64 x= b.back();
	for (int i = 0; i < n; ++i) {
		ans = ans + (abs(a[i] - b[i]));

		i64 tmp = 1e9 + 1;
		if ( (a[i]-x) * (b[i] - x) <= 0) {
			tmp = 0;
		} else {
			tmp = min(abs(a[i]-x), abs(b[i] - x));
		}
		diff = min(tmp, diff);
		// cout << " " << (abs(a[i] - b[i])) << " " << (tmp) << endl;	
		
		// cout << " " << ans << endl;
	}
	ans += diff;
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