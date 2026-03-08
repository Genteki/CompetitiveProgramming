// b.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
	int x;
	cin >> x;
	int tmp = x;
	vector<int> a(32, 0);
	for (int i = 0; i < 32; ++i) {
		int msk = (1 << i); 
		a[i] = (int)(bool)(msk & x);
	}
	int st = 0, ed = 0;
	// for (auto ai : a) cout << ai << " "; cout << endl;
	while (st < 31) {
		if (a[st] == 1 && a[st+1] == 1) {
			ed = st+1;
			a[st] = -1;
			while(a[ed] == 1) {
				a[ed] = 0;
				++ed;
			}
			a[ed] = 1;
			// cout << st << " " << ed << a[st] << endl;;
			st = ed;
		} else {
			++st;
		}
	}
	st = 31;
	while (a[st] == 0) --st;
	cout << (st+1) << endl;
	for (int i = 0; i <= st; ++i) {
		cout << a[i] << " ";
	}cout <<endl;
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