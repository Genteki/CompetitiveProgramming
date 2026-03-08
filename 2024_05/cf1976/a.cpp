// a.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
	int n;
	cin >> n;
	string pw;
	cin >> pw;
	
	for (int i = 0; i <n; ++i) {
		if (!((pw[i] >= 'a' && pw[i] <='z') || (pw[i] >= '0' && pw[i] <= '9'))) {
			// cout << i << "?";
			
			cout << "no" << endl;
			return;
		}
	}	

	if (n == 1) {
		cout << "yes\n"; return;
	}
	int p = n;


	for (int i = 0; i <n; ++i) {
		if (pw[i] >= 'a' && pw[i] <='z') {
			p = i;
			// cout << p << endl;
			break;
		}
	}

	for (int i = p; i < n; ++i) {
		if (!(pw[i] <= 'z' && pw[i] >= 'a')) {
			// cout << i << "?";

			cout << "no" << endl; 
			return;
		}
	}

	for (int i = 0; i < p-1; ++i) {
		if (pw[i] > pw[i+1]) {
			// cout << i << "?";

			cout << "no" <<  endl;
			return;
		}
	}
	for (int i = p; i < n-1; ++i) {
		if (pw[i] > pw[i+1]) {
			// cout << i << "?";

			cout << "no" <<  endl;
			return;
		}
	}
	cout << "yes\n"; 
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