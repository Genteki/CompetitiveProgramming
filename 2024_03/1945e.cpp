	// #include <bits/stdc++.h>
	#include <algorithm>
	#include <bitset>
	#include <iostream>
	#include <string>
	#include <sstream>
	#include <map>
	#include <set>
	#include <memory>
	#include <unordered_map>
	#include <unordered_set>
	#include <random>
	#include <vector>
	#include <regex>

	using namespace std;

	typedef long long i64;

	const int inf = 0x3f3f3f3f;
	// memset(a, 0x3f, sizeof(a))

	void solve() {
		int n, x, ix;
		cin >> n >> x;
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			if (p[i] == x) {
				ix = i;
			}
		}
		int k = 2;
		int iy = int(n/2);
		p[ix] = p[iy];
		p[iy] = x;

		int iz = iy;
		int l = 0, r = n;
		while (r - l != 1 ) {
			int m = int((r+l) / 2);
			if (p[m] <= x) {
				l = m;
				iz = l;
			} else {
				r = m;
			}
		}
		k = k - (ix==iy) - (iy==iz);

		cout << k << endl;
		if (ix != iy) cout << (ix+1) << " " << (iy+1) << endl;
		if (iy != iz) cout << (iy+1) << " " << (iz+1) << endl;


		// int temp = p[iy];
		// p[iy] = p[iz]; p[iz] = temp;
		// l = 0; r = n;
		// while (r - l != 1 ) {
		// 	int m = int((r+l) / 2);
		// 	if (p[m] <= x) {
		// 		l = m;
		// 		iz = l;
		// 	} else {
		// 		r = m;
		// 	}
		// }
		// cout << "true: " <<( p[l] == x) << endl;

	    return;
	}

	int main() {
	    std::ios::sync_with_stdio(false);
	    std::cin.tie(nullptr);
	    
	    int test_cases;
	    cin >> test_cases;
	    for (; test_cases--;) {
	        solve();
	    }
	}