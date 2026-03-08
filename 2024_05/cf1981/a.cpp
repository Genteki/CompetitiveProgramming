// a.cpp

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
	int l;
	int r;
	cin >> l >> r;
	int ans = 0;
	while (r > 0) {
		r = r >> 1;
		ans++;
	}
	cout << (ans-1) << endl;

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