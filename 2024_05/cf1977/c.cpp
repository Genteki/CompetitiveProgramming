// c.cpp
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
	vector<i64> a(n);
	input(a);

	sort(all(a));
	i64 m = a[n-1];
	for (int i = 0; i < n-1; ++i) {
		if (m % a[i]) {
			cout << n << endl;
			return;
		}
	}
	set<i64> st;
	for (auto & ai : a) st.insert(ai);
	map<i64,int,greater<i64>> mp;//, new_mp;
	for (auto ai : a) {
		// new_mp = mp;
		if (mp[ai] == 0) mp[ai] == 1;

		for (auto &mpi : mp) {
			i64 new_lcm = lcm(mpi.first, ai);
			mp[new_lcm] = max(mpi.second+1, mp[new_lcm]);
		}
		// mp = new_mp;
	}

	int largest = 0;
	for (auto mpi : mp) {
		if (mpi.second > largest && (st.find(mpi.first)==st.end())) {
			largest = mpi.second;
		}
	}
	// for (auto & mpi : mp) cout << " " << mpi.first << " " << mpi.second << endl;
	cout << largest << endl;
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