// c.cpp
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define input(x) for(auto&ai:(x)) std::cin>>ai
#define flush fflush(stdout)

using namespace std;

typedef long long i64;
const int inf = 0x3f3f3f3f; // memset(a, 0x3f, sizeof(a))

void solve() {
	int n, m; cin >> n >> m;
	int q = n + m + 1;
	vector<i64> a(q),b(q),c(q);
	input(a); 
	input(b);

	i64 s = 0;
	int t = 0, p = 0;
	int i_overflow = -1;
	bool prog_overflow;
	for (int i = 0; i < m+n+1; ++i) {
		if (a[i] > b[i]) {
			++p;
			if (p == n+1) {i_overflow = i; prog_overflow = 1;}
		} else {
			++t;
			if (t == m+1) {i_overflow = i; prog_overflow = 0;}
		}
	}
	// cout << " " << i_overflow << endl;
	// bool prog_overflow = (p > t);
	if (i_overflow == m + n) {
		for (int i = 0; i < m + n; ++i) {
			s += max(a[i], b[i]);
		}
		for (int i = 0; i < m+n; ++i) {
			cout << (s - max(a[i], b[i]) + (a[i] > b[i] ? a[m+n] : b[m+n])) << " ";
		}
		cout << s << endl;
		return;
	}	
	// cout << i_overflow << endl;
	for (int i = 0; i < i_overflow; ++i) {
		s += max(a[i], b[i]);
	}
	for (int i = i_overflow; i < m + n + 1; ++i) {
		s += (prog_overflow ? b[i] : a[i]);
	}
	// cout << s << endl;
	// cout << prog_overflow << ":";
	for (int i = 0; i < i_overflow; ++i) {
		if ((a[i] > b[i]) == prog_overflow) {
			cout << (s - max(a[i], b[i]) + abs(a[i_overflow] -b[i_overflow])) << " ";
		} else {
			cout << (s - max(a[i], b[i])) << " ";
		}
	}
	for (int i = i_overflow; i < m + n + 1; ++i) {
		// cout << ".";
		cout << (s - (prog_overflow ? b[i] : a[i])) << " ";
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