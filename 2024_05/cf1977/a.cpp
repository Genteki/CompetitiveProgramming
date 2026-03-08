// a.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
	int n, m;
	cin >> n >> m;
	if (n < m) {
		cout << "no";
	} else {
		if ((n-m) % 2 ==0) {
			cout << "yes";
		} else {
			cout << "no";
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


